#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[100100],s[100100];
int len,top;

bool check(char ch)
{
    return ch == ' ' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main()
{
    while (gets(buf))
    {
        len = strlen(buf);
        top = 0;
        char pre = ':';
        for (int i = 0;i < len;i++)
            if (check(buf[i]) == false)
                s[top++] = buf[i];
        int res = 0;
        for (int i = 0;i < top;i++)
            if (s[i] == '(')
            {
                if (i+1 == top || s[i+1] != ')')
                    res++;
            }
            else if (s[i] == ')')
            {
                if (i == 0 || s[i-1] != '(')
                    res++;
            }
        //s[top] = 0;
        //cout << s << endl;
        printf("%d\n",res);
    }
	return 0;
}
