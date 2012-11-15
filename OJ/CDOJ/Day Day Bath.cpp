#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int tim;
priority_queue< int, vector<int>, greater<int> > Q;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        while (!Q.empty())
            Q.pop();
        for (int i = 1;i <= m;i++)
            Q.push(0);
        int res = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&tim);
            int now = Q.top();
            Q.pop();
            Q.push(now+tim);
        }
        res = Q.top();
        if (res > 600)  res = -1;
        printf("%d\n",res);
    }
}
