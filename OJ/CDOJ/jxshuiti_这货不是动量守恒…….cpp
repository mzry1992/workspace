#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,l,v;
    while (true)
    {
        scanf("%d%d%d",&n,&l,&v);
        if (n == 0 && l == 0 && v == 0)
            break;
        char c1,c2;
        int a;
        double mint,tots;
        mint = 0.0;
        tots = 0.0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d %c %c",&a,&c1,&c2);
            if (c2 == 'E')
            {
                tots += (double)(l-a);
                if ((double)(l-a)/(double)v > mint)
                    mint = (double)(l-a)/(double)v;
            }
            else
            {
                tots += (double)(a);
                if ((double)(a)/(double)v > mint)
                    mint = (double)(a)/(double)v;
            }
        }
        printf("%.2lf %.2lf\n",mint,tots);
    }
}
