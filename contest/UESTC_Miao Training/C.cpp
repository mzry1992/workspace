#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int mod[3] = {19921005, 1000000007, 10007};
const int mut[3] = {127, 129, 157};
int id[10000][10][3];
char buf[100],tmp[100];
struct value
{
	int a,b,c;
	value(){}
	value(int _a,int _b,int _c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	bool operator < (const value& t) const
	{
		if (a == t.a)
			if (b == t.b)
				return c < t.c;
			else
				return b < t.b;
		else
			return a < t.a;
	}
};

map<pair<value, value>, int> check;
int n,m;

void Gao()
{
	for (int i = 0;i < m;i++)
		for (int j = i+1;j < m;j++)
		{
			check.clear();
			for (int k = 0;k < n;k++)
			{
				pair<value, value> tmp = make_pair(value(id[k][i][0], id[k][i][1], id[k][i][2]), value(id[k][j][0], id[k][j][1], id[k][j][2]));
				if (check.find(tmp) != check.end())
				{
					printf("NO\n%d %d\n%d %d\n",check[tmp] + 1, k + 1, i + 1, j + 1);
					return;
				}
				check[tmp] = k;
			}
		}
	puts("YES");
}

int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		gets(buf);
		for (int i = 0;i < n;i++)
		{
			gets(buf);
			int pre = 0;
			for (int j = 0;j < m;j++)
			{
				id[i][j][0] = id[i][j][1] = id[i][j][2] = 0;
				for (;buf[pre] != 0 && buf[pre] != ',';pre++)
				{
					for (int k = 0;k < 3;k++)
						id[i][j][k] = ((long long)id[i][j][k] * mut[k] + buf[pre]) % mod[k];
				}
				pre++;
			}
		}
		Gao();
	}
	return 0;
}
