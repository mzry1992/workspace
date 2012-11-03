#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int to[8][3] = {{5,-1,0},{4,-1,0},
                      {7,0,1},{6,0,1},
                      {1,1,0},{0,1,0},
                      {3,0,-1},{2,0,-1}};
int mp[30][30][8];
int n,m;
char buf[10000],con[100];
int respos,resport;

void DFS(int a,int x,int y)
{
    int na = mp[x][y][a];
    int ma = to[na][0];
    int tx = x+to[na][1];
    int ty = y+to[na][2];

    if (tx < 0 || tx >= n || ty < 0 || ty >= m)
    {
        respos = x*m+y;
        resport = na;
        return;
    }

    DFS(ma,tx,ty);
}

int main()
{
    int cas = 1;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(mp,-1,sizeof(mp));

        gets(buf);
        int id,pos,npos;
        while (true)
        {
            pos = 0;
            gets(buf);
            sscanf(buf+pos,"%d%n",&id,&npos);
            pos += npos;
            if (id == 0)    break;

            id--;
            int x = id/m;
            int y = id%m;

            while (sscanf(buf+pos,"%s%n",con,&npos) != EOF)
            {
                mp[x][y][con[0]-'A'] = con[1]-'A';
                mp[x][y][con[1]-'A'] = con[0]-'A';
                pos += npos;
            }
        }
        gets(buf);
        pos = 0;
        if (cas > 1)
            puts("");
        printf("Board %d:\n",cas++);
        while (sscanf(buf+pos,"%s%n",con,&npos) != EOF)
        {
            int tl = strlen(con);
            int sp = con[tl-1]-'A';
            con[tl-1] = 0;
            sscanf(con,"%d",&id);
            id--;
            int x = id/m;
            int y = id%m;

            DFS(sp,x,y);
            printf("%d%c is connected to %d%c\n",id+1,sp+'A',respos+1,resport+'A');

            pos += npos;
        }
    }
    return 0;
}
