#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char line[5000];
int len,add;

const char xx[] = "0123456789abcdef";

void output(char ch)
{
    printf("%c%c",xx[ch/16],xx[ch%16]);
}

void output2(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        printf("%c",ch-'a'+'A');
    else if (ch >= 'A' && ch <= 'Z')
        printf("%c",ch-'A'+'a');
    else
        printf("%c",ch);
}

int main()
{
    //freopen("out.txt","w",stdout);
    while (gets(line))
    {
        len = strlen(line);
        add = 0;
        for (int i = 0;i < len;i += 16)
        {
            printf("%04x:",add);
            for (int j = 0;j < 16;j++)
            {
                if (j%2 == 0)
                    printf(" ");
                if (i+j < len)
                    output(line[i+j]);
                else
                    printf("  ");
            }
            printf(" ");
            for (int j = 0;j < 16;j++)
                if (i+j < len)
                    output2(line[i+j]);
                else
                    break;
            printf("\n");
            add += 16;
        }
    }
    return 0;
}
