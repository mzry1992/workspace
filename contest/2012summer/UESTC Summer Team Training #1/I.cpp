#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int l,r,k,pos;
	node(){};
	node(int _l,int _r,int _k,int _pos)
	{
		l = _l;
		r = _r;
		k = _k;
		pos = _pos;
	}
};

struct customer
{
	int pos,val;
	bool operator < (const customer& b)const
	{
		return pos < b.pos;
	}
};

customer a[101];
int n;
int dp[101][101][101][2];
bool use[101][101][101][2];

int gao()
{
	queue<node> Q;
	memset(use,false,sizeof(use));
	for (int i = 0;i < n;i++)
		if (a[i].pos == 0)
			for (int j = 0;j < n;j++)
			{
				Q.push(node(i,i,j,0));
				dp[i][i][j][0] = 0;
				use[i][i][j][0] = true;
			}
	int res = 0;
	int posnow,val,newval;
	while (!Q.empty())
	{
		node now = Q.front(),upd;
		Q.pop();
		val = dp[now.l][now.r][now.k][now.pos];
		if (now.k == 0)
		{
			res = max(res,val);
			continue;
		}
		if (now.pos == 0)
			posnow = now.l;
		else
			posnow = now.r;
		if (now.l > 0)
		{
			val = dp[now.l][now.r][now.k][now.pos]-now.k*(a[posnow].pos-a[now.l-1].pos);

			newval = val+a[now.l-1].val;
			upd = node(now.l-1,now.r,now.k-1,0);
			if (use[upd.l][upd.r][upd.k][upd.pos] == false ||
					dp[upd.l][upd.r][upd.k][upd.pos] < newval)
			{
				if (use[upd.l][upd.r][upd.k][upd.pos] == false)
					Q.push(upd);
				use[upd.l][upd.r][upd.k][upd.pos] = true;
				dp[upd.l][upd.r][upd.k][upd.pos] = newval;
			}

			newval = val;
			upd = node(now.l-1,now.r,now.k,0);
			if (use[upd.l][upd.r][upd.k][upd.pos] == false ||
					dp[upd.l][upd.r][upd.k][upd.pos] < newval)
			{
				if (use[upd.l][upd.r][upd.k][upd.pos] == false)
					Q.push(upd);
				use[upd.l][upd.r][upd.k][upd.pos] = true;
				dp[upd.l][upd.r][upd.k][upd.pos] = newval;
			}
		}
		if (now.r+1 < n)
		{
			val = dp[now.l][now.r][now.k][now.pos]-now.k*(a[now.r+1].pos-a[posnow].pos);

			newval = val+a[now.r+1].val;
			upd = node(now.l,now.r+1,now.k-1,1);
			if (use[upd.l][upd.r][upd.k][upd.pos] == false ||
					dp[upd.l][upd.r][upd.k][upd.pos] < newval)
			{
				if (use[upd.l][upd.r][upd.k][upd.pos] == false)
					Q.push(upd);
				use[upd.l][upd.r][upd.k][upd.pos] = true;
				dp[upd.l][upd.r][upd.k][upd.pos] = newval;
			}

			newval = val;
			upd = node(now.l,now.r+1,now.k,1);
			if (use[upd.l][upd.r][upd.k][upd.pos] == false ||
					dp[upd.l][upd.r][upd.k][upd.pos] < newval)
			{
				if (use[upd.l][upd.r][upd.k][upd.pos] == false)
					Q.push(upd);
				use[upd.l][upd.r][upd.k][upd.pos] = true;
				dp[upd.l][upd.r][upd.k][upd.pos] = newval;
			}

		}
	}
	return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i].pos);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i].val);
		a[n].pos = 0;
		a[n++].val = 0;
		sort(a,a+n);
		printf("%d\n",gao());
	}
	return 0;
}
