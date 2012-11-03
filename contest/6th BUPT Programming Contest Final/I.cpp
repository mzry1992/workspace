#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,typ,id;
    bool operator < (const Point& b)const
    {
        if (x == b.x)   return y < b.y;
        return x < b.x;
    }
};

int n;
Point a[200000];
int tree[2000100],res[200000];

void update(int pos,int val)
{
    for (;pos < 2000100;pos += pos&-pos)
        tree[pos] = max(tree[pos],val);
}

int read(int pos)
{
    int res = 0;
    for (;pos > 0;pos ^= pos&-pos)
        res = max(res,tree[pos]);
    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
	    {
            scanf("%d%d%d%d",&a[i*2].x,&a[i*2].y,&a[i*2+1].x,&a[i*2+1].y);
            a[i*2].x += 1000001;
            a[i*2].y += 1000001;
            a[i*2+1].x += 1000001;
            a[i*2+1].y += 1000001;
            a[i*2].typ = 0;
            a[i*2+1].typ = 1;
            a[i*2].id = a[i*2+1].id = i;
	    }
        sort(a,a+2*n);
        memset(tree,0,sizeof(tree));
        int ans = 0;
        for (int i = 0,j;i < 2*n;)
        {
            for (j = i;a[j].x == a[i].x;j++)
                if (a[j].typ == 0)
                    res[a[j].id] = read(a[j].y-1)+1;
            for (j = i;a[j].x == a[i].x;j++)
                if (a[j].typ == 1)
                    update(a[j].y,res[a[j].id]);
            i = j;
        }
        for (int i = 0;i < n;i++)
            ans = max(ans,res[i]);
        printf("%d\n",ans);
	}
	return 0;
}
