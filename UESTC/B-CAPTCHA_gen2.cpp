#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    freopen("BC_out.txt","r",stdin);
    freopen("BC_out2.txt","w",stdout);
    for (int i = 1;i <= 26;i++)
    {
        int tot;
        scanf("%d",&tot);
        printf("tot[%d] = %d;\n",i,tot);
        for (int j = 1;j <= tot;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("map[%d][%d][0] = %d;map[%d][%d][1] = %d;\n",i,j,x,i,j,y);
        }
    }
}
