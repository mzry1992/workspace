#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
    freopen("data.in","w",stdout);
    int totcas = 4000;
    printf("%d\n",totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        int n,m,y,x,d;
        n = rand()%5+1;
        m = rand()%5+1;
        x = rand()%n;
        y = rand()%n;
        if (x == 0 || x == n-1)
            d = -1;
        else
            d = rand()%2;

        printf("%d %d %d %d %d\n",n,m,y,x,d);
        int sum = 100;
        for (int i = 0; i < m-1; i++)
        {
            int now = rand()%min(1,sum);
            printf("%d ",now);
            sum -= now;
        }
        printf("%d\n",sum);
    }
    return 0;
}
