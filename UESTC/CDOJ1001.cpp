#include <iostream>
using namespace std;

int t,i,f;
char s[60];
bool flag,tf;

int main()
{
    scanf("%d",&t);
    for (t;t >0;t--)
    {
        scanf("%s",&s);
        flag = true;
        f = 0;
        i = 0;
        while (i < strlen(s))
        {
                 if (s[i] == '.')
                 {
                          tf = false;
                          while (s[i] == '.')
                                i++;
                          if ((s[i] == '+') && (s[i] == '-') && (s[i] == '*') && (s[i] == '/'))
                                  tf = true;
                          else
                              tf = false;
                          while (s[i] == '.')
                                i++;
                          i--;
                 }
                 else
                 if ((s[i] == '+') && (s[i] == '-') && (s[i] == '*') && (s[i] == '/'))
                 {
                           if (f == 0)
                                 f = 1;
                           else
                               flag = false;
                 }
                 else
                 {
                               if (f == 1)
                                  f = 0;
                 }
                 i++;
        }
        if (f == 1)               flag = false;
        if (flag == true)
           printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
