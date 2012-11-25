#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000;
char a[maxn+10],b[maxn+10];
int c[maxn];

int main()
{
    freopen("data.in","w",stdout);
	int totcas = 100;
	printf("%d\n",totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    int la = maxn;
	    int lb = maxn;
	    for (int i = 0;i < la;i++)
            a[i] = rand()%26+'a';
        a[la] = 0;
        for (int i = 0;i < lb;i++)
            b[i] = rand()%26+'a';
        b[lb] = 0;

        int n = 2000;
        for (int i = 0;i < n;i++)
            c[i] = (rand()*rand())%lb+1;
        c[n-1] = lb;
        sort(c,c+n);
        n = unique(c,c+n)-c;
        printf("%d\n",n);
        printf("%s\n",a);
        int pre = 0;
        for (int i = 0;i < n;i++)
        {
            for (int j = pre;j < c[i];j++)
                printf("%c",b[j]);
            printf("\n");
            pre = c[i];
        }
	}
	return 0;
}
