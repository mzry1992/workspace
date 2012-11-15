#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[100];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            a[--tmp] = i;
        }
        for (int i = 0;i < n;i++)
            printf("%d ",a[i]+1);
        printf("\n");
    }
    return 0;
}
