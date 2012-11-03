const int MAXN=100;
const int inf=0x3f3f3f3f;
bool visitx[MAXN],visity[MAXN];
int labx[MAXN],laby[MAXN],matx[MAXN],maty[MAXN],slack[MAXN];
int ma[MAXN][MAXN];
bool check(int x,int n)
{
    visitx[x]=1;
    for (int i=0; i<n; i++)
        if (!visity[i])
            if (labx[x]+laby[i]==ma[x][i])
            {
                visity[i]=1;
                if (maty[i]==-1 || check(maty[i],n))
                {
                    matx[x]=i;
                    maty[i]=x;
                    return 1;
                }
            }
            else
                slack[i]=min(slack[i],labx[x]+laby[i]-ma[x][i]);

    return 0;
}
void maintain(int n)
{
    int diff=inf;
    for (int i=0; i<n; i++)
        if (!visity[i])
            diff=min(diff,slack[i]);
    for (int i=0; i<n; i++)
    {
        if (visitx[i])
            labx[i]-=diff;
        if (visity[i])
            laby[i]+=diff;
        else
            slack[i]-=diff;
    }
}
int Kuhn_Munkras(int n)
{
    for (int i=0; i<n; i++)
    {
        labx[i]=-inf;
        for (int j=0; j<n; j++)
            labx[i]=max(labx[i],ma[i][j]);
    }
    memset(laby,0,4*n);
    memset(matx,-1,4*n);
    memset(maty,-1,4*n);
    for (int i=0; i<n; i++)
    {
        memset(visitx,0,n);
        memset(visity,0,n);
        memset(slack,63,4*n);
        while (!check(i,n))
        {
            maintain(n);
            memset(visitx,0,n);
            memset(visity,0,n);
        }
    }
    int ret=0;
    for (int i=0;i<n;i++)
        ret+=labx[i]+laby[i];
    return ret;
}
