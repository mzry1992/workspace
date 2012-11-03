#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char map[150][150];
char g[150][150];
int li[150][2];
int totl;
bool visit[150][150];
bool isDFS;

void DFS(int x,int y,int N,int M)
{
    if (x < 0)  return;
    if (y < 0)  return;
    if (x >= N) return;
    if (y >= M) return;
    if (g[x][y] == 'X') return;
    if (visit[x][y] == true)    return;
    if (x == N-1 && y == M-1)
        isDFS = true;
    if (isDFS == true)  return;
    visit[x][y] = true;
    DFS(x+1,y,N,M);
    DFS(x,y+1,N,M);
}

int main()
{
    while (scanf("%d%d",&m,&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        int ans = 19921005;
        bool isans = false;
        for (int jj = 4;jj <= n+m;jj++)
        {
            if (isans == true)  break;
            for (int i = 2;i <= n;i++)
            {
                int j = jj-i;
                if (j < 2) break;
                if (i+j-2 >= ans)
                {
                    isans = true;
                    break;
                }
                for (int k = 0;k < i;k++)
                for (int q = 0;q < j;q++)
                    g[k][q] = '.';
                totl = 1;
                li[1][0] = li[1][1] = 0;
                for (int k = 2;;k++)
                {
                    li[k][0] = li[k-1][0]+i-1;
                    li[k][1] = li[k-1][1]+j-1;
                    if (li[k][0] < n && li[k][1] < m)
                        totl++;
                    else
                        break;
                }
                int tsx,tsy;
                tsx = tsy = -1;
                for (int l = 1;l <= totl;l++)
                for (int k = 0;k < i;k++)
                for (int q = 0;q < j;q++)
                if (li[l][0]+k < n && li[l][1]+q < m)
                {
                    if (g[k][q] != 'X')
                        g[k][q] = map[li[l][0]+k][li[l][1]+q];
                    if (li[l][0]+k == n-1 && li[l][1]+q == m-1)
                    {
                        tsx = k;
                        tsy = q;
                    }
                }
                if (tsx == -1 && tsy == -1) continue;
                if (g[0][0] == 'X' || g[i-1][j-1] == 'X')   continue;
                for (int k = tsx+1;k < i;k++)
                for (int q = 0;q < tsy;q++)
                    g[k][q] = 'X';
                for (int k = 0;k < tsx;k++)
                for (int q = tsy+1;q < j;q++)
                    g[k][q] = 'X';
                isDFS = false;
                memset(visit,false,sizeof(visit));
                DFS(0,0,i,j);
                if (isDFS == true)
                {
                    ans = jj-2;
                    isans = true;
                    break;
                }
            }
        }
        if (ans == 19921005)
            ans = -1;
        printf("%d\n",ans);
    }
}
