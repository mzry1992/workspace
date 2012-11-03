#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//scheme://domain:port/path?query_string#fragment_id
char s[2000];
int len;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        len = strlen(s);
        for (int i = 3;i < len;i++)
            if (s[i-1] == '/' && s[i-2] == '/' && s[i-3] == ':')
            {
                for (int j = i;;j++)
                    if (s[j] == '/' || s[j] == ':')
                    {
                        printf("Case #%d: ",ft);
                        for (int k = i;k < j;k++)
                            printf("%c",s[k]);
                        printf("\n");
                        break;
                    }
                break;
            }
    }
    return 0;
}
