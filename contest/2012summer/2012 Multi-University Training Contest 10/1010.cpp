#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int out[100000];
int main()
{
	int t;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++)
	{
	    int n;
	    scanf("%d",&n);
	    int x=0;
	    for (int i=1,t=n;t-i>=0;i+=2,x++)
            t-=i;
        printf("Case #%d: %d\n",cas,n-x);
        for (int i=0;i<n;i++)
            out[i]=i+1;
        int pos=0;
        for (int i=2;i<=x;i++)
        {
            reverse(out+pos,out+pos+i-1);
            pos+=i-1;
            reverse(out+pos,out+pos+i);
            pos+=i;
        }
        printf("%d",out[0]);
        for (int i=1;i<n;i++)
            printf(" %d",out[i]);
        puts("");
	}
	return 0;
}
