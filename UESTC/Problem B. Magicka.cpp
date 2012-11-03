#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const string base = "QWERASDF";
int c,d,n;
char sc[50][10],sd[50][10],sn[120];
char s[200];
int top;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("AAAAAA.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&c);
        for (int i = 1;i <= c;i++)
            scanf("%s",sc[i]);
        scanf("%d",&d);
        for (int i = 1;i <= d;i++)
            scanf("%s",sd[i]);
        scanf("%d",&n);
        scanf("%s",sn);
        top = 1;
        s[top] = sn[0];
        for (int i = 1;i < n;i++)
        {
            char now = sn[i];
            bool isdo = false;
            for (int j = 1;j <= c;j++)
            if (sc[j][0] == now)
            {
                if (sc[j][1] == s[top])
                {
                    s[top] = sc[j][2];
                    isdo = true;
                    break;
                }
            }
            else if (sc[j][1] == now)
            {
                if (sc[j][0] == s[top])
                {
                    s[top] = sc[j][2];
                    isdo = true;
                    break;
                }
            }
            if (isdo == false)
            {
                for (int j = 1;j <= d;j++)
                if (sd[j][0] == now)
                {
                    bool flag = false;
                    for (int k = 1;k <= top;k++)
                    if (s[k] == sd[j][1])
                        flag = true;
                    if (flag == true)
                    {
                        top = 0;
                        isdo = true;
                        break;
                    }
                }
                else if (sd[j][1] == now)
                {
                    bool flag = false;
                    for (int k = 1;k <= top;k++)
                    if (s[k] == sd[j][0])
                        flag = true;
                    if (flag == true)
                    {
                        top = 0;
                        isdo = true;
                        break;
                    }
                }
            }
            if (isdo == false)
            {
                top++;
                s[top] = now;
            }
        }
        printf("Case #%d: [",ft);
        bool first = true;
        for (int i = 1;i <= top;i++)
        {
            if (first == false) printf(", ");
            first = false;
            printf("%c",s[i]);
        }
        printf("]\n");
    }
}
