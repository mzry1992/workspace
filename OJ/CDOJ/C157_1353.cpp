#include <iostream>
using namespace std;

const int xyb[4][4] = {1,1,2,2,
                       1,1,2,2,
                       3,3,4,4,
                       3,3,4,4};        
long long ans;
int map[4][4],kans;
bool han[4][4],lie[4][4],blo[4][4];

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
           ans++;
           cout << endl;
           for (i = 1;i <= 4;i++)
           {
               for (j = 1;j <= 4;j++)
                   cout << map[i][j] << ' ';
               cout << endl;
           }
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
                           map[x][y] = i;
                           dfs(tx,ty);
                           map[x][y] = 0;
                           han[x][i] = false;
                           lie[y][i] = false;
                           blo[xyb[x-1][y-1]][i] = false;
     }
}

int main()
{
    int i;
    freopen("ans.txt","w",stdout);
    memset(map,0,sizeof(map));
    memset(han,false,sizeof(han));
    memset(lie,false,sizeof(lie));
    memset(blo,false,sizeof(blo));
    dfs(1,1);
    printf("%lld\n",ans);
    return 0;
}
