#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigInt
{
    const static int mod = 100000000;
    const static int bitlen = 8;
    int a[600],len;
    BigInt() {}
    BigInt(char s[])
    {
        int l = strlen(s),mut;
        len = 0;
        for (int i = 0; i < l; i++)
        {
            if (i%bitlen == 0)
            {
                mut = 1;
                a[len++] = 0;
            }
            a[len-1] = a[len-1]+(s[l-1-i]-'0')*mut;
            mut *= 10;
        }
    }
    int operator %(const int& b)const
    {
        int res = 0;
        for (int i = len-1; i >= 0; i--)
            res = ((long long)res*mod+a[i])%b;
        return res;
    }
    BigInt operator /(const int& b)const
    {
        BigInt res = *this;
        int re = 0;
        for (int i = len-1; i >= 0; i--)
        {
            int tmp = ((long long)re*mod+a[i])%b;
            res.a[i] = ((long long)re*mod+a[i])/b;
            re = tmp;
        }
        while (res.len > 1 && res.a[res.len-1] == 0)	res.len--;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for (int i = len-2; i >= 0; i--)
            printf("%0*d",bitlen,a[i]);
        printf("\n");
    }
};

int n,m;
char buf[110],mp[400][400];
int a[400][400],addtime[400*400],newpos[400*400],pos[400*400],ppos[400*400],num[400*400],pnum[400*400];
const int mod = 100000;
BigInt times;
int tot;

void Rotate(int i,int j)
{
    int tmp = a[i][j];
    a[i][j] = a[i+1][j];
    a[i+1][j] = a[i+1][j+1];
    a[i+1][j+1] = a[i][j+1];
    a[i][j+1] = tmp;
}

int main()
{
    bool first = true;

    while (scanf("%d%d%s",&n,&m,buf) != EOF)
    {
        if (!first)
            puts("");
        first = false;

        tot = n*m;
        n--;
        m--;
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        times = BigInt(buf);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
            {
                a[i][j] = i*(m+1)+j;
                addtime[a[i][j]] = 0;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                addtime[a[i][j]]++;
                if (addtime[a[i][j]] >= mod)
                    addtime[a[i][j]] -= mod;

                if (mp[i][j] == 'R')
                    Rotate(i,j);
                else if (mp[i][j] == 'L')
                    for (int k = 0; k < 3; k++)
                        Rotate(i,j);
            }
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                newpos[i*(m+1)+j] = a[i][j];

        for (int i = 0; i < tot; i++)
        {
            pos[i] = i;
            num[i] = 0;
            pnum[i] = addtime[i];
            ppos[i] = newpos[i];
        }

        int xx = times%(n*m);
        times = times/(n*m);

        while (true)
        {
            if (times.len == 1 && times.a[0] == 0)	break;

            if (times%2 == 0)
            {
                for (int i = 0; i < tot; i++)
                {
                    num[i] += pnum[pos[i]];
                    if (num[i] >= mod)
                        num[i] -= mod;
                    pos[i] = ppos[pos[i]];
                }
            }
            for (int i = 0; i < tot; i++)
            {
                newpos[i] = ppos[ppos[i]];
                addtime[i] = pnum[i]+pnum[ppos[i]];
                if (addtime[i] >= mod)
                    addtime[i] -= mod;
            }
            for (int i = 0; i < tot; i++)
            {
                ppos[i] = newpos[i];
                pnum[i] = addtime[i];
            }
            times = times/2;
        }

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                a[i][j] = pos[i*(m+1)+j];

        for (int i = 0; i < n && xx > 0; i++)
            for (int j = 0; j < m && xx > 0; j++)
            {
                num[a[i][j]]++;
                if (num[a[i][j]] >= mod)
                    num[a[i][j]] -= mod;
                if (mp[i][j] == 'R')
                    Rotate(i,j);
                else if (mp[i][j] == 'L')
                    for (int k = 0; k < 3; k++)
                        Rotate(i,j);
                xx--;
            }

        for (int i = 0; i < tot; i++)
            printf("%d\n",num[i]);
    }
    return 0;
}
