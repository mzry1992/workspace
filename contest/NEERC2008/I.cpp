#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<string,string> mp;
int cube[3][3][3];
int path[30];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
char pos[7]="DUFBLR";
bool vis[3][3][3];
bool check(int a,int b,int c)
{
	if(a>=0&&a<3&&b>=0&&b<3&&c>=0&&c<3&&!vis[a][b][c])
		return true;
	return false;
}
char s1[30],s2[30];
bool checkpos(int k)
{
	int a1,b1,c1;
	int a2,b2,c2;
	a1=path[k-1]/100;
	b1=(path[k-1]/10)%10;
	c1=path[k-1]%10;

	a2=path[k+1]/100;
	b2=(path[k+1]/10)%10;
	c2=path[k+1]%10;

	int num=0;
	if(a1==a2)
		num++;
	if(b1==b2)
		num++;
	if(c1==c2)
		num++;
	if(num==1)
		return false;
	return true;
}
void solve()
{
	int i,k1;
	s1[0]='F';k1=1;
	for(i=1;i<26;i++)
	{
		if(checkpos(i))
			s1[k1++]='F';
		else
			s1[k1++]='T';
	}
	s1[k1++]='F';
	s1[k1]=0;
	mp[s1]=s2;
}
void dfs(int a,int b,int c,int d)
{
	path[d]=a*100+b*10+c;
	if(d==26)
	{
		s2[d]=0;
		solve();
		return;
	}
	int i;
	for(i=0;i<6;i++)
	{
		int na,nb,nc;
		na=a+dir[i][0];
		nb=b+dir[i][1];
		nc=c+dir[i][2];
		if(check(na,nb,nc))
		{
			s2[d]=pos[i];
			vis[na][nb][nc]=true;
			dfs(na,nb,nc,d+1);
			vis[na][nb][nc]=false;
		}
	}
}
int s[20];
int main()
{
	mp.clear();
	int i,j,k;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
			{
				printf("%d %d %d\n",i,j,k);
				memset(path,-1,sizeof(path));
				memset(vis,false,sizeof(vis));
				dfs(i,j,k,0);
			}
	while(scanf("%s",s)!=EOF)
	{
		printf("%s\n",s);
	}
    return 0;
}

