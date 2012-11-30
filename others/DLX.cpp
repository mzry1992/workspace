#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 110;
const int maxm = 110;
const int maxp = 310+maxn+maxm;
int L[maxp],R[maxp];
int U[maxp],D[maxp];
int row[maxn],col[maxm];
int N,M,nil,cur;

void init(int n,int m)
{
	cur = 0;
	nil = cur++;
	N = n;
	M = m;
	for (int i = 0;i < N;i++)
	{
		L[cur] = R[cur] = nil;
		row[i] = cur++;
	}
	for (int i = 0;i < M;i++)
	{
		U[cur] = D[cur] = nil;
		col[i] = cur++;
	}
}

void build(int g[maxn][maxm]int n,int m)
{

}

int g[maxn][maxm];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		init(n,m);
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				scanf("%d",&g[i][j]);
		build(g);
	}
	return 0;
}
