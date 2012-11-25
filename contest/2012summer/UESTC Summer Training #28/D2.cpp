#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
bool vis[1<<17];
void pout(int a)
{
    printf("%d\n",a);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
        scanf("%d",&n);
        int st,now;
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        st=now=0;
        pout(now);
        st++;
        int full=(1<<n)-1;
        while(st<(1<<n))
        {
            int pos=st&(~(st-1));
            now=~now;
            now&=full;
            now^=pos;
            vis[now]=true;
            pout(now);
            st++;
        }
        int i;
        for(i=0;i<(1<<n);i++)
            if(!vis[i])
                puts("fuck");
	}
	return 0;
}
