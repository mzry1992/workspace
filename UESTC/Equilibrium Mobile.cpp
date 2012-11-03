#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[500000];
struct node
{
    int w;
    int lc,rc;
    int depth;
}tree[1200000];
int tottree;

void build(int depth,int root,int l,int r)
{
    //cout << depth << ' ' << root << ' ' << l << ' ' << r << endl;
    tree[root].depth = depth;
    if (s[l] >= '0' && s[l] <= '9')
    {
        tree[root].lc = tree[root].rc = -1;
        int tw = 0;
        for (int i = l;i <= r;i++)
            tw = tw*10+s[i]-'0';
        tree[root].w = tw;
        return;
    }
    tree[root].w = -1;
    int mid;
    int ttot = 0;
    for (int i = l+1;i <= r-1;i++)
    {
        if (s[i] == '[') ttot++;
        if (s[i] == ']') ttot--;
        if (ttot == 0)
            if (s[i] == ',')
            {
                mid = i;
                break;
            }
    }
    tottree++;
    tree[root].lc = tottree;
    build(depth+1,tottree,l+1,mid-1);
    tottree++;
    tree[root].rc = tottree;
    build(depth+1,tottree,mid+1,r-1);
}

long long a[1100000];
int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        tottree = 0;
        build(0,0,0,strlen(s)-1);
        int l=0;
        for (int i=0;i<=tottree;i++)
        {
            if (tree[i].w>-1) a[++l]=(long long)tree[i].w*(long long)(1LL<<tree[i].depth);
        }
        sort(a+1,a+l+1);
        int ans=0;a[0]=a[1];
        for (int i=1;i<=l;i++)
        {
            int j=i+1;
            int tmp=1;
            while (a[j]==a[j-1])
            {
                tmp++;
                if (j==l) break;
                j++;
            }
            i=j-1;
            if (tmp>ans) ans=tmp;
        }
        cout<<l-ans<<endl;
    }
}
