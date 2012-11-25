#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char mp[300][300];
int tot[5];

int getid(char ch)
{
    if (ch == 'B')  return 0;
    if (ch == 'J')  return 1;
    if (ch == 'H')  return 2;
    if (ch == 'Y')  return 3;
    return 4;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        long long res = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
            {
                memset(tot,0,sizeof(tot));
                for (int k = 0;k < m;k++)
                    if (mp[i][k] == mp[j][k])
                        tot[getid(mp[i][k])]++;
                for (int k = 0;k < 5;k++)
                    res += tot[k]*(tot[k]-1)/2;
            }
        printf("%lld\n",res);
    }
	return 0;
}
