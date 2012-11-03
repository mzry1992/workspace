#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[5],b[5];

int main()
{
    while (scanf("%s%s",a,b) != EOF)
    {
        int bulls,cows;
        bulls = cows = 0;
        for (int i = 0;i < 4;i++)
            if (a[i] == b[i])
                bulls++;
        for (int i = 0;i < 4;i++)
            if (a[i] != b[i])
                for (int j = 0;j < 4;j++)
                    if (a[i] == b[j])
                        cows++;
        printf("%d %d\n",bulls,cows);
    }
    return 0;
}
