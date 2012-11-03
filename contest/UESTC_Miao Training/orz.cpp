/************************************************************************/
/* mccommon.h, 头文件里面声明了Minicpp使用的函数, 声明主要使用的
 * 最新修改时间2012-9-15, 主要增加了var.cpp里面函数的声明                */
/************************************************************************/

const int MAX_T_LEN  = 128;   // max token length
const int MAX_ID_LEN = 31;    // max identifier length
const int PROG_SIZE  = 10000; // max program size
const int NUM_PARAMS = 31;    // max number of parameters

// Enumeration of token types.
enum tok_types { UNDEFTT, DELIMITER, IDENTIFIER,
                 NUMBER, KEYWORD, TEMP, STRING, BLOCK, TYPE
               };

// Enumeration of internal representation of tokens.
//大部分指定的是C++里面的关键字, 当然cout和cin也被加进来了
enum token_ireps { UNDEFTOK, ARG, BOOL, CHAR, SHORT, INT, LONG, FLOAT, DOUBLE, FALSE, TRUE, SWITCH,
                   CASE, IF, ELSE, FOR, DO, WHILE, BREAK,
                   RETURN, COUT, CIN, END, ENDL, DEFAULT, CONTINUE, NONE
                 };


//上面两个枚举的区别是上面的比较广义,指代各种token的类型, 比如block, 这个是不会是关键字的,
//下面的可以理解成就是关键字

//这是个匿名的var结构体, 存储了变量的类型和值, 但是是个匿名的,
//类似python里面的变量的引用的概念
struct anonymous_var
{
    token_ireps var_type; // data type
    long int_value;
    double float_value;
};
// This structure encapsulates the info
// associated with variables.
struct var
{
    char var_name[MAX_ID_LEN + 1]; // name
    anonymous_var value;
};


// This structure encapsulates function info.
struct func_type
{
    char func_name[MAX_ID_LEN + 1]; // name
    token_ireps ret_type; // return type
    char *loc; // location of entry point in program
};

// Enumeration of two-character operators, such as <=.
//这里注意从1开始, 以免用到0出现误解.
enum double_ops { LT = 1, LE, GT, GE, EQ, NE, LS, RS, INC, DEC };

// These are the constants used when throwing a
// syntax error exception.
//
// NOTE: SYNTAX is a generic error message used when
// nothing else seems appropriate.
enum error_msg
{
    SYNTAX, NO_EXP, NOT_VAR, DUP_VAR, DUP_FUNC,
    SEMI_EXPECTED, UNBAL_BRACES, FUNC_UNDEF,
    TYPE_EXPECTED, RET_NOCALL, PAREN_EXPECTED,
    WHILE_EXPECTED, QUOTE_EXPECTED, DIV_BY_ZERO,
    BRACE_EXPECTED, COLON_EXPECTED, UNSUPPORTED_TYPE
    //最后加了一个UNSUPPORTED_TYPE, 是因为最近只支持一些简单的内建类型
};





//下面这些是全局变量, 用来控制解析的, 估计以后如果重构的话就是parser类的主要成员变量.
extern char *prog;  // current location in source code
extern char *p_buf; // points to start of program buffer

extern char token[MAX_T_LEN + 1]; // string version of token
extern tok_types token_type; // contains type of token
extern token_ireps tok; // internal representation of token

extern anonymous_var ret_value; // function return value

extern bool breakfound; // true if break encountered
extern bool continuefound;//true if continue encountered

// Exception class for Mini C++.
class InterpExc
{
    error_msg err;
public:
    InterpExc(error_msg e)
    {
        err = e;
    }
    error_msg get_err()
    {
        return err;
    }
};

// Interpreter prototypes.
void prescan();
void decl_global();
void call();
void putback();
void decl_local();
void exec_if();
void find_eob();
void exec_for();
void exec_switch();
void get_params();
void get_args();
void exec_while();
void exec_do();
void exec_cout();
void exec_cin();
void assign_var(char *var_name, anonymous_var value);
bool load_program(char *p, char *fname);
anonymous_var find_var(char *s);
void interp();
void func_ret();
char *find_func(char *name);
bool is_var(char *s);
token_ireps find_var_type(char *s);
void find_eol();


// Parser prototypes, 这些函数主要用来parse表达式.
void eval_exp(anonymous_var &value);
void eval_exp0(anonymous_var &value);
void eval_exp1(anonymous_var &value);
void eval_exp2(anonymous_var &value);
void eval_exp3(anonymous_var &value);
void eval_exp4(anonymous_var &value);
void eval_exp5(anonymous_var &value);
void atom(anonymous_var &value);
void sntx_err(error_msg error);
void putback();
bool isdelim(char c);
token_ireps look_up(char *s);
anonymous_var find_var(char *s);
tok_types get_token();
int internal_func(char *s);
bool is_var(char *s);

// "Standard library" prototypes, 这几个函数里面是调用了一下C++的库函数, 封装了一下.
anonymous_var call_getchar();
anonymous_var call_putchar();
anonymous_var call_abs();
anonymous_var call_rand();



//下面这些是为了支持多种类型二增加的一些函数.
//在var.cpp里面实现.
anonymous_var add(anonymous_var &a, anonymous_var &b);
anonymous_var sub(anonymous_var &a, anonymous_var &b);
anonymous_var mul(anonymous_var &a, anonymous_var &b);
anonymous_var div(anonymous_var &a, anonymous_var &b);
void cin_var(anonymous_var &v);
void cout_var(anonymous_var &v);
bool is_valid_type(token_ireps ti);
void init_var(anonymous_var &v);
void neg_var(anonymous_var &v);
bool zero(double x);
void abs_var(anonymous_var &v);
int cmp(anonymous_var &a, anonymous_var &b);
bool is_float_type(token_ireps type);
bool is_int_type(token_ireps type);
bool get_bool_val(anonymous_var &v);
void adaptive_assign_var(anonymous_var &a, anonymous_var &b);


/********************************************************************
   var.cpp, 主要是为了增加对多种数值类型的支持而添加的
 目前支持bool, char, short, int, long, float, double
  基本只使用long和double进行结算.
   **********************************************************************/

#include <iostream>
#include <cmath>
#include "mccommon.h"
using namespace std;

inline bool zero(double x)
{
    const double EPS = 1e-9;
    return abs(x) < EPS;
}
bool is_int_type(token_ireps type)
{
    if(type >= BOOL && type <= LONG) return true;
    return false;
}
bool is_float_type(token_ireps type)
{
    if(type >= FLOAT && type <= DOUBLE) return true;
    else return false;
}
bool check_valid_type(anonymous_var &val)
{
    if(!(is_int_type(val.var_type) || is_float_type(val.var_type))) return false;
    return true;
}
anonymous_var add(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);
    anonymous_var res;
    if(a.var_type > b.var_type) res.var_type = a.var_type;
    else res.var_type = b.var_type;

    if(is_int_type(res.var_type))
    {
        res.int_value = a.int_value + b.int_value;
    }
    else
    {
        if(is_int_type(a.var_type))
        {
            res.float_value = double(a.int_value) + b.float_value;
        }
        else if(is_int_type(b.var_type))
        {
            res.float_value = a.float_value + double(b.int_value);
        }
        else
        {
            res.float_value = a.float_value + b.float_value;
        }
    }
    return res;
}

