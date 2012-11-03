#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    freopen("data.in","w",stdout);
	int totcas = 200;
	for (int cas = 1;cas <= totcas;cas++)
	{
	    int n,k,m;
	    n = rand()%41;
	    k = rand()%20+1;
	    m = rand()%20+1;
	    //n = 40;
	    //k = m = 20;
	    printf("%d %d %d\n",n,k,m);
	    for (int i = 0;i < m;i++)
	        printf("%d ",rand()%99+1);
	    printf("\n");
	    for (int i = 0;i < m;i++)
	        printf("%d ",rand()%101);
	    printf("\n");
	    for (int i = 0;i < n;i++,puts(""))
            for (int j = 0;j < m;j++)
                printf("%d ",rand()%2);
	}
	printf("0 0 0\n");
	return 0;
}
