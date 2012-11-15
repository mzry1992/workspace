#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

bool illegal;
char s[100005],s1[10],s2[10];
int cur = 0, n;

char next_char()
{
    for (;s[cur] == ' ' || s[cur] == '\t'; cur++);
    return cur < n ? s[cur] : EOF;
}

const string OP = "&|!";

int get_priority(char ch)
{
    return 1;
}

bool calc(bool a, char op, bool b)
{
    if (op == '|')  return a|b;
    if (op == '&')  return a&b;
}

bool P();

bool calc_exp(int p)
{
    bool a = P();
    while (OP.find(next_char()) != string::npos && get_priority(next_char()) >= p)
    {
        char op = next_char(); cur++;
        a = calc(a, op, calc_exp(get_priority(op) + 1));
    }
    return a;
}

bool P()
{
    if (next_char() == '!')
    {
        cur++;
        return !P();
    }
    else if (next_char() == '(')
    {
        cur++;
        bool r = calc_exp(0);
        if (next_char() == ')')
            cur++;
        return r;
    }
    else
    {
        if (next_char() == 't')
        {
            cur++;
            return true;
        }
        else
        {
            cur++;
            return false;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%s%s",s,s1,s2);
        n = strlen(s);
        cur = 0;
        illegal = false;
        bool res = calc_exp(0);
        bool tres = (s2[0] == 't')?true:false;
        if (res == tres)
            printf("%d: Good brain\n",ft);
        else
            printf("%d: Bad brain\n",ft);
    }
    return 0;
}
