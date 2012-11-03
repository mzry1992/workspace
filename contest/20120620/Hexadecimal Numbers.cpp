#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const char num[20] = "0123456789ABCDEF";
const int w[8] = {15,15,14,13,12,11,10,9};
long long n;
long long init,nowtot,now;
bool use[20];
long long val[9];

int main()
{
    init = 16;
    now = 15;
    for (int i = 15;i >= 9;i--)
    {
        now *= i;
        init += now;
    }
    while (scanf("%I64d",&n) != EOF)
    {
        n = init-n;
        if (n == 0)
        {
            puts("0");
            continue;
        }
        nowtot = 1;
        for (int i = 0;i < 8;i++)
        {
            nowtot *= w[i];
            if (n <= nowtot)
            {
                val[i+1] = 1;
                for (int j = i;j >= 0;j--)
                    val[j] = val[j+1]*w[j];
                memset(use,false,sizeof(use));
                now = 0;
                for (int j = 1;j <= 15;j++)
                {
                    if (now+val[1] >= n)
                    {
                        use[j] = true;
                        printf("%c",num[j]);
                        break;
                    }
                    now += val[1];
                }
                for (int j = 1;j <= i;j++)
                    for (int k = 0;k <= 15;k++)
                        if (use[k] == false)
                        {
                            if (now+val[j+1] >= n)
                            {
                                use[k] = true;
                                printf("%c",num[k]);
                                break;
                            }
                            now += val[j+1];
                        }
                printf("\n");
                break;
            }
            n -= nowtot;
        }
    }
	return 0;
}
