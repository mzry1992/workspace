#include <stdio.h>

void swap(int *a,int *b)
{
     int t;
     t = *a;
     *a = *b;
     *b = t;
}

int main()
{
    int l,m,i,j,result,del;
    int a[100],b[100];
    scanf("%d %d",&l,&m);
    result = l+1;
    del = 0;
    for (i = 0;i < m;i++)  scanf("%d %d",&a[i],&b[i]);
    for (i = 0;i < m;i++)
    for (j = i;j < m;j++)
    if (a[i] > a[j]) 
    {
             swap(&a[i],&a[j]);
             swap(&b[i],&b[j]);
    }
    int left,right;
    left = a[0];
    right = b[0];
    for (i = 1;i < m;i++)
    if (a[i] <= right)
    {
             if (b[i] > right) right = b[i];
    }
    else
    {
             del += right-left+1;
             left = a[i];
             right = b[i];
    }
    del += right-left+1;
    result -= del;
    printf("%d\n",result);
    return 0;
}
        
    
        
