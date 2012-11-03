#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

bool tma[10][10],tmb[10][10],ma[10][10],mb[10][10];
int a[100][3],ed[100][3];
int dua[10],dub[10];
int main()
{
    int n,na,nb;
    int cas=0;
    while(scanf("%d%d%d",&n,&na,&nb)>0 ,n||na||nb)
    {
        cas++;
        int ia,ib,da,db;
        scanf("%d%d%d%d",&ia,&ib,&da,&db);
        memset(ma,false,sizeof(ma));
        memset(mb,false,sizeof(mb));
        for (int i=1;i<=na;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ma[x][y]=ma[y][x]=true;
        }
        int cnt1=0;
        for (int i=1;i<=nb;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ed[cnt1][0]=x;ed[cnt1][1]=y;cnt1++;
        }
        int mapp[10]={1,2,3,4,5,6,7,8};
        int min=1000000000,ans=0;
        //printf("%d%d%d%d\n",ia,ib,da,db);
        do
        {
            int ans=0;
            memset(mb,false,sizeof(mb));
            for (int i=0;i<cnt1;i++)
                mb[mapp[ed[i][0]]-1][mapp[ed[i][1]]-1]=mb[mapp[ed[i][1]]-1][mapp[ed[i][0]]-1]=true;
            int cnt=0;
            for (int i=0;i<n-1;i++)
                for (int j=i+1;j<n;j++)
                {
                    if (mb[i][j] && !ma[i][j])
                    {
                        if (db>ia) ans+=ia;else ans+=db;
                    }
                    else if (!mb[i][j] && ma[i][j])
                    {
                        if (da>ib) ans+=ib;else ans+=da;
                    }
                }
            if (ans<min) min=ans;
        }while (next_permutation(mapp,mapp+n));
        printf("Case #%d: %d\n",cas,min);
    }

}
