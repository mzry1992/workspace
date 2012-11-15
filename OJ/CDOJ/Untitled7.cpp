#include<iostream>
#include<cstdio>
using namespace std;
int sx,sy,tot,n,m;
char map[1010][1010];
bool visit[1010][1010];
const int d[4][4]={{1,0,-1,0},{0,1,0,-1}};
bool check(int x,int y)
{
    return (x>=0)&&(x<n)&&(y>=0)&&(y<m);
}
void find(int x,int y)
{
    if(check(x,y)==false)  return;
    if(map[x][y]=='#')  return;
    if(visit[x][y]==true)  return;
    if(map[x][y]=='*')     tot++;
    visit[x][y]=true;
    for(int i=0;i<4;i++)
    find(x+d[0][i],y+d[1][i]);
}

int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)==2)
    {
    tot=0;
    for(i=0;i<n;i++)
            scanf("%s",map[i]);
    for(i=0;i<1010;i++)
        for(j=0;j<1010;j++)
          visit[i][j]=false;
    for(  i=0;i<n;i++)
        for( j=0;j<m;j++)
          {
              if(map[i][j]=='X')
              {
                  sx=i;
                  sy=j;
              }
          }
    find(sx,sy);
    printf("%d\n",tot);
    }
    return 0;
}
