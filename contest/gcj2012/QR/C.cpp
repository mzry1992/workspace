#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

char sa[10],sb[10];
int a,b,len,lb,vb;
set<pair<int,int> > res;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    //t = 50;
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&b);
        //a = 1000000;
        //b = 2000000;
        res.clear();
        for (int i = a;i <= b;i++)
        {
            sprintf(sa,"%d",i);
            len = strlen(sa);
            for (int j = 1;j < len;j++)
            {
                lb = 0;
                for (int k = j;k < len;k++)
                    sb[lb++] = sa[k];
                for (int k = 0;k < j;k++)
                    sb[lb++] = sa[k];
                sb[lb] = 0;
                sscanf(sb,"%d",&vb);
                if (i < vb && a <= vb && vb <= b)
                    res.insert(make_pair(i,vb));
            }
        }
        //for (set<pair<int,int> >::iterator it = res.begin();it != res.end();it++)
        //    printf("%d %d\n",it->first,it->second);
        printf("Case #%d: %d\n",ft,res.size());
    }
	return 0;
}