anonymous_var sub(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);
    anonymous_var res;
    if(a.var_type > b.var_type) res.var_type = a.var_type;
    else res.var_type = b.var_type;

    if(is_int_type(res.var_type))
    {
        res.int_value = a.int_value - b.int_value;
    }
    else
    {
        if(is_int_type(a.var_type))
        {
            res.float_value = double(a.int_value) - b.float_value;
        }
        else if(is_int_type(b.var_type))
        {
            res.float_value = a.float_value - double(b.int_value);
        }
        else
        {
            res.float_value = a.float_value - b.float_value;
        }
    }
    return res;

}

anonymous_var mul(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);
    anonymous_var res;

    if(a.var_type > b.var_type) res.var_type = a.var_type;
    else res.var_type = b.var_type;

    if(is_int_type(res.var_type))
    {
        res.int_value = a.int_value * b.int_value;
    }
    else
    {
        if(is_int_type(a.var_type))
        {
            res.float_value = double(a.int_value) * b.float_value;
        }
        else if(is_int_type(b.var_type))
        {
            res.float_value = a.float_value * double(b.int_value);
        }
        else
        {
            res.float_value = a.float_value * b.float_value;
        }
    }
    return res;
}

anonymous_var div(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);
    anonymous_var res;
    if(a.var_type > b.var_type) res.var_type = a.var_type;
    else res.var_type = b.var_type;

    if(is_int_type(b.var_type))
    {
        if(0 == a.int_value) throw InterpExc(DIV_BY_ZERO);
    }
    else
    {
        if(zero(b.float_value)) throw InterpExc(DIV_BY_ZERO);
    }

    if(is_int_type(res.var_type))
    {
        res.int_value = a.int_value / b.int_value;
    }
    else
    {
        if(is_int_type(a.var_type))
        {
            res.float_value = double(a.int_value) / b.float_value;
        }
        else if(is_int_type(b.var_type))
        {
            res.float_value = a.float_value / double(b.int_value);
        }
        else
        {
            res.float_value = a.float_value / b.float_value;
        }
    }
    return res;
}


//因为现在我只用long 和double来存储表示所有的数值类型,
//在从控制台读取内容的时候会不方便, 现在先用
void cin_var(anonymous_var &v)
{
    switch (v.var_type)
    {
    case BOOL:
    {
        bool tmp_var;
        cin >> tmp_var;
        v.int_value = tmp_var;
        break;
    }
    case CHAR:
    {
        char tmp_var;
        cin >> tmp_var;
        v.int_value = tmp_var;
        break;
    }
    case SHORT:
    {
        short tmp_var;
        cin >> tmp_var;
        v.int_value = tmp_var;
        break;
    }
    case INT:
    {
        int tmp_var;
        cin >> tmp_var;
        v.int_value = tmp_var;
        break;
    }
    case LONG:
    {
        long tmp_var;
        cin >> tmp_var;
        v.int_value = tmp_var;
        break;
    }
    case FLOAT:
    {
        float tmp_var;
        cin >> tmp_var;
        v.float_value = tmp_var;
        break;
    }
    case DOUBLE:
    {
        double tmp_var;
        cin >> tmp_var;
        v.float_value = tmp_var;
        break;
    }
    default:
        throw InterpExc(UNSUPPORTED_TYPE);
        break;
    }
}


//输出的时候, 要先转化成相应的类型, 然后再打印
void cout_var(anonymous_var &v)
{
    switch(v.var_type)
    {
    case BOOL:
        cout << bool(v.int_value != 0);
        break;
    case CHAR:
        cout << char(v.int_value);
        break;
    case SHORT:
        cout << short(v.int_value);
        break;
    case INT:
        cout << int(v.int_value);
        break;
    case LONG:
        cout << long(v.int_value);
        break;
    case FLOAT:
        cout << float(v.float_value);
        break;
    case DOUBLE:
        cout << double(v.float_value);
        break;
    default:
        throw InterpExc(UNSUPPORTED_TYPE);
        break;
    }
}

bool is_valid_type(token_ireps ti)
{
    return ti >= BOOL && ti <= DOUBLE;
}

void init_var(anonymous_var &v)
{
    v.int_value = 0;
    v.float_value = 0.0;
}

void neg_var(anonymous_var &v)
{
    if(is_int_type(v.var_type))
    {
        v.int_value = -v.int_value;
    }
    else if(is_float_type(v.var_type))
    {
        v.float_value = v.float_value;
    }
    else
    {
        throw InterpExc(UNSUPPORTED_TYPE);
    }
}

void abs_var(anonymous_var &v)
{
    if(is_int_type(v.var_type))
    {
        v.int_value = abs(v.int_value);
    }
    else if(is_float_type(v.var_type))
    {
        v.float_value = abs(v.float_value);
    }
    else
    {
        throw InterpExc(UNSUPPORTED_TYPE);
    }
}



int cmp(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);
    if(is_int_type(a.var_type))
    {
        if(is_int_type(b.var_type))
        {
            if(a.int_value == b.int_value) return 0;
            if(a.int_value < b.int_value) return -1;
            return 1;
        }
        else if(is_float_type(a.var_type))
        {
            if(zero(a.int_value - b.float_value)) return 0;
            if(a.int_value < b.float_value) return -1;
            return 1;
        }
    }
    else
    {
        if(is_int_type(b.var_type))
        {
            if(zero(a.float_value - b.int_value)) return 0;
            if(a.float_value < b.int_value) return -1;
            return 1;
        }
        else
        {
            if(zero(a.float_value - b.float_value)) return 0;
            if(a.float_value < b.float_value) return -1;
            return 1;
        }
    }
}

bool get_bool_val(anonymous_var &v)
{
    bool bool_val = false;
    if(is_int_type(v.var_type))
    {
        bool_val = v.int_value != 0;
    }
    else if(is_float_type(v.var_type))
    {
        bool_val = !zero(v.float_value);
    }
    else
    {
        throw InterpExc(UNSUPPORTED_TYPE);
    }
    return bool_val;
}


//这个函数适配性地进行了赋值.
void adaptive_assign_var(anonymous_var &a, anonymous_var &b)
{
    if(!check_valid_type(a) || !check_valid_type(b)) throw InterpExc(UNSUPPORTED_TYPE);

    if(is_int_type(a.var_type))
    {
        if(is_int_type(b.var_type))
        {
            a.int_value = b.int_value;
        }
        else
        {
            a.int_value = int(b.float_value);
        }
    }
    else
    {
        if(is_int_type(b.var_type))
        {
            a.float_value = double(b.int_value);
        }
        else
        {
            a.float_value = b.float_value;
        }
    }
}



/*********************************************************************
    parser.cpp 用来递归下降地解析表达式, 使用anonymous_var类型传递中间结果
  *********************************************************************/


// Recursive descent parser for integer expressions.
//
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "mccommon.h"

