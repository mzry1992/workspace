#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1001];
int dot,len;

int main()
{
    s[0] = '0';
    scanf("%s",s+1);
    dot = len;
    len = strlen(s);
    for (int i = 1;i < len;i++)
        if (s[i] == '.')
            dot = i;
    if (s[dot-1] == '9')
        printf("GOTO Vasilisa.\n");
    else
    {
        if (s[dot+1] <= '4')
        {
            for (int i = 1;i < dot;i++)
                printf("%c",s[i]);
            printf("\n");
        }
        else
        {
            s[dot-1]++;
            for (int i = dot-1;i >= 0;i--)
                if (s[i] > '9')
                {
                    s[i-1]++;
                    s[i] -= 10;
                }
            if (s[0] != '0')
            {
                for (int i = 0;i < dot;i++)
                    printf("%c",s[i]);
                printf("\n");
            }
            else
            {
                for (int i = 1;i < dot;i++)
                    printf("%c",s[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
