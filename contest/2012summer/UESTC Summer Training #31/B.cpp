#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[4000],tmp[2000];
int a[4000],sum[4000];

void Gao(char a[],int len)
{
    int i = 0,j = 1,k = 0;
    while (i < len && j < len && k < len)
    {
        int cmp = a[(j+k)%len]-a[(i+k)%len];
        if (cmp == 0)
            k++;
        else
        {
            if (cmp > 0)
                j += k+1;
            else
                i += k+1;
            if (i == j) j++;
            k = 0;
        }
    }
    int pos = min(i,j);
    for (i = 0;i < len;i++)
        tmp[i] = s[(pos+i)%len];
    for (i = 0;i < len;i++)
        s[i] = tmp[i];
}

int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s",s);
    int n=strlen(s);
    Gao(s,n);
    puts(s);
    for (int i=0;i<n;i++)
        s[n+i]=s[i];
    int ans=0,pos;
    for (int l=1;l<=n/2;l++)
    {
        for (int j=0;j<n;j++)
            a[j]=s[j]!=s[l+j];
        for (int j=n;j<n+n;j++)
            a[j]=a[j-n];
        for (int i=0;i<n;i++)
            printf("%d ",a[i]);
        puts("");
        sum[0]=a[0];
        for (int j=1;j<n*2;j++)
            sum[j]=sum[j-1]+a[j];
        for (int j=0;j<n;j++)
        {
            printf("%d %d %d\n",l,j,sum[j+n+l-1]-sum[n+j-1]);
            if (sum[j+n+l-1]-sum[j+n-1]<=k)
            {
                ans=l;
                pos=j;
                break;
            }
        }
    }
    if (pos>=n)
        pos-=n;
    for (int i=pos;i<ans*2+pos;i++)
        putchar(s[i]);
    puts("");
    return 0;
}