using namespace std;

// This structure links a library function name
// with a pointer to that function.
struct intern_func_type
{
    char *f_name; // function name
    anonymous_var (*p)();   // pointer to the function
} intern_func[] =
{
    "getchar", call_getchar,
    "putchar", call_putchar,
    "abs", call_abs,
    "rand", call_rand,
    "", 0  // null terminate the list
};

// Keyword lookup table.
// Keywords must be entered lowercase.
// 定义关键字, 对应一个tok的id, 能提高些效率
struct commands
{
    char command[20];
    token_ireps tok;
} com_table[] =
{
    "if", IF,
    "else", ELSE,
    "for", FOR,
    "do", DO,
    "while", WHILE,
    "bool", BOOL,
    "char", CHAR,
    "short", SHORT,
    "int", INT,
    "long", LONG,
    "float", FLOAT,
    "double", DOUBLE,
    "return", RETURN,
    "switch", SWITCH,
    "break", BREAK,
    "case", CASE,
    "cout", COUT,
    "cin", CIN,
    "endl", ENDL,
    "default", DEFAULT,
    "continue", CONTINUE,
    "true", TRUE,
    "false", FALSE,
    "", END  // mark end of table
};

//eval_exp不根据之前读到的信息来操作, 是在eval_exp函数里面, 读到什么就调用相应的处理过程.
// Entry point into parser.
void eval_exp(anonymous_var &value)
{
    get_token();

    if(!*token)
    {
        throw InterpExc(NO_EXP);
    }

    //对于空语句给予一个默认的设置.
    if(*token == ';')
    {
        value.var_type = BOOL; // empty expression
        value.int_value = false;
        return;
    }

    eval_exp0(value);


    //这里会把处理完之后读出来的token再返回去.
    putback(); // return last token read to input stream
}


// Process an assignment expression.
void eval_exp0(anonymous_var &value)
{
    // temp holds name of var receiving the assignment.
    char temp[MAX_ID_LEN + 1];

    tok_types temp_tok;

    if(token_type == IDENTIFIER)
    {
        if(is_var(token))   // if a var, see if assignment
        {
            strcpy(temp, token);
            temp_tok = token_type;
            get_token();
            if(*token == '=')   // is an assignment
            {
                get_token();
                eval_exp0(value); // get value to assign

                assign_var(temp, value); // assign the value

                return;
            }
            else   // not an assignment
            {
                putback(); // restore original token
                strcpy(token, temp);
                token_type = temp_tok;
            }
        }
    }
    eval_exp1(value);
}

// Process relational operators.
void eval_exp1(anonymous_var &value)
{
    anonymous_var partial_value;
    char op;
    char relops[] =
    {
        LT, LE, GT, GE, EQ, NE, 0
    };

    eval_exp2(value);

    op = *token;
    if(strchr(relops, op))
    {
        get_token();
        eval_exp2(partial_value);

        switch(op)   // perform the relational operation
        {
        case LT:
        {
            int res = cmp(value, partial_value);
            value.var_type = BOOL;
            value.int_value = res < 0;
            break;
        }
        case LE:
        {
            int res = cmp(value, partial_value);
            value.var_type = BOOL;
            value.int_value = res <= 0;
            break;
        }
        case GT:
        {
            int res = cmp(value, partial_value);
            value.var_type = BOOL;
            value.int_value = res > 0;
            break;
        }
        case GE:
        {
            int res = cmp(value, partial_value);
            value.var_type = BOOL;
            value.int_value = res >= 0;
            break;
        }
        case EQ:
        {
            int res = cmp(value, partial_value);

            value.var_type = BOOL;
            value.int_value = (res == 0);
            break;
        }
        case NE:
        {
            int res = cmp(value, partial_value);
            value.var_type = BOOL;
            value.int_value = !(res == 0);
            break;
        }
        }
    }
}

// Add or subtract two terms.
void eval_exp2(anonymous_var &value)
{
    char  op;
    anonymous_var partial_value;
    char okops[] =
    {
        '(', INC, DEC, '-', '+', 0
    };

    eval_exp3(value);

    while((op = *token) == '+' || op == '-')
    {
        get_token();

        if(token_type == DELIMITER &&
                !strchr(okops, *token))
            throw InterpExc(SYNTAX);

        eval_exp3(partial_value);



        switch(op)   // add or subtract
        {
        case '-':
        {
            value = sub(value, partial_value);
            break;
        }
        case '+':
        {
            value = add(value, partial_value);
            break;
        }
        }
    }
}

// Multiply or divide two factors.
void eval_exp3(anonymous_var &value)
{
    char  op;
    anonymous_var partial_value;
    char okops[] =
    {
        '(', INC, DEC, '-', '+', 0
    };

    eval_exp4(value);

    while((op = *token) == '*' || op == '/'
            || op == '%')
    {
        get_token();

        if(token_type == DELIMITER &&
                !strchr(okops, *token))
            throw InterpExc(SYNTAX);

        eval_exp4(partial_value);

        switch(op)   // mul, div, or modulus
        {
        case '*':
        {
            value = mul(value, partial_value);
            break;
        }

        case '/':
        {
            //判断除零异常在程序里面做了
            value = div(value, partial_value);
            break;
        }
        case '%':
        {
            anonymous_var tmp = div(value, partial_value);
            tmp = mul(partial_value, tmp);
            value = sub(value, tmp);
            break;
        }
        }
    }
}

// Is a unary +, -, ++, or --.
void eval_exp4(anonymous_var &value)
{
    char  op;
    char temp;

    op = '\0';
    if(*token == '+' || *token == '-' ||
            *token == INC || *token == DEC)
    {
        temp = *token;
        op = *token;
        get_token();
        value = find_var(token);
        //处理前缀++, --要把变化反应到变量身上.
        if(temp == INC)
        {
            anonymous_var tmp_var;
            tmp_var.int_value = 1;
            tmp_var.var_type = value.var_type;
            value = add(value, tmp_var);
            assign_var(token, value);
            get_token();
            return;
        }
        if(temp == DEC)
        {
            anonymous_var tmp_var;
            tmp_var.int_value = 1;
            tmp_var.var_type = value.var_type;
            value = add(value, tmp_var);
            assign_var(token, value);
            get_token();
            return;
        }
    }

    eval_exp5(value);
    if(op == '-')
    {
        neg_var(value);
    }
}

// Process parenthesized expression.
void eval_exp5(anonymous_var &value)
{
    if((*token == '('))
    {
        get_token();

        eval_exp0(value); // get subexpression

        if(*token != ')')
            throw InterpExc(PAREN_EXPECTED);
        get_token();
    }
    else
        atom(value);
}

