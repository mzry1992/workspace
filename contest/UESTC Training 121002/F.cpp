#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[20];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        int tim = 0;
        while (true)
        {
            bool flag = true;
            for (int i = 0;i < n;i++)
                if (a[i] != 0)  flag = false;
            if (n == 1 || flag)   break;

            n--;
            tim++;
            for (int i = 0;i < n;i++)
                a[i] = a[i+1]-a[i];
        }
        if (a[0] == 0)
        {
            for (int i = 0;i < tim;i++)
                printf("z");
            printf("ap!\n");
        }
        else if (a[0] > 0)
            puts("*fizzle*");
        else
            puts("*bunny*");
	}
    return 0;
}

