#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,m,s;
char b[100000];

double r(int a,int m,int &s)
{
    double val = (s%m)/(double)m;
    s = (int)(((long long)a*(long long)s+1)%m);
    return val;
}

int ceiling(double a)
{
    if ((a-(double)((int)a)) < 1e-8)    return (int)a;
    return (int)a+1;
}

int main()
{
    scanf("%d%d%d",&a,&m,&s);
    gets(b);
    while (gets(b))
    {
        int l = strlen(b);
        for (int i = 0;i < l;i++)
        if (b[i] >= 0x20 && b[i] <= 0x7e)
        {
            char c = b[i];
            c = ((c-32)+ceiling(95-r(a,m,s)*95))%95+32;
            putchar(c);
        }
        puts("");
    }
}
