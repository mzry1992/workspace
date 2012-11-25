#include<cstdio>
#include<cstring>
#include<algorithm>
int n,m;
int lp[500][500],board[500][500];
inline bool inBoard(int x,int y)
{
    if (x<0||x>=n)
        return 0;
    if (y<0||y>=m)
        return 0;
    return 1;
}
bool check(int x)
{
    memset(lp,0,sizeof(lp));
    lp[0][0]=x;
    for (int i=1; i<n+m-1; i++)
        for (int j=0; j<=i; j++)
            if (inBoard(j,i-j))
            {
                if (inBoard(j-1,i-j) && lp[j-1][i-j]>0)
                    lp[j][i-j]=lp[j-1][i-j]+board[j][i-j];
                if (inBoard(j,i-j-1) && lp[j][i-j-1]>0)
                    lp[j][i-j]=std::max(lp[j][i-j],lp[j][i-j-1]+board[j][i-j]);
            }
    return lp[n-1][m-1]>0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d",&board[i][j]);
        int l=1,r=1000*1000*1000;
        while (l<r)
        {
            int mid=l+r>>1;
            if (check(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
