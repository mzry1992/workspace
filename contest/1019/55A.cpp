#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        int cb = 0;
        for (int i = 0;i < 20;i++)
        if (((n>>i)&1) == 1)
            cb++;
        if (cb == 1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
