#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char gr[10][10];
int n,q;
int W[10];
char oth;
int c[6][1010][1010];

bool check(int depth,int x,int y)
{
    if (c[depth][x][y] != 0)
        return (c[depth][x][y]-1);
    int ax,ay,bx,by;
    if (depth == 1)
    {
        c[depth][x][y] = (gr[x][y] != ' ')+1;
        return c[depth][x][y]-1;
    }
    ax = x/W[depth-1];
    ay = y/W[depth-1];
    bx = x%W[depth-1];
    by = y%W[depth-1];
    if (gr[ax][ay] == ' ')
    {
        c[depth][x][y] = 1;
        return false;
    }
    if (depth < q)
    {
        c[depth][x][y] = check(depth-1,bx,by)+1;
        return (c[depth][x][y]-1);
    }
    return check(depth-1,bx,by);
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        gets(gr[0]);
        for (int i = 0;i < n;i++)
            gets(gr[i]);
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (gr[i][j] != ' ')
            oth = gr[i][j];
        scanf("%d",&q);
        W[0] = 1;
        for (int i = 1;i <= q;i++)
            W[i] = W[i-1]*n;
        memset(c,0,sizeof(c));
        for (int i = 0;i < W[q];i++)
        {
            for (int j = 0;j < W[q];j++)
            {
                if (check(q,i,j))
                    putchar(oth);
                else
                    putchar(' ');
            }
            puts("");
        }
    }
}
