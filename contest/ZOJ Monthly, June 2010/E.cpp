#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxm = 100000;
int w,h,a[300][300];
int xa[maxm],ya[maxm],xb[maxm],yb[maxm],op[maxm];
int stack[maxm],top;

int main()
{
    while (scanf("%d%d",&w,&h) != EOF)
    {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf("%d",&a[i][j]);
        int m;
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i],&op[i]);
        int x,y;
        scanf("%d%d",&x,&y);
        top = 0;
        for (int i = m-1; i >= 0; i--)
            if (xa[i] <= x && x <= xb[i] &&
                    ya[i] <= y && y <= yb[i])
            {
                if (op[i] == 4)
                    x = xa[i]+xb[i]-x;
                else if (op[i] == 5)
                    y = ya[i]+yb[i]-y;
                stack[top++] = i;
            }
        int ans = a[y][x];
        while (top > 0)
        {
            top--;
            if (op[stack[top]] == 1)
                ans = -ans;
            else if (op[stack[top]] == 2)
                ans ++;
            else if (op[stack[top]] == 3)
                ans --;
        }
        printf("%d\n",ans);
    }
    return 0;
}
