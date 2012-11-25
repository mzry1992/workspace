#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ff[1<<6];
int tot;

void DFS(int now,int tree)
{
    if (((tree>>now)&1) == 0)   return;
    ff[now] = true;
    tot++;
    DFS(now*2,tree);
    DFS(now*2+1,tree);
}

bool check(int tree)
{
    memset(ff,false,sizeof(ff));
    tot = 0;
    DFS(0,tree);
    return tot == 5;
}

int main()
{
    for (int i = 0;i < 1<<6;i++)
        if (check(i) == true)
        {

        }
    return 0;
}
