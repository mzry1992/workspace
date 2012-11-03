#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,m,s;
char b[100000];

double r(int a,int m,int &s)
{
    double val = (s%m)/(double)m;
    s = ((a*s+1)%m);
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
            int tr = ceiling(95-r(a,m,s)*95);
            for (char q = 0x20;q <= 0x7e;q++)
            if (((q-32)+tr)%95+32 == c)
            {
                putchar(q);
                break;
            }
        }
        puts("");
    }
}

