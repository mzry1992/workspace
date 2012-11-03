#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int H,W,L,K,R,N;
int map[30][30];
int b[10][2];
bool r[10][10];
struct state
{
    int b[10][2];
    int step;
    int tot;
    int eat;
};

int BFS()
{
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d%d%d%d%d",&H,&W,&L,&K,&R,&N);
        memset(map,0,sizeof(map));
        for (int i = 1;i <= L;i++)
            scanf("%d%d",&b[i][0],&b[i][1]);
        for (int i = 1;i <= K;i++)
        {
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            map[tx][ty] = 3;
        }
        memset(r,false,sizeof(r));
        for (int i = 1;i <= R;i++)
        {
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            r[tx][ty] = true;
        }
        for (int i = 1;i <= N;i++)
        {
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            map[tx][ty] = 1;
        }
        int res = BFS();
        printf("%d\n",res);
    }
}
