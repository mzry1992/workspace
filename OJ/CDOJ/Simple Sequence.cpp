#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

long long sum=0;
int main()
{
    freopen("simple.out","w",stdout);
    int m=0;
    for (int i=2;i<=1000;i+=2)
    {
        int n=i,cnt=0;
        while (n%2==0)
        {
            n>>=1;cnt++;
        }
        //printf("%d ",m+1);
        for (int j=1;j<=cnt;j++)
        {
            printf("%d %d %d\n",++m,i,sum+i);
           // ++m;
            sum+=i;
        }
    }
}
