#include <cstdio>
#include <algorithm>
using namespace std;

int g[810][810],a[810];
int x[810*810],y[810*810];

int gcd(int x,int y)
{
    return (y == 0)?x:gcd(y,x%y);
}

int wg;
char ch;
bool ng;

inline int readint() //整数，包括负数
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
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
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    int t;
    t = readint();
    while(t--)
    {
        int n;
        n = readint();
        for (int i = 0;i < n;i++)
            a[i] = readint();
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                g[i][j] = g[j][i] = gcd(a[i],a[j]);
        int ans = 0;
        for (int i = 1,tot = 0;i < n;i++)
        {
            for (int j = 0;j < tot;j++)
                if (g[x[j]][i] != 1 && g[y[j]][i] != 1)
                    ans++;
            for (int j = 0;j < i;j++)
                if (g[i][j] != 1)
                {
                    x[tot] = i;
                    y[tot++] = j;
                }
        }
        for (int i = 1,tot = 0;i < n;i++)
        {
            for (int j = 0;j < tot;j++)
                if (g[x[j]][i] == 1 && g[y[j]][i] == 1)
                    ans++;
            for (int j = 0;j < i;j++)
                if (g[i][j] == 1)
                {
                    x[tot] = i;
                    y[tot++] = j;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}
