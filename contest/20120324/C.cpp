#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct node
{
    int l,r,type;
    node(){}
    node(int _l,int _r,int _type)
    {
        l = _l;
        r = _r;
        type = _type;
    }
    bool operator<(const node &a)const
    {
        if (a.r!=r)
            return r<a.r;
        else
            return type>a.type;
    }
};
map<int,int> tmp;
int a[1000000],n,m,q;
node b[2000000];
int ans[1000000];
int main()
{
	while (true)
	{
	    scanf("%d%d",&m,&q);
	    if (m == 0 && q == 0)   break;
	    n = 0;
	    tmp.clear();
	    for (int i = 0;i < m;i++)
	    {
            scanf("%d",&a[i]);
            if (tmp.find(a[i]) != tmp.end())
                b[n++] = node(tmp[a[i]],i,a[i]);
            tmp[a[i]] = i;
	    }
	    for (int i = 0;i < q;i++)
	    {
	        int u,v;
	        scanf("%d%d",&u,&v);
	        b[n++] = node(u-1,v-1,-i-1);
	    }
	    sort(b,b+n);
	    for (int i=0,pre=-1,idx;i<n;i++)
	        if (b[i].type<0)
	        {
                if (pre>=b[i].l)
                    ans[-b[i].type-1]=idx;
                else
                    ans[-b[i].type-1]=-1;
	        }
	        else if (pre<b[i].l)
	        {
	            pre=b[i].l;
	            idx=b[i].type;
	        }
	    for (int i=0;i<q;i++)
            if (ans[i]>-1)
                printf("%d\n",ans[i]);
            else
                puts("OK");
	}
	return 0;
}
