#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int l,res;

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int main()
{
    while (true)
    {
        scanf("%d",&l);
        res = 0;
        for (int i = 1;i <= l;i++)
            for (int j = i+1;j <= l;j++)
                for (int k = j+1;k <= l;k++)
                    if (i*i+j*j == k*k)
                        if (gcd(i,j) == 1 && gcd(i,k) == 1 && gcd(j,k) == 1)
                            res++;
        printf("%d\n",res);
    }
}
