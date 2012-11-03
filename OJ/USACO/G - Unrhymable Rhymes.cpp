#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[5000],ta[5000],ls[5000];
int c[5000];
int p[5000][3];
int pre;
int sum;
int res[5000][5];

int main()
{
    bool first = true;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            ta[i] = a[i];
        }
        sort(ta+1,ta+n+1);
        int totls = 0;
        ta[0] = ta[1]-1;
        for (int i = 1;i <= n;i++)
        if (ta[i] != ta[i-1])
        {
            totls++;
            ls[totls] = ta[i];
        }
        for (int i = 1;i <= totls;i++)
        for (int j = 1;j <= n;j++)
        if (a[j] == ls[i])
            a[j] = i;
        sum = 0;
        pre = 0;
        memset(c,0,sizeof(c));
        for (int i = 1;i <= n;i++)
        {
            int now = a[i];
            c[now]++;
            p[now][c[now]] = i;
            if (c[a[i]] == 4)
            {
                sum++;
                for (int j = 1;j <= 4;j++)
                    res[sum][j] = p[a[i]][j];
                memset(c,0,sizeof(c));
                pre = 0;
            }
            if (c[a[i]] == 2)
            {
                if (pre != 0)
                {
                    sum++;
                    res[sum][1] = p[pre][1];
                    res[sum][2] = p[pre][2];
                    res[sum][3] = p[a[i]][1];
                    res[sum][4] = p[a[i]][2];
                    sort(res[sum]+1,res[sum]+1+4);
                    memset(c,0,sizeof(c));
                    pre = 0;
                }
                else
                    pre = a[i];
            }
        }
        if (first == false)
            printf("\n");
        first = false;
        printf("%d\n",sum);
        for (int i = 1;i <= sum;i++)
            printf("%d %d %d %d\n",res[i][1],res[i][2],res[i][3],res[i][4]);
    }
}
