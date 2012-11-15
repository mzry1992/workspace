#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const double eps = 1e-8;

int sgn(double x)
{
    if (x >= -eps && x <= eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}

bool illegal;
char s[100005];
int cur = 0, n;

char next_char()
{
    for (;s[cur] == ' ' || s[cur] == '\t'; cur++);
    return cur < n ? s[cur] : EOF;
}

const string OP = "+-*/^";

int get_priority(char ch)
{
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else return 1;
}

double calc(double a, char op, double b)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
    {
        if (sgn(b) == 0)
        {
            illegal = true;
            return 1.0;
        }
        else
        {
            return a / b;
        }
    }
    else if (op == '^')
    {
        return pow(a, b);
    }
    return 0;
}

double P();

double calc_exp(int p)
{
    double a = P();
    while (OP.find(next_char()) != string::npos && get_priority(next_char()) >= p)
    {
        char op = next_char(); cur++;
        a = calc(a, op, calc_exp(get_priority(op) + 1));
    }
    return a;
}

char tmp[1024];

double P()
{
    if (next_char() == '-')
    {
        cur++;
        return -P();
    }
    else if (next_char() == '+')
    {
        cur++;
        return P();
    }
    else if (next_char() == '(')
    {
        cur++;
        double r = calc_exp(0);
        if (next_char() == ')')
            cur++;
        return r;
    }
    else
    {
        int n = 0;
        while (next_char() >= '0' && next_char() <= '9' || next_char() == '.')
        {
            tmp[n++] = next_char();
            cur++;
        }
        tmp[n] = 0;
        double x;
        sscanf(tmp, "%lf", &x);
        return x;
    }
}

int main()
{
    while (gets(s))
    {
        n = strlen(s);
        cur = 0;

        illegal = false;
        double res = calc_exp(0);

        if (illegal)
        {
            printf("The teacher is so lazy!\n");
        }
        else
        {
            printf("%.8f\n", res);
        }

    }
    return 0;
}