// Find value of number, variable, or function.
//增加一个处理功能, 处理浮点数, 但目前只允许***.***的形式, 不允许科学技术法.
void atom(anonymous_var &value)
{
    int i;
    char temp[MAX_ID_LEN + 1];

    switch(token_type)
    {
    case IDENTIFIER:
        i = internal_func(token);
        if(i != -1)
        {
            // Call "standard library" function.
            value = ((*intern_func[i].p)());
        }
        else if(find_func(token))
        {
            // Call programmer-created function.
            call();
            value = ret_value;//目前函数还只支持int返回值
        }
        else
        {

            //在这里处理了后缀++, --
            value = find_var(token); // get var's value
            strcpy(temp, token); // save variable name

            // Check for ++ or --.
            get_token();
            if(*token == INC || *token == DEC)
            {
                anonymous_var tmp_val = find_var(temp);
                value = tmp_val;
                if(*token == INC)
                {
                    anonymous_var one;
                    one.int_value = 1;
                    one.var_type = tmp_val.var_type;
                    tmp_val = add(tmp_val, one);
                    assign_var(temp, tmp_val);
                }
                else
                {
                    anonymous_var one;
                    one.int_value = 1;
                    one.var_type = tmp_val.var_type;
                    tmp_val = sub(tmp_val, one);
                    assign_var(temp, tmp_val);
                }

            }
            else putback();
        }

        get_token();
        return;
    case NUMBER: // is numeric constant
        //这里对浮点和整型类型做个判断
        if(strchr(token, '.'))
        {

            value.var_type = DOUBLE;
            value.float_value = atof(token);
        }
        else
        {
            value.var_type = INT;
            value.int_value = atoi(token);
        }
        get_token();

        return;

        //char constant
    case DELIMITER: // see if character constant
        if(*token == '\'')
        {
            value.var_type = CHAR;
            value.int_value = *prog;
            prog++;
            if(*prog != '\'')
                throw InterpExc(QUOTE_EXPECTED);

            prog++;
            get_token();

            return ;
        }
        if(*token == ')') return; // process empty expression
        else throw InterpExc(SYNTAX);  // otherwise, syntax error
    case KEYWORD:
    {
        if(0 == strcmp(token, "true"))
        {
            //cout << "jackieddddd" << endl;
            value.var_type = BOOL;
            value.int_value = 1;
        }
        else if(0 == strcmp(token, "false"))
        {
            value.var_type = BOOL;
            value.int_value = 0;
        }
        else
        {
            throw InterpExc(SYNTAX);
        }
        get_token();
        break;
    }
    default:
        throw InterpExc(SYNTAX); // syntax error
    }
}

// Display an error message.
void sntx_err(error_msg error)
{
    char *p, *temp;
    int linecount = 0;

    static char *e[] = //这里的显示信息, 是跟头文件里面定义的错误flag顺序一致的
    {
        "Syntax error",
        "No expression present",
        "Not a variable",
        "Duplicate variable name",
        "Duplicate function name",
        "Semicolon expected",
        "Unbalanced braces",
        "Function undefined",
        "Type specifier expected",
        "Return without call",
        "Parentheses expected",
        "While expected",
        "Closing quote expected",
        "Division by zero",
        "{ expected (control statements must use blocks)",
        "Colon expected",
        "Unsupported type yet",
    };

    // Display error and line number.
    cout << "\n" << e[error];
    p = p_buf;
    while(p != prog)   // find line number of error
    {
        p++;
        if(*p == '\r')
        {
            linecount++;
        }
    }
    cout << " in line " << linecount << endl;

    temp = p;
    while(p > p_buf && *p != '\n') p--;

    // Display offending line.
    while(p <= temp)
        cout << *p++;

    cout << endl;
}

// Get a token.
tok_types get_token()
{
    char *temp;

    token_type = UNDEFTT;
    tok = UNDEFTOK;

    temp = token;
    *temp = '\0';

    // Skip over white space.
    while(isspace(*prog) && *prog) ++prog;

    // Skip over newline.
    while(*prog == '\r')
    {
        ++prog;
        ++prog;
        // Again, skip over white space.
        while(*prog && isspace(*prog)) ++prog;
    }

    // Check for end of program.
    if(*prog == '\0')
    {
        *token = '\0';
        tok = END;
        return (token_type = DELIMITER);
    }

    // Check for block delimiters.
    if(strchr("{}", *prog))
    {
        *temp = *prog;
        temp++;
        *temp = '\0';
        prog++;
        return (token_type = BLOCK);
    }

    // Look for comments.
    if(*prog == '/')
        if(*(prog + 1) == '*') // is a /* comment
        {
            prog += 2;

            //这个循环很给力
            do   // find end of comment
            {
                while(*prog != '*') prog++;
                prog++;
            }
            while (*prog != '/');
            prog++;
            return (token_type = DELIMITER);
        }
        else if(*(prog + 1) == '/')   // is a // comment
        {
            prog += 2;
            // Find end of comment.
            while(*prog != '\r' && *prog != '\0') prog++;
            if(*prog == '\r') prog += 2;
            return (token_type = DELIMITER);
        }

    // Check for double-ops.
    if(strchr("!<>=+-", *prog))
    {
        switch(*prog)
        {
        case '=':
            if(*(prog + 1) == '=')
            {
                prog++;
                prog++;
                *temp = EQ;
                temp++;
                *temp = EQ;
                temp++;
                *temp = '\0';
            }
            break;
        case '!':
            if(*(prog + 1) == '=')
            {
                prog++;
                prog++;
                *temp = NE;
                temp++;
                *temp = NE;
                temp++;
                *temp = '\0';
            }
            break;
        case '<':
            if(*(prog + 1) == '=')
            {
                prog++;
                prog++;
                *temp = LE;
                temp++;
                *temp = LE;
            }
            else if(*(prog + 1) == '<')
            {
                prog++;
                prog++;
                *temp = LS;
                temp++;
                *temp = LS;
            }
            else
            {
                prog++;
                *temp = LT;
            }
            temp++;
            *temp = '\0';
            break;
        case '>':
            if(*(prog + 1) == '=')
            {
                prog++;
                prog++;
                *temp = GE;
                temp++;
                *temp = GE;
            }
            else if(*(prog + 1) == '>')
            {
                prog++;
                prog++;
                *temp = RS;
                temp++;
                *temp = RS;
            }
            else
            {
                prog++;
                *temp = GT;
            }
            temp++;
            *temp = '\0';
            break;
        case '+':
            if(*(prog + 1) == '+')
            {
                prog++;
                prog++;
                *temp = INC;
                temp++;
                *temp = INC;
                temp++;
                *temp = '\0';
            }
            break;
        case '-':
            if(*(prog + 1) == '-')
            {
                prog++;
                prog++;
                *temp = DEC;
                temp++;
                *temp = DEC;
                temp++;
                *temp = '\0';
            }
            break;
        }

        if(*token) return(token_type = DELIMITER);
    }

    // Check for other delimiters.
    if(strchr("+-*^/%=;:(),'", *prog))
    {
        *temp = *prog;
        prog++;
        temp++;
        *temp = '\0';
        return (token_type = DELIMITER);
    }

    // Read a quoted string.
    if(*prog == '"')
    {
        prog++;
        while(*prog != '"' && *prog != '\r' && *prog)
        {
            // Check for \n escape sequence.
            if(*prog == '\\')
            {
                if(*(prog + 1) == 'n')
                {
                    prog++;
                    *temp++ = '\n';
                }
            }
            else if((temp - token) < MAX_T_LEN)
                *temp++ = *prog;

            prog++;
        }
        if(*prog == '\r' || *prog == 0)
            throw InterpExc(SYNTAX);
        prog++;
        *temp = '\0';
        return (token_type = STRING);
    }

    // Read an integer number, or float
    //由于现在还没加入结构体和类, 所以直接这样判断'.'还是可以的, 不过会有隐患, 要记得~
    if(isdigit(*prog) || *prog == '.')
    {
        while(!isdelim(*prog)) //这样判断安全吗?
        {
            if((temp - token) < MAX_ID_LEN)
                *temp++ = *prog;
            prog++;
        }
        *temp = '\0';
        return (token_type = NUMBER);
    }

    // Read identifier or keyword.
    if(isalpha(*prog))
    {
        while(!isdelim(*prog))
        {
            if((temp - token) < MAX_ID_LEN)
                *temp++ = *prog;
            prog++;
        }
        token_type = TEMP;
    }

    *temp = '\0';

    // Determine if token is a keyword or identifier.
    if(token_type == TEMP)
    {
        tok = look_up(token); // convert to internal form
        if(tok) token_type = KEYWORD; // is a keyword
        else token_type = IDENTIFIER;
    }

    // Check for unidentified character in file.
    if(token_type == UNDEFTT)
        throw InterpExc(SYNTAX);

    return token_type;
}

