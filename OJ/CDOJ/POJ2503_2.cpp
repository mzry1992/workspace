#include<stdio.h>
#include<string.h>

struct dictype //����һ�����͡�����ֵ� 
{
	char word[13];
	char foreign[13];
};
struct dictype dic[100010];
int hash[300000],i,j,n,getf,rt;
char line[50];

int main()
{
	gets(line);
	n = 0;
	for (i = 0;i < 300000;i++)
		hash[i] = -1;
	while (line[0] != '\0' ) //���벿�� 
	{
		for (i = 0;line[i] != ' ';i++)
			dic[n].word[i] = line[i];
		dic[n].word[i++] = '\0';
		j = 0;
		for (i = i;line[i] != '\0';i++)
		{
			dic[n].foreign[j]=line[i];
			j++;
        }
		dic[n].foreign[j] = '\0';
		getf = 0;
		i = 0;
		while (dic[n].foreign[i] != '\0') //��ϣ������ 
		{
			getf = getf*26+dic[n].foreign[i];
			getf %= 300000;
			i++;
		}
		while (hash[getf] != -1) //���Գ�ͻ̽�� 
			getf = (getf+1)%300000;
		hash[getf] = n;
		n++;
		gets(line);
	}
	while (gets(line)) //��ȡ���� 
	{
		getf = 0;
        i = 0;
		while (line[i] != '\0') //��ϣ���� 
		{
			getf = getf*26+line[i];
			getf %= 300000;
			i++;
		}
		while ((hash[getf] != -1) && (strcmp(dic[hash[getf]].foreign,line) != 0)) //�ҵ�λ�� 
			getf = (getf+1)%300000;
		if (hash[getf] != -1)  
			printf("%s\n",dic[hash[getf]].word); //����ҵ�����ô��� 
		else
			printf("eh\n"); //�������eh 
	}
	return 0;
}
