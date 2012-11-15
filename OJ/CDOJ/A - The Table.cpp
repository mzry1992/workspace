#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int a[1100][1100];
bool f[1100];
bool z[1100];

int main()
{
    while (scanf("%d%d",&m,&n) != EOF)
    {
        memset(f,false,sizeof(f));
        memset(z,false,sizeof(z));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j] < 0)
                {
                    if (f[j] == false)
                        f[j] = true;
                    else
                        f[j] = false;
                    a[i][j] = -a[i][j];
                }
                if (a[i][j] == 0)
                    z[j] = true;
            }
        bool flag = false;
        for (int i = 1;i <= m;i++)
        if (f[i] == false)
            flag = true;
        int code;
        if (flag == false)  code = 0;
        else    code = 1;
        int ans = 0;
        int minans[1100],b[1100];
        if (code == 0)
        {
            minans[0] = 100000;
            minans[1] = 0;
        }
        else
        {
            minans[0] = 1;
            minans[1] = 0;
        }
        for (int i = 1;i <= m;i++)
        if (z[i] == false)
        if ((code == 1 && f[i] == false) || (code == 0))
        {
            b[0] = b[1] = 1;
            for (int j = 1;j <= n;j++)
            {
                for (int k = 1;k <= b[0];k++)
                    b[k] *= a[j][i];
                for (int k = 1;k <= b[0]-1;k++)
                {
                    b[k+1] += b[k]/10;
                    b[k] %= 10;
                }
                while (b[b[0]] >= 10)
                {
                    b[b[0]+1] = b[b[0]]/10;
                    b[b[0]] %= 10;
                    b[0]++;
                }
            }
            int comp = 0;
            if (b[0] > minans[0])   comp = 1;
            else if (b[0] < minans[0])  comp = -1;
            else
            {
                for (int j = b[0];j >= 1;j--)
                if (b[j] > minans[j])
                {
                    comp = 1;
                    break;
                }
                else if (b[j] < minans[j])
                {
                    comp = -1;
                    break;
                }
            }
            if (code == 0)
            {
                if (comp <= 0)
                {
                    for (int j = 0;j <= b[0];j++)
                        minans[j] = b[j];
                    ans = i;
                }
            }
            else
            {
                if (comp >= 0)
                {
                    for (int j = 0;j <= b[0];j++)
                        minans[j] = b[j];
                    ans = i;
                }
            }
        }
        if (code == 0)
        {
            for (int i = 1;i <= m;i++)
            if (z[i] == true)
                ans = i;
        }
        bool tflag = false;
        for (int i = 1;i <= m;i++)
        if (z[i] == false)
            tflag = true;
        if (tflag == false)
            ans = m;
        printf("%d\n",ans);
    }
}
