#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10000];
int res;

int main()
{
    int t;
    scanf("%d",&t);
    gets(s);
    for (int ft = 1;ft <= t;ft++)
    {
        gets(s);
        res = 0;
        int len = strlen(s);
        s[len] = ' ';
        for (int i = 0;i < len+1;i++)
        {
            if (i+2 < len+1)
            {
                if (s[i] == ':' && s[i+1] == '(')
                {
                    if (s[i+2] == '(')
                        res -= 5;
                    else
                        res -= 1;
                }
                if (s[i] == ':' && s[i+1] == ')')
                {
                    if (s[i+2] == ')')
                        res += 4;
                    else
                        res += 2;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
