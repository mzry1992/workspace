#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int step[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
bool visit[30][30];
int n,m;
bool hasans;

void DFS(int x,int y,string s)
{
    s = s+(char)(y+'A'-1)+(char)(x+'0');
    //cout << x << ' ' << y << ' ' << s << endl;
    if (hasans == true) return;
    if (x <= 0)  return; if (x > n) return;
    if (y <= 0)  return; if (y > m) return;
    visit[x][y] = true;
    if (s.size() == 2*n*m)
    {
        printf("%s\n",s.c_str());
        hasans = true;
        return;
    }
    for (int i = 0;i < 8;i++)
    {
        int tx = x+step[i][0];
        int ty = y+step[i][1];
        if (visit[tx][ty] == false)
            DFS(tx,ty,s);
    }
    visit[x][y] = false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",ft);
        memset(visit,false,sizeof(visit));
        hasans = false;
        DFS(1,1,"");
        if (hasans == false)
            printf("impossible\n");
    }
}
