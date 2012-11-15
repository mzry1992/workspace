#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    printf("%d\n",10*6);
    for (int i = 1;i <= 10;i++)
    {
        for (int j = 1;j <= 6;j++)
            printf("%d %d\n",i,j);
        printf("\n");
    }
    return 0;
}
