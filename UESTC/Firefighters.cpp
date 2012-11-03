#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

bool illegal;
char s[100005];
int cur, n;

char next_char()
{
    for (;s[cur] == ' ' || s[cur] == '\t'; cur++);
    return cur < n ? s[cur] : EOF;
}

const string OP = "+-*/";

int get_priority(char ch)
{
    if (ch == '*' || ch == '/') return 2;
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
    else if (op == '/')
    {
        if (b == 0)
        {
            illegal = true;
            return 1;
        }
        else
        {
            return a / b;
        }
    }
    return 0;
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
    return a;
}

char tmp[1024];

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
    else
    {
        int n = 0;
        while (next_char() >= '0' && next_char() <= '9')
        {
            tmp[n++] = next_char();
            cur++;
        }
        tmp[n] = 0;
        int x;
        sscanf(tmp, "%d", &x);
        return x;
    }
}

int res;
int pos[20],totp;
bool cancal;

void DFS(int now)
{
    if (cancal == true) return;
    if (now == totp+1)
    {
        illegal = false;
        cur = 0;
        int ans = calc_exp(0);
        if (illegal == false)
        if (ans == res)
            cancal = true;
        return;
    }
    for (int i = 0;i < 4;i++)
    {
        s[pos[now]] = OP[i];
        DFS(now+1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%d",s,&res);
        n = strlen(s);
        totp = 0;
        for (int i = 0;i < n;i++)
        if (s[i] == '?')
        {
            totp++;
            pos[totp] = i;
        }
        cancal = false;
        DFS(1);
        if (cancal)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
