#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char buf[5200000],s[5200000];
int buflen,len;

int main()
{
    scanf("%s",buf);
    buflen = strlen(buf);
    len = 0;
    for (int i = 0;i < buflen;)
        if (buf[i] == '[')
        {
            int num = 0;
            for (int j = i+1;;j++)
                if (buf[j] >= '0' && buf[j] <= '9')
                    num = num*10+buf[j]-'0';
                else
                {
                    for (int k = 0;k < num;k++)
                        s[len++] = buf[j];
                    i = j+2;
                    break;
                }
        }
        else
            s[len++] = buf[i++];
    s[len] = 0;
    printf("%s\n",s);
    return 0;
}
