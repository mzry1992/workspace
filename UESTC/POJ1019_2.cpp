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
		j = len = 0; //len Ϊ��K�����ĳ��� 
		k = 1;
		while (j < i)		//�ҵ���һ����	
		{
			len += inc(k); // kΪNλ��ʱlen�Ĺ���ΪN 
			k++;   //�ۼ�K 
			j += len;      //ǰK�����ĳ��� 
		}
		
		j -= len;          //i�ڵ�k�����У�ǰk-1�������ܳ�Ϊj -= len 
		k = 1;             //i���⴮���еĵ�K���� 
		while (j < i)          //�ҵ��Ǵ�������Ǹ���
		{
			j += inc(k);       //kΪNλ��ʱK�ĳ���Ϊinc(k)=N 
			k++;               //��K 
		}
		k--;                   //i�ڵ�K������ 
		j -= inc(k);           //ǰk-1�����ܳ�Ϊj 
		len = inc(k) - (i - j);
		while(len--)           //�ҵ��Ǹ�������Ǹ�����
			k = k / 10;

		printf("%I64d\n",k % 10);
	}

	return 0;
}
