#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n,a[15],len[1<<15],totlen,b[3];
set<pair<int,int> > res;


int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    totlen = 0;
	    for (int i = 0;i < n;i++)
	    {
            scanf("%d",&a[i]);
            totlen += a[i];
	    }
        for (int i = 0;i < (1<<n);i++)
        {
            len[i] = 0;
            for (int j = 0;j < n;j++)
                if (((i>>j)&1) == 1)
                    len[i] += a[j];
        }
        res.clear();
        for (int i = 1;i < (1<<n);i++)
        {
            int full = ((1<<n)-1)^i;
            if (len[i]>=len[full])
                continue;
            for (int j = full;j;j = (j-1)&full)
            {
                if (len[i]+len[j] == totlen)
                    continue;
                b[0] = len[i],b[1] = len[j],b[2] = totlen-len[i]-len[j];
                if (!(b[0]<=b[1] && b[1]<=b[2]))
                    continue;
                if (b[0]+b[1] <= b[2])   continue;
                res.insert(make_pair(b[0],b[1]));
            }
        }
        printf("%d\n",res.size());
	}
	return 0;
}
