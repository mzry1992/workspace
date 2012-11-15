#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,id;
    Point() {}
    Point(int _x,int _y,int _id)
    {
        x = _x;
        y = _y;
        id = _id;
    }
};

int n,first;
Point p[300],step[3];

const char s[2][10] = {"white","black"};

int mp[15][15];

const int dx[8] = {-1,-1,0,1,1,1,0,-1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};

int cc[8],tx,ty;

bool judge(int x,int y)
{
    for (int i = 0; i < 8; i++)
        cc[i] = 1;
    for (int i = 0; i < 8; i++)
    {
        tx = x;
        ty = y;
        while (true)
        {
            tx += dx[i];
            ty += dy[i];
            if (tx < 0 || tx > 14 || ty < 0 || ty > 14) break;
            if (mp[tx][ty] != mp[x][y]) break;
            cc[i]++;
        }
    }
    for (int i = 0; i < 4; i++)
        if (cc[i]+cc[i+4]-1 >= 5)
            return true;
    return false;
}

bool check(int x,int y)
{
    if (mp[x][y] != 2)  return false;
    for (int i = 0; i < 8; i++)
        for (int j = 1; j <= 1; j++)
        {
            tx = x+j*dx[i];
            ty = y+j*dy[i];
            if (tx < 0 || tx > 14 || ty < 0 || ty > 14) continue;
            if (mp[tx][ty] != 2)
                return true;
        }
    return false;
}

int DFS(int deep,int now)
{
    int ext = 2;
    for (int wx = 0; wx < 15; wx++)
        for (int wy = 0; wy < 15; wy++)
            if (check(wx,wy) == true)
            {
                mp[wx][wy] = now;
                if (judge(wx,wy) == true)
                {
                    mp[wx][wy] = 2;
                    return 1;
                }
                else
                {
                    int tmp;
                    if (deep == 2)  tmp = 0;
                    else
                        tmp = DFS(deep+1,1-now);
                    if (tmp == 2)
                    {
                        mp[wx][wy] = 2;
                        return 1;
                    }
                    else if (ext == 2 && tmp == 0)
                        ext = 0;
                }
                mp[wx][wy] = 2;
            }
    return ext;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        int countw,countb;
        countw = countb = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].id);
            if (p[i].id == 0)   countw++;
            else
                countb++;
        }
        if (countb == countw)
            first = 1;
        else if (countb == countw+1)
            first = 0;
        else
        {
            puts("Invalid.");
            continue;
        }
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                mp[i][j] = 2;
        for (int i = 0; i < n; i++)
            mp[p[i].x][p[i].y] = p[i].id;
        int ans = 2;
        for (int wx = 0; wx < 15 && ans != 1; wx++)
            for (int wy = 0; wy < 15 && ans != 1; wy++)
            {
                if (check(wx,wy) == true)
                {
                    mp[wx][wy] = first;
                    if(judge(wx,wy))
                    {
                        printf("Place %s at (%d,%d) to win in 1 move.\n",s[first],wx,wy);
                        ans = 1;
                        continue;
                    }
                    mp[wx][wy] = 2;
                }
            }
        if (ans == 2)
        {
            for (int wx = 0; wx < 15 && ans != 1; wx++)
                for (int wy = 0; wy < 15 && ans != 1; wy++)
                {
                    if (check(wx,wy) == true)
                    {
                        mp[wx][wy] = first;
                        int tmp = DFS(1,1-first);
                        if (tmp == 2)
                        {
                            printf("Place %s at (%d,%d) to win in 3 moves.\n",s[first],wx,wy);
                            ans = 1;
                            continue;
                        }
                        else if (ans == 2 && tmp == 0)
                            ans = 0;
                        mp[wx][wy] = 2;
                    }
                }
        }
        if (ans == 0)
            puts("Cannot win in 3 moves.");
        else if (ans == 2)
            puts("Lose in 2 moves.");
    }
    return 0;
}
