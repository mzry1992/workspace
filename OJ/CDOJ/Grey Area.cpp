#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int cnt[100];
int main()
{
    int n,w;
    while (scanf("%d%d",&n,&w)>0)
    {
        memset(cnt,0,sizeof(cnt));
        int x;
        int max=0,maxi=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            cnt[x/w]++;
            if (x/w>max) max=x/w;
        }
        for (int i=0;i<=max;i++)
        {
            if (cnt[i]>maxi) maxi=cnt[i];
        }
        double rate=1.0/(double)max;
        double now=1.0;
        double sum=0;
        for (int i=0;i<=max;i++)
        {
            sum+=(double)cnt[i]/(double)maxi*now;
            now-=rate;
        }
        sum+=0.01;
        printf("%lf\n",sum);
    }
}
