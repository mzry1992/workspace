#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a,res;
char s[20];
int len;

int main()
{
    while (true)
    {
        scanf("%d",&a);
        if (a == 0) break;
        res = 0;
        sprintf(s,"%d",a);
        len = strlen(s);
        for (int i = 0;i < len;i++)
            if (s[i] >= '4' && s[i] <= '7')
                s[i]--;
            else if (s[i] >= '9')
                s[i] -= 2;
        for (int i = 0;i < len;i++)
        {
            res = res*8+s[i]-'0';
        }
        printf("%d: %d\n",a,res);
    }
	return 0;
}
