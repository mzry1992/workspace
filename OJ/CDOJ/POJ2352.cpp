#include <stdio.h>

int n,x[16000],y,fn,sum[16000],a[330000];

int lowbit(int t)
{
    return (t & (-t));
}

int getsum(int end)
{
    int temp = 0;
    while (end > 0)
    {
          temp += a[end];
          end -= lowbit(end);
    }
    return temp;
}

void plus(int pos,int num)
{
     while (pos <= 330000)
     {
           a[pos] += num;
           pos += lowbit(pos);
     }
}

int main()
{
    scanf("%d",&n);
    sum[0] = 0;
    for (fn = 1;fn <= n;fn++)
    {
        scanf("%d %d",&x[fn],&y);
        sum[fn] = 0;
    }
    for (fn = 0;fn <= 320000;fn++)
        a[fn] = 0;
    for (fn = 1;fn <= n;fn++)
    {
        sum[getsum(x[fn]+1)]++;
        plus(x[fn]+1,1);
    }
    for (fn = 0;fn <= n-1;fn++)
        printf("%d\n",sum[fn]);
    return 0;
}
