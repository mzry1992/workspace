#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n,k,x,blank,div1,sum1,div2,sum2;
int p;

int main()
{
    while (scanf("%I64d%I64d%d",&n,&k,&p) != EOF)
    {
        if (k == 0)
        {
            for (int i = 0;i < p;i++)
            {
                scanf("%I64d",&x);
                printf(".");
            }
            printf("\n");
        }
        else if (k == n)
        {
            for (int i = 0;i < p;i++)
            {
                scanf("%I64d",&x);
                printf("X");
            }
            printf("\n");
        }
        else
        {
            blank = n-k;
            div1 = 1;
            sum1 = min(blank,k)-1;
            div2 = blank-sum1*div1;
            sum2 = 1;
            if (div2%2 == 0)
                if (sum1 > 0)
                {
                    sum1--;
                    div2++;
                }
            if (div1 < div2)
            {
                swap(div1,div2);
                swap(sum1,sum2);
            }
            //cout << div1 << ' ' << sum1 << ' ' << div2 << ' ' << sum2 << endl;
            //continue;
            for (int i = 0;i < p;i++)
            {
                scanf("%I64d",&x);
                if ((div1+1)*sum1 >= x)
                {
                    //cout << x << ' ' << div1+1 << endl;
                    if (x%(div1+1) == 0)    printf("X");
                    else printf(".");
                }
                else if ((div1+1)*sum1+(div2+1)*sum2 >= x)
                {
                    //cout << x << ' ' << div2+1 << endl;
                    if ((x-(div1+1)*sum1)%(div2+1) == 0)    printf("X");
                    else printf(".");
                }
                else
                    printf("X");
            }
            printf("\n");
        }
    }
    return 0;
}
