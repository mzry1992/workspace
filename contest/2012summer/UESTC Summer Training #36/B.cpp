#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char dic[110][110];
int n,m;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < m;i++)
            scanf("%s",dic[i]);
        printf("%s\n",dic[(n-1)%m]);
    }
	return 0;
}
