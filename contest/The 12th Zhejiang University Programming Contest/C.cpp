#include<iostream>
#include<algorithm>
#include <cstdio>
using namespace std;

long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if (b)
    {
        long long ret = ex_gcd(b,a%b,x,y),tmp = x;
        x = y;
        y = tmp-(a/b)*y;
        return ret;
    }
    else
    {
        x = 1;
        y = 0;
        return a;
    }
}

long long D;

long long solve(long long a,long long b)
{
    long long x,y;
    long long g=ex_gcd(a,b,x,y);
    if (g<0)
    {
        g=-g;
        x=-x;
    }
    x*=D/g;
    x%=b/g;
    if (x<0)
        x+=b/g;
    y=(D-a*x)/b;
    //cout<<x<<" "<<y<<endl;
    long long ret=(abs(x)+abs(y));
    x-=b/g;
    y=(D-a*x)/b;
    return min(ret,(abs(x)+abs(y)));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a,b,A,B;
        cin>>A>>B>>a>>b;
        D=abs(A-B);
        if (D%__gcd(a,b))
        {
            puts("-1");
            continue;
        }
        long long ans=solve(a,a+b);
        ans=min(ans,solve(b,a+b));
        ans=min(ans,solve(a,b));
        ans=min(ans,solve(b,a));
        cout<<ans<<endl;
    }
    return 0;
}
