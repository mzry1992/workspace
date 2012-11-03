#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w,h;
int map[300][300];

int main()
{
    //freopen("out.txt","r",stdin);
    while (scanf("%d%d",&w,&h) != EOF)
    {
        for (int i = 0;i < h;i++)
        for (int j = 0;j < w;j++)
            scanf("%d",&map[i][j]);
        int m;
        scanf("%d",&m);
        for (int i = 1;i <= m;i++)
        {
            int x1,x2,y1,y2,ty;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&ty);
            if (ty == 1)
            {
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    map[x][y] = -map[x][y];
            }
            else if (ty == 2)
            {
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    map[x][y] += 1;
            }
            else if (ty == 3)
            {
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    map[x][y] -= 1;
            }
            else if (ty == 4)
            {
                int tmap[300][300];
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    tmap[x][y] = map[x1+x2-x][y];
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    map[x][y] = tmap[x][y];
            }
            else if (ty == 5)
            {
                int tmap[300][300];
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    tmap[x][y] = map[x][y1+y2-y];
                for (int x = x1;x <= x2;x++)
                for (int y = y1;y <= y2;y++)
                    map[x][y] = tmap[x][y];
            }
            for (int i = 0;i < w;i++)
            {
                for (int j = 0;j < h;j++)
                    cout << map[i][j] << ' ' ;
                cout << endl;
            }
        }
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",map[x][y]);
    }
}
