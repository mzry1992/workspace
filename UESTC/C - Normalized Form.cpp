#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[32001];
bool res;
int len,deep[32001];
int sd[32001];
bool sv[32001];
int top,maxdeep;

bool calc(bool a,int deep,bool b)
{
    if ((maxdeep-deep)%2 == 0)    return a&b;
    else return a|b;
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%s",s);
        if (strcmp(s,"()") == 0)    break;
        ft++;
        len = strlen(s);
        deep[0] = 0;
        maxdeep = 0;
        int cur = 0;
        for (int i = 0;i < len;i++)
        {
            if (s[i] == '(')
                cur++;
            else if (s[i] == ')')
                cur--;
            deep[i] = cur;
            maxdeep = max(maxdeep,deep[i]);
        }
        top = 0;
        for (int i = 0;i < len;i++)
        {
            if (s[i] == 'T' || s[i] == 'F')
            {
                sd[top] = deep[i];
                sv[top++] = (s[i]=='T')?true:false;
            }
            else if (s[i] == ')')
            {
                while (top > 1 && sd[top-1] == sd[top-2])
                {
                    sv[top-2] = calc(sv[top-1],sd[top-1],sv[top-2]);
                    top--;
                }
                sd[top-1]--;
            }
        }
        res = sv[top-1];
        printf("%d. %s\n",ft,res?"true":"false");
    }
    return 0;
}
