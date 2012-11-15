#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        bool dot1,dot2,oper,num;
        dot1 = dot2 = oper = num = false;
        if (s[0] > '9' || s[0] < '0')
        {
            puts("No");
            continue;
        }
        num = true;
        bool flag = true;
        for (int i = 0;i < strlen(s);i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (num == false)
                {
                    if (oper == false)
                    {
                        flag = false;
                        break;
                    }
                    num = true;
                    dot1 = dot2 = oper = false;
                }
            }
            else if (s[i] == '.')
            {
                if (oper == false)  dot1 = true;
                else dot2 = true;
                num = false;
            }
            else
            {
                if (dot2 == true)
                {
                    flag = false;
                    break;
                }
                oper = true;
                num = false;
            }
        }
        if (flag == false)  puts("No");
        else puts("Yes");
    }
}
