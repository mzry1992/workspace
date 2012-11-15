#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int now;
bool die[200];
int a,b;

int next(int now)
{
    now = now+1;
    if (now > n)    now = 1;
    if (die[now] == false)  return now;
    while (die[now] == true)
    {
        now = now+1;
        if (now > n)    now = 1;
    }
    return now;
}

int kill(int now)
{
    for (int i = 1;i <= m-1;i++)
        now = next(now);
    die[now] = true;
    return now;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        now = 1;
        n += 2;
        memset(die,false,sizeof(die));
        for (int i = 1;i <= n;i++)
        {
            now = kill(now);
            if (i == n-1)   a = now;
            if (i == n)   b = now;
            cout << now << endl;
            if (i < n)
                now = next(now);
        }
        printf("%d %d\n",(a<b)?a:b,(a>b)?a:b);
    }
}
