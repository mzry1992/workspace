#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,q;
int tree[1200][1200];
char com[10];
int a,b,c,d;

void updata(int x,int y,int val)
{
    if (x == 0) return;
    if (y == 0) return;
    while (x <= n)
    {
        tree[x][y] += val;
        int ty = y;
        ty += ty & -ty;
        while (ty <= n)
        {
            tree[x][ty] += val;
            ty += ty & -ty;
        }
        x += x & -x;
    }
}

int read(int x,int y)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree[x][y];
        int ty = y;
        ty -= ty & -ty;
        while (ty > 0)
        {
            sum += tree[x][ty];
            ty -= ty & -ty;
        }
        x -= x & -x;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof(tree));
        for (int i = 1;i <= q;i++)
        {
            scanf("%s",com);
            if (strcmp(com,"C") == 0)
            {
                scanf("%d%d%d%d",&a,&b,&c,&d);
                updata(a,b,1);
                updata(a,d+1,-1);
                updata(c+1,b,-1);
                updata(c+1,d+1,1);
            }
            else
            {
                scanf("%d%d",&a,&b);
                if (read(a,b)%2 == 0)
                    printf("0\n");
                else
                    printf("1\n");
            }
        }
        printf("\n");
    }
}
