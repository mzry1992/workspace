/*
ID: muziriy3
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s;
int temp[40];

int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    scanf("%d%d",&n,&s);
    int now = s;
    for (int i = 1;i <= n;i++)
    {
        while (true)
        {
            now++;
            int flag = 0;
            for (int base = 2;base <= 10;base++)
            {
                int tot = 0;
                int tt = now;
                while (tt > 0)
                {
                    tot++;
                    temp[tot] = tt%base;
                    tt /= base;
                }
                bool tflag = true;
                for (int j = 1;j <= tot/2;j++)
                if (temp[j] != temp[tot+1-j])
                    tflag = false;
                if (tflag == true)
                    flag++;
            }
            if (flag >= 2)
            {
                printf("%d\n",now);
                break;
            }
        }
    }
}
