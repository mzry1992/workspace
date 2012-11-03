#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n,m;
char tmp[9];
vector<vector<char> > mp;

struct Node
{
    vector<vector<char> > mp;
    int step;
    bool operator < (const Node& b)const
    {
        if (step == b.step)
            return mp < b.mp;
        return step < b.step;
    }
};

set<Node> hash;
queue<Node> Q;

int BFS()
{
    Node now;
    now.mp = mp;
    now.step = 0;
    hash.clear();
    hash.insert(now);
    while (!Q.empty())  Q.pop();
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.front();
        for (int i = 0;i < )
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        mp.resize(n);
        for (int i = 0;i < n;i++)
            mp[i].resize(m);
        gets(tmp);
        for (int i = 0;i < n;i++)
        {
            gets(tmp);
            for (int j = 0;j < m;j++)
                mp[i][j] = tmp[j];
        }
        printf("%d\n",BFS());
    }
	return 0;
}
