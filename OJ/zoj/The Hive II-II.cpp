#include<cstdio>
#include<cstring>
using namespace std;
int i,k,sh,g1,g2,n,m,s,tmp,h[8][3],t[8];
long long f[2][327680];
bool g[11][11];
char c[5];
inline void dp(int j)
{
    for(; j<8; j+=2)
        for(g1=!g1,g2=!g2,s=0; s<32768; ++s)
        {
            if(j)sh=(j<<1)-1,tmp=(s>>sh)&7;
            else tmp=s&3,sh=0;
            if(g[i][j])
            {
                for(f[g2][s]=k=0; k<t[tmp]; ++k)
                    if((j&&j<7)||(h[tmp][k]&4)==0)
                        f[g2][s]+=f[g1][s^(h[tmp][k]<<sh)];
            }
            else f[g2][s]=tmp?0:f[g1][s];
        }
}
int main()
{
    t[0]=3;
    h[0][0]=3;
    h[0][1]=5;
    h[0][2]=6;
    t[1]=3;
    h[1][0]=0;
    h[1][1]=3;
    h[1][2]=5;
    t[2]=3;
    h[2][0]=0;
    h[2][1]=3;
    h[2][2]=6;
    t[3]=1;
    h[3][0]=3;
    t[4]=3;
    h[4][0]=0;
    h[4][1]=5;
    h[4][2]=6;
    t[5]=1;
    h[5][0]=5;
    t[6]=1;
    h[6][0]=6;
    t[7]=0;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        memset(g,1,sizeof(g));
        for(i=0; i<m; ++i)scanf("%s",c),g[c[0]-'A'][c[1]-'A']=0;
        memset(f[0],0,sizeof(f[0]));
        for(f[0][0]=g1=1,g2=i=0; i<n; ++i)dp(1),dp(0);
        printf("%lld\n",f[g2][0]);
    }
    return 0;
}