// Return a token to input stream.
void putback()
{
    char *t;

    t = token;
    for(; *t; t++) prog--;
}

// Look up a token's internal representation in the
// token table.
token_ireps look_up(char *s)
{
    int i;

    //C++本来就区分大小写的, 为什么还给程序转化..
    //char *p;

    //// Convert to lowercase.
    //p = s;
    //while(*p)
    //{
    //    *p = tolower(*p);
    //    p++;
    //}

    // See if token is in table.
    for(i = 0; *com_table[i].command; i++)
    {
        if(!strcmp(com_table[i].command, s))
            return com_table[i].tok;
    }

    return UNDEFTOK; // unknown command
}

// Return index of internal library function or -1 if
// not found.
int internal_func(char *s)
{
    int i;

    for(i = 0; intern_func[i].f_name[0]; i++)
    {
        if(!strcmp(intern_func[i].f_name, s))  return i;
    }
    return -1;
}

// Return true if c is a delimiter.
bool isdelim(char c)
{
    if(strchr(" !:;,+-<>'/*%^=()", c) || c == 9 ||
            c == '\r' || c == 0) return true;
    return false;
}




/***********************************************************************
   minicpp.cpp 主函数在这里, 对于for, if while switch等的实现也写在了这里.
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <new>
#include <stack>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "mccommon.h"

using namespace std;

char *prog;  // current execution point in source code
char *p_buf; // points to start of program buffer

// This vector holds info for global variables.
vector<var> global_vars;

// This vector holds info for local variables
// and parameters.
vector<var> local_var_stack;

// This vector holds info about functions.
vector<func_type> func_table;

// Stack for managing function scope.

stack<int> func_call_stack;

// Stack for managing nested scopes.
//整形的栈, 存储的是本函数压栈之前栈的大小.
stack<int> nest_scope_stack;

char token[MAX_T_LEN + 1]; // current token
tok_types token_type; // token type
token_ireps tok; // internal representation

anonymous_var ret_value; // function return value

bool breakfound = false; // true if break encountered
bool continuefound = false;




int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Usage: minicpp <filename>\n";
        return 1;
    }

    // Allocate memory for the program.
    try
    {
        p_buf = new char[PROG_SIZE];
    }
    catch (bad_alloc exc)
    {
        cout << "Could Not Allocate Program Buffer\n";
        return 1;
    }

    // Load the program to execute.
    if(!load_program(p_buf, argv[1])) return 1;

    // Set program pointer to start of program buffer.
    prog = p_buf;

    try
    {
        // Find the location of all functions
        // and global variables in the program.
        prescan();

        // Next, set up the call to main().

        // Find program starting point.
        prog = find_func("main");

        // Check for incorrect or missing main() function.
        if(!prog)
        {
            cout << "main() Not Found\n";
            return 1;
        }

        // Back up to opening (.
        prog--;

        // Set the first token to main
        strcpy(token, "main");

        // Call main() to start interpreting.
        call();
    }
    catch(InterpExc exc)
    {
        sntx_err(exc.get_err());
        return 1;
    }
    catch(bad_alloc exc)
    {
        cout << "Out Of Memory\n";
        return 1;
    }

    return ret_value.int_value;
}

// Load a program.
bool load_program(char *p, char *fname)
{
    int i = 0;

    ifstream in(fname, ios::in | ios::binary);
    if(!in)
    {
        cout << "Cannot Open file.\n";
        return false;
    }

    do
    {
        *p = in.get();
        p++;
        i++;
    }
    while(!in.eof() && i < PROG_SIZE);

    if(i == PROG_SIZE)
    {
        cout << "Program Too Big\n";
        return false;
    }

    // Null terminate the program. Skip any EOF
    // mark if present in the file.
    if(*(p - 2) == 0x1a) *(p - 2) = '\0';
    else *(p - 1) = '\0';

    in.close();

    return true;
}

// Find the location of all functions in the program
// and store global variables.
void prescan()
{
    char *p, *tp;
    char temp[MAX_ID_LEN + 1];
    token_ireps datatype;
    func_type ft;

    // When brace is 0, the current source position
    // is outside of any function.
    int brace = 0;

    p = prog;

    do
    {
        // Bypass code inside functions, brace==0, 保证了现在是在全局作用域
        while(brace)
        {
            get_token();
            if(tok == END) throw InterpExc(UNBAL_BRACES);
            if(*token == '{') brace++;
            if(*token == '}') brace--;
        }

        tp = prog; // save current position
        get_token();

        // See if global var type or function return type.
        if(is_valid_type(tok))
        {
            datatype = tok; // save data type
            get_token();

            if(token_type == IDENTIFIER)
            {
                strcpy(temp, token);
                get_token();

                if(*token != '(')   // must be global var
                {
                    prog = tp; // return to start of declaration
                    decl_global();
                }
                else if(*token == '(')   // must be a function
                {

                    // See if function already defined.
                    for(unsigned i = 0; i < func_table.size(); i++)
                        if(!strcmp(func_table[i].func_name, temp))
                            throw InterpExc(DUP_FUNC);

                    ft.loc = prog;
                    ft.ret_type = datatype;
                    strcpy(ft.func_name, temp);
                    func_table.push_back(ft);

                    do
                    {
                        get_token();
                    }
                    while(*token != ')');
                    // Next token will now be opening curly
                    // brace of function.
                }
                else putback();
            }
        }
        else
        {
            if(*token == '{') brace++;
            if(*token == '}') brace--;
        }
    }
    while(tok != END);
    if(brace) throw InterpExc(UNBAL_BRACES);
    prog = p;
}

// Interpret a single statement or block of code. When
// interp() returns from its initial call, the final
// brace (or a return) in main() has been encountered.

//对于interp我做了一个小改动, 如果执行语句里面有break, 那么就在推出interp之前让程序把整个block的代码都走一遍, 但是不执行了
//这样, 以后调用interp的程序就不用再为break后面的语句做清理工作了.
//在interp里面, 遇到{}会产生一个新的名字空间, 遇到int 和char还会declare一个local变量
void interp()
{
    anonymous_var value;
    int block = 0;
    char *tmp_prog = NULL;
    //break语句会对外面的控制流程造成影响, 但是continue不会, 它只会不让本次循环后面的语句不执行.
    //但是还是要维护一个全局的continue, 因为本block需要知道子block里面是不是有continue;
    do
    {
        if(breakfound || continuefound)
        {

            //如果这是个{}包含的块, 那么就用find_eob把整个块吃掉
            if(block && tmp_prog)
            {

                prog = tmp_prog;
                find_eob();
            }
            else
            {
                //对于知识一条语句的块, 在break跳出之前吃掉这个分号
                get_token();

            }
            return;
        }

        token_type = get_token();
        //对于那些exec_while, exec_while那个向前看的token是在这里读出来的
        //跟eval_exp没有关系.

        // See what kind of token is up.
        if(token_type == IDENTIFIER ||
                *token == INC || *token == DEC)
        {
            // Not a keyword, so process expression.
            putback();  // restore token to input stream for
            // further processing by eval_exp()
            eval_exp(value); // process the expression
            //eval_exp和exec_while是相同的层次, 在interp看到向前看字符的时候, 就会递归调用相应的过程.
            if(*token != ';') throw InterpExc(SEMI_EXPECTED);
        }
        else if(token_type == BLOCK) // block delimiter?
        {
            if(*token == '{')   // is a block
            {
                putback();
                tmp_prog = prog;
                get_token();
                block = 1; // interpreting block, not statement
                // Record nested scope.
                nest_scope_stack.push(local_var_stack.size());
                //nest_scope_stack里面存的是上一个block的stack的位置,
                //用户恢复栈.
            }
            else   // is a }, so reset scope and return
            {
                // Reset nested scope.
                local_var_stack.resize(nest_scope_stack.top());
                nest_scope_stack.pop();
                return;
            }
        }
        else if(is_valid_type(tok))
        {
            putback();
            decl_local();
        }
        else // is keyword
            switch(tok)
            {
            case RETURN:  // return from function call, 不要在这里清理局部作用域了, call里面做了处理.
                /*if(block)
                                  {
                				                       local_var_stack.resize(nest_scope_stack.top());
                									                        nest_scope_stack.pop();
                															                 }*/
                func_ret();
                return;
            case IF:      // process an if statement
                exec_if();
                break;
            case ELSE:    // process an else statement
                find_eob(); // find end of else block
                // and continue execution
                break;
            case WHILE:   // process a while loop
                exec_while();
                break;
            case DO:      // process a do-while loop
                exec_do();
                break;
            case FOR:     // process a for loop
                exec_for();

                break;
            case BREAK:   // handle break
                breakfound = true;
                // Reset nested scope.
                //这里要特判一下是不是从一个block里面的break, 因为在我修改之后, for while的循环体现在可以是
                //一个单个的语句了
                if(block)
                {
                    local_var_stack.resize(nest_scope_stack.top());
                    nest_scope_stack.pop();
                }
                break;
            case CONTINUE:
            {
                continuefound = true;
                if(block)
                {
                    local_var_stack.resize(nest_scope_stack.top());
                    nest_scope_stack.pop();
                }
                break;
            }
            case SWITCH:  // handle a switch statement
                exec_switch();
                break;
            case COUT:    // handle console output
                exec_cout();
                //cout << "breakfuond :" << breakfound << endl;
                break;
            case CIN:     // handle console input
                exec_cin();
                break;
            case END:
                exit(0);

            }
    }
    while (tok != END && block);
    return;
}


