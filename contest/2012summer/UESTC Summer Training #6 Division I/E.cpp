#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[110];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d",&n);
	    for (int i = n;i >= 0;i--)
            scanf("%d",&a[i]);
	    if (n == 0)
            puts("0");
        else
        {
            for (int i = n;i >= 1;i--)
            {
                int v;
                printf("%d",a[i]*i);
                if (i > 1)  printf(" ");
            }
            printf("\n");
        }
	}
	return 0;
}
