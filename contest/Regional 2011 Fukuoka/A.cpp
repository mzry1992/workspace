#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,mon,day,h,m,p;
char e;
bool at[1000];
int res[1000],timin[1000];
int tim[13][32][24][60];

const int dayofmon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void init()
{
    int now = 0;
    for (int mo = 1;mo <= 12;mo++)
        for (int da = 1;da <= dayofmon[mo-1];da++)
            for (int ho = 0;ho < 24;ho++)
                for (int mi = 0;mi < 60;mi++)
                    tim[mo][da][ho][mi] = now++;
}

int main()
{
    init();
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        memset(res,0,sizeof(res));
        memset(at,false,sizeof(at));
        for (int i = 0;i < n;i++)
        {
            scanf("%d/%d%d:%d %c%d",&mon,&day,&h,&m,&e,&p);
            int now = tim[mon][day][h][m];
            if (e == 'I')
            {
                at[p] = true;
                timin[p] = now;
                if (p == 0)
                {
                    for (int j = 1;j < 1000;j++)
                        if (at[j] == true)
                            timin[j] = now;
                }
            }
            else
            {
                at[p] = false;
                if (p == 0)
                {
                    for (int j = 1;j < 1000;j++)
                        if (at[j] == true)
                            res[j] += now-timin[j];
                }
                else
                {
                    if (at[0] == true)
                        res[p] += now-timin[p];
                }
            }
        }
        int mx = 0;
        for (int i = 1;i < 1000;i++)
            mx = max(mx,res[i]);
        printf("%d\n",mx);
    }
	return 0;
}
