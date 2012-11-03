#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

int r,c,mp[510][510],tmp,en,ex,curx,cury,curf,nexf;
bool visit[510][510],visit2[510][510][4],flag;

void setwall(int x,int y,int f)
{
    mp[x][y] = mp[x][y]|(1<<f);
}

int getwall(int x,int y,int f)
{
    return ((mp[x][y]>>f)&1);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d%d",&r,&c,&en,&ex);
        for (int i = 0;i < r;i++)
            for (int j = 0;j < c;j++)
                mp[i][j] = 0;
        for (int i = 0;i < r;i++)
        {
            setwall(i,0,1);
            setwall(i,c-1,3);
        }
        for (int i = 0;i < c;i++)
        {
            if (i != en)
                setwall(0,i,2);
            if (i != ex)
                setwall(r-1,i,0);
        }
        for (int i = 0;i < 2*r-1;i++)
        {
            if (i%2 == 0)
            {
                for (int j = 0;j < c-1;j++)
                {
                    scanf("%d",&tmp);
                    if (tmp == 1)
                    {
                        setwall(i/2,j,3);
                        setwall(i/2,j+1,1);
                    }
                }
            }
            else
            {
                for (int j = 0;j < c;j++)
                {
                    scanf("%d",&tmp);
                    if (tmp == 1)
                    {
                        setwall(i/2,j,0);
                        setwall(i/2+1,j,2);
                    }
                }
            }
        }
        curx = 0;
        cury = en;
        curf = 0;
        memset(visit,false,sizeof(visit));
        memset(visit2,false,sizeof(visit2));
        flag = true;
        while (true)
        {
            if (curx == r && cury == ex && curf == 0)  break;
            if (visit2[curx][cury][curf] == true)
            {
                flag = false;
                break;
            }
            visit2[curx][cury][curf] = visit[curx][cury] = true;
            for (int i = 1;i > -3;i--)
            {
                nexf = (curf+i+4)%4;
                if (getwall(curx,cury,nexf) == 0)
                {
                    curx += step[nexf][0];
                    cury += step[nexf][1];
                    curf = nexf;
                    break;
                }
            }
        }
        if (flag == true)
        {
            curx = r-1;
            cury = ex;
            curf = 2;
            memset(visit2,false,sizeof(visit2));
            while (true)
            {
                if (curx == -1 && cury == en && curf == 2)  break;
                if (visit2[curx][cury][curf] == true)
                {
                    flag = false;
                    break;
                }
                visit2[curx][cury][curf] = visit[curx][cury] = true;
                for (int i = 1;i > -3;i--)
                {
                    nexf = (curf+i+4)%4;
                    if (getwall(curx,cury,nexf) == 0)
                    {
                        curx += step[nexf][0];
                        cury += step[nexf][1];
                        curf = nexf;
                        break;
                    }
                }
            }
        }
        if (flag == true)
        {
            for (int i = 0;i < r && flag == true;i++)
                for (int j = 0;j < c;j++)
                    if (visit[i][j] == false)
                    {
                        flag = false;
                        break;
                    }
        }
        if (flag == true)   printf("YES\n");
        else printf("NO\n");
    }
}
