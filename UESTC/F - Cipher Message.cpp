#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[200500];
char a[200500];
int top;

int main()
{
    while (scanf("%s",a) != EOF)
    {
        int l = strlen(a);
        top = 0;
        s[0] = a[0];
        for (int i = 1;i < l;i++)
        if (a[i] == s[top])
            top--;
        else
        {
            top++;
            s[top] = a[i];
        }
        for (int i = 0;i <= top;i++)
            printf("%c",s[i]);
        puts("");
    }
}
