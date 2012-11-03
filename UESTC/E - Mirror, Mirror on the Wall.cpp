#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10000];
const char gao[] = "abcdefghijklmnopqrstuvwxyz";
const char ji[] =  "AdAbAAAAiAAAAAoqpAAAAvwxAA";

int main()
{
    while (true)
    {
        scanf("%s",s);
        if (strcmp(s,"#") == 0) break;
        int l = strlen(s);
        bool hasans = true;
        for (int i = l-1;i >= 0;i--)
        {
            if (ji[s[i]-'a'] == 'A')
            {
                hasans = false;
                break;
            }
            else
                s[i] = ji[s[i]-'a'];
        }
        if (hasans == false)    printf("INVALID\n");
        else
        {
            for (int i = l-1;i >= 0;i--)
                printf("%c",s[i]);
            puts("");
        }
    }
}
