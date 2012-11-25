#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct sb
{
    int l,r;
    bool operator < (const sb& b)const
    {
        if (l == b.l)
            return r < b.r;
        return l < b.l;
    }
};

sb a[100000];
int n;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d%d",&a[i].l,&a[i].r);
        sort(a,a+n);
        int pos = a[0].l+1;
        int move = a[0].r-pos;
        int res = 0;
        for (int i = 1;i < n;i++)
        {
            if (pos+move < a[i].l)
            {
                res++;
                pos = a[i].l+1;
                move = a[i].r-pos;
            }
            else
            {
                int tmove = a[i].l-pos;
                pos = a[i].l+1;
                move = min(move-tmove,a[i].r-pos);
            }
        }
        printf("%d\n",res);
	}
	return 0;
}
