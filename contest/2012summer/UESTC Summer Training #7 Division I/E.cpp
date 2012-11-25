#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,K;
int s[35],sum;
bool vis[30][35],flag;
int ans[35];
struct N
{
    int x,y,z;
    int num;
    int loop[5];
}nod[35];
inline void fill(int p,int v)
{
    vis[nod[p].x][v]=true;
    vis[nod[p].y+7][v]=true;
    vis[nod[p].z+14][v]=true;
    int i;
    for(i=0;i<nod[p].num;i++)
        vis[21+nod[p].loop[i]][v]=true;
}
inline bool check(int p,int v)
{
    if(vis[nod[p].x][v])
        return false;
    if(vis[nod[p].y+7][v])
        return false;
    if(vis[nod[p].z+14][v])
        return false;
    int i;
    for(i=0;i<nod[p].num;i++)
        if(vis[21+nod[p].loop[i]][v])
            return false;
    return true;
}
inline void unfill(int p,int v)
{
    vis[nod[p].x][v]=false;
    vis[nod[p].y+7][v]=false;
    vis[nod[p].z+14][v]=false;
    int i;
    for(i=0;i<nod[p].num;i++)
        vis[21+nod[p].loop[i]][v]=false;
}
bool dfs(int p)
{
    int i;
    if(p>31)
    {
        sum++;
        if(sum==K)
        {
            flag=true;
            return true;
        }
    }
    else
    {
        if(s[p]!=0)
            dfs(p+1);
        else
        {
            for(i=1;i<=n;i++)
                if(check(p,i))
                {
                    ans[p]=i;
                    fill(p,i);
                    if(dfs(p+1))
                        return true;
                    unfill(p,i);
                }
        }
    }
    return false;
}
int main()
{
    nod[1].x=1;nod[1].y=5;nod[1].z=2;
    nod[2].x=1;nod[2].y=6;nod[2].z=3;
    nod[3].x=2;nod[3].y=3;nod[3].z=1;
    nod[4].x=2;nod[4].y=4;nod[4].z=2;
    nod[5].x=2;nod[5].y=5;nod[5].z=3;
    nod[6].x=2;nod[6].y=6;nod[6].z=4;
    nod[7].x=2;nod[7].y=7;nod[7].z=5;
    nod[8].x=3;nod[8].y=2;nod[8].z=1;
    nod[9].x=3;nod[9].y=3;nod[9].z=2;
    nod[10].x=3;nod[10].y=4;nod[10].z=3;
    nod[11].x=3;nod[11].y=5;nod[11].z=4;
    nod[12].x=3;nod[12].y=6;nod[12].z=5;
    nod[13].x=3;nod[13].y=7;nod[13].z=6;
    nod[14].x=4;nod[14].y=2;nod[14].z=2;
    nod[15].x=4;nod[15].y=3;nod[15].z=3;
    nod[16].x=4;nod[16].y=4;nod[16].z=4;
    nod[17].x=4;nod[17].y=5;nod[17].z=5;
    nod[18].x=4;nod[18].y=6;nod[18].z=6;
    nod[19].x=5;nod[19].y=1;nod[19].z=2;
    nod[20].x=5;nod[20].y=2;nod[20].z=3;
    nod[21].x=5;nod[21].y=3;nod[21].z=4;
    nod[22].x=5;nod[22].y=4;nod[22].z=5;
    nod[23].x=5;nod[23].y=5;nod[23].z=6;
    nod[24].x=5;nod[24].y=6;nod[24].z=7;
    nod[25].x=6;nod[25].y=1;nod[25].z=3;
    nod[26].x=6;nod[26].y=2;nod[26].z=4;
    nod[27].x=6;nod[27].y=3;nod[27].z=5;
    nod[28].x=6;nod[28].y=4;nod[28].z=6;
    nod[29].x=6;nod[29].y=5;nod[29].z=7;
    nod[30].x=7;nod[30].y=2;nod[30].z=5;
    nod[31].x=7;nod[31].y=3;nod[31].z=6;

    nod[1].num=1;nod[1].loop[0]=1;
    nod[2].num=1;nod[2].loop[0]=1;
    nod[3].num=1;nod[3].loop[0]=2;
    nod[4].num=2;nod[4].loop[0]=1;nod[4].loop[1]=2;
    nod[5].num=1;nod[5].loop[0]=1;
    nod[6].num=2;nod[6].loop[0]=1;nod[6].loop[1]=3;
    nod[7].num=1;nod[7].loop[0]=3;
    nod[8].num=1;nod[8].loop[0]=2;
    nod[9].num=1;nod[9].loop[0]=2;
    nod[10].num=3;nod[10].loop[0]=1;nod[10].loop[1]=2;nod[10].loop[2]=4;
    nod[11].num=3;nod[11].loop[0]=1;nod[11].loop[1]=3;nod[11].loop[2]=4;
    nod[12].num=1;nod[12].loop[0]=3;
    nod[13].num=1;nod[13].loop[0]=3;
    nod[14].num=2;nod[14].loop[0]=2;nod[14].loop[1]=5;
    nod[15].num=3;nod[15].loop[0]=2;nod[15].loop[1]=4;nod[15].loop[2]=5;
    nod[16].num=1;nod[16].loop[0]=4;
    nod[17].num=3;nod[17].loop[0]=3;nod[17].loop[1]=4;nod[17].loop[2]=6;
    nod[18].num=2;nod[18].loop[0]=3;nod[18].loop[1]=6;
    nod[19].num=1;nod[19].loop[0]=5;
    nod[20].num=1;nod[20].loop[0]=5;
    nod[21].num=3;nod[21].loop[0]=4;nod[21].loop[1]=5;nod[21].loop[2]=7;
    nod[22].num=3;nod[22].loop[0]=4;nod[22].loop[1]=6;nod[22].loop[2]=7;
    nod[23].num=1;nod[23].loop[0]=6;
    nod[24].num=1;nod[24].loop[0]=6;
    nod[25].num=1;nod[25].loop[0]=5;
    nod[26].num=2;nod[26].loop[0]=5;nod[26].loop[1]=7;
    nod[27].num=1;nod[27].loop[0]=7;
    nod[28].num=2;nod[28].loop[0]=6;nod[28].loop[1]=7;
    nod[29].num=1;nod[29].loop[0]=6;
    nod[30].num=1;nod[30].loop[0]=7;
    nod[31].num=1;nod[31].loop[0]=7;
	while(scanf("%d%d",&n,&K)==2)
	{
        int i;
        memset(vis,false,sizeof(vis));
        flag=true;
        for(i=1;i<=31;i++)
        {
            scanf("%d",&s[i]);
            if(s[i]>0)
            {
                if(!check(i,s[i]))
                    flag=false;
                fill(i,s[i]);
            }
        }
        if(!flag||(n==7&&K>10080))
        {
            printf("No way\n");
            continue;
        }
        sum=0;
        flag=false;
        dfs(1);
        if(flag)
        {
            printf("Found\n");
            for(i=1;i<=31;i++)
            {
                if(i==1)
                    printf("%d",ans[i]);
                else
                    printf(" %d",ans[i]);
            }
            printf("\n");
        }
        else
            printf("No way\n");
	}
	return 0;
}
