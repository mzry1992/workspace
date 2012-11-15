#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,res;

void Gao(int sum,int last)
{
    if (sum%n == 0)
        res++;
    for (int i = last+1;i < n;i++)
        Gao(sum+i,i);
}

int main()
{
    for (n = 1;n <= 30;n++)
    {
        res = 0;
        Gao(0,-1);
        printf("a[%d]=%d;\n",n,res);
    }
    return 0;
}
