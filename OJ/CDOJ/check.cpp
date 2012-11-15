#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("out.txt","r",stdin);
    for (int i = 3;i <= 18;i++)
    {
        double sum = 0.0;
        for (int j = 1;j <= i;j++)
        {
            int temp;
            scanf("%d",&temp);
            sum += 1.0/(double)temp;
        }
        if (sum == 1.0) printf("N = %d is Right\n",i);
        else    printf("N = %d is Wrong\n",i);
    }
}
