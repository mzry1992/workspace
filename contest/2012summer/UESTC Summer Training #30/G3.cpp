#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[110000],b[110000];
int l;

int solve()
{
    bool mut = false;
    for (int i = 1; i < l; i++)
        if (a[i] == '?' && b[i] == '?')
        {
            int j=i+1;
            for (; j<l && a[j]=='?' && b[j]!='?'; j++);
            if (j==l || b[j]=='?')
            {
                mut=true;
                b[i]='0';
                for (; i<j; i++)
                {
                    int x = (a[i-1]-'0')^(b[i]-'0');
                    a[i] = '0'+x;
                }
            }
            else
            {
                for (int k=j-1; k>=i; k--)
                    a[k]=(a[k+1]-'0')^(b[k+1]-'0')+'0';
                b[i]=(a[i]-'0')^(a[i-1]-'0')+'0';
            }
            i=j-1;
        }
        else
        {
            int x;
            if (a[i] != '?')
            {
                x = (a[i-1]-'0')^(a[i]-'0');
                if (b[i] != '?' && b[i]-'0' != x)
                    return 0;
                b[i] = '0'+x;
            }
            else
            {
                int x = (a[i-1]-'0')^(b[i]-'0');
                a[i] = '0'+x;
            }
        }
    if (mut == true)
        return 1;
    return 2;
}

int main()
{
    a[0] = b[0] = '0';
    scanf("%s%s",a+1,b+1);
    l = strlen(a);
    int res = solve();
    if (res == 0)
        puts("Impossible");
    else if (res == 1)
        puts("Ambiguity");
    else
    {
        puts(a+1);
        puts(b+1);
    }
    return 0;
}
