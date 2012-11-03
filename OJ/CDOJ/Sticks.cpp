#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[64],sum,tot,len,maxlen,lastlen[64];
bool used[64];

bool cmp(const int& a,const int& b)
{
    return a > b;
}

bool DFS(int now,int nowlen,int nowc)
{
    if (now == tot) return true;
    if (nowlen == len)
        return DFS(now+1,0,0);
    if (nowc == n)  return false;

    int lastno = 0;
    for (int i = nowc;i < n;i++)
        if (used[i] == false)
        {
            if (a[i] == lastno) continue;//¼ôÖ¦ËÄ
            if (a[i]+nowlen > len)  continue;
            if (nowlen+lastlen[i] < len) break;//¼ôÖ¦¶þ

            used[i] = true;
            bool ret = DFS(now,nowlen+a[i],i+1);
            used[i] = false;

            if (nowlen+a[i] == len) return ret;//¼ôÖ¦Èý

            if (ret == true)    return true;
            else
            {
                if (nowlen == 0)    return false;//¼ôÖ¦Ò»
                lastno = a[i];
            }
        }

    return false;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        sum = maxlen = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
            maxlen = max(maxlen,a[i]);
        }
        sort(a,a+n,cmp);
        lastlen[n-1] = a[n-1];
        for (int i = n-2;i >= 0;i--)
            lastlen[i] = lastlen[i+1]+a[i];
        for (len = maxlen;len <= sum;len++)
            if (sum%len == 0)
            {
                tot = sum/len;
                for (int i = 0;i < n;i++)
                    used[i] = false;
                if (DFS(0,0,0) == true)
                {
                    printf("%d\n",len);
                    break;
                }
            }
    }
	return 0;
}
