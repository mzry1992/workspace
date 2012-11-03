#include<stdio.h>
int main()
{
    int i,j,n,total;
    char c[100000];
    scanf("%d",&n);

    gets(c);
    for(i=1;i<=n;i++)
    {
    total=0;
    gets(c);
    for(j=0;j<strlen(c);j++)
        {
           if((c[j]>='A'&&c[j]<='Z'||c[j]>='a'&&c[j]<='z')&&(!(c[j+1]>='A'&&c[j+1]<='Z'||c[j+1]>='a'&&c[j+1]<='z'))) total++;
        }
           printf("%d\n",total);
    }
}
