#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct seg
{
	int left,right;
};
struct seg tree[100005*4];
int val[20][100005],sorted[100005],toleft[20][100005];
void build(int l,int r,int deep,int idx)
{
	tree[idx].left=l;
	tree[idx].right=r;
	if (l==r) return;
	int mid=(l+r)/2;
	int lsame=mid-l+1;
	for (int i=l;i<=r;i++)
	{
		if (val[deep][i]<sorted[mid])
			lsame--;
	}
	int lpos=l,rpos=mid+1,same=lsame;
	for (int i=l;i<=r;i++)
	{
		if (i==l) toleft[deep][i]=0;
		else toleft[deep][i]=toleft[deep][i-1];
		if (val[deep][i]<sorted[mid])
		{
			toleft[deep][i]++;
			val[deep+1][lpos++]=val[deep][i];
		}
		else if (val[deep][i]>sorted[mid])
			val[deep+1][rpos++]=val[deep][i];
		else if (val[deep][i]==sorted[mid] && same>0)
		{
			toleft[deep][i]++;
			val[deep+1][lpos++]=val[deep][i];
			same--;
		}
		else
			val[deep+1][rpos++]=val[deep][i];
	}
	build(l,mid,deep+1,2*idx);
	build(mid+1,r,deep+1,2*idx+1);
}

int query(int l,int r,int k,int deep,int idx)
{
	if (l==r) return val[deep][l];
	int s;
	int ss;
	if (l==tree[idx].left)
	{
		s=toleft[deep][r];
		ss=0;
	}
	else
	{
		s=toleft[deep][r]-toleft[deep][l-1];
		ss=toleft[deep][l-1];
	}
	if (s>=k)
	{
		int newl=tree[idx].left+ss;
		int newr=tree[idx].left+ss+s-1;
		return query(newl,newr,k,deep+1,2*idx);
	}
	else
	{
		int mid=(tree[idx].left+tree[idx].right)/2;
		int b=(r-l+1)-s;
		int bb=l-tree[idx].left-ss;
		int newl=mid+1+bb;
		int newr=mid+bb+b;
		return query(newl,newr,k-s,deep+1,2*idx+1);
	}
}
int main()
{
	int n,m;
	int cas = 0;
	while (scanf("%d",&n) != EOF)
	{
	    cas++;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&val[0][i]);
            sorted[i]=val[0][i];
        }
        sort(sorted+1,sorted+1+n);
        build(1,n,0,1);
        scanf("%d",&m);
        printf("Case %d:\n",cas);
        for (int i=1;i<=m;i++)
        {
            int x,y,k;
            scanf("%d%d",&x,&y);
            k = y-x+1;
            k = k/2+k%2;
            printf("%d\n",query(x,y,k,0,1));
        }
	}
	return 0;
}

