#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const char blank[10] = "&nbsp;";
const char su[2][10] = {"<sub>","<sup>"};
const char csu[2][10] = {"</sub>","</sup>"};

const int maxlen = 1000000;
char s[maxlen];
int len;

bool get_formula()
{
    for (int i = 0;i < len;i++)
        if (s[i] == '$')
        {
            len = 0;
            for (int j = i+1;s[j] != 0 && s[j] != '$';j++)
                s[len++] = s[j];
            s[len] = 0;
            return true;
        }
    return false;
}

int stack[maxlen];
int next[maxlen];

void get_next()
{
    int top = 0;
    for (int i = 0;i < len;i++)
        if (s[i] == '{')
            stack[top++] = i;
        else if (s[i] == '}')
            next[stack[--top]] = i;
}

bool is_letter(char a)
{
    if (a >= 'a' && a <= 'z')   return true;
    if (a >= 'A' && a <= 'Z')   return true;
    return false;
}

bool is_operator(char a)
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}

void parser(int l,int r)
{
    for (int i = l;i <= r;)
    {
        if (s[i] == ' ')
            i++;
        else if (is_letter(s[i]))
        {
            printf("<i>");
            for (;is_letter(s[i]) || s[i] == ' ';i++)
                if (is_letter(s[i]))
                    printf("%c",s[i]);
            printf("</i>");
        }
        else if (is_operator(s[i]))
            printf("%s%c%s",blank,s[i++],blank);
        else if (s[i] == '_' || s[i] == '^')
        {
            int typ = 0;
            if (s[i] == '_')
                typ = 0;
            else
                typ = 1;
            printf("%s",su[typ]);
            if (s[i+1] == '{')
            {
                parser(i+2,next[i+1]-1);
                i = next[i+1]+1;
            }
            else
            {
                parser(i+1,i+1);
                i = i+2;
            }
            printf("%s",csu[typ]);
        }
        else
            printf("%c",s[i++]);
    }
}

int main()
{
    int cas = 0;
    while (gets(s))
    {
        len = strlen(s);
        if (get_formula())
        {
            cas++;
            get_next();
            parser(0,len-1);
            puts("");
        }
    }
	return 0;
}
