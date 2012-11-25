#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 3000100;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int c0(int *r,int a,int b)
{
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b)
{
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0; i<n; i++) wv[i]=r[a[i]];
    for(i=0; i<m; i++) ws[i]=0;
    for(i=0; i<n; i++) ws[wv[i]]++;
    for(i=1; i<m; i++) ws[i]+=ws[i-1];
    for(i=n-1; i>=0; i--) b[--ws[wv[i]]]=a[i];
    return;
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0; i<tbc; i++) san[rn[i]]=i;
    for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0; i<ta&&j<tbc; p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(; i<ta; p++) sa[p]=wa[i++];
    for(; j<tbc; p++) sa[p]=wb[j++];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    dc3(str,sa,n,m);
    int i,j,k;
    for (i = 0; i < n; i++)   rank[sa[i]] = i;
    for (i = 0,j = 0,k = 0; i < n; height[rank[i++]] = k)
        if (rank[i] > 0)
            for (k?k--:0,j = sa[rank[i]-1]; i+k < n && j+k < n && str[i+k]==str[j+k]; k++);
}

int min(int a,int b)
{
    if (a < b)  return a;
    return b;
}

int n,m;
char a[maxn],b[maxn];
int sa[maxn],rank[maxn],height[maxn],ts[maxn];
int pa[maxn],pb[maxn],A[maxn];

void doit(int pa[])
{
    int len = 0;
    for (int i = 0; i < m; i++)
        ts[len++] = b[i];
    ts[len++] = '#';
    for (int i = 0; i < 2*n; i++)
        ts[len++] = a[i];
    ts[len] = 0;
    int j = 0;
    while (ts[j] == ts[j+1])
        j = j+1;
    A[1] = j;
    int k= 1;
    for (int i = 2;i < len;i++)
    {
        int Len = k+A[k]-1,L = A[i-k];
        if (L < Len-i+1)
            A[i] = L;
        else
        {
            j = std::max(0,Len-i+1);
            while (ts[i+j] == ts[j])
                j++;
            A[i] = j,k = i;
        }
    }
    for (int i = m+1;i < len;i++)
        pa[i-m-1] = A[i];
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);

    memset(ts,0,sizeof(ts));
    for (int i = 0; i < m; i++)
        ts[i] = ts[m+i] = b[i];
    for (int i = 0; i < n; i++)
        a[n+i] = a[i];
    a[2*n] = 0;
    da(ts,sa,rank,height,2*m,256);
    for (int i = 0; i < 2*m; i++)
        if (sa[i] < m)
        {
            for (int j = sa[i]; j < sa[i]+m; j++)
                b[j-sa[i]] = ts[j];
            break;
        }
    puts(b);

    //puts(a);

    doit(pa);

    std::reverse(b,b+m);
    std::reverse(a,a+2*n);

    doit(pb);
    std::reverse(pb,pb+2*n);
    std::reverse(a,a+2*n);

    int respos = 0,restim = n+1;
    for (int i = 0; i < n; i++)
        if (pa[i]+pb[i+m-1] >= m-1)
        {
            if (i < restim || n-i < restim)
            {
                respos = i;
                restim = min(i,n-i);
            }
        }
    //while (restim == n+1)   puts("fuck");
    //int diff = 0;
    //for (int j = 0;j < m;j++)
    //    if (a[respos+j] != b[j])
    //        diff++;
    //if (diff < m-1)
    //    printf("%d\n",pa[-50000000]);
    for (int j = 0; j < n; j++)
        putchar(a[respos+j]);
    puts("");
    return 0;
}
