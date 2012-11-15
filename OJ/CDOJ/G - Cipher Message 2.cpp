#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxL = 5000;
int k;
char ts[2*MaxL+10];
int Suffix[MaxL+10],Rank[MaxL+10],Height[MaxL+10],Ts[MaxL+10];

int wa[MaxL+10],wb[MaxL+10],wv[MaxL+10],ws[MaxL+10];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void CalcSuffix(int *r,int *Suffix,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) Suffix[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(Suffix[i]>=j) y[p++]=Suffix[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) Suffix[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[Suffix[0]]=0,i=1;i<n;i++)
       x[Suffix[i]]=cmp(y,Suffix[i-1],Suffix[i],j)?p-1:p++;
     }
     return;
}
void CalcHeight(int *r,int *Suffix,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) Rank[Suffix[i]]=i;
     for(i=0;i<n;Height[Rank[i++]]=k)
     for(k?k--:0,j=Suffix[Rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}

int main()
{
    while (scanf("%d",&k) != EOF)
    {
        scanf("%s",ts);
        int tl = strlen(ts);
        for (int i = 0;i < tl;i++)
            ts[tl+i] = ts[i];
        bool first = true;
        for (int pos = 0;pos < tl;pos++)
        {
            int l = k;
            for (int i = 0;i < l;i++)   Ts[i] = ts[pos+i];
            Ts[l] = 0;
            CalcSuffix(Ts,Suffix,l+1,128);
            CalcHeight(Ts,Suffix,l);
            int res = 0;
            for (int i = 1;i <= l;i++)
                res += l-Suffix[i]-Height[i];
            if (first == false) printf(" ");
            first = false;
            printf("%d",res);
        }
        printf("\n");
    }
}
