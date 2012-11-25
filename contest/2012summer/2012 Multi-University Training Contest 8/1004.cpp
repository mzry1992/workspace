#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 364875103;
//3761599 97

long long m[2],a[2];//模数m 余数a

long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if (b)
    {
        long long ret = ex_gcd(b,a%b,x,y),tmp = x;
        x = y;
        y = tmp-(a/b)*y;
        return ret;
    }
    else
    {
        x = 1;
        y = 0;
        return a;
    }
}
bool solve(long long  &m0,long long  &a0,long long  m,long long  a)//模线性方程组
{
    long long  y,x;
    long long  g=ex_gcd(m0,m,x,y);
    if (abs(a-a0)%g) return 0;
    x*=(a-a0)/g;
    x%=m/g;
    a0=(x*m0+a0);
    m0*=m/g;
    a0%=m0;
    if (a0<0) a0+=m0;
    return 1;
}
long long MLES()
{
    bool flag=1;
    long long m0=1,a0=0;
    for (int i=0; i<2; i++)
        if (!solve(m0,a0,m[i],a[i]))
        {
            flag=0;
            break;
        }
    if (flag)
        return a0;
    else
        return -1;
}

long long inv[2][2000000];

void getInv()
{
    for (int i = 0;i < 2;i++)
    {
        inv[i][1] = 1;
        for (int j = 2;j < m[i];j++)
            inv[i][j] = (m[i]-(m[i]/j)*inv[i][m[i]%j]%m[i])%m[i];
    }
}

long long power(int x,int y,int m)
{
    long long res = 1;
    for (long long a = x%m;y;y>>=1,a = a*a%m)
        if (y&1)
            res = res*a%m;
    return res;
}

long long getInv2(int id,int x)
{
    return power(x,m[id]-2,m[id]);
}

long long pre[2][2000000];

void initpre()
{
    for (int i = 0;i < 2;i++)
    {
        pre[i][0] = 1;
        for (int j = 1;j < 2000000;j++)
            if (j%m[i])
                pre[i][j] = pre[i][j-1]*j%m[i];
            else
            {
                int tmp=j;
                while (tmp%m[i]==0)
                    tmp/=m[i];
                pre[i][j] = pre[i][j-1]*tmp%m[i];
            }
    }
}
int count(int x,int y)
{
    int ret=0;
    for (;x;x/=y)
        ret+=x%y;
    return ret;
}
long long calc(int c,int d)
{
    //C_{a}^{b}
    long long res[2];
    res[0] = res[1] = 1;

    for (int i = 0;i < 2;i++)
    {
        if (count(c,m[i])!=count(c-d,m[i])+count(d,m[i]))
        {
            res[i]=0;
            continue;
        }
        res[i] = pre[i][c];
        res[i] = res[i]*getInv2(i,pre[i][d])%m[i];
        res[i] = res[i]*getInv2(i,pre[i][c-d])%m[i];
    }
    a[0] = res[0];
    a[1] = res[1];
    long long ans = MLES();
    return ans;
}

long long calc2(int a,int b)
{
    long long res = 1;
    if (b > a/2)
        b = a-b;
    for (int i = a-b+1;i <= a;i++)
        res = res*i;
    for (int i = 1;i <= b;i++)
        res = res/i;
    return res;
}

int f[20];

int main()
{
    m[0] = 97,m[1] = mod/97;
    //getInv();
    initpre();
    /*int aaa,bbb;
    while (scanf("%d%d",&aaa,&bbb) != EOF)
    {
        printf("%lld %lld\n",calc(aaa,bbb)%mod,calc2(aaa,bbb));
    }*/

	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    int fn,fm,fk;
	    scanf("%d%d%d",&fn,&fm,&fk);
        for (int i = 0;i < fk;i++)
            scanf("%d",&f[i]);
        f[fk] = fm;
	    long long res = 1;
	    for (int i = 0;i < fk;i++)
            res = res*calc(fn+f[i+1]-f[i]-1,f[i+1]-f[i])%mod;
	    printf("Case #%d: %I64d\n",cas,res);
	}
	return 0;
}
