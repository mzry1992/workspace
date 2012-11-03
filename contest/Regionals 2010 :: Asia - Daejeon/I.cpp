#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
const int inf = 1<<29;
long long ans;
struct N
{
    int x,y;
    int disA,disB;
}rest[50005];
int calc(N a,N b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
bool cmp(N a,N b)
{
    return a.disA<b.disA;
}
long long solve(int a,int b)
{
    if(a==0||b==0||a+b-2<rest[0].disB)
        return 0;
    long long len=a+b-1-rest[0].disB;
    long long ret=(long long)2*(len/2)*(len/2);
    if(len%2==1)
        ret+=len;
    long long sum=0,over;
    if(len%2==1)
    {
        if(rest[0].y+len/2>=n)
        {
            over=rest[0].y+len/2-n+1;
            sum+=over*over;
        }
        if(rest[0].y-len/2<0)
        {
            over=len/2-rest[0].y;
            sum+=over*over;
        }
    }
    else
    {
        if(rest[0].y+len/2-1>=n)
        {
            over=rest[0].y+len/2-n;
            sum+=over*(over+1);
        }
        if(rest[0].y-len/2+1<0)
        {
            over=len/2-rest[0].y-1;
            sum+=over*(over+1);
        }
    }
    return ret-sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d%d",&n,&m);
	    int i;
	    for(i=0;i<2;i++)
            scanf("%d%d",&rest[i].x,&rest[i].y);
        rest[0].disA=rest[1].disB=0;
        rest[0].disB=rest[1].disA=calc(rest[0],rest[1]);
        for(i=2;i<m;i++)
        {
            scanf("%d%d",&rest[i].x,&rest[i].y);
            rest[i].disA=calc(rest[i],rest[0]);
            rest[i].disB=calc(rest[i],rest[1]);
        }
        sort(rest,rest+m,cmp);
        int mi=inf,L;
        ans=0;
        L=0;
        for(i=0;i<m;i++)
        {
            if(rest[i].disA>L)
            {
                ans+=solve(rest[i].disA,mi)-solve(L,mi);
                L=rest[i].disA;
            }
            mi=min(mi,rest[i].disB);
        }
        printf("%lld\n",ans);
	}
    return 0;
}


