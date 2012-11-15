#include <iostream>
__int64 count[20]={0,9,18,108,198,1098,1998,10998,19998,109998,199998,1099998,1999998,10999998,19999998,109999998,199999998,1099999998,1999999998,10999999998};
__int64 cc[20]={0,1,1,10,10,100,100,1000,1000,10000,10000,100000,100000,1000000,1000000,10000000,10000000,100000000,100000000,1000000000};
int main ()
{
	__int64 n,tmp,tag,tag1,tag2;
	char ch[20];
	int i,j,head,tail;
	while (scanf ("%I64d",&n)!=EOF)
	{
		if (n==0)
			break;
		if (n<10)
			printf ("%I64d\n",n);
		else
		{
			for (i=2;i<20;i++)
				if (n<=count[i])
					break;
		    tmp=n-count[i-1];
			if (tmp==0)
			{
				for (j=1;j<=i-1;j++)
					printf ("9");
				printf ("\n");
			}
			else
			{
				tmp--;tag1=cc[i];
				tag=tmp/tag1;			
				head=0;tail=i-1;
				ch[i]='\0';
				ch[head]='1'+tag;
				ch[tail]=ch[head];
				head++;tail--;
				tmp=tmp%tag1;
				tag1=tag1/10;
				while (tag1>=1)
				{
					tag=tmp/tag1;			
			    	ch[head]='0'+tag;
			    	ch[tail]=ch[head];
			    	head++;tail--;
			    	tmp=tmp%tag1;
			    	tag1=tag1/10;
				}
				printf ("%s\n",ch);
			}
		}
	}
	return 0;
}

