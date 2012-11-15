#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

int n;
char map[10][50][50];
struct point2
{
    int x,y;
};
struct point3
{
    int x,y,z;
};
const string sfx = "FBLRUD";
const int fys[6] = {0,3,1,2,4,5};
struct sta
{
    point3 pos;
    string step;
};
deque<sta> Q;
bool visit[100][100][100];

point2 getpoint(point3 a,int fx)
{
    point2 res;
    if (fx == 0)
    {
        res.y = n-a.x-1;
        res.x = n-a.z-1;
    }
    else if (fx == 1)
    {
        res.y = a.x;
        res.x = n-a.z-1;
    }
    else if (fx == 2)
    {
        res.y = n-a.y-1;
        res.x = n-a.z-1;
    }
    else if (fx == 3)
    {
        res.y = a.y;
        res.x = n-a.z-1;
    }
    else if (fx == 4)
    {
        res.y = n-a.x-1;
        res.x = n-a.y-1;
    }
    else if (fx == 5)
    {
        res.x = a.y;
        res.y = n-a.x-1;
    }
    return res;
}

sta getsta(point3 pos,string step)
{
    sta res;
    res.pos.x = pos.x;
    res.pos.y = pos.y;
    res.pos.z = pos.z;
    res.step = step;
    return res;
}

point3 getpoint3(int x,int y,int z)
{
    point3 res;
    res.x = x;
    res.y = y;
    res.z = z;
    return res;
}

const int step[6][3] = {{0,-1,0},{0,1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1}};

string BFS()
{
    memset(visit,false,sizeof(visit));
    visit[1][1][1] = true;
    Q.clear();
    Q.push_back(getsta(getpoint3(1,1,1),""));
    while (!Q.empty())
    {
        sta now = Q.front();
        Q.pop_front();
        if (now.pos.x == n-2 && now.pos.y == n-2 && now.pos.z == n-2)   return now.step;
        for (int i = 0;i < 6;i++)
        {
            sta updata;
            updata.step = now.step+sfx[i];
            updata.pos.x = now.pos.x+step[i][0];
            updata.pos.y = now.pos.y+step[i][1];
            updata.pos.z = now.pos.z+step[i][2];
            if (updata.pos.x < 0)   continue;
            if (updata.pos.y < 0)   continue;
            if (updata.pos.z < 0)   continue;
            if (updata.pos.x >= n)  continue;
            if (updata.pos.y >= n)  continue;
            if (updata.pos.z >= n)  continue;
            if (visit[updata.pos.x][updata.pos.y][updata.pos.z] == false)
            {
                bool flag = true;
                for (int j = 0;j < 6;j++)
                {
                    point2 cur = getpoint(updata.pos,j);
                    if (map[j][cur.x][cur.y] != ' ')
                    {
                        flag = false;
                    }
                }
                if (flag == false)  continue;
                visit[updata.pos.x][updata.pos.y][updata.pos.z] = true;
                Q.push_back(updata);
            }
        }
    }
    return "";
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        gets(map[0][0]);
        for (int i = 0;i < 6;i++)
        {
            for (int j = 0;j < n;j++)
                gets(map[fys[i]][j]);
        }
        string res = BFS();
        printf("%s\n",res.c_str());
    }
}
