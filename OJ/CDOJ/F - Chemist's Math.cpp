#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

char s[100];
int mid,len;
map<string,int> ys;
int totys;
struct hxs
{
    long long val[100];
}pre,nex;
int kh[100],top;

hxs gao(int l,int r)
{
    hxs res,tres;
    for (int i = 1;i <= 80;i++)
        res.val[i] = 0;
    for (int i = l;i <= r;)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            string ts = "";
            ts = ts+s[i];
            int pos = i+1;
            for (;;pos++)
                if (s[pos] >= 'a' && s[pos] <= 'z')
                    ts = ts+s[pos];
                else break;
            long long val = 0;
            for (;;pos++)
                if (s[pos] >= '0' && s[pos] <= '9')
                    val = val*10+(s[pos]-'0');
                else break;
            if (val == 0)   val = 1;
            //cout << ts << ' ' << val << ' ' << pos << endl;
            if (ys.find(ts) == ys.end())
            {
                totys++;
                ys[ts] = totys;
            }
            res.val[ys[ts]] += val;
            i++;
        }
        else if (s[i] == '(')
        {
            top = 1;
            kh[1] = 1;
            int nextpos;
            for (int j = i+1;;j++)
                if (s[j] == '(')
                {
                    top++;
                    kh[top] = 1;
                }
                else if (s[j] == ')')
                {
                    top--;
                    if (top == 0)
                    {
                        nextpos = j;
                        break;
                    }
                }
            //cout << "(" << endl;
            //cout << i+1 << ' ' << nextpos-1 << endl;
            tres = gao(i+1,nextpos-1);
            nextpos++;
            long long val = 0;
            for (;;nextpos++)
                if (s[nextpos] >= '0' && s[nextpos] <= '9')
                    val = val*10+(s[nextpos]-'0');
                else break;
            if (val == 0)   val = 1;
            //for (int j = 1;j <= 5;j++)
            //    cout << "J " << res.val[j] << ' ' << tres.val[j] << ' ' << val << endl;
            for (int j = 1;j <= 80;j++)
                res.val[j] += tres.val[j]*val;
            i = nextpos;
        }
        else i++;
    }
    return res;
}

long long a[100][100],n,m;
long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    while (true)
    {
        gets(s);
        if (strcmp(s,".") == 0) break;
        len = strlen(s);
        for (int i = 0;i < len;i++)
            if (s[i] == '-')
            {
                mid = i;
                break;
            }
        ys.clear();
        totys = 0;
        pre = gao(0,mid-1);
        nex = gao(mid+2,len-1);
        //for (int i = 1;i <= totys;i++)
        //    cout << pre.val[i] << ' ' << nex.val[i] << ' ' << endl;
        memset(a,0,sizeof(a));
        n = totys;
        m = 0;
        for (int i = 0;i < mid-1;i++)
            if (i == 0 || s[i-1] == '+')
                for (int j = i;;j++)
                    if (s[j] == '+' || j == mid)
                    {
                        pre = gao(i,j-1);
                        m++;
                        for (int k = 1;k <= totys;k++)
                            a[k][m] = pre.val[k];
                        break;
                    }
        for (int i = mid+2;i < len;i++)
            if (i == mid+2 || s[i-1] == '+')
                for (int j = i;;j++)
                    if (s[j] == '+' || j == len)
                    {
                        pre = gao(i,j-1);
                        m++;
                        for (int k = 1;k <= totys;k++)
                            a[k][m] = -pre.val[k];
                        break;
                    }
        bool hasres = true;
        long long mula,mulb,tgcd,tlcm;
        for (int i = 1;i <= n;i++)
        {
            if (a[i][i] == 0)
            {
                for (int j = i+1;j <= n;j++)
                    if (a[j][i] != 0)
                    {
                        for (int k = 1;k <= m;k++)
                            swap(a[i][k],a[j][k]);
                    }
            }
            if (a[i][i] == 0)
            {
                hasres = false;
                break;
            }
            for (int j = 1;j <= n;j++)
                if (j != i)
                    if (a[j][i] != 0)
                    {
                        tgcd = gcd(a[i][i],a[j][i]);
                        tlcm = (a[i][i]*a[j][i])/tgcd;
                        mula = tlcm/a[i][i];
                        mulb = tlcm/a[j][i];
                        for (int k = 1;k <= m;k++)
                            a[j][k] = a[j][k]*mulb-a[i][k]*mula;
                    }
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                if (a[i][j] < 0)    a[i][j] = -a[i][j];
        /*for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }*/
        tlcm = 1;
        for (int i = 1;i <= n;i++)
            if(a[i][i])
            {
                tgcd = gcd(a[i][i],a[i][m]);
                a[i][i] /= tgcd;
                a[i][m] /= tgcd;
                tlcm = lcm(tlcm,a[i][i]);
            }
        //cout << tlcm << endl;
        for (int i = 1;i <= m-1;i++)
            if(a[i][i])
                printf("%lld ",(tlcm/a[i][i])*a[i][m]);
        printf("%lld\n",tlcm);
    }
}
