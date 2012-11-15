#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

char s[100005];
int cur = 0, n;
int now;

char next_char()
{
    for (;s[cur] == ' ' || s[cur] == '\t'; cur++);
    return cur < n ? s[cur] : EOF;
}

const string OP = "+-*";

int get_priority(char ch)
{
    if (ch == '*') return 2;
    else return 1;
}

int calc(int a, int op, int b)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
}

int P();

int calc_exp(int p)
{
    int a = P();
    while (OP.find(next_char()) != string::npos && get_priority(next_char()) >= p)
    {
        char op = next_char(); cur++;
        a = calc(a, op, calc_exp(get_priority(op) + 1));
    }
    //cout << cur << ' ' << a << endl;
    return a;
}

int P()
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
        int r = calc_exp(0);
        if (next_char() == ')')
            cur++;
        return r;
    }
    else if (next_char() >= '0' && next_char() <= '9')
    {
        int x = 0;
        x = next_char()-'0';
        cur++;
        return x;
    }
    else
    {
        int x = next_char()+now;
        cur++;
        return x;
    }
}

int res[1020];

int main()
{
    int t;
    scanf("%d",&t);
    gets(s);
    for (int ft = 1;ft <= t;ft++)
    {
        gets(s);
        n = strlen(s);
        for (int i = 0;i <= 1000;i++)
        {
            cur = 0;
            now = i;
            res[i] = calc_exp(0);
        }
        gets(s);
        n = strlen(s);
        bool flag = true;
        for (int i = 0;i <= 1000;i++)
        {
            cur = 0;
            now = i;
            int tres = calc_exp(0);
            if (tres != res[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)  printf("NO\n");
        else    printf("YES\n");
    }
    return 0;
}
