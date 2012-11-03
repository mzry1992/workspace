#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char b[1000010];
int p[1000010],l;

int main()
{
    while (scanf("%s",b) != EOF)
    {
        l = strlen(b);
        int j;
        p[0] = j = -1;
        for (int i = 1; i < l; i++)
        {
            while (j >= 0 && b[j+1] != b[i]) j = p[j];
            if (b[j+1] == b[i]) j++;
            p[i] = j;
        }
        printf("%d\n",l-p[l-1]-1);
    }
    return 0;
}
