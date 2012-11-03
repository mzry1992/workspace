#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200010;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    int *s = str;
    int *x=wx,*y=wy,*t,p;
    int i,j;
    for(i=0; i<m; i++)wss[i]=0;
    for(i=0; i<n; i++)wss[x[i]=s[i]]++;
    for(i=1; i<m; i++)wss[i]+=wss[i-1];
    for(i=n-1; i>=0; i--)sa[--wss[x[i]]]=i;
    for(j=1,p=1; p<n && j<n; j*=2,m=p)
    {
        for(i=n-j,p=0; i<n; i++)y[p++]=i;
        for(i=0; i<n; i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
        for(i=0; i<n; i++)wv[i]=x[y[i]];
        for(i=0; i<m; i++)wss[i]=0;
        for(i=0; i<n; i++)wss[wv[i]]++;
        for(i=1; i<m; i++)wss[i]+=wss[i-1];
        for(i=n-1; i>=0; i--)sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0; i<n; i++)
            x[sa[i]]=cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(int i=0; i<n; i++) rank[sa[i]]=i;
    for(int i=0,j=0,k=0; i<n; height[rank[i++]]=k)
        if(rank[i]>0)
            for(k?k--:0,j=sa[rank[i]-1]; i+k < n && j+k < n && str[i+k]==str[j+k]; k++);
}

int n,k,l1,l2,a[maxn],sa[maxn],rank[maxn],height[maxn];
char s1[maxn],s2[maxn];
int head,tail,lcp[maxn];

int main()
{
    while (true)
    {
        scanf("%d",&k);
        if (k == 0) break;
        scanf("%s%s",s1,s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        n = l1+l2+1;

        for (int i = 0; i < l1; i++)
            a[i] = s1[i];
        a[l1] = '$';
        for (int i = 0; i < l2; i++)
            a[l1+1+i] = s2[i];
        da(a,sa,rank,height,n,256);
        long long res = 0,tsum;

        for (int i = 1;i < n;i++)
            if (height[i] < k)
            {
                tsum = 0;
                head = tail = maxn;
            }
            else
            {
                //用height[i]去更新lcp
                for (int j = head;j < tail;j++)
                {
                    if (lcp[j] > height[i])//比height[i]的lcp都变成height
                    {
                        tsum -= lcp[j]-height[i];//然后答案减少相应的数量
                        lcp[j] = height[i];
                    }
                    else
                        break;
                }
                //如果sa[i-1]是B串就入队
                if (sa[i-1] > l1)
                {
                    lcp[--head] = height[i];
                    tsum += lcp[head]-k+1;//答案加上相应的数量
                }
                //如果sa[i]是A串就累加答案
                if (sa[i] < l1)
                    res += tsum;

            }

        for (int i = 1;i < n;i++)
            if (height[i] < k)
            {
                tsum = 0;
                head = tail = maxn;
            }
            else
            {
                //用height[i]去更新lcp
                for (int j = head;j < tail;j++)
                {
                    if (lcp[j] > height[i])
                    {
                        tsum -= lcp[j]-height[i];
                        lcp[j] = height[i];
                    }
                    else
                        break;
                }
                //如果sa[i-1]是A串就入队
                if (sa[i-1] < l1)
                {
                    lcp[--head] = height[i];
                    tsum += lcp[head]-k+1;
                }
                //如果sa[i]是B串就累加答案
                if (sa[i] > l1)
                    res += tsum;
            }

        printf("%I64d\n",res);
    }
    return 0;
}

