#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int md[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
int day[10001][12][31],ry[3000000];
char rm[3000000],rd[3000000];
int YY,MM,DD,HH,T,now,ansd,ansh;

int main()
{
    int tl = 0,l = 0;
    for (YY = 2001; YY <= 10000; YY++)
    {
        int tmp = 0;
        if (YY%400 == 0 || (YY%100 != 0 && YY%4 == 0))  tmp = 1;
        for (MM = 0; MM < 12; MM++)
            for (DD = 0; DD < md[tmp][MM]; DD++)
            {
                day[YY][MM][DD] = tl++;
                if ((tl-1)%7 < 5)
                {
                    ry[l] = YY;
                    rm[l] = MM;
                    rd[l++] = DD;
                }
            }
    }
    int t;
    scanf("%d",&t);

    int nowd,nowh;
    nowd = nowh = 0;

    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d/%d/%d%d%d",&YY,&MM,&DD,&HH,&T);
        now = day[YY][MM-1][DD-1];

        if (HH < 10)
            HH = 10;
        else if (HH >= 18)
        {
            HH = 10;
            now++;
        }
        if (now%7 > 4)
        {
            now += 7-now%7;
            HH = 10;
        }

        now = (now/7)*5+now%7;
        HH -= 10;

        if (nowd < now || (nowd == now && nowh < HH))
        {
            nowd = now;
            nowh = HH;
        }

        nowh += T;
        nowd += nowh/8;
        nowh %= 8;

        ansd = nowd;
        ansh = nowh;
        if (ansh == 0)
        {
            ansd--;
            ansh = 8;
        }

        printf("Case #%d: %d/%02d/%02d %d\n",ft,ry[ansd],rm[ansd]+1,rd[ansd]+1,ansh+10);
    }
    return 0;
}
