#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int s;
const char ys[] = "lmpjeoruadbcyhwszxntfgqvik";
char rys[30];

int main()
{
    for (int i = 0;i < strlen(ys);i++)
        rys[ys[i]-'a'] = i+'a';
    while ((s = getchar()) != EOF)
    {
        if (s >= 'A' && s <= 'Z')
            putchar(rys[s-'A']-'a'+'A');
        else
        if (s >= 'a' && s <= 'z')
            putchar(rys[s-'a']);
        else
            putchar(s);
    }
}
