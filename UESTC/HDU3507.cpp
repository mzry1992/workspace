#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m,head,tail;
long long a,s[500010],Q[500010],dp[500010];

inline long long X(int i)
{
    return 2*s[i];
}

inline long long Y(int i)
{
    return dp[i]+s[i]*s[i];
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        s[0] = head = tail = dp[0] = 0;
        Q[tail++] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%I64d",&a);
            s[i] = s[i-1]+a;
            while (head+1 < tail)
            {
                if ((Y(Q[head])-Y(Q[head+1])) >= s[i]*(X(Q[head])-X(Q[head+1])))   head++;
                else    break;
            }
            dp[i] = dp[Q[head]]+(s[i]-s[Q[head]])*(s[i]-s[Q[head]])+m;
            while (head+1 < tail)
            {
                if ((Y(i)-Y(Q[tail-1]))*(X(Q[tail-1])-X(Q[tail-2])) <= (X(i)-X(Q[tail-1]))*(Y(Q[tail-1])-Y(Q[tail-2]))) tail--;
                else    break;
            }
            Q[tail++] = i;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
