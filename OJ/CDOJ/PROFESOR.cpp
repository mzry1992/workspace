#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[100000],b[100000],pre,res,resb;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d%d",&a[i],&b[i]);
        res = 0;
        for (int i = 1;i <= 5;i++)
        {
            pre = -1;
            for (int j = 0;j < n;j++)
                if (a[j] == i || b[j] == i)
                {
                    if (pre == -1)
                    {
                        pre = j;
                        if (1 > res)
                        {
                            res = 1;
                            resb = i;
                        }
                    }
                    else
                    {
                        if (j-pre+1 > res)
                        {
                            res = j-pre+1;
                            resb = i;
                        }
                    }
                }
                else
                    pre = -1;
        }
        printf("%d %d\n",res,resb);
    }
}
