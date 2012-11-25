#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,x[2000],mx[2000],h[2000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&n);
        bool check = true;
        for (int i = 0;i < n-1;i++)
        {
            scanf("%d",&x[i]);
            x[i]--;
            if (x[i] <= i)  check = false;
            mx[i] = n-1;
        }
        for (int i = 0;i < n-1;i++)
            for (int j = i+1;j < x[i];j++)
                mx[j] = min(mx[j],x[i]);
        for (int i = 0;i < n-1;i++)
            if (mx[i] < x[i])
                check = false;
        printf("Case #%d: ",cas);
        if (check == false)
        {
            puts("Impossible");
            continue;
        }
        h[n-1] = 0;
        for (int i = n-2;i >= 0;i--)
        {

        }
	}
	return 0;
}
