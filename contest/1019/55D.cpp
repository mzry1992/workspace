#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char l[25],r[25];
int mod[1<<8];
long long tl,tr,dp[20][2][1<<8][2520];
bool hasdp[20][2][1<<8][2520];

inline int getsta(int sta,int i)
{
    if (i > 1)
        return sta|(1<<(i-2));
    return sta;
}

long long DP(int pos,int u,int sta,int rem)
{
    //cout << pos << ' ' << u << ' ' << d << ' ' << sta << ' ' << rem << endl;
    if (pos == 20) return rem%mod[sta] == 0;
    if (hasdp[pos][u][sta][rem] == true)
        return dp[pos][u][sta][rem];
    int op = 0;
    int ed = (u == 1)?(r[pos]-'0'):9;
    //cout << pos << ' ' << op << ' ' << ed << endl;
    long long res = 0;
    for (int i = op;i <= ed;i++)
        res += DP(pos+1,i > ed-u,getsta(sta,i),(rem*10+i)%2520);
    hasdp[pos][u][sta][rem] = true;
    dp[pos][u][sta][rem] = res;
    return res;
}

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

long long resl,resr;

int main()
{
    for (int i = 0;i < (1<<8);i++)
    {
        mod[i] = 1;
        for (int j = 0;j < 8;j++)
            if (((i>>j)&1) == 1)
                mod[i] = lcm(mod[i],2+j);
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        cin >> tl >> tr;
        tl--;
        sprintf(r,"%020I64d",tl);
        memset(hasdp,false,sizeof(hasdp));
        resl = DP(0,1,0,0);
        sprintf(r,"%020I64d",tr);
        memset(hasdp,false,sizeof(hasdp));
        resr = DP(0,1,0,0);
        cout << resr-resl << endl;
    }
    return 0;
}
