#include<cstdio>
int fa[200001];
int more[200001];
int find(int x)
{
    if (fa[x]==x)
        return x;
    else
    {
        int fu=find(fa[x]);
        more[x]+=more[fa[x]];
        return fa[x]=fu;
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<=n;i++)
        {
            fa[i]=i;
            more[i]=0;
        }
        int ans=0;
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x--;
            int fx=find(x),fy=find(y);
            if (fx!=fy)
            {
                fa[fy]=fx;
                more[fy]=z;
            }
            else
            {
                if (more[fy]-more[fx]!=z)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
