#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long count(long long x)
{
    long long tot=0;
    for (long long i=2;i<=x*2;i*=4)
        tot+=(x+i/2)/i;
    //cout<<x<<" "<<tot<<endl;
    return tot;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        long long n;
        cin >> n;
        bool flag=~n&1;
        if (flag)
        {
            n--;
        }
        n/=2;
        n++;
        long long l=1,r=(long long)n*10;
        while (l<r)
        {
            int mid=l+r>>1;
            if (count(mid)>=n)
                r=mid;
            else
                l=mid+1;
        }
        if (flag)
            l<<=1;
        cout<<l<<endl;
    }
    return 0;
}
