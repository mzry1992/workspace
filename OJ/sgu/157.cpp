#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,table[14];
int res;

void DFS(int now,int id)
{
	for (int i = n-1;i > id;i--)
		printf("  ");
		for (int i = 0;i <= n;i++)
			printf("%d ",table[i]);
		printf("\n");

	if (id == 0)
	{
		res++;
		return;
	}
	DFS(now);
	for (int i = 1;i <= n;i++)
		if (table[i] == id && table[i-1] == id-1)
		{
			swap(table[i],table[now]);
			DFS(i);
			swap(table[i],table[now]);
		}
}

int main()
{
	freopen("data.in","r",stdin);

    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        table[i] = i;
    table[n] = -1;

    res = 0;
    DFS(n,n-1);
    printf("%d\n",res);
    return 0;
}

