#include <stdio.h>
#include <string.h>

int main()
{
    int t,ft;
    char s[200];
    scanf("%d",&t);
    gets(s);
    for (ft = 1;ft <= t;ft++)
    {
        gets(s);
        int tot = 0;
        int now = 0;
        int next = 0;
        while (now < strlen(s))
        {
            while (s[now] == ' ')   now++;
            next = now;
            while (s[next] != ' ')  next++;
            tot++;
            now = next;
        }
        printf("%d\n",tot);
    }
}
