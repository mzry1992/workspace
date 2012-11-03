#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,l;

bool Gao(int n)
{
    if (l%2 == 1)
        return false;
	if (n < 2)
		return false;

    for (int x = 2; x <= n; x ++)
        for (int y = 2; y <= n; y ++)
            if (l/2 == x+y-2)
            {
                puts("Overwhelming power of magic");
                for (int i = 1; i <= y; i++)
                    printf("%d %d\n",1,i);
                for (int i = 2; i <= x; i++)
                    printf("%d %d\n",i,y);
                for (int i = y-1; i >= 1; i--)
                    printf("%d %d\n",x,i);
                for (int i = x-1; i >= 2; i--)
                    printf("%d %d\n",i,1);
                return true;
            }

    if (n%2 == 0)
    {
        int maxv = n*n;
        if (l <= maxv)
        {
            l -= (n+n-2)*2;
            int totz = n/2-1,maxz = n-2,add;
            puts("Overwhelming power of magic");
            l /= 2;
            for (int z = 0; z < totz; z++)
            {
                if (l <= maxz)
                {
                    add = l;
                    l = 0;
                }
                else
                {
                    add = maxz;
                    l -= maxz;
                }
                for (int aa = 0; aa <= add; aa++)
                    printf("%d %d\n",n-aa,z*2+2);
                for (int aa = add; aa >= 0; aa--)
                    printf("%d %d\n",n-aa,z*2+3);
            }
            for (int i = n; i >= 1; i--)
                printf("%d %d\n",i,n);
            for (int i = n-1; i >= 1; i--)
                printf("%d %d\n",1,i);
            for (int i = 2; i <= n; i++)
                printf("%d %d\n",i,1);
			return true;
        }
    }
    else
    {
        int maxv = n*n-1;
        if (l <= maxv)
        {
            l -= 5*n-7;
            int totz = n/2-1,maxz = n-2,add;
            puts("Overwhelming power of magic");
            l /= 2;
            for (int z = 0; z < totz; z++)
            {
                if (l <= maxz)
                {
                    add = l;
                    l = 0;
                }
                else
                {
                    add = maxz;
                    l -= maxz;
                }
                for (int aa = 0; aa <= add; aa++)
                    printf("%d %d\n",n-aa,z*2+2);
                for (int aa = add; aa >= 0; aa--)
                    printf("%d %d\n",n-aa,z*2+3);
            }
            for (int i = n; i >= 3; i -= 2)
            {
            	printf("%d %d\n",i,n-1);
            	printf("%d %d\n",i,n);
            	printf("%d %d\n",i-1,n);
            	printf("%d %d\n",i-1,n-1);
            }
            for (int i = n-1; i >= 1; i--)
                printf("%d %d\n",1,i);
            for (int i = 2; i <= n; i++)
                printf("%d %d\n",i,1);
			return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&l);
    if (!Gao(n))
    {
    	if (!Gao(n-1))
			puts("Unsuitable device");
    }
    return 0;
}

