#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,l;
char buf[1100][1100],s[1100];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",buf[i]);
        m = strlen(buf[0]);
        l = 0;
        bool start = false;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
            {
                if (buf[j][i] != '_')
                    start = true;
                if (start)
                    s[l++] = buf[j][i];
            }
        s[l] = 0;
        for (int i = l-1;i >= 0;i--)
            if (s[i] == '_')
                printf(" ");
            else if (s[i] == '\\')
                printf("\n");
            else
                printf("%c",s[i]);
        printf("\n\n");
    }
	return 0;
}
