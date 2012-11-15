#include <stdio.h>

int inc(__int64 k)
{
	int len = 0;
	while(k != 0)
	{
		len++;
		k = k / 10;
	}
	return len;
}

int main()
{
	__int64 i,j,n,k,len;

	scanf("%I64d",&n);
	while (n--)
	{
		scanf("%I64d",&i);
		j = len = 0; //len 为第K串数的长度 
		k = 1;
		while (j < i)		//找到那一串数	
		{
			len += inc(k); // k为N位数时len的公差为N 
			k++;   //累加K 
			j += len;      //前K串数的长度 
		}
		
		j -= len;          //i在第k串数中，前k-1串数的总长为j -= len 
		k = 1;             //i在这串数中的第K个数 
		while (j < i)          //找到那串数里的那个数
		{
			j += inc(k);       //k为N位数时K的长度为inc(k)=N 
			k++;               //加K 
		}
		k--;                   //i在第K个数中 
		j -= inc(k);           //前k-1个数总长为j 
		len = inc(k) - (i - j);
		while(len--)           //找到那个数里的那个数字
			k = k / 10;

		printf("%I64d\n",k % 10);
	}

	return 0;
}
