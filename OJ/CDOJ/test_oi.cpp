#include <iostream>
using namespace std;

const int xyb[4][4] = {1,1,2,2,
                       1,1,2,2,
                       3,3,4,4,
                       3,3,4,4};        
bool han[40][40],lie[40][40],blo[40][40];
long long ans;
int n,map[40][40],tmap[40][40],tans;

void dfs(int x,int y)
{
     int i,j;
     int tx,ty;
     tx = x;
     ty = y;
     ty++;
     if (ty > 4)
     {
            ty = 1;
            tx++;
     }
     if (x == 5)
     {
           tans++;
           return;
     }
     if (tmap[x][y] != 0)
     {
                    dfs(tx,ty);
                    return;
     }
     for (i = 1;i <= 4;i++)
     if (han[x][i] == false)
     if (lie[y][i] == false)
     if (blo[xyb[x-1][y-1]][i] == false)
     {
                           han[x][i] = true;
                           lie[y][i] = true;
                           blo[xyb[x-1][y-1]][i] = true;
                           tmap[x][y] = i;
                           dfs(tx,ty);
                           tmap[x][y] = 0;
                           han[x][i] = false;
                           lie[y][i] = false;
                           blo[xyb[x-1][y-1]][i] = false;
     }
}

bool test()
{
     int i,j;
     memset(han,false,sizeof(han));
     memset(lie,false,sizeof(lie));
     memset(blo,false,sizeof(blo));
     tans = 0;
     for (i = 1;i <= 4;i++)
     for (j = 1;j <= 4;j++)
     {
         tmap[i][j] = map[i][j];
         han[i][tmap[i][j]] = true;
         lie[j][tmap[i][j]] = true;
         blo[xyb[i-1][j-1]][tmap[i][j]] = true;
     }
     dfs(1,1);
     if (tans == 1)                    return true;
     return false;
}

bool solve(int del,int x,int y)
{
     int temp;
     int tx,ty;
     int i,j;
     tx = x;
     ty = y;
     ty++;
     if (ty > 4)
     {
            ty = 1;
            tx++;
     }
     if (x == 5)
     {
           if (test() == true)
           {
              ans++;
              return true;
           }
           return false;
     }
     if (solve(del,tx,ty) == false)
        return false;
     temp = map[x][y];
     map[x][y] = 0;
     solve(del+1,tx,ty);
     map[x][y] = temp;
     return true;
}

int main()
{
    int ft,i,j;
    freopen("ans.txt","r",stdin);
    freopen("out_ans.txt","w",stdout);
    scanf("%d",&n);
    ans = 0;
    for (ft = 1;ft <= n;ft++)
    {
        for (i = 1;i <= 4;i++)
        for (j = 1;j <= 4;j++)
            scanf("%d",&map[i][j]);
        solve(0,1,1);
    }
    printf("%lld\n",ans);
    return 0;
}
