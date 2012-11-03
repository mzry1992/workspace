#include <stdio.h>
#include <string.h>

struct dictype //字典类型。 
{
       char word[50];
};
struct dictype dic[15000];
char line[50];
int n,i,j;

int found(char *s) //查找这个单词是否存在于字典中。 
{
    int i,j;
    for (i = 1;i <= n;i++)
        if (strcmp(dic[i].word,line) == 0) return i;
    return 0;
}

int cmp(char *s1,char *s2) //比较两个单词是否“相近”。 
{
    int l1,l2,i,j,k,flag;
    l1 = strlen(s1);
    l2 = strlen(s2);
    if (l1 == l2) //如果长度相同，判断是否只相差一个字母。 
    {
           i = 0;
           while (s1[i] == s2[i]) //先找到不同的单词在哪里。 
                 i++;
           for (j = i+1;j < l1;j++) //判断后面的字母是否都一样。 
               if (s1[j] != s2[j]) return 1;
           return 0;
    }
    if (l1 < l2) //如果l1小于l2 
    {
        if (l1+1 != l2) return 1; //如果不是相差1，那么肯定不是“相似”的单词。 
        for (i = 0;i < l2;i++) //枚举多出来的那个字母在S2中的位置 
        {
            flag = 0;
            for (j = 0;j <= i-1;j++) //如果去掉这个字母s1s2还不能匹配那么就说明这两个单词不是“相似”的单词。 
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
        if (l2+1 != l1) return 1; //如果是多一个字母，与上面对称。 
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
    while (1 == 1) //输入字典。 
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
          if (found(line) != 0) //先判断是否正确。 
             printf("%s is correct\n",line);
          else //如果不正确找到所有与它“相似”的单词，并且输出。 
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
