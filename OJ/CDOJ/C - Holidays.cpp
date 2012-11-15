#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,tot[101];

int main()
{
    scanf("%d%d",&n,&m);
    memset(tot,0,sizeof(tot));
    for (int i = 1;i <= m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for (int j = a;j <= b;j++)
            tot[j]++;
    }
    bool flag = true;
    for (int i = 1;i <= n;i++)
        if (tot[i] != 1)
        {
            printf("%d %d\n",i,tot[i]);
            flag = false;
            break;
        }
    if (flag == true)
        printf("OK\n");
}
