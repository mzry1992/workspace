#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300010;
int n,q,a[maxn],w[maxn],f[maxn],m[maxn],add[maxn],allmax,x,y;
char com[10];

int findf(int x)
{
    if (f[x] == x)  return x;
    else return findf(f[x]);
}

void unionset(int x,int y)
{

}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)  scanf("%d",&a[i]);
        scanf("%d",&q);
        allmax = a[1];
        for (int i = 1;i <= n;i++)
        {
            f[i] = i;
            m[i] = a[i];
            w[i] = 1;
            add[i] = 0;
            allmax = max(allmax,a[i]);
        }
        for (int i = 1;i <= q;i++)
        {
            scanf("%s",com);
            if (strcmp(com,"U") == 0)
            {
                scanf("%d%d",&x,&y);
                unionset(x,y);
            }
            else if (strcmp(com,"A1") == 0)
            {
                scanf("%d%d",&x,&y);
            }
            else if (strcmp(com,"A2") == 0)
            {
                scanf("%d%d",&x,&y);
            }
            else if (strcmp(com,"F1") == 0)
            {
                scanf("%d",&x);
            }
            else if (strcmp(com,"F2") == 0)
            {
                scanf("%d",&x);
            }
            else
            {

            }
        }
    }
}