//可以使用map优化.
// Return the entry point of the specified function.
// Return NULL if not found.
char *find_func(char *name)
{
    unsigned i;

    for(i = 0; i < func_table.size(); i++)
        if(!strcmp(name, func_table[i].func_name))
            return func_table[i].loc;

    return NULL;
}

// Declare a global variable.
void decl_global()
{
    token_ireps vartype;
    var v;

    get_token(); // get type

    vartype = tok; // save var type

    anonymous_var value;

    // Process comma-separated list.
    do
    {
        v.value.var_type = vartype;
        init_var(v.value); // init to 0
        get_token(); // get name

        // See if variable is a duplicate.
        for(unsigned i = 0; i < global_vars.size(); i++)
            if(!strcmp(global_vars[i].var_name, token))
                throw InterpExc(DUP_VAR);

        strcpy(v.var_name, token);
        global_vars.push_back(v);

        putback();
        eval_exp(value); //这个eval_exp会实现赋值, 这里value只是个哑元, 我们不用

        get_token();

    }
    while(*token == ',');

    if(*token != ';') throw InterpExc(SEMI_EXPECTED);
}

// Declare a local variable.
void decl_local()
{
    var v;

    get_token(); // get var type
    v.value.var_type = tok; // store type

    init_var(v.value); // init var to 0, 对局部变量也直接初始化成0了..
    anonymous_var value;

    // Process comma-separated list.
    do
    {
        get_token(); // get var name

        // See if variable is already the name
        // of a local variable in this scope.
        if(!local_var_stack.empty())
            for(int i = local_var_stack.size() - 1;
                    i >= nest_scope_stack.top(); i--)
            {
                if(!strcmp(local_var_stack[i].var_name, token))
                    throw InterpExc(DUP_VAR);
            }

        strcpy(v.var_name, token);
        local_var_stack.push_back(v);
        putback();
        eval_exp(value);//这个eval_exp会实现赋值, 这里value只是个哑元, 我们不用
        get_token();
    }
    while(*token == ',');

    if(*token != ';') throw InterpExc(SEMI_EXPECTED);
}

// Call a function.
void call()
{
    char *loc, *temp;
    int lvartemp;

    // First, find entry point of function.
    loc = find_func(token);

    if(loc == NULL)
        throw InterpExc(FUNC_UNDEF); // function not defined
    else
    {
        // Save local var stack index.
        lvartemp = local_var_stack.size();

        //get_args 和get_params先后调用 , 进行了一下替换
        get_args(); // get function arguments
        temp = prog; // save return location

        func_call_stack.push(lvartemp); // push local var index

        prog = loc; // reset prog to start of function
        get_params(); // load the function's parameters with
        // the values of the arguments

        interp(); // interpret the function

        prog = temp; // reset the program pointer

        if(func_call_stack.empty()) throw InterpExc(RET_NOCALL);

        // Reset local_var_stack to its previous state.

        //这里的resize会把后面的刚刚压入栈的变量删掉.
        local_var_stack.resize(func_call_stack.top());
        func_call_stack.pop();
    }
}

