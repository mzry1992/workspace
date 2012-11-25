#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int s[20],n,k[20],num;
void dfs(int p,int st,int up)
{
    if(p>=3)
        num++;
    printf("%d\n",num);
    if(p>=18)
        return;
   // printf("p = %d\n",p);
   // int j;
   // for(j=0;j<p;j++)
   //     printf("%d ",s[j]);
   // printf("\n");
    int i;
    for(i=1;i<=(up?k[p]:9);i++)
    {
        s[p]=i;
        if(st==0)
        {
            if(i<s[p-1])
                dfs(p+1,1,up&(i==k[p]));
            else if(i>s[p-1])
                dfs(p+1,2,up&(i==k[p]));
        }
        if(st==1)
        {
            if(i>s[p-1])
                dfs(p+1,2,up&(i==k[p]));
        }
        if(st==2)
        {
            if(i<s[p-1])
                dfs(p+1,1,up&(i==k[p]));
        }
    }
}
int main()
{
	while(scanf("%d",&n)==1)
	{
	    int i;
	    memset(k,0,sizeof(k));
	    for(i=0;i<n;i++)
            scanf("%d",&k[i]);
        memset(s,0,sizeof(s));
        num=0;
        for(i=1;i<=k[0];i++)
        {
            s[0]=i;
            if(i<k[0])
                dfs(1,0,0);
            else
                dfs(1,0,1);
        }
        printf("%d\n",num);
	}
	return 0;
}
