#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int k,m,t,n,mp[11],pre[11][1<<16],res,dp[11][200][200],dif,get;

int Count(int now)
{
    int res = 0;
    for (int i = 0;i < 16;i++)
        if (((now>>i)&1) == 1)  res++;
    return res;
}

int GetPos(int now,int x,int y)
{
    if (x < 0 || x >= 4 || y < 0 || y >= 4) return 0;
    return (((now>>(x*4+y))&1) == 1)?1:0;
}

int Play(int now)
{
    int res = 0;
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
        {
            int count = 0;
            for (int q = 0;q < 8;q++)
                count += GetPos(now,i+step[q][0],j+step[q][1]);
            if (((now>>(i*4+j))&1) == 1)
            {
                if (count == 2 || count == 3)   res = res|(1<<(i*4+j));
            }
            else
            {
                if (count == 3) res = res|(1<<(i*4+j));
            }
        }
    return res;
}

int GetDif(int a,int b)
{
    int res = 0;
    for (int i = 0;i < 16;i++)
        if (((a>>i)&1) == 0 && ((b >> i)&1) == 1)
            res++;
        else if (((a>>i)&1) == 1 && ((b >> i)&1) == 0)
            return -1;
    return res;
}

void output(int now)
{
    cout << "++++++++++" << endl;
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < 4;j++)
            printf("%c",(((now>>(i*4+j))&1) == 1)?'#':' ');
        printf("\n");
    }
    printf("Count = %d\n",Count(now));
}

int main()
{
    memset(pre,0,sizeof(pre));
    for (int now = 0;now < (1<<16);now++)
    {
        int tmp = now;
        for (int tim = 0;tim <= 10;tim++)
        {
            pre[tim][now] = Count(tmp);
            if (tmp == 0)   break;
            tmp = Play(tmp);
        }
    }
    /*int tmp[17] = {0};
    for (int i = 0;i < 11;i++)
        for (int j = 0;j < (1<<16);j++)
            tmp[pre[i][j]]++;
    for (int i = 0;i <= 16;i++)
        cout << tmp[i] << ' ';
    cout << endl;
    return 0;*/
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d%d%d",&k,&m,&t,&n);
        for (int i = 1;i <= k;i++)
        {
            mp[i] = 0;
            for (int j = 0;j < 4;j++)
                for (int q = 0;q < 4;q++)
                {
                    int tmp;
                    scanf("%d",&tmp);
                    mp[i] = ((mp[i])<<1)+tmp;
                }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1;i <= k;i++)
            for (int j = 0;j < (1<<16);j++)
            {
                dif = GetDif(mp[i],j);
                if (dif != -1)
                {
                    get = pre[t][j];
                    for (int prem = 0;prem <= m-dif;prem++)
                        for (int pren = 0;pren <= n-get;pren++)
                        dp[i][prem+dif][pren+get] += dp[i-1][prem][pren];
                }
            }
        res = 0;
        for (int i = 0;i <= m;i++)
            res += dp[k][i][n];
        printf("Case #%d: %d\n",ft,res);
    }
}
