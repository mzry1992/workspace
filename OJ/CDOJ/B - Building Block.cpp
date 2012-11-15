#include<cstdio>
int fa[30001],sum[30001],len[30001];
int fint(int x)
{
    if (fa[x]==x) return x;
    else
    {
        int tmp=fa[x];
        fa[x]=fint(tmp);
        len[x]+=len[tmp];
        return fa[x];
    }
}
int main()
{
    int p;
    while (scanf("%d",&p) != EOF)
    {
        for (int i=1;i<30001;i++)
        {
            fa[i]=i;
            sum[i]=1;
            len[i]=0;
        }
        for (int i=0;i<p;i++)
        {
            char c;
            scanf(" %c",&c);
            if (c=='M')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int fx=fint(x),fy=fint(y);
                if (fx == fy)   continue;
                len[fx]+=sum[fy];
                sum[fy]+=sum[fx];
                fa[fy]=fx;
            }
            else
            {
                int x;
                scanf("%d",&x);
                fint(x);
                printf("%d\n",len[x]);
            }
        }
    }
    return 0;
}
