#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//T , HS , A , R , U , D , FI , P ,
int t,hs,a,r,u,d,fi,p,def[210];
int dp[2][110][40][10];
// 时间 血量 敌人的燃烧等级 敌人的燃烧时间

int main()
{
    int tcas;
    scanf("%d",&tcas);
    for (int ft = 1;ft <= tcas;ft++)
    {
        scanf("%d%d%d%d%d%d%d%d",&t,&hs,&a,&r,&u,&d,&fi,&p);
        for (int i = 1;i <= t;i++)
            scanf("%d",&def[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][hs][0][0] = 0;
        int atk,cur,nhc,nbd,nbt;
        for (int tim = 1;tim <= t;tim++)
            for (int hc = 1;hc <= hs;hc++)
                for (int bd = 0;bd <= hs/d;bd++)
                    for (int bt = 0;bt <= 6;bt++)
                        if (dp[(tim-1)&1][hc][bd][bt] != -1)
                        {
                            atk = a+((hs-hc)/r)*u;
                            cur = dp[(tim-1)&1][hc][bd][bt];
                            cur += (atk>def[tim])?(atk-def[tim]):0;
                            cur += bd*fi;
                            //Burning Spear
                            if (hc > d)
                            {
                                nbd = bd+1;
                                nbt = 6;
                                nhc = hc-d;
                                dp[tim&1][nhc][nbd][nbt] = max(dp[tim&1][nhc][nbd][nbt],cur);
                            }
                            //normal attack
                                nbt = (bt>1)?(bt-1):0;
                                nbd = (nbt>0)?bd:0;
                                nhc = hc;
                                dp[tim&1][nhc][nbd][nbt] = max(dp[tim&1][nhc][nbd][nbt],cur);
                        }
        int res = 0;
        for (int tim = t;tim <= t;tim++)
            for (int hc = 0;hc <= hs;hc++)
                for (int bd = 0;bd <= hs/d;bd++)
                    for (int bt = 0;bt <= 6;bt++)
                        if (dp[tim&1][hc][bd][bt] != -1)
                            res = max(res,dp[tim&1][hc][bd][bt]-(hs-hc)*p);
        printf("Case #%d: %d\n",ft,res);
    }
    return 0;
}
