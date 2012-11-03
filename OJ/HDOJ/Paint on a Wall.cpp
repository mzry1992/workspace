#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char a[2][9];

void BFS()
{

}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < 2;i++)
            scanf("%s",a[i]);
        printf("Case #%d: %d\n",cas,BFS());
	}
	return 0;
}
