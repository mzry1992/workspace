#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long res2,res,a;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        res = res2 = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%I64d",&a);
            for (int j = 0;j < a-1;j++)
                res += i+1;
            res++;
        }
        printf("%I64d\n",res);
    }
}
