#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigInt
{
	const static int mod = 100000000;
	int a[600],len;
	BigInt (){}
	BigInt (int v)
	{
		len = 0;
		do
		{
			a[len++] = v%mod;
			v /= mod;
		}while(v);
	}
	BigInt operator *(const int& b) const
	{
		BigInt res;
		res.len = len;
		for (int i = 0; i <= len; ++i)
			res.a[i] = 0;
		for (int i = 0; i < len; ++i)
		{
			res.a[i] += a[i]*b;
			res.a[i+1] += res.a[i]/mod;
			res.a[i] %= mod;
		}
		if (res.a[len] > 0)	res.len++;
		return res;
	}
	BigInt operator +(const BigInt& b) const
	{
		BigInt res;
		res.len = max(len,b.len);
		for (int i = 0; i <= res.len; ++i)
			res.a[i] = 0;
		for (int i = 0; i < res.len; ++i)
		{
			res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
			res.a[i+1] += res.a[i]/mod;
			res.a[i] %= mod;
		}
		if (res.a[res.len] > 0)	res.len++;
		return res;
	}
	void output()
	{
		while (len > 1 && a[len-1] == 0)
			puts("fuck");
		printf("%d",a[len-1]);
		for (int i = len-2; i >= 0; --i)
			printf("%08d",a[i]);
		printf("\n");
	}
};

int a[11000];
char sa[11000];
int len,n,spos;
bool visit[5500][2][2];
BigInt dp[5500][2][2],res;

BigInt DP(int pos,int xx,int yy)
{
	if (visit[pos][xx][yy] == true)	return dp[pos][xx][yy];
	visit[pos][xx][yy] = true;
	BigInt& res = dp[pos][xx][yy];
	res = BigInt(0);
	//spos+pos,len-1-pos;
	int a0 = a[spos+pos];
	int an = a[len-1-pos];
	if (spos+pos == len-pos)
		res = BigInt(xx == yy);
	else if (spos+pos == len-1-pos)
	{
		if ((yy*10+an-xx)%2 == 0)
			res = BigInt(1);
	}
	else
	{
		int sum = an-xx;
		int tot = sum+1;
		if (pos == 0)	tot--;
		if (sum == a0+yy*10)
			res = res+DP(pos+1,0,0)*tot;
		else if (sum+1 == a0+yy*10)
			res = res+DP(pos+1,0,1)*tot;

		sum = an+10-xx;
		tot = 18-sum+1;
		if (sum == a0+10*yy)
			res = res+DP(pos+1,1,0)*tot;
		else if (sum+1 == a0+10*yy)
			res = res+DP(pos+1,1,1)*tot;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	freopen("J.in","r",stdin);
	//freopen("J.out","w",stdout);
	while (scanf("%s",sa) != EOF)
	{
		if (strcmp(sa,"0") == 0)	break;

		len = 0;
		spos = 0;
		while (sa[spos] == '0')	spos++;
		for (int i = spos; sa[i] != 0; ++i)
			a[len++] = sa[i]-'0';

		memset(visit,false,sizeof(visit));
		spos = 0;
		res = DP(0,0,0);
		if (a[0] == 1 && len > 1)
		{
			memset(visit,false,sizeof(visit));
			spos = 1;
			res = res+DP(0,0,1);
		}
		res.output();

	}
	return 0;
}