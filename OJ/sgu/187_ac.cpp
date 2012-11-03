#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;

const int MAX=130000+10;

int n,m;

int size[MAX],key[MAX],ch[MAX][2],pre[MAX],root;
bool rev[MAX];

int swap(int &a,int &b){int t=a;a=b;b=t;}

void pushdown(int x)
{
	if(!x)return;
	if(rev[x])
	{
		rev[x]^=1;
		if(ch[x][0])rev[ch[x][0]]^=1;
		if(ch[x][1])rev[ch[x][1]]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}

void updata(int x)
{
	if(!x)return;
	pushdown(x);
	pushdown(ch[x][0]);
	pushdown(ch[x][1]);
	size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}

void rorate(int x,int T)
{
	int y=pre[x];
	if(T)
	{
		pre[ch[x][1]]=y;
		ch[y][0]=ch[x][1];
		ch[x][1]=y;
	}else
	{
		pre[ch[x][0]]=y;
		ch[y][1]=ch[x][0];
		ch[x][0]=y;
	}
	pre[x]=pre[y];
	pre[y]=x;
	if(ch[pre[x]][1]==y)ch[pre[x]][1]=x;
	else ch[pre[x]][0]=x;
	updata(x);
	updata(y);
	return;
}

void splay(int x,int goal)
{
	if(x==goal)return;
	if(goal==0)root=x;
	int y,t;
	for(;pre[x]!=goal;)
	{
		int y=pre[x],t=pre[y];
		if(t==goal)
			rorate(x,ch[y][0]==x);
		else if(ch[t][0]==y)
		{
			if(ch[y][0]==x){rorate(x,1);rorate(x,1);}
			else if(ch[y][1]==x){rorate(x,0);rorate(x,1);}
		}else
		{
			if(ch[y][1]==x){rorate(x,0);rorate(x,0);}
			else if(ch[y][0]==x){rorate(x,1);rorate(x,0);}
		}
	}
}

int rank(int k)
{
	int x=0,done;
	for(;;)
	{
		updata(x);
		if(done+size[ch[x][0]]+1==k)
			return x;
		else if(done+size[ch[x][0]]+1<k)
		{
			done+=size[ch[x][0]]+1;
			x=ch[x][1];
		}else x=ch[x][0];
	}
}

void build()
{
	int i,j,k;
	size[0]=0;
	for(i=1;i<=n+2;++i)
	{
		key[i]=i;
		size[i]=n+3-i;
		rev[i]=0;
		if(i+1<=n+2)ch[i][1]=i+1;
		pre[i]=i-1;
	}
	root=1;
}

void output()
{
	int i,j,k;
	for(i=2;i<=n+1;++i)
	{
		k=rank(i);
		splay(k,0);
		printf("%d ",key[k]-1);
	}
	printf("\n");
}
void work()
{
    build();
	int i,x,y,l,r;
	for(i=1;i<=m;++i)
	{
	    scanf("%d%d",&l,&r);
		x=rank(l),y=rank(r+2);
		splay(x,0);
		splay(y,x);
		rev[ch[y][0]]^=1;
	}
	output();
}

int main()
{
	//freopen("187.in","r",stdin);
	//freopen("187.out","w",stdout);
	scanf("%d%d",&n,&m);
	work();
	return 0;
}
