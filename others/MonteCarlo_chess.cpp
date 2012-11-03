#include <cstdio>
#include <algorithm>
#include <stdlib.h>
//#include <bits/stl_pair.h>
#define NMax 22
#define NMax2 (22*22)
using namespace std;
int okstat[1<<NMax];
struct board
{
    int stat[22][22],ec;
    int tree[NMax2];
    int row[NMax][2],col[NMax][2],d1[NMax+NMax][2],d2[NMax+NMax][2];
    board()
    {
        ec=NMax2;
        for (int i=0; i<NMax; i++)for (int j=0; j<NMax; j++)stat[i][j]=0;
        for (int i=0; i<NMax2; i++)tree[i]=0;
        for (int i=0; i<NMax2; i++)for (int j=i; j<NMax2; j+=((j+1)&-(j+1)))tree[j]++;
        for (int i=0; i<NMax; i++)for (int j=0; j<2; j++)
                row[i][j]=col[i][j]=d1[i][j]=d2[i][j]=0;
        for (int i=NMax; i<NMax+NMax; i++)for (int j=0; j<2; j++)
                d1[i][j]=d2[i][j]=0;
        for (int i=0; i<(1<<NMax); i++)
        {
            int j=i;
            j&=(j>>1);
            j&=(j>>2);
            j&=(j>>1);
            okstat[i]=(1&&j);
        }
    }
    pair<int,int> getXY(int id)
    {
        //for (int i=0;i<NMax;i++)for (int j=0;j<NMax;j++)if (stat[i][j]==0){
        //if (!id)return make_pair(i,j);
        //id--;
        //}
        //return make_pair(NMax,0);
        int a=-1;
        for (int i=128; i>=1; i>>=1)if (a+i<NMax2 && tree[a+i]<=id)
            {
                a+=i;
                id-=tree[a];
            }
        a++;
        return make_pair(a/NMax,a%NMax);
    }
    int put(int x,int y,int c)
    {
        ec--;
        stat[x][y]=c;
        int a=x*NMax+y;
        for (int i=a; i<NMax2; i+=((i+1)&-(i+1)))tree[i]--;
        int cc=(c+1)>>1;
        if (okstat[row[x][cc]|=(1<<y)])return c;
        if (okstat[col[y][cc]|=(1<<x)])return c;
        if (okstat[d1[x+y][cc]|=(1<<x)])return c;
        if (okstat[d2[x-y+NMax][cc]|=(1<<x)])return c;
        return 0;
        //int l=1;
        //for (int i=x+1;i<NMax && stat[i][y]==c;i++)l++;
        //for (int i=x-1;i>=0 && stat[i][y]==c;i--)l++;
        //if (l>=5)return c;
        //l=1;
        //for (int i=y+1;i<NMax && stat[x][i]==c;i++)l++;
        //for (int i=y-1;i>=0 && stat[x][i]==c;i--)l++;
        //if (l>=5)return c;
        //l=1;
        //for (int i=1;x-i>=0 && y-i>=0 && stat[x-i][y-i]==c;i++)l++;
        //for (int i=1;x+i<NMax && y+i<NMax && stat[x+i][y+i]==c;i++)l++;
        //if (l>=5)return c;
        //l=1;
        //for (int i=1;x-i>=0 && y+i<NMax && stat[x-i][y+i]==c;i++)l++;
        //for (int i=1;x+i<NMax && y-i>=0 && stat[x+i][y-i]==c;i++)l++;
        //if (l>=5)return c;
        //return 0;
    }
    void unput(int x,int y)
    {
        int c=stat[x][y];
        ec++;
        stat[x][y]=0;
        int a=x*NMax+y;
        for (int i=a; i<NMax2; i+=((i+1)&-(i+1)))tree[i]++;
        int cc=(c+1)>>1;
        row[x][cc]&=~(1<<y);
        col[y][cc]&=~(1<<x);
        d1[x+y][cc]&=~(1<<x);
        d2[x-y+NMax][cc]&=~(1<<x);
    }
};
board B;
int vc[3];
void randomPlay(int c)
{
    //printf("ec=%d\n",B.ec);
    if (B.ec==0)
    {
        vc[1]++;
        return;
    }
    int u=(rand()>>5)%B.ec;
    pair<int,int> p=B.getXY(u);
    int x=p.first,y=p.second;
    if (B.put(x,y,c)!=c)randomPlay(-c);
    else vc[1+c]++;
    B.unput(x,y);
}
int tc,nc;
double Evaluate(int i,int j,int c,int rptimes)
{
    if (B.stat[i][j])return -9.99;
    if (B.put(i,j,c)==c)
    {
        B.unput(i,j);
        return 9.99;
    }
    vc[0]=vc[1]=vc[2]=0;
    for (int _=0; _<rptimes; _++)
    {
        randomPlay(-c);
        nc++;
        if (nc*100/tc!=(nc-1)*100/tc)
        {
            printf("%d%c finishes %c",nc*100/tc,'%',13);
            fflush(stdout);
        }
    }
    B.unput(i,j);
    return double(vc[1+c]-vc[1-c])/rptimes;
}
int alive[NMax][NMax];
double value[NMax][NMax];
int main()
{
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c)!=EOF && a!=-1)B.put(a,b,c);
    srand(365521);
    for (int i=0; i<NMax; i++)for (int j=0; j<NMax; j++)alive[i][j]=1;
    static double buf[NMax2];
    int l=NMax2,rpt=1000;
    while (l>5)
    {
        printf("l=%d rpt=%d\n",l,rpt);
        int z=0;
        nc=0;
        tc=rpt*l;
        for (int i=0; i<NMax; i++)for (int j=0; j<NMax; j++)if (alive[i][j])
                {
                    buf[z++]=value[i][j]=Evaluate(i,j,1,rpt);
                }
        sort(buf,buf+l);
        double k=buf[l>>1];
        for (int i=0; i<NMax; i++)for (int j=0; j<NMax; j++)if (alive[i][j])
                {
                    if (value[i][j]<k)
                    {
                        alive[i][j]=0;
                        l--;
                    }
                }
        printf("%6s","");
        for (int i=0; i<NMax; i++)printf("%-6d",i);
        puts("");
        for (int i=0; i<NMax; i++)
        {
            printf("%-6d",i);
            for (int j=0; j<NMax; j++)
            {
                if (alive[i][j])printf("%6.3f",value[i][j]);
                else if (B.stat[i][j]==1)printf("......");
                else if (B.stat[i][j]==-1)printf("XXXXXX");
                else printf("%6s","");
            }
            puts("");
        }
        rpt<<=1;
    }
    //B.put(0,0,1);
    //randomPlay(-1);
    return 0;
}

