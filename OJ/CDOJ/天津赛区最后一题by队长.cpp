#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int val[21][100005],a[100005],L,r[100005],b[100005],toleft[21][100005];
long long ans1,ans2,ans3;
int tr[100005];
struct oper
{
	int kind,x1,x2,x3;
}o[235100];
struct seg
{
	int left,right;
}tree[100005*4];
bool cmp(int u,int v)
{
	return a[u]<a[v];
}
int check(char a[])
{
	if (strcmp(a,"Insert")==0) return 0;
	else if (strcmp(a,"Query_1")==0) return 1;
	else if (strcmp(a,"Query_2")==0) return 2;
	else return 3;
}
void add(int x)
{
	while (x<=L)
	{
		tr[x]++;
		x+=x&(-x);
	}
}
int query1(int x)
{
	int sum=0;
	while (x>0)
	{
		sum+=tr[x];
		x-=x&(-x);
	}
	return sum;
}

void lisan()
{
	for (int i=1;i<=L;i++) r[i]=i;
	sort(r+1,r+L+1,cmp);
	for (int i=1;i<=L;i++)
		a[r[i]]=i;
}
void build(int l,int r,int deep,int idx)
{
	tree[idx].left=l;
	tree[idx].right=r;
	if (l==r) return;
	int mid=(l+r)/2;
	int lsame=mid-l+1;
	for (int i=l;i<=r;i++)
		if (val[deep][i]<b[mid]) lsame--;
	int lpos=l,rpos=mid+1,same=lsame;
	for (int i=l;i<=r;i++)
	{
		if (i==l) toleft[deep][i]=0;
		else toleft[deep][i]=toleft[deep][i-1];
		if (val[deep][i]<b[mid])
		{
			val[deep+1][lpos++]=val[deep][i];
			toleft[deep][i]++;
		}
		else if (val[deep][i]>b[mid])
			val[deep+1][rpos++]=val[deep][i];
		else if (val[deep][i]==b[mid] && same>0)
		{
			val[deep+1][lpos++]=val[deep][i];
			toleft[deep][i]++;
			same--;
		}
		else val[deep+1][rpos++]=val[deep][i];
	}
	build(l,mid,deep+1,idx*2);
	build(mid+1,r,deep+1,idx*2+1);
}

int query(int l,int r,int k,int idx,int deep)
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
		return query(newl,newr,k,idx*2,deep+1);
	}
	else
	{
		int mid=(tree[idx].left+tree[idx].right)>>1;
		int b=(r-l+1)-s;
		int bb=l-tree[idx].left-ss;
		int newl=mid+1+bb;
		int newr=mid+bb+b;
		return query(newl,newr,k-s,idx*2+1,deep+1);
	}
}
int find(int x)
{
	if (b[L]==x) return L;
	int i=1,j=L,mid;
	while (i<j-1)
	{
		mid=(i+j)/2;
		if (b[mid]>x) j=mid;
		else i=mid;
	}
	return i;
}
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	int cas=0;
	while (scanf("%d",&n)>0)
	{
		memset(tr,0,sizeof(tr));
		cas++;
		ans1=ans2=ans3=0;
		char s[10];
		int x1,x2,x3;
		L=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			int chk=check(s);
			o[i].kind=chk;
			if (chk==0 || chk==2 || chk==3)
			{
				scanf("%d",&x1);
				o[i].x1=x1;
				if (chk==0)
				{
					a[++L]=x1;
					val[0][L]=x1;
					b[L]=x1;
				}
			}
			else
			{
				scanf("%d%d%d",&x1,&x2,&x3);
				o[i].x1=x1,o[i].x2=x2,o[i].x3=x3;
			}
		}
		lisan();
		/*for (int i=1;i<=L;i++)
			printf("%d ",ori[i]);
		puts("");
		for (int i=1;i<=L;i++)
			printf("%d ",a[i]);*/
		//for (int i=1;i<=n;i++)
		//{
		//	if (o[i].kind==2)
		sort(b+1,b+L+1);
		build(1,L,0,1);
		for (int i=1;i<=n;i++)
		{
			if (o[i].kind==1)
				ans1+=query(o[i].x1,o[i].x2,o[i].x3,1,0);
		}
		int ccc=0;
		for (int i=1;i<=n;i++)
		{
			if (o[i].kind==0)
			{
				add(find(o[i].x1));
				//printf("%d %d\n",o[i].x1,find(o[i].x1));
				ccc++;
			}
			else if (o[i].kind==2)
			{
				int t=query1(find(o[i].x1));
				//printf("%d %d\n",find(o[i].x1),t);
				ans2+=t;
			}
			else if (o[i].kind==3)
				ans3+=query(1,ccc,o[i].x1,1,0);
		}
		printf("Case %d:\n%lld\n%lld\n%lld\n",cas,ans1,ans2,ans3);
	}
	//system("pause");
}
