#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int count(int x)
{
    int ret=0;
    while (x/=10)
        ret++;
    return ret+1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        if (n==100000000)
        {
            puts("None");
            continue;
        }
        int len=count(n);
        int H=1,G=1,mod;
        for (int i=0;i<(len+1)/2;i++)
            H*=10;
        for (int i=0;i<len-(len+1)/2;i++)
            G*=10;
        mod=H*G;
        vector<int> B;
        for (int i=0;i<H;i++)
            if ((long long)i*i%H==n%H)
                B.push_back(i);
        int ans=0x7fffffff;
        for (int i=0;i<B.size();i++)
            for (int j=0;j<G;j++)
                if ((long long)(j*H+B[i])*(j*H+B[i])%mod==n)
                    ans=min(ans,j*H+B[i]);
        if (ans==0x7fffffff)
            puts("None");
        else
            printf("%d\n",ans);
    }
	return 0;
}
