#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m,len;
bool visit[10][21];
char s[10][21],tmp[201];
int tree[200*8*200][26],L,fa[200*8*200];
char cha[200*200*8];
int tim[200*8*200];

int newnode()
{
    for (int i = 0; i < 26; i++)
        tree[L][i] = 0;
    tim[L] = 0;
    return L++;
}

int reslen,pos;

void Gao(int now,int x,int y,int dx,int dy)
{
    if (visit[x][y] == true)
        return;
    if (tree[now][s[x][y]-'A'] == 0)
    {
        tree[now][s[x][y]-'A'] = newnode();
        fa[L-1]=now;
        cha[L-1]=s[x][y];
    }
    tim[now]++;
    tmp[len++] = s[x][y];
    visit[x][y] = true;
    Gao(tree[now][s[x][y]-'A'],(x+dx+n)%n,(y+dy+m)%m,dx,dy);
}

void DFS(int now,int dep)
{
    if (tim[now]==1)
        return ;
    if (dep>reslen)
    {
        reslen=dep;
        pos=now;
    }
    for (int i=0; i<26; i++)
        if (tree[now][i])
            DFS(tree[now][i],dep+1);
}

void print(int x)
{
    if (x)
    {
        print(fa[x]);
        putchar(cha[x]);
    }
}
int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < n; i++)
            scanf("%s",s[i]);
        L=0;
        newnode();
        reslen = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 8; k++)
                {
                    memset(visit,false,sizeof(visit));
                    len = 0;
                    Gao(0,i,j,step[k][0],step[k][1]);
                }
        DFS(0,0);
        if (reslen < 2)
            putchar('0');
        else
            print(pos);
        puts("");
    }
    return 0;
}
