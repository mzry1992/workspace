#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool isPrime[100000];
int prime[100000];
int L;
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i=2; i<100000; i++)
        if (isPrime[i])
        {
            for (int j=i+i; j<100000; j+=i)
                isPrime[j]=0;
            prime[L++]=i;
        }
}
int N;
int num[30],fac[30];
void getFactor(long long x)
{
    N=0;
    memset(num,0,sizeof(num));
    for (long long i=0; prime[i]*prime[i]<=x; i++)
    {
        if (x%prime[i]==0)
        {
            while (x%prime[i]==0)
            {
                x/=prime[i];
                num[N]++;
            }
            fac[N++]=prime[i];
        }
    }
    if (x>1)
    {
        num[N]=1;
        fac[N++]=x;
    }
}
long long ex_gcd(long long a,long long b,long long &x,long long &y)//À©Õ¹gcd
{
    if(b)
    {
        long long ret=ex_gcd(b,a%b,x,y),tmp=x;
        x=y;
        y=tmp-(a/b)*y;
        return ret;
    }
    else
    {
        x=1;
        y=0;
        return a;
    }
}
long long power(long long x,long long y,long long mod)
{
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}
long long getPriRoot(long long p)//Ô­¸ù
{
    if (p==2) return 1;
    long long phi = p - 1;
    getFactor(phi);
    for (long long g = 2; g < p; ++g)
    {
        bool flag=1;
        for (long long i = 0; flag && i < N; ++i)
            if (power(g, phi/fac[i], p) == 1)
                flag=0;
        if (flag)
            return g;
    }
}
#define MOD 76543//baby step giant step
int hs[MOD], head[MOD], next[MOD], id[MOD], top;
void insert(int x, int y)
{
    int k = x%MOD;
    hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}
int find(int x)
{
    int k = x%MOD;
    for (int i = head[k]; i; i = next[i]) if (hs[i] == x) return id[i];
    return -1;
}
long long BSGS(long long a, long long b, long long n)
{
    memset(head, 0, sizeof(head));
    top = 1;
    if (b==1) return 0;
    long long m = sqrt(n+.0), j;
    long long x = 1, p = 1;
    for (long long i = 0; i < m; ++i, p = p*a%n) insert(p*b%n, i);
    for (long long i = m; ; i += m)
    {
        if ((j = find(x=x*p%n)) != -1) return i-j;
        if (i > n) break;
    }
    return -1;
}
const int mond[2][13] = {{0,31,28,31,30,31,30,31,31,30,30,31},
    {0,31,29,31,30,31,30,31,31,30,30,31}
};
void output(long long x)
{
    long long tx = 0,nowx,nx;
    int run,leap;
    for (int year = 2000;; year++)
    {
        if (year%400 == 0 || (year%4 == 0 && year%100 != 0))
            run = 1;
        else
            run = 0;
        if (year%10 == 5 || year%10 == 8)
            leap = 1;
        else
            leap = 0;
        if (run == 0)
            nowx = 3600*24*365;
        else
            nowx = 3600*24*366;
        if (leap == 1)
            nowx++;
        nx = tx+nowx;
        if (nx >= x)
        {
            for (int mon = 1; mon <= 12; mon++)
            {
                nowx = 3600*24*mond[run][mon];
                if (mon == 12 && leap == 1)
                    nowx++;
                nx = tx+nowx;
                if (tx+nowx >= x)
                {
                    for (int day = 1; day <= mond[run][mon]; day++)
                    {
                        nowx = 3600*24;
                        if (mon == 12 && leap == 1 && day == mond[run][mon])
                            nowx++;
                        nx = tx+nowx;
                        if (tx+nowx >= x)
                        {
                            int hour,minu,seco;
                            nowx = x-tx;
                            if (nowx == 3600*24+1)
                            {
                                hour = 23;
                                minu = 59;
                                seco = 60;
                            }
                            else
                            {
                                seco = nowx%60;
                                nowx /= 60;
                                minu = nowx%60;
                                nowx /= 60;
                                hour = nowx;
                            }
                            printf("%d.%02d.%02d %02d:%02d:%02d\n",year,mon,day,hour,minu,seco);
                            break;
                        }
                        tx = nx;
                    }
                    break;
                }
                tx = nx;
            }
            break;
        }
        tx = nx;
    }
}
void out(vector<long long> ans)
{
    if (ans.size() == 0)
    {
        printf("Transmission error\n");
        return;
    }
    for (int i = 0; i < ans.size(); i++)
        outDate(ans[i]);
}
void solve(long long b,long long c,long long p)
{
    vector<long long> ans;
    if (c == 0)
    {
        output(0);
        return;
    }
    long long pR=getPriRoot(p),x,y;
    long long g=ex_gcd(b,p-1,x,y),d=(p-1)/g;
    long long I=BSGS(pR,c,p);
    if (I==-1 || I%g)
    {
        out(ans);
        return ;
    }
    x=(x%d+d)%d;
    x=(x*(I/g))%(p-1);
    for (x=(x%d+d)%d; x<p-1; x+=d)
        ans.push_back(power(pR,x,p));
    sort(ans.begin(),ans.end());
    out(ans);
}
int main()
{
    getPrime();
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        long long p,b,c;
        scanf("%I64d%I64d%I64d",&p,&b,&c);
        printf("Case #%d:\n",cas);
        solve(b,c,p);
    }
    return 0;
}
