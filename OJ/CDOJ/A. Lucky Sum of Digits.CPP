#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        int minlen = 19921005;
        int maxfour = 0;
        for (int i = n/4;i >= 0;i--)
            if ((n-4*i)%7 == 0)
            {
                if (minlen > i+(n-4*i)/7)
                {
                    minlen = i+(n-4*i)/7;
                    maxfour = i;
                }
                else if (minlen == i+(n-4*i)/7)
                    maxfour = max(maxfour,i);
            }
        if (minlen == 19921005)  printf("-1\n");
        else
        {
            for (int i = 0;i < maxfour;i++)
                printf("4");
            for (int i = maxfour;i < minlen;i++)
                printf("7");
            printf("\n");
        }
    }
    return 0;
}
