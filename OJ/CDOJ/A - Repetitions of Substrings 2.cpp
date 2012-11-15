#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) ws[i]=0;
       for(i=0;i<n;i++) ws[wv[i]]++;
       for(i=1;i<m;i++) ws[i]+=ws[i-1];
       for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int RMQ[maxn];
int mm[maxn];
int best[20][maxn];
void initRMQ(int n)
{
     int i,j,a,b;
     for(mm[0]=-1,i=1;i<=n;i++)
     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
     for(i=1;i<=n;i++) best[0][i]=i;
     for(i=1;i<=mm[n];i++)
     for(j=1;j<=n+1-(1<<i);j++)
     {
       a=best[i-1][j];
       b=best[i-1][j+(1<<(i-1))];
       if(RMQ[a]<RMQ[b]) best[i][j]=a;
       else best[i][j]=b;
     }
     return;
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    int t;
    a=rank[a];b=rank[b];
    if(a>b) {t=a;a=b;b=t;}
    return(height[askRMQ(a+1,b)]);
}

int k, len, r[maxn], sa[maxn];
char s[maxn];

int maxrep[maxn];

int main()
{
    freopen("in.txt","r",stdin);

	int i, j, t, L;
	long long ans;

	while( scanf("%s %d", s, &k) != EOF )
	{
		if( k == 1 )
		{
			len = strlen(s);
			printf("%lld\n", (long long)len*(long long)(len+1)/2);
			continue;
		}
		ans = 0;
		len = strlen(s);
		for( i = 0; i < len; ++i )	maxrep[i] = 1;
		for( i = 0; i < len; ++i )	r[i] = s[i] - 'a' + 10;
		r[len] = 0;
		da(r, sa, len+1, 50);
		calheight(r, sa, len);
		for( i = 1; i <= len; ++i )	RMQ[i] = height[i];
		initRMQ(len);

		for( L = 1; L*k <= len; ++L )
		{
			for( i = L; i < len; i += L )	if( maxrep[i-L] == 1 )
			{
				t = lcp(i-L, i);
				if( t )
				{
					j = 0;
					while( j < L && i-L >= j && s[i-L-j] == s[i-j] )
					{
						if( t >= L && lcp(i-L-j, i-j) >= (k-1)*L )
							maxrep[i-L-j] = max(maxrep[i-L-j], t/L+1);
						++t, ++j;
					}
				}
			}
		}

		for( i = 0; i < len; ++i )	if( maxrep[i] >= k )
			ans += maxrep[i] - k + 1;
		printf("%lld\n", ans);
	}

	return 0;
}
