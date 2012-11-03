#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c;
int a1,a2,a3,a4;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&c);
        a1 = a2 = a3 = a4 = 0;
        a1 = c/25;
        c -= a1*25;
        if (c > 0)
        {
            a2 = c/10;
            c -= a2*10;
            if (c > 0)
            {
                a3 = c/5;
                c -= a3*5;
            }
            a4 = c;
        }
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",ft,a1,a2,a3,a4);
    }
}
