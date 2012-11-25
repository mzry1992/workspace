#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[20000000];

int main()
{
	int n,L,A,B,mod;
	while (scanf("%d%d%d%d%d",&n,&L,&A,&B,&mod) != EOF)
	{
	    A %= mod;
	    B %= mod;
	    int num;
	    int max=-1,min=mod+1;
	    int size=0;
	    for (int i = 0;i < n;i++)
	    {
	        if (!i)
	            num=A+B;
            else
                num+=A;
            if (num>=mod)
                num-=mod;
            if (num*2<=L)
                size++;
            if (max<num && num*2<=L)
                max=num;
            if (min>num && num*2>L)
                min=num;
	    }
	    if (max==-1)
            if (min<=L)
                size++;
            else;
        else
            if (max+min<=L && min!=mod+1)
                size++;
	    printf("%d\n",size);
	}
	return 0;
}
