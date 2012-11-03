#include<stdio.h>
struct
{
	int l,r;
	long long key,lazy;
}tree[410000];
int n,m,a[100001];
void init(int x,int l,int r)
{
    tree[x].l=l;
	tree[x].r=r;
	tree[x].lazy=0;
	if (l==r)
	{
		tree[x].key=a[l];
		return ;
	}
	init(x*2,l,(l+r)/2);
	init(x*2+1,(l+r)/2+1,r);
	tree[x].key=tree[x*2].key+tree[x*2+1].key;
}
void clear(int x)
{
     tree[x].key+=tree[x].lazy*(tree[x].r-tree[x].l+1);
     if (tree[x].l!=tree[x].r)
	 {
		tree[x*2].lazy+=tree[x].lazy;
		tree[x*2+1].lazy+=tree[x].lazy;
	 }
     tree[x].lazy=0;
}
void update(int x,int s,int t,int v){
    if (tree[x].lazy) clear(x);
    if (tree[x].l>=s && tree[x].r<=t) {tree[x].lazy+=v;clear(x);return;}
	int mid=(tree[x].l+tree[x].r)/2;
    if (s<=mid) update(x*2,s,t,v);
    if (t>mid) update(x*2+1,s,t,v);
	clear(x*2);
	clear(x*2+1);
	tree[x].key=tree[x*2].key+tree[x*2+1].key;
    return ;
}
long long read(int x,int s,int t){
    long long ans=0;
    if (tree[x].lazy) clear(x);
    if (tree[x].l>=s && tree[x].r<=t) return tree[x].key;
	int mid=(tree[x].l+tree[x].r)/2;
    if (s<=mid) ans=read(x*2,s,t);
    if (t>mid) ans+=read(x*2+1,s,t);
    return ans;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("ans.txt","w",stdout);
    int i,j,t,x,y,z;
    char s;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    init(1,1,n);
    for (i=1;i<=m;i++)
	{
        scanf(" %c",&s);
        if (s=='Q') {scanf("%d%d",&x,&y);printf("%lld\n",read(1,x,y));}
        if (s=='C') {scanf("%d%d%d",&x,&y,&z);update(1,x,y,z);}
	}
    return 0;
}
