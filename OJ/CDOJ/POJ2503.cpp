#include <stdio.h>
#include <string.h>

char s[50],s1[20],s2[20],hashs[201000][20],hasht[201000][20];
int i,len,j,thash,hashf[201000];

int gethash(char *s)
{
    int len,i,j,temp,low;
    len = strlen(s);
    low = 1;
    temp = 0;
    for (i = 0;i < len;i++)
    {
        temp += (low*(s[i]-'A'))%201000;
        low *= 26;
    }
    return temp%201000;
}

int main()
{
    for (thash = 0;thash <= 201000;thash++)
        hashf[thash] = 0;
    while (1 == 1)
    {
        gets(s);
        len = strlen(s);
        if (len == 0) break;
        i = 0;
        while (s[i] != ' ')
        {
              s1[i] = s[i];
              i++;
        }
        s1[i] = '\0';
        i++;
        j = 0;
        while (s[i] != '\0')
        {
              s2[j] = s[i];
              i++;
              j++;
        }
        s2[j] = '\0';
        thash = gethash(s2);
        while (hashf[thash] != 0)
              thash = (thash+1)%201000;
        thash %= 201000;
        hashf[thash] = 1;
        strcpy(hashs[thash],s1);
        strcpy(hasht[thash],s2);
    }
    while (1 == 1)
    {
          gets(s);
          len = strlen(s);
          if (len == 0) break;
          thash = gethash(s);
          while ((hashf[thash] == 1) && (strcmp(hasht[thash],s) != 0))
                thash = (thash+1)%201000;
          thash %= 201000;
          if (hashf[thash] == 0)
             printf("eh\n");
          else
              printf("%s\n",hashs[thash]);                 
    }
    return 0;
}
