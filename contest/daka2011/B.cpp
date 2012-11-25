#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool can[1<<10][101];

void Gao(int sta)
{
    for (int i = 0; i < 10; i++)
        if (((sta>>i)&1) == 1)
            can[sta][i] = true;
    for (int i = 0; i < 10; i++)
        if (((sta>>i)&1) == 1)
            for (int j = 0; j < 10; j++)
                if (i != j && ((sta>>j)&1) == 1)
                    can[sta][i*10+j] = can[sta][i+j] = true;
    for (int i = 0; i < 10; i++)
        if (((sta>>i)&1) == 1)
            for (int j = 0; j < 10; j++)
                if (i != j && ((sta>>j)&1) == 1)
                    for (int k = 0; k < 10; k++)
                        if (i != k && j != k && ((sta>>k)&1) == 1)
                        {
                            if (i*10+j+k <= 100)
                                can[sta][i*10+j+k] = true;
                        }
    for (int i = 0; i < 10; i++)
        if (((sta>>i)&1) == 1)
            for (int j = 0; j < 10; j++)
                if (i != j && ((sta>>j)&1) == 1)
                    for (int k = 0; k < 10; k++)
                        if (i != k && j != k && ((sta>>k)&1) == 1)
                            for (int q = 0;q < 10;q++)
                                if (i != q && j != q && k != q && ((sta>>q)&1) == 1)
                                    if (i*10+j+k*10+q <= 100)
                                        can[sta][i*10+j+k*10+q] = true;
}

int n,a[10];

int main()
{
    memset(can,false,sizeof(can));
    for (int i = 1; i < (1<<10); i++)
        Gao(i);
    int ft = 0;
    while (true)
    {
        ft++;
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        long long res = 9876543210ll;
        for (int i = 1;i < (1<<10);i++)
        {
            bool check = true;
            for (int j = 0;j < n;j++)
                if (can[i][a[j]] == false)
                {
                    check = false;
                    break;
                }
            if (check == true)
            {
                long long tmp = 0;
                for (int j = 9;j >= 0;j--)
                    if (((i>>j)&1) == 1)
                        tmp = tmp*10+j;
                res = min(res,tmp);
            }
        }
        printf("Case %d: %lld\n",ft,res);
    }
    return 0;
}
