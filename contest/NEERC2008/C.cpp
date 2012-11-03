#include <cstdio>
#include <cstring>
int dis[100000],a[100000],pre[100000];
int mins[10000],idx[10000];
void print(int x)
{
    if (pre[x]!=-1)
    {
        print(pre[x]);
		printf(" %d",a[x]+1);
    }
    else
		printf("%d",a[x]+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
    }
    memset(dis,63,sizeof(dis));
    memset(mins,63,sizeof(mins));
    mins[a[0]]=dis[0]=0;
    pre[0]=idx[a[0]]=-1;
    for (int i=1;i<n;i++)
	{
		if (dis[i-1]+1<mins[a[i]])
		{
			dis[i]=mins[a[i]]=dis[i-1]+1;
			pre[i]=idx[a[i]]=i-1;
		}
		else
		{
			dis[i]=mins[a[i]];
			pre[i]=idx[a[i]];
		}
	}
	print(n-1);
	puts("");
    return 0;
}

