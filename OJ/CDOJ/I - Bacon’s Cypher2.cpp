#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[6000];

int main()
{
    while (scanf("%s",s) != EOF)
    {
        totbuf = 0;
        for (int i = 0;i < 26;i++)
            buf[0].next[i] = -1;
        int l = strlen(s);
        int totres = 0;
        for (int i = 0;i < l;i++)
        {
            int cur = 0;
            for (int j = i;j < l;j++)
            {
                if (buf[cur].next[s[j]-'a'] == -1)
                {
                    totres++;
                    totbuf++;
                    for (int k = 0;k < 26;k++)
                        buf[totbuf].next[k] = -1;
                    buf[cur].next[s[j]-'a'] = totbuf;
                }
                cur = buf[cur].next[s[j]-'a'];
            }
        }
        printf("%d\n",totres);
    }
}
