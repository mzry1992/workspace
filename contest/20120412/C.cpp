#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1000],b[1000];
int la,lb,mb,id[256];

int main()
{
    while (scanf("%s",a) != EOF)
    {
        la = strlen(a);
        for (int i = 0;i < la;i++)
            id[a[i]] = i+1;
        gets(b);
        while (true)
        {
            if (!gets(b))   return 0;
            sscanf(b,"%s",b);
            lb = strlen(b);
            if (lb == 0) break;
            mb = 0;
            for (int i = 0;i < lb;i++)
                mb = max(mb,id[b[i]]);
            long long res = 0;
            for (int i = mb;i <= la;i++)
            {
                long long tmp = 0;
                for (int j = 0;j < lb;j++)
                    tmp = tmp*i+id[b[j]]-1;
                res += tmp;
            }
            printf("%lld\n",res);
        }
    }
	return 0;
}
