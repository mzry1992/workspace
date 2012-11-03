#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,s,t,mp[100][100],len[100*100],tot,dis[100];
bool inq[100];

int main()
{
    int tcas;
    scanf("%d",&tcas);
    for (int ft = 1;ft <= tcas;ft++)
    {
        scanf("%d%d%d",&n,&s,&t);
        s--;
        t--;
        for (int i = 0;i < n-1;i++)
            for (int j = 0;j < n-1-i;j++)
            {
                scanf("%d",&len[tot]);
                mp[i][i+1+j] = mp[i+1+j][i] = len[tot];
                tot++;
            }
        sort(len,len+tot);
        tot = unique(len,len+tot)-len;
        double res = 0;
        int minlen,maxdis;
        for (int ti = tot-1;ti >= 0;ti--)
        {
            minlen = len[ti];
            //minlen/dis > res
            //minlen/res > dis
            if (res == 0)
                maxdis = n*n;
            else
                maxdis = (int)((double)minlen/res)+1;

            for (int i = 0;i < n;i++)
            {
                dis[i] = 19921005;
                inq[i] = false;
            }
            queue<int> Q;
            dis[s] = 0;
            inq[s] = true;
            Q.push(s);
            while (!Q.empty())
            {
                int now = Q.front();
                Q.pop();
                inq[now] = false;
                if (dis[now] > maxdis)  continue;
                for (int i = 0;i < n;i++)
                    if (mp[now][i] >= minlen)
                        if (dis[i] > dis[now]+1)
                        {
                            dis[i] = dis[now]+1;
                            if (inq[i] == false)
                            {
                                inq[i] = true;
                                Q.push(i);
                            }
                        }
            }
            if (dis[t] < maxdis)
                res = (double)minlen/dis[t];
        }
        printf("%.2f\n",res);
    }
    return 0;
}
