#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct fac
{
    long long a,b,c;
    fac(){}
    fac(int _a,int _c)
    {
        a = _a;
        b = c = _c;
        int gcd = __gcd(a,b);
        a /= gcd;
        b /= gcd;
    }
    bool operator < (const fac& fb)const
    {
        return a*fb.b < b*fb.a;
    }
};

priority_queue<fac> Q;
int n,m;
fac now;
long long gcd;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        while (!Q.empty())  Q.pop();
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
        {
            int a,c;
            scanf("%d%d",&a,&c);
            Q.push(fac(c,a));
        }
        for (int i = 0;i < m-1;i++)
        {
            now = Q.top();
            Q.pop();
            //printf("get : %lld/%lld\n",now.a,now.b);
            now.a = now.a*(now.c-1);
            now.b = now.b*now.c;
            gcd = __gcd(now.a,now.b);
            now.a /= gcd;
            now.b /= gcd;
            //printf("put : %lld/%lld\n",now.a,now.b);
            Q.push(now);
        }
        now = Q.top();
        printf("%lld/%lld\n",now.a,now.b);
    }
	return 0;
}
