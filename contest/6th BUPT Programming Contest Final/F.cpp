#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[8],b,c[8];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    for (int i = 0;i < 8;i++)
            scanf("%d",&a[i]);
        scanf("%d",&b);
        for (int i = 0;i < 8;i++)
            c[i] = i;
        bool res = false;
        do{
            int v = 0;
            for (int i = 0;i < 8;i++)
                v = v*10+a[c[i]];
            if (v >= 10000000)
                if (v%b == 0)
                {
                    res = true;
                    break;
                }
        }while (next_permutation(c,c+8));
        if (res == true)
            puts("Yes");
        else
            puts("No");
	}
	return 0;
}
