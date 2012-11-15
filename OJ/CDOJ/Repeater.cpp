#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool map[5000][5000];
char gr[10][10];
int n,q;
char oth;
int W[10];

void cover(int depth,int x,int y,int nx,int ny)
{
    if (depth == 0)
    {
        map[x][y] = true;
        return;
    }
    for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
    if (gr[i][j] != ' ')
    {
        oth = gr[i][j];
        cover(depth-1,x+i*W[depth-1],y+j*W[depth-1],i,j);
    }
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
        scanf("%d",&q);
        if (q == 1)
        {
            for (int i = 0;i < n;i++)
                puts(gr[i]);
            continue;
        }
        memset(map,false,sizeof(map));
        W[0] = 1;
        for (int i = 1;i <= q;i++)
            W[i] = W[i-1]*n;
        cover(q-1,0,0,0,0);
        for (int i = 0;i < W[q];i++)
        {
            for (int j = 0;j < W[q];j++)
            {
                int tx,ty;
                tx = i/W[q-1];
                ty = j/W[q-1];
                if (gr[tx][ty] == ' ')
                    putchar(' ');
                else
                {
                    if (map[i%W[q-1]][j%W[q-1]] == true)
                        putchar(oth);
                    else
                        putchar(' ');
                }
            }
            puts("");
        }
    }
}
