#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

FILE *fout;

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    fout = fopen("res4.txt","w");
    int curmax = 0,curtot = 0,nowtot,tot = 0;
    int dif = 1,nxt = 2,ndif;
    for (int i = 1;i <= 1000000000;i += dif)
    {
        nowtot = 0;
        for (int j = 1;j <= i;j++)
            if (i%j == 0)
            {
                nowtot ++;
            }
        if (nowtot > curtot)
        {
            curmax = i;
            curtot = nowtot;
            fprintf(fout,"a[%d] = %d;b[%d] = %d;\n",tot,curmax,tot,curtot);
            tot++;
            printf("a[%d] = %d;\n",tot-1,curmax);
            /*if (curmax%2520 == 0)
                dif = 2520;*/
            /*ndif = lcm(dif,nxt);
            if (curmax%ndif == 0)
            {
                dif = ndif;
                nxt++;
            }*/
            /*if (curmax%(dif*nxt) == 0)
            {
                dif *= nxt;
                nxt++;
            }*/
        }
    }
    return 0;
}
