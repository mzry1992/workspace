#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int f[20];

int main()
{
    freopen("data.in","w",stdout);
    int totcas = 100;
    printf("%d\n",totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        int n = 100;
        int m = 4;
        int k = 2;
        printf("%d %d %d\n",n,m,k);
        f[0] = 0;
        for (int i = 1;i < k;i++)
        {
            while (true)
            {
                f[i] = rand()%m;
                bool flag = true;
                for (int j = 0;j < i && flag;j++)
                    if (f[j] == f[i])
                        flag = false;
                if (flag)
                    break;
            }
        }
        sort(f,f+k);
        for (int i = 0;i < k;i++)
            printf("%d ",f[i]);
        printf("\n");
    }
	return 0;
}
