#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[200];
int n;

int findnext(int p)
{
    for (int j = p;j >= 0;j--)
            if (s[j] >= '0' && s[j] <= '9')
            {
                return j;
            }
            else if (s[j] >= 'a' && s[j] <= 'z')
            {
                return j;
            }
            else if (s[j] >= 'A' && s[j] <= 'Z')
            {
                return j;
            }
    return p;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%d",s,&n);
        for (int i = 1;i <= n;i++)
        {
            int l = strlen(s);
            int lm = findnext(l-1);
            int jt = 0;
            bool jw = false;
            bool hasdone = false;
            while (true)
            {
                if (jw == true)
                if ((lm >= 0 && (!((s[lm] >= '0' && s[lm] <= '9') || (s[lm] >= 'a' && s[lm] <= 'z') || (s[lm] >= 'A' && s[lm] <= 'Z')))) || lm == -1)
                {
                    for (int i = l;i > lm;i--)
                        s[i] = s[i-1];
                    s[l+1] = 0;
                    if (jt == 0)
                        s[lm+1] = '1';
                    else if (jt == 1)
                        s[lm+1] = 'a';
                    else if (jt == 2)
                        s[lm+1] = 'A';
                    break;
                }
                s[lm]++;
                if (s[lm] == '9'+1)
                {
                    s[lm] = '0';
                    jt = 0;
                    jw = true;
                }
                else if (s[lm] == 'z'+1)
                {
                    s[lm] = 'a';
                    jt = 1;
                    jw = true;
                }
                else if (s[lm] == 'Z'+1)
                {
                    s[lm] = 'A';
                    jt = 2;
                    jw = true;
                }
                else break;
                lm = findnext(lm-1);
            }
            printf("%s\n",s);
        }
        printf("\n");
    }
}
