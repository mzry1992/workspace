#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a0,a1;
char s[101];

int main()
{
    s[0] = '2';
    scanf("%s",s+1);
    int len = strlen(s);
    a0 = a1 = 0;
    bool flag = true;
    for (int i = 1;i < len;i++)
    {
        if (s[i] == '0' && s[i-1] == '0')
        {
            a0++;
            if (a0 >= 7)    flag = false;
        }
        else if (s[i] == '1' && s[i-1] == '1')
        {
            a1++;
            if (a1 >= 7)    flag = false;
        }
        else if (s[i] == '1')
        {
            a0 = 0;
            a1 = 1;
        }
        else
        {
            a0 = 1;
            a1 = 0;
        }
    }
    if (flag == true)   printf("NO\n");
    else printf("YES\n");
}