// Push the arguments to a function onto the local
// variable stack.
void get_args()
{
    anonymous_var value, temp[NUM_PARAMS];
    int count = 0;
    var vt;

    count = 0;
    get_token();
    if(*token != '(') throw InterpExc(PAREN_EXPECTED);

    // Process a comma-separated list of values.
    do
    {
        eval_exp(value);
        temp[count] = value; // save temporarily
        get_token();
        count++;
    }
    while(*token == ',');
    count--;

    // Now, push on local_var_stack in reverse order.
    for(; count >= 0; count--)
    {
        vt.value = temp[count];
        local_var_stack.push_back(vt);
    }
}

// Get function parameters.

//在这个函数里面实现了从实参到形参的转化工作, 不错.
void get_params()
{
    var *p;
    int i;

    i = local_var_stack.size() - 1;

    // Process comma-separated list of parameters.
    do
    {
        get_token();
        p = &local_var_stack[i];
        if(*token != ')' )
        {
            if(is_valid_type(tok))
                throw InterpExc(TYPE_EXPECTED);

            p->value.var_type = tok;
            get_token();

            // Link parameter name with argument already on
            // local var stack.
            strcpy(p->var_name, token);
            get_token();
            i--;
        }
        else break;
    }
    while(*token == ',');

    //在这里判了一下, 看最后一个读到的是不是')'
    if(*token != ')') throw InterpExc(PAREN_EXPECTED);
}

// Return from a function.
void func_ret()
{
    anonymous_var value;

    //value = 0;

    // Get return value, if any.
    //目前设定是只支持int返回值.
    eval_exp(value);

    ret_value = value;
}

// Assign a value to a variable.
void assign_var(char *vname, anonymous_var value)
{
    //cout << "assign_var" << endl;
    // First, see if it's a local variable.
    if(!local_var_stack.empty())
        for(int i = local_var_stack.size() - 1;
                i >= func_call_stack.top(); i--)
        {
            if(!strcmp(local_var_stack[i].var_name,
                       vname))
            {
                adaptive_assign_var(local_var_stack[i].value, value);
                return;
            }
        }

    // Otherwise, try global vars.
    for(unsigned i = 0; i < global_vars.size(); i++)
        if(!strcmp(global_vars[i].var_name, vname))
        {
            adaptive_assign_var(global_vars[i].value, value);
            //cout << value.float_value << " >>>" << endl;
            return;
        }

    throw InterpExc(NOT_VAR); // variable not found
}

// Find the value of a variable.
anonymous_var find_var(char *vname)
{
    // First, see if it's a local variable.
    if(!local_var_stack.empty())
        for(int i = local_var_stack.size() - 1;
                i >= func_call_stack.top(); i--)
        {
            if(!strcmp(local_var_stack[i].var_name, vname))
                return local_var_stack[i].value;
        }

    // Otherwise, try global vars.
    for(unsigned i = 0; i < global_vars.size(); i++)
        if(!strcmp(global_vars[i].var_name, vname))
            return global_vars[i].value;

    throw InterpExc(NOT_VAR); // variable not found
}


//在处理if的时候也处理了else的模块
// Execute an if statement.
void exec_if()
{
    anonymous_var cond;

    eval_exp(cond); // get if expression.

    if(get_bool_val(cond))   // if true, process target of IF
    {
        // Confirm start of block.

        interp();
    }
    else
    {
        // Otherwise skip around IF block and
        // process the ELSE, if present.

        find_eob(); // find start of next line
        get_token();

        if(tok != ELSE)
        {
            // Restore token if no ELSE is present.
            putback();
            return;
        }
        // Confirm start of block.
        get_token();

        if(tok == IF)
        {
            exec_if();
            return;
        }
        putback();
        interp();
    }
}

// Execute a switch statement.
void exec_switch()
{
    anonymous_var sval, cval;
    int brace;

    eval_exp(sval); // Get switch expression.

    // Check for start of block.
    if(*token != '{')
        throw InterpExc(BRACE_EXPECTED);

    // Record new scope.
    nest_scope_stack.push(local_var_stack.size());

    // Now, check case statements.
    for(;;)
    {
        brace = 1;
        // Find a case statement.
        do
        {
            get_token();
            if(*token == '{') brace++;
            else if(*token == '}') brace--;
        }
        while(tok != CASE && tok != END && brace && tok != DEFAULT);

        // If no matching case found, then skip.
        if(!brace) break;


        if(tok == END) throw InterpExc(SYNTAX);
        if(tok == DEFAULT)
        {
            get_token();
            if(*token != ':')
                throw InterpExc(COLON_EXPECTED);
            do
            {
                interp();
                get_token();
                if(*token == '}')
                {
                    putback();
                    break;
                }
                putback();
                //if(*token == '{') brace++;
                //else if(*token == '}') brace--;
            }
            while(!breakfound && tok != END);

            brace = 1;

            // Find end of switch statement.
            while(brace)
            {
                get_token();
                if(*token == '{') brace++;
                else if(*token == '}') brace--;
            }
            breakfound = false;

            break;

        }

        // Get value of the case statement.
        eval_exp(cval);

        // Read and discard the :
        get_token();

        if(*token != ':')
            throw InterpExc(COLON_EXPECTED);

        // If values match, then interpret.
        if(0 == cmp(cval, sval))
        {

            do
            {
                interp();

                get_token();
                if(*token == '}')
                {
                    putback();
                    break;
                }
                putback();
            }
            while(!breakfound && tok != END && brace);

            brace = 1;

            // Find end of switch statement.
            while(brace)
            {
                get_token();
                if(*token == '{') brace++;
                else if(*token == '}') brace--;
            }
            breakfound = false;

            break;
        }
    }
}

// Execute a while loop.
//同下面的do while, 这个也会putback while
void exec_while()
{
    anonymous_var cond;
    char *temp;

    putback(); // put back the while
    temp = prog; // save location of top of while loop

    get_token();
    eval_exp(cond); // check the conditional expression

    if(get_bool_val(cond))
        interp(); // if true, interpret
    else   // otherwise, skip to end of loop
    {
        find_eob();
        return;
    }
    continuefound = false;
    if(!breakfound)
        prog = temp; // loop back to top
    else
    {
        breakfound = false;
        return;
    }
}

// Execute a do loop.

//解释: exec_do是在主函数读到了do的时候才会调用, 因此
//在exec_do调用的时候, do这个token已经被读出来了,
//而exec_do还想要在需要继续执行的时候是prog复位到do, 那么就得在程序开始putback一下.
void exec_do()
{
    anonymous_var cond;
    char *temp;

    // Save location of top of do loop.
    putback(); // put back do
    temp = prog;

    get_token(); // get start of loop block

    // Confirm start of block.
    get_token();
    if(*token != '{')
        throw InterpExc(BRACE_EXPECTED);
    putback();

    interp(); // interpret loop

    // Check for break in loop.
    if(breakfound)
    {
        breakfound = false;
        get_token();
        if(tok != WHILE) throw InterpExc(WHILE_EXPECTED);
        eval_exp(cond); // check the loop condition
        return;
    }
    if(continuefound)
    {
        continuefound = false;
        prog = temp;
        return;
    }

    get_token();
    if(tok != WHILE) throw InterpExc(WHILE_EXPECTED);

    eval_exp(cond); // check the loop condition

    // If true loop; otherwise, continue on.

    if(get_bool_val(cond)) prog = temp;
}

