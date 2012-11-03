#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,sum[100001],Q[100001],head,tail,a;
double ans;
int wg;
char ch;
bool ng;

inline bool check(int xa,int ya,int xb,int yb,int xc,int yc)
{
    return (long long)(xb-xa)*(yc-ya) <= (long long)(yb-ya)*(xc-xa);
}

inline int readint() //整数，包括负数
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        sum[0] = Q[0] = head = 0;
        tail = 1;
        ans = 0.0;
        for (int i = 1; i <= n; i++)
        {
            a = readint();
            sum[i] = sum[i-1]+a;
            if (i-m >= 0)
            {
                while (tail-2 >= head)
                {
                    if (check(Q[tail-2],sum[Q[tail-2]],Q[tail-1],sum[Q[tail-1]],i-m,sum[i-m]) == true)  tail--;
                    else    break;
                }
                Q[tail++] = i-m;
                while (head+1 < tail)
                {
                    if ((long long)(sum[i]-sum[Q[head]])*(i-Q[head+1]) <= (long long)(sum[i]-sum[Q[head+1]])*(i-Q[head])) head++;
                    else    break;
                }
                ans = max(ans,(double)(sum[i]-sum[Q[head]])/(i-Q[head]));
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
