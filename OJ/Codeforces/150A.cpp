#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

set<int> hash;
pair<int,int> w[20];
int nxt[20];
int a[100000];
int n;

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for (int i = 0;i < 20;i++)
			nxt[i] = -1;

		hash.clear();
		for (int i = n-1;i >= 0;i--)
		{
			for (int j = 0;j < 20;j++)
			{
				if (((i>>j)&1) == 1)
					nxt[j] = i;
				w[j] = make_pair(nxt[j],j);
			}
			sort(w,w+20);
			int ans = a[i];
			for (int j = 0;j < 20;j++)
			{
				if (w[j].first != -1)
					ans |= (1<<w[j].second);
				if (j+1 == 20 || w[j].first != w[j+1].first)
					hash.insert(ans);
			}
		}
		printf("%d\n",hash.size());
	}
	return 0;
}
