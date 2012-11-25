#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int step[4] = {1,7,30,365};
const int mid = 365*30;
int l,r,dl[mid*2+1],dr[mid*2+1];

int solve(int l,int r)
{
    memset(dl,63,sizeof(dl));
    memset(dr,63,sizeof(dr));
    queue<int> Q;

    dl[mid] = 0;
    Q.push(mid);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        int nx = l+now-mid;
        if (nx < 1) continue;

        for (int i = 0;i < 4;i++)
        {
            if (nx-step[i] >= 1 && now-step[i] >= 0 && (nx-1)%step[i] == 0)
                if (dl[now-step[i]] > dl[now]+1)
                {
                    dl[now-step[i]] = dl[now]+1;
                    Q.push(now-step[i]);
                }

            if (now+step[i] < mid*2+1 && (nx-1)%step[i] == 0)
                if (dl[now+step[i]] > dl[now]+1)
                {
                    dl[now+step[i]] = dl[now]+1;
                    Q.push(now+step[i]);
                }
        }
    }

    dr[mid] = 0;
    Q.push(mid);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();

        int nx = r+now-mid;
        if (nx < 1) continue;

        for (int i = 0;i < 4;i++)
        {
            if (nx-step[i]+1 >= 1 && now-step[i] >= 0 && nx%step[i] == 0)
                if (dr[now-step[i]] > dr[now]+1)
                {
                    dr[now-step[i]] = dr[now]+1;
                    Q.push(now-step[i]);
                }

            if (now+step[i] < mid*2+1 && nx%step[i] == 0)
                if (dr[now+step[i]] > dr[now]+1)
                {
                    dr[now+step[i]] = dr[now]+1;
                    Q.push(now+step[i]);
                }
        }
    }

    int res = 2147483647;
    for (int i = max(0,r-mid);i < l+mid;i++)
    {
        /*if (dl[mid+i+1-l]+dr[mid+i-r] == 1)
        {
            printf("%d %d %d\n",i,dl[mid+i+1-l],dr[mid+i-r]);
        }*/
        res = min(res,dl[mid+i+1-l]+dr[mid+i-r]);
    }
    //cout << l << ' ' << r << ' ' << res << endl;
    return res;
}

int pl,pr;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&l,&r);
        int res;
        if (l+mid >= r+1)
            res = solve(l,r);
        else
        {
            for (pl = l+1;pl%365 != 1;pl++);
            for (pr = r+1;pr%365 != 0;pr++);

            res = solve(l,pl-1)+solve(r+1,pr)+(pr-pl+1)/365;
            /*if (pl-365 > 0)
                res = min(res,solve(pl-365,l-1)+solve(r+1,pr)+(pr-pl+366)/365);
            if (pl-365 > 0 && pr-364 > 0)
                res = min(res,solve(pl-365,l-1)+solve(pr-364,r)+(pr-pl+1)/365);*/
            if (pr-364 > 0)
                res = min(res,solve(l,pl-1)+solve(pr-364,r)+(pr-pl+1-365)/365);

        }

        printf("Case #%d: %d\n",ft,res);
    }
	return 0;
}
