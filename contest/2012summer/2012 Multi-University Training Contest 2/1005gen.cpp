#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("1005.in","w",stdout);
	for (int i = 0;i < 100;i++)
	{
	    printf("3\n");
	    for (int j = 0;j < 3;j++)
            printf("%d %d\n",rand()%10+1,rand()%10+1);
        printf("%d\n",rand()%20+1);
	}
	return 0;
}

