#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int n,m;
char ts[200];
char s[200][10];
int st[200];
int tots;
int tys;
char ys[200][10];
int xs[200][200];
int txs[200];

void gao(int l,int r)
{
    int res[200];
    memset(res,0,sizeof(res));
    memset(txs,0,sizeof(txs));
    int i = l;
    while (true)
    {
        if (st[i] == 1)
        {
            int tcode = 0;
            if (i+1 <= r)
                if (st[i+1] < 0)
                    tcode = 1;
            int num = 0;
            if (tcode == 0) num = 1;
            else    num = -st[i+1];
            int pos = 0;
            for (int j = 1;j <= tys;j++)
            if (strcmp(s[i],ys[j]) == 0)
                pos = j;
            if (pos == 0)
            {
                tys++;
                for (int j = 0;j <= strlen(s[i]);j++)
                    ys[tys][j] = s[i][j];
                pos = tys;
            }
            res[pos] += num;
            if (tcode == 0) i++;
            else i += 2;
        }
        else
        {
            int stop = 0;
            for (int j = i;;j++)
                if (s[j][0] == '(') stop++;
                else if (s[j][0] == ')')
                {
                    stop--;
                    if (stop == 0)
                    {
                        gao(i+1,j-1);
                        int tcode = 0;
                        if (j+1 <= r)
                            if (st[j+1] < 0)    tcode = 1;
                        int num = 0;
                        if (tcode == 0) num = 1;
                        else    num = -st[j+1];
                        for (int j = 1;j <= tys;j++)
                            res[j] += txs[j]*num;
                        i = j+2;
                        break;
                    }
                }
        }
        if (i > r)   break;
    }
    for (int i = 1;i <= tys;i++)
        txs[i] = res[i];
}

void gaoji()
{
    tots = 0;
    int j = 0;
    while (true)
    {
        if (j >= strlen(ts))    break;
        if (ts[j] >= 'A' && ts[j] <= 'Z')
        {
            int tcode = 0;
            if (j+1 < strlen(ts))
                if (ts[j+1] >= 'a' && ts[j+1] <= 'z')
                    tcode = 1;
            if (tcode == 0)
            {
                tots++;
                s[tots][0] = ts[j];
                s[tots][1] = 0;
                st[tots] = 1;
                j++;
            }
            else
            {
                tots++;
                s[tots][0] = ts[j];
                s[tots][1] = ts[j+1];
                s[tots][2] = 0;
                st[tots] = 1;
                j += 2;
            }
        }
        else if (ts[j] == '(' || ts[j] == ')')
        {
            tots++;
            s[tots][0] = ts[j];
            s[tots][1] = 0;
            st[tots] = 2;
            j++;
        }
        else
        {
            tots++;
            int num = 0;
            for (int k = 0;;k++)
            {
                if (ts[j] >= '0' && ts[j] <= '9')
                {
                    s[tots][k] = ts[j];
                    num = num*10+ts[j]-'0';
                    j++;
                }
                else
                {
                    s[tots][k] = 0;
                    st[tots] = -num;
                    break;
                }
            }
        }
    }
    gao(1,tots);
}

int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    int tgcd = gcd(a,b);
    return (a*b)/tgcd;
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        tys = 0;
        memset(xs,0,sizeof(xs));
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",ts);
            gaoji();
            for (int j = 1;j <= tys;j++)
                xs[i][j] = txs[j];
        }
        for (int i = n+1;i <= n+m;i++)
        {
            scanf("%s",ts);
            gaoji();
            for (int j = 1;j <= tys;j++)
                xs[i][j] = -txs[j];
        }
        int tn,tm;
        tn = tys;
        tm = n+m;
        ft++;
        printf("Case %d:",ft);
        if (tn+1 < tm)
        {
            printf(" No\n");
            continue;
        }
        bool flag = true;
        tm++;
        tn++;
        xs[tm][tn] = xs[tm-1][tn] = 1;
        for (int i = 1;i <= tm-1;i++)
        {
            int minnum = 19921005;
            int minpos = 0;
            for (int j = 1;j <= tn;j++)
            {
                if (xs[i][j] < 0)
                    for (int k = 1;k <= tm;k++)
                        xs[k][j] = -xs[k][j];
                if (j >= i)
                    if (xs[i][j] > 0)
                        if (xs[i][j] < minnum)
                        {
                            minnum = xs[i][j];
                            minpos = j;
                        }
            }
            if (minpos == 0)
            {
                flag = false;
                break;
            }
            for (int j = 1;j <= tm;j++)
            {
                int temp = xs[j][i];
                xs[j][i] = xs[j][minpos];
                xs[j][minpos] = temp;
            }
            for (int j = 1;j <= tn;j++)
            if (j != i)
            if (xs[i][j] > 0)
            {
                int tlcm = lcm(minnum,xs[i][j]);
                int tmul = tlcm/xs[i][j];
                int tmul2 = tlcm/minnum;
                for (int k = 1;k <= tm;k++)
                    xs[k][j] = xs[k][j]*tmul-xs[k][i]*tmul2;
            }
        }
        int ans[200][2];
        for (int i = 1;i <= tm-1;i++)
        {
            ans[i][0] = xs[i][i];
            ans[i][1] = xs[tm][i];
            if (ans[i][0] < 0)
            {
                ans[i][0] = -ans[i][0];
                ans[i][1] = -ans[i][1];
            }
            if (ans[i][0] == 0) flag = false;
            if (ans[i][1] <= 0)  flag = false;
            if (ans[i][1] < 0)
                ans[i][1] = -ans[i][1];
        }
        for (int i = tm;i <= tn;i++)
            if (xs[tm][i] != 0)
                flag = false;
        if (flag == false)
        {
            printf(" No\n");
            continue;
        }
        int tlcm = 1;
        for (int i = 1;i <= tm-1;i++)
        {
            int tgcd = gcd(ans[i][0],ans[i][1]);
            ans[i][0] /= tgcd;
            ans[i][1] /= tgcd;
            tlcm = lcm(tlcm,ans[i][0]);
        }
        for (int i = 1;i <= tm-1;i++)
            ans[i][1] = ans[i][1]*(tlcm/ans[i][0]);
        for (int i = 1;i <= tm-1;i++)
            printf(" %d",ans[i][1]);
        printf("\n");
    }
}
