#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

char buf[11000],a[200][5100][51];
int n,tot[200];
set<string> hash[100];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        gets(buf);
        for (int i = 0; i < 2*n; i++)
        {
            gets(buf);
            int len = strlen(buf);
            tot[i] = 0;
            for (int j = 0; j < len; j++)
                if (buf[j] != ' ')
                {
                    int k;
                    for (k = 0; j+k < len && buf[j+k] != ' '; k++)
                        a[i][tot[i]][k] = buf[j+k];
                    a[i][tot[i]++][k] = 0;
                    j += k;
                }
        }
        for (int i = 0;i < n;i++)
        {
            hash[i].clear();
            for (int j = 1;j < tot[i];j++)
                hash[i].insert(a[i][j]);
        }
        double res = 0;
        for (int i = n;i < 2*n;i++)
            for (int j = 0;j < n;j++)
                if (strcmp(a[i][0],a[j][0]) == 0)
                {
                    double avep = 0;
                    int cnt = 0;
                    for (int k = 1;k < tot[i];k++)
                        if (hash[j].find(a[i][k]) != hash[j].end())
                        {
                            cnt++;
                            avep += (double)cnt/(double)k;
                        }
                    res += avep/(double)(tot[j]-1);
                    break;
                }
        printf("Case #%d: %.6f\n",cas,res/(double)n);
    }
    return 0;
}
