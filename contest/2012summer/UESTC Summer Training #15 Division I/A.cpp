#include <cstdio>
#include <cmath>

int n;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        int L = ceil(log((double)n));
        double x = 1-(double)n/exp((double)L);
        double x2 = 1-(double)n/exp((double)(L-1));
        if (fabs(x2) < 1)
        {
            L = L-1;
            x = x2;
        }
        printf("%d %.8f\n",L,x);
    }
	return 0;
}
