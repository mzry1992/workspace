#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct every
{
    int a,b,c,now,wan;
    bool iss;
}p[15];
int cnt;
int main()
{
    int n;
    int cas=0;
    while (scanf("%d",&n)>0,n!=0)
    {
        printf("Case %d: ",++cas);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
            p[i].wan=p[i].c;
        }
        bool issolve=false;
        for (int i=1;i<=100000;i++)
        {
            cnt=0;
            for (int j=1;j<=n;j++)
            {
                if (p[j].wan<=p[j].a)
                {
                    p[j].iss=false;
                }
                else
                {
                    p[j].iss=true;cnt++;
                }
                //p[j].wan++;
                if (p[j].wan==p[j].a+p[j].b) p[j].wan=0;
            }
            if (cnt==0)
            {
                issolve=true;
                printf("%d\n",i);
                break;
            }
            for (int j=1;j<=n;j++)
            {
                if (p[j].wan==p[j].a)
                {
                    if (cnt<=n-cnt) p[j].wan=0;
                    else p[j].wan=p[j].a+1;
                }
                else p[j].wan++;
            }
        }
        if (!issolve) printf("-1\n");
    }
}
