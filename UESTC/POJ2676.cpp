#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tcase,fcase;
int sd[10][10];//保存数独
char tsd[10][10];//读入的数独
int han[10][10],lie[10][10],kua[10][10];//标记行、列、块的1到9的使用情况
int flag;//标记是否已经填完

int getb(int x,int y)//获得块编号
{
    int tx,ty,ans;
    if ((x >= 1) && (x <= 3)) tx = 1;
    if ((x >= 4) && (x <= 6)) tx = 2;
    if ((x >= 7) && (x <= 9)) tx = 3;
    if ((y >= 1) && (y <= 3)) ty = 1;
    if ((y >= 4) && (y <= 6)) ty = 2;
    if ((y >= 7) && (y <= 9)) ty = 3;
    ans = (tx-1)*3+ty;
    return ans;
}

void add(int x,int y,int v)//在（X,Y）处填数字V
{
     han[x][v] = lie[y][v] = kua[getb(x,y)][v] = true;
     sd[x][y] = v;
}

void del(int x,int y,int v)//划掉在（X,Y）处填的数字V
{
     han[x][v] = lie[y][v] = kua[getb(x,y)][v] = false;
     sd[x][y] = 0;
}

void readin()//输入
{
     int i,j;
     for (i = 1;i <= 9;i++)
     {
         scanf("%s",&tsd[i]);
         for (j = 1;j <= 9;j++)
             sd[i][j] = tsd[i][j-1]-'0';
     }
}

void output();

void DFS(int nowx,int nowy)//搜索到了（nowx,nowy）
{
     int tx,ty,i;
     tx = nowx; ty = nowy;
     ty++;//获得下一个要搜索的坐标
     if (ty > 9)
     {
            ty -= 9;
            tx++;
     }
     if ((nowx == 10) && (nowy == 1))//如果搜索完了，那么输出答案并且标记有解
     {
             output();
             flag = true;
     }
     if (flag == true)  return;//如果已经有解，那么退出
     if (sd[nowx][nowy] != 0)  //如果这里有数字，那么搜索下一个点
     {
                        DFS(tx,ty);
                        return;
     }
     for (i = 1;i <= 9;i++)//枚举1到9
     if (han[nowx][i] == false)
     if (lie[nowy][i] == false)
     if (kua[getb(nowx,nowy)][i] == false)//如果可以填
     {
                             if (flag == true) return;
                             add(nowx,nowy,i);//填入
                             DFS(tx,ty);//搜索
                             del(nowx,nowy,i);//恢复
     }
}

void solve()
{
     int i,j;
     memset(han,false,sizeof(han));
     memset(lie,false,sizeof(lie));
     memset(kua,false,sizeof(kua));
     for (i = 1;i <= 9;i++)
     for (j = 1;j <= 9;j++)
         add(i,j,sd[i][j]);//先填入已知的数据
     flag = false;
     DFS(1,1);
}

void output()
{
     int i,j;
     for (i = 1;i <= 9;i++)
     {
         for (j = 1;j <= 9;j++)
             printf("%d",sd[i][j]);
         printf("\n");
     }
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        readin();
        solve();
    }
}
