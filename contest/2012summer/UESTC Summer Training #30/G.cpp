#include <cstdio>
void out(int x,int l)
{
    int a[20];
    for (int i=0;i<20;i++)
        a[i]=0;
    for (int i=0;x;x/=2,i++)
        a[i]=x%2;
    for (int i=l-1;i>=0;i--)
        printf("%d",a[i]);
    putchar(' ');
    for (int i=l-1;i>=0;i--)
        printf("%d",a[i]^a[i+1]);
    puts("");
}
int main()
{
    int n;
    scanf("%d",&n);
    int l=0;
    for (int i=n-1;i;i/=2)
        l++;
    for (int i=0;i<n;i++)
        out(i,l);
}
