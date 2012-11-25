#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1000],a[12],b[12],c[12];
long long dp[12][12][12];

long long Gao(int pa,int pb,int pc)
{

}

int main()
{
    int cas = 0;
	while (scanf("%s",buf) != EOF)
	{
	    int la,lb,lc,l;
	    la = lb = lc = 0;
        for (int i = 0;buf[i] != 0;i++)
        {
            a[la++] = buf[i];
            if (buf[i] == '+')
            {
                a[la-1] = 0;
                for (++i;buf[i] != 0;i++)
                {
                    b[lb++] = buf[i];
                    if (buf[i] == '=')
                    {
                        b[lb-1] = 0;
                        for (++i;buf[i] != 0;i++)
                            c[lc++] = buf[i];
                        c[lc] = 0;
                        break;
                    }
                }
                break;
            }
        }
        printf("%s %s %s\n",a,b,c);
        l = max(la,max(lb,lc));
        printf("Case %d: %lld\n",++cas,Gao(0,0));
	}
	return 0;
}