// Execute a for loop.
//但是for就不能像while和do while那样, 在需要继续循环的时候复位prog指针了, 因为for
//复位的话, 初始点也跟着复位了, 就是for(int i= 0; i< 12; i++)里面的i也会变成0
void exec_for()
{
    anonymous_var cond;
    char *temp, *temp2;
    int paren ;

    //for_local用来标记是不是在for()内部定义了新变量, 如果是, 就会产生新的作用域
    bool for_local = false;

    get_token(); // skip opening (
    get_token();

    if(is_valid_type(tok))//当前读入的token是个类型关键字, 这样就会触发一个局部作用域
    {
        putback();
        nest_scope_stack.push(local_var_stack.size());
        for_local = true;
        decl_local();

    }
    else
    {
        eval_exp(cond); // initialization expression
    }

    //这个是decl_local和eval_exp最后读到的token, 已经被读出来了
    if(*token != ';') throw InterpExc(SEMI_EXPECTED);

    prog++; // get past the ;
    temp = prog;

    for(;;)
    {
        // Get the value of the conditional expression.
        eval_exp(cond);

        if(*token != ';') throw InterpExc(SEMI_EXPECTED);
        prog++; // get past the ;
        temp2 = prog;

        // Find start of for block.
        paren = 1;
        while(paren)
        {
            get_token();
            if(*token == '(') paren++;
            if(*token == ')') paren--;
        }


        // If condition is true, interpret
        //现在从for()后面开始interpret
        //
        if(get_bool_val(cond))
        {
            //continue只对interp里面的执行起作用, 不会对外面有影响.
            interp();
            //cout << prog << endl;

        }
        else   // otherwise, skip to end of loop
        {
            find_eob();
            if(for_local)
            {
                local_var_stack.resize(nest_scope_stack.top());
                nest_scope_stack.pop();
            }
            return;
        }
        if(breakfound)
        {
            breakfound = false;
            if(for_local)
            {
                local_var_stack.resize(nest_scope_stack.top());
                nest_scope_stack.pop();
            }
            return;
        }
        if(continuefound)
        {
            continuefound = false;
        }


        prog = temp2; // go to increment expression

        // Check for break in loop.



        // Evaluate the increment expression.
        eval_exp(cond);

        prog = temp; // loop back to top
    }

}

// Execute a cout statement.
void exec_cout()
{
    anonymous_var val;

    get_token();
    if(*token != LS) throw InterpExc(SYNTAX);
    do
    {
        get_token();

        if(token_type == STRING)
        {
            // Output a string.
            cout << token;
        }
        else if(tok == ENDL)
        {
            cout << endl;
        }
        else
        {
            //cout << token << " :---" << endl;
            putback();
            eval_exp(val);
            //cout << val.float_value << "<<<" << endl;
            cout_var(val);
        }

        get_token();
    }
    while(*token == LS); //<<

    if(*token != ';') throw InterpExc(SEMI_EXPECTED);
}

// Execute a cin statement.
void exec_cin()
{
    token_ireps vtype;

    get_token();
    if(*token != RS) throw InterpExc(SYNTAX);

    do
    {
        get_token();
        if(token_type != IDENTIFIER)
            throw InterpExc(NOT_VAR);

        vtype = find_var_type(token);
        anonymous_var tmp;
        tmp.var_type = vtype;

        cin_var(tmp);
        assign_var(token, tmp);
        get_token();
    }
    while(*token == RS); //RS 是>>

    if(*token != ';') throw InterpExc(SEMI_EXPECTED);
}


// Find the end of a block.
//#这里find_eob在逻辑上做了一点修改, 由外部保证调用的正确
//如果开始的是{, 那么就处理一个block, 否则就调用find_eol处理一个;语句.
void find_eob()
{
    int brace;

    get_token();
    //cout << token <<  " find_eob" <<endl;
    if(*token != '{')
    {
        putback();
        find_eol();
        return ;
    }

    brace = 1;

    do
    {
        get_token();
        //cout << token <<  " find_eob" <<endl;
        if(*token == '{') brace++;
        else if(*token == '}') brace--;
    }
    while(brace && tok != END);

    if(tok == END) throw InterpExc(UNBAL_BRACES);
}

void find_eol()
{
    do
    {
        get_token();
    }
    while (*token != ';' && tok != END);

    if(tok == END) throw InterpExc(SYNTAX);
}

// Determine if an identifier is a variable. Return
// true if variable is found; false otherwise.
bool is_var(char *vname)
{
    // See if vname a local variable.
    if(!local_var_stack.empty())
        for(int i = local_var_stack.size() - 1;
                i >= func_call_stack.top(); i--)
        {
            if(!strcmp(local_var_stack[i].var_name, vname))
                return true;
        }

    // See if vname is a global variable.
    for(unsigned i = 0; i < global_vars.size(); i++)
        if(!strcmp(global_vars[i].var_name, vname))
            return true;

    return false;
}

// Return the type of variable.
token_ireps find_var_type(char *vname)
{
    // First, see if it's a local variable.
    if(!local_var_stack.empty())
        for(int i = local_var_stack.size() - 1;
                i >= func_call_stack.top(); i--)
        {
            if(!strcmp(local_var_stack[i].var_name, vname))
                return local_var_stack[i].value.var_type;
        }

    // Otherwise, try global vars.
    for(unsigned i = 0; i < global_vars.size(); i++)
        if(!strcmp(global_vars[i].var_name, vname))
            return local_var_stack[i].value.var_type;

    return UNDEFTOK;
}


/***********************************************************************
    libcpp.cpp, 主要是对库函数的封装
  ************************************************************************/

// Add more of your own, here.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "mccommon.h"

using namespace std;

// Read a character from the console.
// If your compiler supplies an unbuffered
// character intput function, feel free to
// substitute it for the call to cin.get().
anonymous_var call_getchar()
{
    char ch;

    ch = getchar();

    // Advance past ()
    get_token();
    if(*token != '(')
        throw InterpExc(PAREN_EXPECTED);

    get_token();
    if(*token != ')')
        throw InterpExc(PAREN_EXPECTED);
    anonymous_var val;
    val.var_type = CHAR;
    val.int_value = ch;
    return val;
}

// Write a character to the display.
anonymous_var call_putchar()
{
    anonymous_var value;

    eval_exp(value);

    putchar(char(value.int_value));

    return value;
}

// Return absolute value.
anonymous_var call_abs()
{
    anonymous_var val;

    eval_exp(val);
    abs_var(val);
    return val;
}

// Return a randome integer.
anonymous_var call_rand()
{

    // Advance past ()
    get_token();
    if(*token != '(')
        throw InterpExc(PAREN_EXPECTED);

    get_token();
    if(*token != ')')
        throw InterpExc(PAREN_EXPECTED);

    anonymous_var val;
    val.var_type = INT;
    val.int_value = rand();
    return val;
}
