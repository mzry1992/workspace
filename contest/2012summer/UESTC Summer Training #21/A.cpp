#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long ans[1000];
char buf[20];

bool check(long long n,int n2,int n5)
{
    sprintf(buf,"%lld",n);
    int len = strlen(buf);
    return n2 <= len && n5 <= len;
}

int main()
{
    int cnt = 0;
    long long num = 1;
    for (int i = 0;num < (1LL<<32);i++,num *= 2)
    {
        long long nn = num;
        for (int j = 0;nn < (1LL<<32);j++,nn *= 5)
            if (check(nn,i,j))
                ans[cnt++] = nn;
    }
    sort(ans,ans+cnt);
    int l,r;
    while (scanf("%d%d",&l,&r) != EOF)
    {
        int tot = 0;
        for (int i = 0;i < cnt;i++)
            if (ans[i] >= l && ans[i] <= r)
                tot++;
        printf("%d\n",tot);
    }
	return 0;
}
