#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a[16];
int n,cnt[65537],tot[8][257],presum[65537];
char typ;

bool check(int pos,int val)
{
    return (val&(1<<pos)) > 0;
}

int calc(int l,int r)
{
    l = (l%65536+65536)%65536;
    r = (r%65536+65536)%65536;

    if (l <= r)
        return presum[r]-presum[l]+cnt[l];
    else
        return calc(l,65535)+calc(0,r);
}

int main()
{
    for (int i = 8;i < 16;i++)
        for (int j = 0;j < 65536;j++)
            if (check(i,j) && !check(i,j-1))
                a[i].push_back(j);

    int cas = 1;
    while (true)
    {
        scanf("%d",&n);
        if (n == -1)    break;

        memset(cnt,0,sizeof(cnt));
        memset(tot,0,sizeof(tot));
        for (int i = 0;i < n;i++)
        {
            int v;
            scanf("%d",&v);
            cnt[v]++;

            for (int j = 0;j < 8;j++)
                tot[j][v&((1<<j+1)-1)]++;
        }

        presum[0] = cnt[0];
        for (int i = 1;i < 65536;i++)
            presum[i] = presum[i-1]+cnt[i];

        long long sum = 0;
        int add = 0;
        while (true)
        {
            scanf(" %c",&typ);
            if (typ == 'E') break;

            int v;
            scanf("%d",&v);
            if (typ == 'C')
                add += v;
            else
            {
                int res = 0;
                if (v < 8)
                {
                    int full = (1<<(v+1));
                    for (int i = 0;i < full;i++)
                        if (check(v,(i+add)&(full-1)))
                            res += tot[v][i];
                }
                else
                {
                    int len = (1<<v);
                    for (int i = 0;i < a[v].size();i++)
                        res += calc(a[v][i]-add,a[v][i]+len-1-add);
                }

                //printf("%d\n",res);
                sum += res;
            }
        }

        printf("Case %d: ",cas++);
        cout << sum << endl;
    }
    return 0;
}

