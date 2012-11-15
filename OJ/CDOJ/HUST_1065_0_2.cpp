#include <stdio.h>
#include <string.h>
#include <algorithm>
#define Inf 1000000000;
using namespace std;
int num[100010];
int seg[500010];
void Init(int k, int L, int H)
{
	if(L == H)	
	{
		seg[k] = num[L];
		return;
	}	
	Init(k*2, L, (L+H)/2);
	Init(k*2+1, (L+H)/2+1, H);
	seg[k] = max(seg[k*2], seg[k*2+1]);	
}
int read(int k, int L, int H, int l, int r)
{
	if(L > r || H < l)	return -Inf;
	if(L >= l && H <= r)	return seg[k];
	int left = read(k*2, L, (L+H)/2, l, r);
	int right = read(k*2+1, (L+H)/2+1, H, l, r);
	return max(left, right);	
}
void update(int k, int L, int H, int idx, int v)
{
	if(L == H)	
	{
		seg[k] = v;
		return;	
	}
	if(idx <= (L+H)/2)	
		update(k*2, L, (L+H)/2, idx, v);
	else
		update(k*2+1, (L+H)/2+1, H, idx, v);
	seg[k] = max(seg[k*2], seg[k*2+1]);	
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
         scanf("%d",&num[i]);
    }
    Init(1,0,n-1);
    int ope,l,r;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&ope,&l,&r);
        if (ope==1)
        {
           update(1,0,n-1,l-1,r);
        }
        else
        {
            printf("%d\n",read(1,0,n-1,l-1,r-1));
        }
    }
    return 0;
}
