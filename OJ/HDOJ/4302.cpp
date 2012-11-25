#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int L,n;
int tree[100003];
int read(int k)
{
	int sum = 0;
	for (;k;k ^= k&-k)
		sum += tree[k];
	return sum;
}
void update(int k,int v)
{
	for (;k <= L;k += k&-k)
		tree[k] += v;
}
int find_kth(int k)
{
	int idx = 0;
	for (int i = 20;i >= 0;i--)
	{
		idx |= 1<<i;
		if (idx <= L && tree[idx] < k)
			k -= tree[idx];
		else
			idx ^= 1<<i;
	}
	return idx+1;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%d%d",&L,&n);
		L++;
		memset(tree,0,sizeof(tree));
		int nowpos = 1;
		int ans = 0;
		int dir = 1;// <- -1 : 1 ->
		for (int i = 0;i < n;i++)
		{
			int typ;
			scanf("%d",&typ);
			if (typ == 0)
			{
				int x;
				scanf("%d",&x);
				x++;
				update(x,1);
			}
			else
			{
				int sum = read(nowpos);
				int prepos = find_kth(sum);
				int nxtpos = find_kth(sum+1);
				int pre = read(prepos)-read(prepos-1);
				int	nxt = read(nxtpos)-read(nxtpos-1);
				int topos = -1;
				if (pre != 0 && nxt != 0)
				{
					if (nowpos-prepos < nxtpos-nowpos)
						topos = prepos;
					else if (nowpos-prepos > nxtpos-nowpos)
						topos = nxtpos;
					else
					{
						if (dir == -1)	topos = prepos;
						else	topos = nxtpos;
					}
				}
				else if (pre != 0)
					topos = prepos;
				else if (nxt != 0)
					topos = nxtpos;
				if (topos != -1)
				{
					if (topos < nowpos)
						dir = -1;
					else if (topos > nowpos)
						dir = 1;
					ans += abs(nowpos-topos);
					nowpos = topos;
					update(nowpos,-1);
				}
			}
		}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
