#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char mp[5][10];
int x[12];

/*
 012345678
0....x....
1.A.I.D.x.
2..x...x..
3.x.x.x.x.
4....x....
*/

const int pos[12][2] ={{0,4},{1,1},{1,3},{1,5},{1,7},{2,2},{2,6},{3,1},{3,3},{3,5},{3,7},{4,4}};
bool hasres;

void DFS(int now,int used)
{
    if (hasres == true) return;
    if (now == 5)
        if (x[1]+x[2]+x[3]+x[4] != 26)  return;
    if (now == 8)
        if (x[0]+x[2]+x[5]+x[7] != 26)  return;
    if (now == 11)
        if (x[7]+x[8]+x[9]+x[10] != 26) return;
    if (now == 11)
        if (x[0]+x[3]+x[6]+x[10] != 26) return;
    if (now == 12)
        if (x[1]+x[5]+x[8]+x[11] != 26) return;
    if (now == 12)
        if (x[4]+x[6]+x[9]+x[11] != 26) return;
    if (now == 12)
    {
        hasres = true;
        for (int i = 0;i < 12;i++)
            mp[pos[i][0]][pos[i][1]] = x[i]+'A'-1;
        for (int i = 0;i < 5;i++)
            printf("%s\n",mp[i]);
        return;
    }
    if (x[now] != 0)
    {
        if (((used>>(x[now]-1))&1) == 0)
            DFS(now+1,used|(1<<(x[now]-1)));
        return;
    }
    for (int i = 0;i < 12;i++)
        if (((used>>i)&1) == 0)
        {
            x[now] = i+1;
            DFS(now+1,used|(1<<(x[now]-1)));
            x[now] = 0;
        }
}

int main()
{
    while (scanf("%s",mp[0]) != EOF)
    {
        for (int i = 1;i < 5;i++)
            scanf("%s",mp[i]);
        memset(x,0,sizeof(x));
        for (int i = 0;i < 12;i++)
            if (mp[pos[i][0]][pos[i][1]] != 'x')
                x[i] = mp[pos[i][0]][pos[i][1]]-'A'+1;
        hasres = false;
        DFS(0,0);
    }
    return 0;
}
