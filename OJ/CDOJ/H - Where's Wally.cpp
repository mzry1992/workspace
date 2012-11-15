#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w,h,tarh;
bool g[1001][1001],tar[101][6];
char s[1001];
int len;

int calc(char ch)
{
    if (ch >= 'A' && ch <= 'Z') return ch-'A';
    if (ch >= 'a' && ch <= 'z') return ch-'a'+26;
    if (ch >= '0' && ch <= '9') return ch-'0'+52;
    if (ch == '+')  return 62;
    return 63;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d",&w,&h,&tarh);
        for (int i = 0;i < h;i++)
        {
            scanf("%s",s);
            len = strlen(s);
            for (int j = 0;j < (w+5)/6;j++)
            {
                int num = calc(s[j]);
                for (int k = 5;k >= 0;k--)
                    g[i][j*6+k] = (((num>>k)&1) == 1);
            }
        }
        for (int i = 0;i < tarh;i++)
        {
            scanf("%s",s);
            int num = calc(s[0]);
            for (int j = 5;j >= 0;j--)
                tar[i][j] = (((num>>j)&1) == 1);
        }
        int res = 0;
        printf("%d\n",res);
    }
    return 0;
}
