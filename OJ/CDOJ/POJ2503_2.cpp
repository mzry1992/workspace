#include<stdio.h>
#include<string.h>

struct dictype //定义一个类型。存放字典 
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
	while (line[0] != '\0' ) //输入部分 
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
		while (dic[n].foreign[i] != '\0') //哈希函数。 
		{
			getf = getf*26+dic[n].foreign[i];
			getf %= 300000;
			i++;
		}
		while (hash[getf] != -1) //线性冲突探测 
			getf = (getf+1)%300000;
		hash[getf] = n;
		n++;
		gets(line);
	}
	while (gets(line)) //读取部分 
	{
		getf = 0;
        i = 0;
		while (line[i] != '\0') //哈希函数 
		{
			getf = getf*26+line[i];
			getf %= 300000;
			i++;
		}
		while ((hash[getf] != -1) && (strcmp(dic[hash[getf]].foreign,line) != 0)) //找到位置 
			getf = (getf+1)%300000;
		if (hash[getf] != -1)  
			printf("%s\n",dic[hash[getf]].word); //如果找到，那么输出 
		else
			printf("eh\n"); //否则输出eh 
	}
	return 0;
}
