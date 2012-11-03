#include<iostream>
#include<stdio.h>
#include<string.h>
struct num
{
	int a[600];
	int l;
};
int fun(char *x,num *a)
{
	a->l=0;
	while(*x!='\0')
	{
		a->a[a->l]=*x-'0';
		a->l++;
		x++;
	}
	return 0;
}
int main()
{
	char x[600],y[600];
	while(scanf("%s%s",x,y)!=EOF)
	{
		num a,b,ans;
		fun(x,&a);
		fun(y,&b);
		ans.l=0;
		a.l-=1;
		b.l-=1;
		ans.a[0]=0;
		int l;
		l=(a.l>b.l)?a.l:b.l;
		for(;;ans.l++)
		{
			ans.a[ans.l]+=(a.a[a.l]+b.a[b.l]);
			ans.a[ans.l+1]=ans.a[ans.l]/10;
			ans.a[ans.l]=ans.a[ans.l]%10;
			if(a.l>0&&a.l<=l)
				a.l--;
			else
			{
				a.l=l+1;
				a.a[l+1]=0;
			}
			if(b.l>0&&b.l<=l)
				b.l--;
			else
			{
				b.l=l+1;
				b.a[l+1]=0;
			}
			if(ans.l>=l&&ans.a[l+1]==0)
				break;
		}
		for(int i=ans.l;i>=0;i--)
			printf("%d",ans.a[i]);
		printf("\n");
	}
}
