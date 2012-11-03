#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct work
{
    int d,t,z;
}works[1100];
int n;
int tree[10000],mark[1005];
bool cmp(work u,work v)
{
    if (u.t!=v.t) return u.d>v.d;
    else return u.t<v.t;
}
bool cmp2(work u,work v)
{
    return u.t>v.t;
}
int read(int x)
{
    int tmp=0;
    while (x>0)
    {
        tmp+=tree[x];
        x-=x&(-x);
    }
    return tmp;
}
void update(int x)
{
    while (x<=n)
    {
        tree[x]++;
        x+=x&(-x);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        memset(tree,0,sizeof(tree));
        memset(mark,false,sizeof(mark));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&works[i].d);
        for (int i=1;i<=n;i++)
            scanf("%d",&works[i].t);
        sort(works+1,works+n+1,cmp);
        for (int i=1;i<=n;i++)
            works[i].z=i;
        sort(works+1,works+n+1,cmp2);
        for (int i=1;i<=n;i++)
        {
            if (read(works[i].d)<works[i].d)
            {
                update(works[i].d);mark[i]=true;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (!mark[i]) ans+=works[i].t;
        }
        printf("%d\n",ans);
    }
}
