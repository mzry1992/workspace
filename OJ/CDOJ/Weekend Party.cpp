#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[64],v,tot[2*3*5+1];
char s[5];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= 2*3*5;i++)
            tot[i] = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%*s%s",s);
            v = 1;
            for (int j = 0;j < strlen(s);j++)
                if (s[j] == 'A')
                    v *= 2;
                else if (s[j] == 'C')
                    v *= 3;
                else
                    v *= 5;
            a[i] = v;
            tot[v]++;
        }
    }
    return 0;
}
