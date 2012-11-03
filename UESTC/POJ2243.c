#include <stdio.h>

const int step[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};//8个方向上xy坐标的变化
int visit[10][10],head,tail,i,j;//visit记录棋盘上各点的状况，head和tail是队列的队头和队尾
struct Status//用结构体保存状态
{
    int x,y,step;
}Q[100000],now;

int BFS(int sx,int sy,int tx,int ty)//BFS函数，传入初始坐标和目标坐标，传出最小步数
{
    head = tail = 0;
    Q[head].x = sx; Q[head].y = sy; Q[head].step = 0;//队列清空，加入初始点
    for (i = 1;i <= 8;i++)
        for (j = 1;j <= 8;j++)  visit[i][j] = 19930703;//初始时visit内的元素为一个足够大的值（说明还没有到过）
    visit[sx][sy] = 0;//到达初始位置花费的步数为0
    while (head <= tail)//如果队列非空
    {
        now = Q[head];  head++;//取出队首
        if (now.x == tx && now.y == ty) return now.step;//如果已经到达终点那么就返回最小步数，退出BFS函数
        for (i = 0;i < 8;i++)//对8个方向扩展
        if (now.x+step[i][0] >= 1 && now.x+step[i][0] <= 8)
        if (now.y+step[i][1] >= 1 && now.y+step[i][1] <= 8)//先判断坐标是否还在棋盘内
        if (visit[now.x+step[i][0]][now.y+step[i][1]] > now.step+1)//再判断一下是否在此之前已经到达过
            tail++, Q[tail].x = now.x+step[i][0], Q[tail].y = now.y+step[i][1], Q[tail].step = now.step+1;//加入队尾
    }
}

int main()
{
    char sa[3],sb[3];
    while (scanf("%s%s",sa,sb) != EOF)
    {
        printf("To get from %s to %s takes %d knight moves.\n",sa,sb,BFS(sa[0]-'a'+1,sa[1]-'0',sb[0]-'a'+1,sb[1]-'0'));
    }
}
