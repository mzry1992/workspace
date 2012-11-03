#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b,p;
int va[10000000],vb[10000000];
int x,y,res;

int main()
{
    while (scanf("%d%d%d",&a,&b,&p) != EOF)
    {
        for (int i = 0;i < p;i++)
            va[i] = vb[i] = -1;
        x = y = 0;
        while (true)
        {
            if (va[x] != -1)  break;
            va[x] = y;
            x = x+1000000000;
            x %= p;
            y++;
            if (y > a)  break;
        }
        x = y = 0;
        while (true)
        {
            if (vb[x] != -1)  break;
            vb[x] = y;
            x = x+1000000000;
            x %= p;
            y++;
            if (y > b)  break;
        }
        res = a+1;
        bool flag = true;
        for (int i = 0;i < p;i++)
            if (va[i] != -1 && vb[(p-i)%p] == -1)
            {
                res = min(res,va[i]);
                flag = false;
            }
        if (flag == true)
            printf("2\n");
        else
            printf("1 %09d\n",res);
    }
    return 0;
}
