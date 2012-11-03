#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int mid = 365*365;
const int step[4] = {1,7,30,365};
int l,r,disl[2*mid+1],disr[2*mid+1];

void solve(int pos,int dis[2*mid+1])
{
    int now,id;
    dis[mid] = 0;
    queue<int> Q;
    Q.push(pos);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();

        id = mid+now-pos;

        if (now < 1)    break;

        /*if (now >= 10 && now <= 31)
            printf("%d %d\n",now,dis[id]);*/
        for (int i = 0; i < 4; i++)
        {
            if (id-step[i] >= 0 && now-step[i] >= 1 && (now-1)%step[i] == 0)
                if (dis[id-step[i]] > dis[id]+1)
                {
                    dis[id-step[i]] = dis[id]+1;
                    Q.push(now-step[i]);
                }
            if (id+step[i] < 2*mid+1 && (now+step[i]-1)%step[i] == 0)
                if (dis[id+step[i]] > dis[id]+1)
                {
                    dis[id+step[i]] = dis[id]+1;
                    Q.push(now+step[i]);
                }
        }
    }

    /*for (int i = x-20;i < x+25;i++)
        cout << dis[i] << ' ';
    cout << endl;*/
}

int res,pl,pr,kl,kr,il,ir;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&l,&r);
        memset(disr,63,sizeof(disl));
        memset(disl,63,sizeof(disr));
        solve(l,disl);
        solve(r,disr);

        cout << disr[mid+l-1-r] << endl;
        res = disl[mid+r+1-l];

        printf("Case #%d: %d\n",ft,res);

    }
    return 0;
}
