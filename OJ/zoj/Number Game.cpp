#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[3],b[3];

int main()
{
    int cas;
    scanf("%d",&cas);
    for (int ft = 1; ft <= cas; ft++)
    {
        for (int i = 0; i < 3; i++)
            scanf("%d",&a[i]);
        for (int i = 0; i < 3; i++)
            scanf("%d",&b[i]);
        sort(a,a+3);
        sort(b,b+3);
        while (a[2] > b[2])
        {
            if (a[0]+a[1]-1 != a[2])    break;
            a[2] = a[1];
            a[1] = a[0];
            a[0] = a[2]-a[1]+1;
            sort(a,a+3);
        }
        int cnt = 0;
        for (int i = 0;i < 3;i++)
            if (a[i] == b[i])
                cnt++;
        if (cnt >= 2)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
