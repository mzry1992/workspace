#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
	    int res = 1000000000;
	    for (int i = 0;i < m;i++)
	    {
	        int u,d;
	        scanf("%d%d",&u,&d);
	        int x = (n*d)/(u+d) + 1;
	        res = min(res,u*x-(n-x)*d);
	    }
	    printf("%d\n",res);
	}
    return 0;
}

