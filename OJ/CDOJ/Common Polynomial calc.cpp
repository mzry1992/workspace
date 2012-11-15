#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const double eps = 1e-8;

struct poly
{
    int a[12000];
    int m;
};

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

int getlen(poly a)
{
    int res = 200;
    while (a.a[res] == 0)
    {
        res--;
        if (res == 0) return 0;
    }
    return res;
}

poly cons(int p,int x)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    res.a[p] = x;
    res.m = getlen(res);
    return res;
}


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

poly padd(poly a,poly b)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i <= max(a.m,b.m);i++)
        res.a[i] = a.a[i]+b.a[i];
    res.m = getlen(res);
    return res;
}

poly pdel(poly a,poly b)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i <= max(a.m,b.m);i++)
        res.a[i] = a.a[i]-b.a[i];
    res.m = getlen(res);
    return res;
}

poly pmul(poly a,poly b)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i <= a.m;i++)
    for (int j = 0;j <= b.m;j++)
        res.a[i+j] += a.a[i]*b.a[j];
    res.m = getlen(res);
    while (res.a[res.m] == 0) res.m--;
    return res;
}

poly ppow(poly a,poly b)
{
    poly res;
    if (b.a[0] == 0)
        return cons(0,1);
    if (b.a[0] == 1)
        return a;
    memset(res.a,0,sizeof(res.a));
    res = a;
    for (int i = 2;i <= b.a[0];i++)
        res = pmul(res,a);
    return res;
}

poly calc(poly a, char op, poly b)
{
    if (op == '+')
        return padd(a,b);
    else if (op == '-')
        return pdel(a,b);
    else if (op == '*')
        return pmul(a,b);
    else if (op == '^')
    {
        return ppow(a,b);
    }
}

poly P();

bool iszero(poly a)
{
    for (int i = a.m;i >= 0;i--)
    if (a.a[i] != 0) return false;
    return true;
}

void output(poly a)
{
    if (iszero(a))
    {
        puts("0");
        return;
    }
    bool first = true;
    for (int i = a.m;i > 0;i--)
    if (a.a[i] != 0)
    {
        if (a.a[i] > 0)
        if (!first)
            cout << '+';
        if (a.a[i] < 0) cout << '-';
        first = false;
        if (a.a[i] != 1 && a.a[i] != -1) cout << abs(a.a[i]);
        if (i > 1)
            cout << "x^" << i;
        else if (i == 1)
            cout << "x";
    }
    if (a.a[0] != 0)
    {
        if (a.a[0] > 0)
        if (!first) cout << '+';
        cout << a.a[0];
    }
    cout << endl;
}

poly calc_exp(int p)
{
    poly a = P();
    while (OP.find(next_char()) != string::npos && get_priority(next_char()) >= p)
    {
        char op = next_char(); cur++;
        a = calc(a, op, calc_exp(get_priority(op) + 1));
    }
    return a;
}

char tmp[1024];

poly unsign(poly a)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i <= a.m;i++)
        res.a[i] = -a.a[i];
    res.m = getlen(res);
    return res;
}

poly P()
{
    if (next_char() == '-')
    {
        cur++;
        return unsign(P());
    }
    else if (next_char() == '+')
    {
        cur++;
        return P();
    }
    else if (next_char() == '(')
    {
        cur++;
        poly r = calc_exp(0);
        if (next_char() == ')')
            cur++;
        return r;
    }
    else
    {
        int n = 0;
        poly res;
        if (next_char() == 'x')
        {
            res = cons(1,1);
            cur++;
        }
        else
        {
            while (next_char() >= '0' && next_char() <= '9')
            {
                tmp[n++] = next_char();
                cur++;
            }
            tmp[n] = 0;
            int x;
            sscanf(tmp, "%d", &x);
            res = cons(0,x);
        }
        return res;
    }
}

poly getpoly(char ns[])
{
    int tl = strlen(ns);
    int ll = 0;
    if (ns[0] == '-')
    {
        s[0] = '0';
        ll++;
    }
    s[ll] = ns[0];
    ll++;
    for (int i = 1;i < tl;i++)
    if (ns[i] == 'x' || ns[i] == '(')
    {
        if ((ns[i-1] >= '0' && ns[i-1] <= '9') || (ns[i-1] == ')'))
        {
            s[ll] = '*';
            ll++;
            s[ll] = ns[i];
            ll++;
        }
        else
        {
            s[ll] = ns[i];
            ll++;
        }
    }
    else
    {
        s[ll] = ns[i];
        ll++;
    }
    s[ll] = 0;
    n = strlen(s);
    cur = 0;
    poly res = calc_exp(0);
    return res;
}

char sa[100000],sb[100000];
poly p1,p2;

int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    bool first = true;
    while (true)
    {
        if (!first) gets(sa);
        first = false;
        gets(sa);
        if (sa[0] == '.') break;
        gets(sb);
        p1 = getpoly(sa);
        p2 = getpoly(sb);
        output(padd(p1,p2));
    }
}
