#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Oper
{
    int typ,val,id;
};
Oper op[100000];
int a[100000];
int n,cnt;
char buf[20];
long long tree[400000][5];
int num[400000];
void update(int x,int l,int r,int p,int v)
{
    if (l==r)
    {
        tree[x][0]+=v;
        num[x]=!num[x];
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p,v);
    else
        update(x*2+1,mid+1,r,p,v);
    for (int i=0;i<5;i++)
        tree[x][(i+num[x*2])%5]=tree[x*2][(i+num[x*2])%5]+tree[x*2+1][i];
    num[x]=num[x*2]+num[x*2+1];
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data1.out","w",stdout);
    while (scanf("%d",&n) != EOF)
    {
        cnt = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            if (strcmp(buf,"add") == 0)
            {
                op[i].typ = 0;
                scanf("%d",&op[i].val);
                while (op[i].val<=0)
                    puts("FUCK");
                a[cnt++] = op[i].val;
            }
            else if (strcmp(buf,"del") == 0)
            {
                op[i].typ = 1;
                scanf("%d",&op[i].val);
                a[cnt++] = op[i].val;
            }
            else
                op[i].typ = 2;
        }

        sort(a,a+cnt);
        cnt = unique(a,a+cnt)-a;
        for (int i = 0;i < n;i++)
            if (op[i].typ < 2)
                op[i].id = lower_bound(a,a+cnt,op[i].val)-a;
        memset(tree,0,sizeof(tree));
        memset(num,0,sizeof(num));
        for (int i=0;i<n;i++)
        {
            if (op[i].typ==0)
                update(1,0,cnt-1,op[i].id,op[i].val);
            else if (op[i].typ==1)
                update(1,0,cnt-1,op[i].id,-op[i].val);
            else
                printf("%I64d\n",tree[1][2]);
            /*for (int j=0;j<5;j++)
                printf("%lld ",tree[1][j]);
            puts("");*/
        }
        //puts("");
    }
    return 0;
}
