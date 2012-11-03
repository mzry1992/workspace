#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        int res = 0;
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            if (i > 0)
            {
                int cnt = 0;
                for (int j = 0;j < i;j++)
                    if (a[j] <= a[i])
                        res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

