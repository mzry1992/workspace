#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int res[20];

int main()
{
    for (int n = 1;n <= 15;n++)
    {
        for (int i = 1;i <= n;i++)
            res[i] = 0;
        for (int i = 0;i < (1<<n);i++)
        {
            int tres = 0,nowsum = 0;
            for (int j = 0;j < n;j++)
            {
                nowsum = 0;
                for (int k = j;k < n;k++)
                {
                    if (((i>>k)&1) == 1)
                        nowsum--;
                    else
                        nowsum++;
                    tres = max(tres,abs(nowsum));
                }
            }
            res[tres]++;
        }
        int resa,resb;
        resa = resb = 0;
        for (int i = 1;i <= n;i++)
        {
            resa += res[i]*i;
            resb += res[i];
        }
        for (int i = 1;i <= n;i++)
            printf("%5d ",i*res[i]);
        printf("\n");
        //printf("%d %d = %.6f\n",resa,resb,(double)resa/resb);
    }
    return 0;
}
