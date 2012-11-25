#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[10];
int n,a[3000];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%s",buf);
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        if (strcmp(buf,"Faster") == 0)
        {
            for (int i = 1;i < n;i++)
                if (a[0] > a[i])
                    a[0] = a[i];
        }
        else
        {
            for (int i = 1;i < n;i++)
                if (a[0] < a[i])
                    a[0] = a[i];
        }
        printf("%d\n",a[0]);
	}
	return 0;
}
