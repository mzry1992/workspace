#include <stdio.h>
#include <string.h>

struct dictype //�ֵ����͡� 
{
       char word[50];
};
struct dictype dic[15000];
char line[50];
int n,i,j;

int found(char *s) //������������Ƿ�������ֵ��С� 
{
    int i,j;
    for (i = 1;i <= n;i++)
        if (strcmp(dic[i].word,line) == 0) return i;
    return 0;
}

int cmp(char *s1,char *s2) //�Ƚ����������Ƿ�������� 
{
    int l1,l2,i,j,k,flag;
    l1 = strlen(s1);
    l2 = strlen(s2);
    if (l1 == l2) //���������ͬ���ж��Ƿ�ֻ���һ����ĸ�� 
    {
           i = 0;
           while (s1[i] == s2[i]) //���ҵ���ͬ�ĵ�������� 
                 i++;
           for (j = i+1;j < l1;j++) //�жϺ������ĸ�Ƿ�һ���� 
               if (s1[j] != s2[j]) return 1;
           return 0;
    }
    if (l1 < l2) //���l1С��l2 
    {
        if (l1+1 != l2) return 1; //����������1����ô�϶����ǡ����ơ��ĵ��ʡ� 
        for (i = 0;i < l2;i++) //ö�ٶ�������Ǹ���ĸ��S2�е�λ�� 
        {
            flag = 0;
            for (j = 0;j <= i-1;j++) //���ȥ�������ĸs1s2������ƥ����ô��˵�����������ʲ��ǡ����ơ��ĵ��ʡ� 
                if (s1[j] != s2[j])
                   flag = 1;
            for (j = i+1;j < l2;j++)
                if (s1[j-1] != s2[j])
                   flag = 1;
            if (flag == 0) return 0;
        }
    }
    else
    {
        if (l2+1 != l1) return 1; //����Ƕ�һ����ĸ��������Գơ� 
        for (i = 0;i < l1;i++)
        {
            flag = 0;
            for (j = 0;j <= i-1;j++)
                if (s1[j] != s2[j])
                   flag = 1;
            for (j = i+1;j < l1;j++)
                if (s1[j] != s2[j-1])
                   flag = 1;
            if (flag == 0) return 0;
        }
    }
    return 1;
}

int main()
{
    n = 0;
    while (1 == 1) //�����ֵ䡣 
    {
         gets(line);
         if ((strlen(line) == 1) && (line[0] == '#'))
            break;
         n++;
         strcpy(dic[n].word,line);
    }
    while (1 == 1)
    {
          gets(line);
          if ((strlen(line) == 1) && (line[0] == '#'))
            break;
          if (found(line) != 0) //���ж��Ƿ���ȷ�� 
             printf("%s is correct\n",line);
          else //�������ȷ�ҵ��������������ơ��ĵ��ʣ���������� 
          {
              printf("%s:",line);
              for (i = 1;i <= n;i++)
              if (cmp(dic[i].word,line) == 0)
                 printf(" %s",dic[i].word);
              printf("\n");
          }
    }
    return 0;
}
