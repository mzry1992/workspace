#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int la,len;
char a[1000],res[7][1000];

void putit(int num,int pos)
{
    for (int i = 0;i < num;i++)
        res[i][pos] = '+';
    for (int i = num;i < 7;i++)
        res[i][pos] = '*';
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%s",a);
        la = strlen(a);
        len = 0;
        int pre = a[0]-'0';
        int mx = pre;
        for (int i = 0;i < la;i++)
        {
            if (a[i]-'0' == pre)
                putit(a[i]-'0',len++);
            else if (a[i]-'0' > pre)
                for (int j = pre+1;j <= a[i]-'0';j++)
                    putit(j,len++);
            else
                for (int j = pre-1;j >= a[i]-'0';j--)
                    putit(j,len++);
            pre = a[i]-'0';
            mx = max(mx,pre);
        }
        for (int i = mx-1;i >= 0;i--)
        {
            for (int j = 0;j < len;j++)
                putchar(res[i][j]);
            puts("");
        }
    }
	return 0;
}
