#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    freopen("data.in","w",stdout);
	int totcas = 10;
	printf("%d\n",totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    int n = 10;
	    int m = 10;
	    printf("%d %d\n",n,m);
	    for (int i = 0;i < m;i++)
	    {
	        int typ = rand()%2+1;
	        if (typ == 1)
	        {
	            int x,y,p;
	            x = rand()%n+1;
	            y = rand()%n+1;
	            if (x > y)
                    swap(x,y);
                p = rand()%20+1;
                printf("%d %d %d %d\n",typ,x,y,p);
	        }
	        else
	        {
	            int x,c;
	            x = rand()%n+1;
	            c = rand()%20+1;
	            printf("%d %d %d\n",typ,x,c);
	        }
	    }
	}
	return 0;
}
