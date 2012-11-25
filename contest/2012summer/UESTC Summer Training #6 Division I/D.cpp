#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<30;
int n,C,ans;
int sumL[40005],sumR[40005];
int pos[50005];
struct N
{
    int val;
    int kind;
}L[20005],R[20005],num[40005];
bool cmp(N a,N b)
{return a.val<b.val;}
bool check1(int low,int p,int kind)
{
    int LK,RK,res;
    LK=sumL[low-1]+1;
    RK=n-sumR[pos[L[p].val]];
    if(kind==1)
        RK++;
    while (abs(LK-RK)>=n)
        puts("FUCK");
    if(LK==RK)
        res=LK*2;
    else if(LK>RK)
    {
        int tmp=sumR[pos[L[p].val]]-sumR[low];
        if(RK+tmp>=LK-1)
            res=LK*2-2;
        else
            res=(RK+tmp)*2+(LK-RK-tmp)*(LK-RK-tmp-1);
    }
    else
    {
        int tmp=sumL[pos[L[p].val]-1]-sumL[low];
        if(LK+tmp>=RK-1)
            res=(RK-1)*2;
        else
            res=(LK+tmp)*2+(RK-LK-tmp)*(RK-LK-tmp-1);
    }
    if(res<=C)
        return true;
    else
        return false;
}
bool check2(int low,int p,int kind)
{
    int LK,RK,res;
    LK=sumL[low-1];
    RK=n-sumR[pos[R[p].val]];
    if(kind==1)
        RK++;
    while (abs(LK-RK)>=n)
        puts("FUCK");
    if(LK==RK)
        res=LK*2;
    else if(LK>RK)
    {
        int tmp=sumR[pos[R[p].val]-1]-sumR[low];
        if(RK+tmp>=LK-1)
            res=LK*2-2;
        else
            res=(RK+tmp)*2+(LK-RK-tmp)*(LK-RK-tmp-1);
    }
    else
    {
        int tmp=sumL[pos[R[p].val]]-sumL[low];
        if(LK+tmp>=RK-1)
            res=(RK-1)*2;
        else
            res=(LK+tmp)*2+(RK-LK-tmp)*(RK-LK-tmp-1);
    }
    if(res<=C)
        return true;
    else
        return false;
}
void solve1(int p,int kind)
{
    int l,r,mid;
    l=sumL[p]+1;r=n;mid=(l+r)>>1;
    if(!check1(p,n,kind))
        return;
    while(l<r)
    {
        mid=l+r>>1;
        if(check1(p,mid,kind))
            r=mid;
        else
            l=mid+1;
    }
    ans=max(ans,num[p].val-L[l].val);
}
void solve2(int p,int kind)
{
    int l,r,mid;
    l=sumR[p]+1;r=n;mid=(l+r)>>1;
    if(!check2(p,n,kind))
        return;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check2(p,mid,kind))
            r=mid;
        else
            l=mid+1;
    }
    ans=max(ans,num[p].val-R[l].val);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&C);
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i].val);
            L[i].val=num[i].val;
            num[i].kind=1;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i+n].val);
            R[i].val=num[i+n].val;
            num[i+n].kind=2;
        }
        if(n==1)
        {
            printf("%d\n",num[1].val-num[2].val);
            continue;
        }
        sort(num+1,num+2*n+1,cmp);
        sort(L+1,L+n+1,cmp);
        sort(R+1,R+n+1,cmp);
        sumL[0]=0;sumR[0]=0;
        for(i=1;i<=2*n;i++)
        {
            pos[num[i].val]=i;
            sumL[i]=sumL[i-1];
            sumR[i]=sumR[i-1];
            if(num[i].kind==1)
                sumL[i]++;
            else if(num[i].kind==2)
                sumR[i]++;
        }
        ans=-inf;
        int res;
        for(i=1;i<=2*n;i++)
        {
            int LK,RK;
            if(num[i].kind==1)
            {
                LK=sumL[i-1];
                RK=n-sumR[i];
                res=min(LK,RK)*2+abs(LK-RK)*(abs(LK-RK)-1);
              //  printf("%d %d %d %d\n",LK,RK,res,C);
                if(i>1&&res<=C&&abs(LK-RK)<n)
                    ans=max(ans,num[i].val-num[i-1].val);
                if(ans<0)
                {
                    if(sumL[i]<n)
                        solve1(i,0);
                    if(sumR[i]<n)
                        solve2(i,0);
                }
            }
            else if(num[i].kind==2)
            {
                LK=sumL[i];
                RK=n-sumR[i]+1;
                res=min(LK,RK)*2+abs(LK-RK)*(abs(LK-RK)-1);
               // printf("%d %d %d %d\n",LK,RK,res,C);
                if(i>1&&res<=C&&abs(LK-RK)<n)
                    ans=max(ans,num[i].val-num[i-1].val);
                if(ans<0)
                {
                    if(sumL[i]<n)
                        solve1(i,1);
                    if(sumR[i]<n)
                        solve2(i,1);
                }
            }
        }
        printf("%d\n",ans);
	}
	return 0;
}
