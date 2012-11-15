#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b,res,num[10],totnum,ti,tn;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&b);
        res = 0;
        for (int i = a;i <= b;i++)
        {
            totnum = 0;
            ti = i;
            while (ti > 0)
            {
                totnum++;
                num[totnum] = ti%10;
                ti /= 10;
            }
            tn = 0;
            for (int i = 1;i <= totnum;i++)
                tn = tn*10+num[i];
            if (tn >= a && tn <= b) res++;
        }
        printf("%d\n",res);
    }
}
