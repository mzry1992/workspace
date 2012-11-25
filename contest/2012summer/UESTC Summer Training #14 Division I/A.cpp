#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char s[110][20];
int n;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        int pos = -1;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",s[i]);
            if (s[i][0] != '#')
                pos = i;
        }
        bool first = true;
        for (int i = pos+1;i < n;i++)
        {
            if (!first) printf(" ");
            first = false;
            printf("%s",s[i]);
        }
        if (pos >= 0)
        {
            if (!first) printf(" ");
            first = false;
            printf("%s",s[pos]);
        }
        for (int i = 0;i < pos;i++)
        {
            if (!first) printf(" ");
            first = false;
            printf("%s",s[i]);
        }
        puts("");

    }
	return 0;
}
