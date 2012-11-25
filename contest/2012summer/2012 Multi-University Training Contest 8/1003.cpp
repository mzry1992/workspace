#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[20],cnt[20][20];

int main()
{
    for (n = 1;n < 10;n++)
    {
        for (int i = 0;i < n;i++)
            a[i] = i;
        memset(cnt,0,sizeof(cnt));
        do
        {
            int f = 0,b = 0;
            int mx = -1;
            for (int i = 0;i < n;i++)
                if (a[i] > mx)
                {
                    f++;
                    mx = a[i];
                }
            mx = -1;
            for (int i = n-1;i >= 0;i--)
                if (a[i] > mx)
                {
                    b++;
                    mx = a[i];
                }
            cnt[f][b]++;
        }while (next_permutation(a,a+n));
        printf("%d : -----------------------\n",n);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (cnt[i][j] != 0)
                printf("%d %d %d\n",i,j,cnt[i][j]);
    }
	return 0;
}
