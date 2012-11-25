#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int k,n,G;
struct N
{
    int year;
    int str;
}moose[200005];
class cmp
{
    public:
        bool operator()(const int a,const int b) const
            {
                return a<b;
            }
};
priority_queue<int,vector<int>,cmp> q;
bool arr(const N a,const N b)
{return a.year<b.year;}
int main()
{
	while(scanf("%d%d",&k,&n)==2)
	{
	    int i;
	    scanf("%d%d",&moose[0].year,&moose[0].str);
	    G=moose[0].str;
	    for(i=1;i<=n+k-2;i++)
            scanf("%d%d",&moose[i].year,&moose[i].str);
        sort(moose,moose+n+k-1,arr);
        while(!q.empty())
            q.pop();
        for(i=0;i<k;i++)
            q.push(moose[i].str);
        bool flag=false;
        for(i=0;i<n;i++)
        {
            int ma;
            ma=q.top();
            if(ma==G)
            {
                flag=true;
                break;
            }
            q.pop();
            q.push(moose[i+k].str);
        }
        if(flag)
            printf("%d\n",2011+i);
        else
            printf("unknown\n");
	}
	return 0;
}
