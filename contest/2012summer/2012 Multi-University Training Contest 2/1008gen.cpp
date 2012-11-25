#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("1008.in","w",stdout);
	for (int i = 0;i < 10;i++)
	{
	    printf("10\n");
	    for (int j = 0;j < 10;j++)
            printf("%d ",rand()%1000+1);
        printf("\n");
	}
	return 0;
}
