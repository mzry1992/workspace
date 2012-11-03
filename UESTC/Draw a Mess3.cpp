#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,q,mp[200][200];
char com[50];
int xc,yc,l,r,w,c;

void Circle()
{
    scanf("%d%d%d%d",&xc,&yc,&r,&c);
    for (int x = 0;x < n;x++)
        for (int y = 0;y < m;y++)
            if ((x - xc)*(x-xc) + (y - yc)*(y-yc) <= r*r)
                mp[x][y] = c;
}

int abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

void Diamond()
{
    scanf("%d%d%d%d",&xc,&yc,&r,&c);
    for (int x = 0;x < n;x++)
        for (int y = 0;y < m;y++)
            if (abs(x - xc) + abs(y - yc) <= r)
                mp[x][y] = c;
}

void Rectangle()
{
    scanf("%d%d%d%d%d",&xc,&yc,&l,&w,&c);
    for (int x = 0;x < n;x++)
        for (int y = 0;y < m;y++)
        // xc ¡Ü x ¡Ü xc+l-1, yc ¡Ü y ¡Ü yc+w-1
        if (xc <= x && x <= xc+l-1 && yc <= y && y <= yc+w-1)
                mp[x][y] = c;
}

void Triangle()
{
    scanf("%d%d%d%d",&xc,&yc,&w,&c);
    for (int x = 0;x < n;x++)
        for (int y = 0;y < m;y++)
            if (abs(x-xc) <= (w-1)/2)
                if (y >= yc)
                    if (y-yc <= (w-1)/2-abs(x-xc))
                        mp[x][y] = c;
}

int res[9];

int main()
{
    while (scanf("%d%d%d",&n,&m,&q) != EOF)
    {
        memset(mp,0,sizeof(mp));
        for (int i = 0;i < q;i++)
        {
            scanf("%s",com);
            if (com[0] == 'C')
                Circle();
            else if (com[0] == 'D')
                Diamond();
            else if (com[0] == 'R')
                Rectangle();
            else if (com[0] == 'T')
                Triangle();
        }
        memset(res,0,sizeof(res));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (mp[i][j] > 0)
                    res[mp[i][j]-1]++;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                printf("%d",mp[i][j]);
            printf("\n");
        }
        for (int i = 0;i < 9;i++)
            cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}
