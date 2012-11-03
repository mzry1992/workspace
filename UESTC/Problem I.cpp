#include <iostream>
#include <cstdio>
using namespace std;

int tf[3],mod;

int check(int a,int b)
{
    mod = 10;
    for (int i = 1;i <= b;i++)
        mod *= 10;
    tf[0] = 0;
    tf[1] = 1;
    for (int i = 2;;i++)
    {
        tf[2] = (tf[0]+tf[1])%mod;
        if (tf[2] != 0 && tf[2]%(mod/10) == 0)
        {
            a--;
            if (a == 0) return i;
        }
        tf[0] = tf[1];
        tf[1] = tf[2];
    }
}

int f[1000];

int power(int x,int y)
{
    int ret=1;
    for (int a=x;y;y>>=1,a*=a)
        if (y&1)
            ret*=a;
    return ret;
}

void init()
{
    f[1]=15;
    f[2]=150;
    f[3]=750;
    for (int i=4;i<10;i++)
        f[i]=f[i-1]*10;
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        int k=n;
        if (m==1)
        {
            k+=k/10;
            k-=k/5;
            for (int i=500,sng=1;k/i;i*=10,sng*=-1)
                k+=k/i*sng;
        }
        else if (m==2)
        {
            k+=k/5;
            for (int i=50,sng=-1;k/i;i*=10,sng*=-1)
                k+=k/i*sng;
        }
        else
        {
            for (int i=10,sng=1;k/i;i*=10,sng*=-1)
                k+=k/i*sng;
        }
        printf("%d\n",f[m]*k);
        cout << check(n,m) << endl;
    }
    return 0;
}
