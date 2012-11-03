#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[50001]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},b[50001],ini[50001]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int ans[50001];
int main()
{
    //freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    for (int i=1;i<=50000;i++)
        a[i]=i;
    int n,m;
    for (int n=1;n<=15;n++)
    {
        for (int m=1;m<=n;m++)
        {
           int c=0,cnt=0;
           memset(ans,-1,sizeof(ans));
           while (true)
           {
              int j=n/m+1;
              for (int i=1;i<=n;i++)
              {
                if (i%m==0) b[i]=a[i/m];
                else b[i]=a[j++];
              }
              for (int i=1;i<=n;i++)
              {
                if (b[i]==i && ans[i]<0)
                {
                    cnt++;ans[i]=c;
                }
                a[i]=b[i];
              }
              c++;
              if (cnt>=n) break;
              //int ch=getchar();
           }
           for (int i=1;i<=n;i++) printf("%d ",ans[i]);
           puts("");
        }
        puts("");
    }
}

