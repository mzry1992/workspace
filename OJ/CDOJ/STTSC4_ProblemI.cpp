/*
Problem I

Treausure  

Description 

����Loneknight is finding treasures in a maze. He is so greedy that he always takes away all the treasure he can reach. Now, he has a map for the maze, and he want to know the maximum of treasure he can get. Please help him calculate this value. Note that in every step, Loneknight can only move up, down, left, or right, if the target place is not a wall. Moreover, he can't move out of the maze, or you may assume that there is a wall suround the whole maze.

Input 

����The input consists of several test cases. Each test case start with a line containing two number, n, m(1 < n, m <= 1000), the rows and the columns of grid. Then n lines follow, each contain exact m characters, representing the type of block in it. (. for empty place, X for loneknight, * for treasure, # for wall). Each case contain exactly one X. The input end with EOF.

Output 

����You have to print the maximum number of treasures loneknight can get in a single line for each case.

Sample Input 

4 4
*...
.X..
....
...*

4 4
*#..
#X..
....
...*

Sample Output 

2
1

Source 
���Ŵ�ѧ���Ľ������ƾ��� �ֳ����� 
*/

//����������������˵�������ɣ����Ѽ��ɡ�
 
#include <stdio.h>

int x,y,tx,ty,i,j,tot,map[1500][1500];
char str[1500];
bool visit[1500][1500];

void dfs(int tx,int ty) //�������� 
{
     int px,py,i;
     visit[tx][ty] = true; //����Ѿ������������ 
     if (map[tx][ty] == 0) tot++; //����������*����ô��������һ�� 
     //�ĸ��������������������step����ģ����Ī������Ĵ�������ͷ�� 
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
          dfs(tx,ty); //��X��λ�ÿ�ʼ���� 
          printf("%d\n",tot);
    }
    return 0;
}
