#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[100];
bool dp[1100][1100],vis[1100][1100];

bool calc(int pos,int pre)
{
    if (vis[pos][pre] == true)
        return dp[pos][pre];
    //printf("%d %d\n",pos,pre);
    bool &res = dp[pos][pre];
    vis[pos][pre] = true;
    for (int i = 0;i < m;i++)
    {
        if (pos+a[i] > pre && pos+a[i] <= n)
            if (calc(pos+a[i],pos) == false)
                return res = true;
        if (pos-a[i] > pre)
            if (calc(pos-a[i],pos) == false)
                return res = true;
    }
    return res = false;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);
        n %= 2*a[0];
        //cout << n << endl;
        printf("Case #%d: ",cas);
        if (n < a[0])
            puts("Alice");
        else
            puts("Bob");
    }
    /*while (scanf("%d",&m) != EOF)
    {
        for (int i = 0;i < m;i++)
            scanf("%d",&a[i]);
        sort(a,a+m);

        for (n = 1;n <= 100;n++)
        {
            memset(vis,false,sizeof(vis));
            printf("%d %d\n",n,calc(0,0));
        }

    }*/
    return 0;
}
