#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    char mp[6][6];
    int step;
};

int n,xa,xb,ya,yb,m;
char mp[6][6];
queue<node> Q;
node now,tmp;
bool hash[1007][713];

void push(node now)
{
    int key0 = 0,key1 = 0;
    for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
        {
            key0 = (key0*20+(now.mp[i][j] == ' ')?0:(now.mp[i][j]-'a'+1))%1007;
            key1 = (key1*19+(now.mp[i][j] == ' ')?0:(now.mp[i][j]-'a'+1))%713;
        }
    if (hash[key0][key1] == true)   return;
    hash[key0][key1] = true;
    Q.push(now);
}

int BFS()
{
    while (!Q.empty())  Q.pop();
    for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
            now.mp[i][j] = mp[i][j];
    now.step = 0;
    push(now);
    memset(hash,false,sizeof(hash));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        //return a res
        for (int j = 0;j < 6;j++)
            if (now.mp[2][j] == 'A'+m)
            {
                bool flag = true;
                for (int k = j;k < 6;k++)
                    if (now.mp[2][k] != now.mp[2][j] || now.mp[2][k] != ' ')
                    {
                        flag = false;
                        break;
                    }
                if (flag == true)
                    return now.step;
                break;
            }
        //bfs!
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 6;j++)
                if (now.mp[i][j] != ' ')
                {
                }
    }
    return 0;
}

int main()
{
    while (scanf("%d",&n) != 0)
    {
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 6;j++)
                mp[i][j] = ' ';
        for (int i = 0;i < n;i++)
        {
            scanf("%*d%d%d%d%d",&xa,&ya,&xb,&yb);
            for (int i = xa;i <= xb;i++)
                for (int j = ya;j <= yb;j++)
                    mp[i][j] = 'A'+i;
        }
        scanf("%d",&m);
        printf("%d\n",BFS());
    }
    return 0;
}
