#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;

struct node
{
    int a[3];
    friend bool operator< (node a, node t)
    {
        if (a.a[0] == t.a[0])
        {
            if (a.a[1] == t.a[1])
                return a.a[2] < t.a[2];
            return a.a[1] < t.a[1];
        }
        return a.a[0] < t.a[0];
    }
}s,t,res[3];

set<node> hash;
set<node>::iterator it;
deque<node> Q;

node getnode(int a,int b,int c)
{
    node res;
    res.a[0] = a;res.a[1] = b;res.a[2] = c;
    return res;
}

bool equal(node a,node b)
{
    return (a.a[0] == b.a[0] && a.a[1] == b.a[1] && a.a[2] == b.a[2]);
}

const int step[3][3] = {{0,1,2},{2,0,1},{1,0,2}};

bool BFS()
{
    hash.clear();
    Q.clear();
    Q.push_back(t);
    hash.insert(t);
    node now,updata;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        for (int i = 0;i < 3;i++)
        if (equal(now,res[i]))   return true;
        for (int i = 0;i < 3;i++)
        if (now.a[step[i][0]] == now.a[step[i][1]]+now.a[step[i][2]]-1)
        {
            int ta,tb,tc;
            ta = now.a[step[i][1]];
            tb = now.a[step[i][2]];
            if (ta-tb+1 > 0)
            {
                tc = ta-tb+1;
                updata.a[0] = ta;
                updata.a[1] = tb;
                updata.a[2] = tc;
                sort(updata.a,updata.a+3);
                it = hash.find(updata);
                if (it == hash.end())
                {
                    hash.insert(updata);
                    Q.push_back(updata);
                }
            }
            if (tb-ta+1 > 0)
            {
                tc = tb-ta+1;
                updata.a[0] = ta;
                updata.a[1] = tb;
                updata.a[2] = tc;
                sort(updata.a,updata.a+3);
                it = hash.find(updata);
                if (it == hash.end())
                {
                    hash.insert(updata);
                    Q.push_back(updata);
                }
            }
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d%d%d%d%d",&t.a[0],&t.a[1],&t.a[2],&s.a[0],&s.a[1],&s.a[2]);
        sort(s.a,s.a+3);
        sort(t.a,t.a+3);
        for (int i = 0;i < 3;i++)
        {
            res[i].a[0] = s.a[step[i][1]];
            res[i].a[1] = s.a[step[i][2]];
            res[i].a[2] = s.a[step[i][1]]+s.a[step[i][2]]-1;
            sort(res[i].a,res[i].a+3);
        }
        if (BFS() == true)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
