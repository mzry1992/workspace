#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool a[1010];
int na,nb;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        memset(a,false,sizeof(a));
        scanf("%d",&na);
        for (int i = 1;i <= na;i++)
        {
            int temp;
            scanf("%d",&temp);
            a[temp] = true;
        }
        scanf("%d",&nb);
        for (int i = 1;i <= nb;i++)
        {
            int temp;
            scanf("%d",&temp);
            a[temp] = false;
        }
        printf("{");
        bool first = true;
        for (int i = 0;i <= 1000;i++)
        if (a[i] == true)
        {
            if (first == false)
            {
                printf(",");
            }
            first = false;
            printf("%d",i);
        }
        printf("}\n");
    }
}
