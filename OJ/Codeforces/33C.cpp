#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[100001],sum,psum[100001],tmax,res;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        sum = psum[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            a[i] = -a[i];
            sum += a[i];
            psum[i] = psum[i-1]+a[i];
        }
        res = sum;
        tmax = psum[0];
        for (int i = 1;i <= n;i++)
        {
            res = max(res,sum-2*(psum[i]-tmax));
            tmax = max(tmax,psum[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
