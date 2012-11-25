#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "ctime"
using namespace std;

long long muti_mod(long long a,long long b,long long n)
{
	long long exp = a%n,res = 0;
	while (b)
	{
		if (b&1)
		{
			res += exp;
			if (res > n)	res -= n;
		}
		exp <<= 1;
		if (exp > n)	exp -= n;
		b >>= 1;
	}
	return res;
}

long long mod_exp(long long a,long long p,long long m)
{
	long long exp = a%m,res = 1;
	while (p > 1)
	{
		if (p&1)
			res = muti_mod(res,exp,m);
		exp = muti_mod(exp,exp,m);
		p >>= 1;
	}
	return muti_mod(res,exp,m);
}

bool miller_rabin(long long n,int times)
{
	if (n == 2)	return 1;
	if (n < 2 || !(n&1))	return 0;
	long long a,u = n-1,x,y;
	int t = 0;
	while (u%2 == 0)
	{
		t++;
		u /= 2;
	}
	srand(time(0));
	for (int i = 0;i < times;i++)
	{
		a = rand()%(n-1)+1;
		x = mod_exp(a,u,n);
		for (int j = 0;j < t;j++)
		{
			y = muti_mod(x,x,n);
			if (y == 1 && x != 1 && x != n-1)
				return false;
			x = y;
		}
		if (y != 1)	return false;
	}
	return true;
}

long long n,a[1000],tot,res;

void Gao(int now,long long nown,long long nowm)
{
    if (nown == 1)
    {
        if (res == 0 || res > nowm)
            res = nowm;
    }
	if (res > 0 && nowm >= res)	return;
	for (int i = now;i < tot;i++)
        if (nown%a[i] == 0)
        {
            long long tmp = nown/a[i];
            while (true)
            {
                Gao(i+1,tmp,(a[i]+1)*nowm/a[i]);
                if (tmp%(a[i]+1) != 0)  break;
                tmp /= a[i]+1;
            }
        }
}

int main(int argc, char const *argv[])
{
	while (scanf("%I64d",&n) != EOF)
	{
		tot = 0;
		for (int i = 1;i*i <= n;i++)
			if (n%i == 0)
			{
				if (miller_rabin(i+1,10))
					a[tot++] = i;
				if (i*i != n && miller_rabin(n/i+1,10))
					a[tot++] = n/i;
			}
		sort(a,a+tot);
		res = 0;
		Gao(0,n,n);
		printf("%I64d\n",res);
	}
	return 0;
}
