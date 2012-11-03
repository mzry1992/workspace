#include <stdio.h>

int x,y,tx,ty,i,j,tot,map[1500][1500];
char str[1500];
bool visit[1500][1500];

void dfs(int tx,int ty)
{
     int px,py,i;
     visit[tx][ty] = true;
     if (map[tx][ty] == 0) tot++;
     px = tx-1;
     py = ty;
     if ((px >= 1) && (px <= x) && (py >= 1) && (py <= y))
     if (visit[px][py] == false)
     if (map[px][py] != 2)
            dfs(px,py);
     px = tx;
     py = ty-1;
     if ((px >= 1) && (px <= x) && (py >= 1) && (py <= y))
     if (visit[px][py] == false)
     if (map[px][py] != 2)
            dfs(px,py);
     px = tx;
     py = ty+1;
     if ((px >= 1) && (px <= x) && (py >= 1) && (py <= y))
     if (visit[px][py] == false)
     if (map[px][py] != 2)
            dfs(px,py);
     px = tx+1;
     py = ty;
     if ((px >= 1) && (px <= x) && (py >= 1) && (py <= y))
     if (visit[px][py] == false)
     if (map[px][py] != 2)
            dfs(px,py);
}

int main()
{
    while (scanf("%d %d",&x,&y) == 2)
    {

          for (i = 1;i <= x;i++)
          {
              scanf("%s",&str);
              for (j = 1;j <= y;j++)
              {
                  if (str[j-1] == '*')
                     map[i][j] = 0;
                  if (str[j-1] == '.')
                     map[i][j] = 1;
                  if (str[j-1] == '#')
                     map[i][j] = 2;
                  if (str[j-1] == 'X')
                  {
                         map[i][j] = 3;
                         tx = i;
                         ty = j;
                  }
              }
          }
          for (i = 1;i <= x;i++)
          for (j = 1;j <= y;j++)
              visit[i][j] = false;
          tot = 0;
          dfs(tx,ty);
          printf("%d\n",tot);
    }
    return 0;
}
