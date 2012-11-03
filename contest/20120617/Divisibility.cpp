#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[20];
bool vis[26];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%s",buf);
        int len = strlen(buf);
        long long num,gcd,ww;
        gcd = -1;
        for (int i = 0;i < len;i++)
        {
            num = 0;
            ww = 1;
            for (int j = len-1;j >= 0;j--)
            {
                if (buf[j] == buf[i])
                    num += ww;
                ww *= 10;
            }
            if (gcd == -1)  gcd = num;
            else    gcd = __gcd(gcd,num);
        }
        printf("Case %d:",cas);
        long long i;
        for (i = 1;i*i <= gcd;i++)
            if (gcd%i == 0)
                printf(" %I64d",i);
        for (i -= 2;i;--i)
            if (gcd%i == 0)
                printf(" %I64d",gcd/i);
        puts("");
    }
	return 0;
}
