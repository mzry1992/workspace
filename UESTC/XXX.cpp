#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int map[100][100];
int visit[10000];
bool use[1000];
deque<int> Q;

int SPFA(int s,int t)
{
    Q.clear();
    Q.push_back(s);
    memset(visit,127,sizeof(visit));
    memset(use,false,sizeof(use));
    use[s] = true;
    visit[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop_front();
        use[now] = false;
        if (now == t)   return visit[now];
        for (int i = 1;i <= 100;i++)
        if (visit[now]+map[now][i] < visit[i])
        {
            visit[i] = visit[now]+map[now][i];
            if (use[i] == false)
            {
                Q.push_back(i);
            }
        }
    }
}

int main()
{
    DFS(5);
}
