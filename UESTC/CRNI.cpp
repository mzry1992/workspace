#include <iostream>
#include <cstdio>
#include <cstring>
#include<stack>
using namespace std;

const int mod = 10007;
int n;
char mp[1100][1100];

int u[1100][1100],d[1100][1100];

int ru[1100][1100],rd[1100][1100],lu[1100][1100],ld[1100][1100];

int presum[1100][1100],presum1[1100][1100];

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%s",mp[i]+1);
    memset(u,0,sizeof(u));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            if (mp[i][j] == 'C')
                u[i][j] = u[i-1][j]+1;
            else
                u[i][j] = 0;
    memset(d,0,sizeof(d));
    for (int i = n;i >= 1;i--)
        for (int j = 1;j <= n;j++)
            if (mp[i][j] == 'C')
                d[i][j] = d[i+1][j]+1;
            else
                d[i][j] = 0;
    for (int i=1;i<=n;i++)
    {
        stack<int> sta;
        sta.push(0);
        for (int j=1;j<=n;j++)
        {
            while (u[i][sta.top()]>u[i][j]) sta.pop();
            rd[i][j]=rd[i][sta.top()]+u[i][j]*(j-sta.top());
            sta.push(j);
        }
    }
    for (int i=1;i<=n;i++)
    {
        stack<int> sta;
        sta.push(0);
        for (int j=1;j<=n;j++)
        {
            while (d[i][sta.top()]>d[i][j]) sta.pop();
            ru[i][j]=ru[i][sta.top()]+d[i][j]*(j-sta.top());
            sta.push(j);
        }
    }
    for (int i=1;i<=n;i++)
    {
        stack<int> sta;
        sta.push(n+1);
        for (int j=n;j>=1;j--)
        {
            while (d[i][sta.top()]>d[i][j]) sta.pop();
            lu[i][j]=lu[i][sta.top()]+d[i][j]*(sta.top()-j);
            sta.push(j);
        }
    }
    for (int i=1;i<=n;i++)
    {
        stack<int> sta;
        sta.push(n+1);
        for (int j=n;j>=1;j--)
        {
            while (u[i][sta.top()]>u[i][j]) sta.pop();
            ld[i][j]=ld[i][sta.top()]+u[i][j]*(sta.top()-j);
            sta.push(j);
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (mp[i][j]=='C')
                {
                    lu[i][j]--;
                    rd[i][j]--;
                    ld[i][j]--;
                    ru[i][j]--;
                }
    memset(presum,0,sizeof(presum));
    for (int i = n;i >= 1;i--)
        for (int j = n;j >= 1;j--)
            presum[i][j] = (lu[i][j]+presum[i][j+1]+presum[i+1][j]-presum[i+1][j+1]+mod)%mod;
    memset(presum1,0,sizeof(presum1));
    for (int i = n;i >= 1;i--)
        for (int j = 1;j <= n;j++)
            presum1[i][j] = (ld[i][j]+presum1[i][j-1]+presum1[i+1][j]-presum1[i+1][j-1]+mod)%mod;
    cout << "RU = " << endl;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << ru[i][j] << ' ';
        cout << endl;
    }
    cout << "RD = " << endl;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << rd[i][j] << ' ';
        cout << endl;
    }
    cout << "LU = " << endl;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << lu[i][j] << ' ';
        cout << endl;
    }
    cout << "LD = " << endl;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << ld[i][j] << ' ';
        cout << endl;
    }
    cout << "Presum1 = " << endl;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            cout << presum1[i][j] << ' ';
        cout << endl;
    }
    int res = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            res = (res+
                   (rd[i][j]*(presum[1][j+1]+presum[i+1][1]-presum[i+1][j+1]+mod))%mod-
                   (ld[i][j]*presum1[i+1][j-1])%mod+
                   mod)%mod;
    printf("%d\n",res);
}
