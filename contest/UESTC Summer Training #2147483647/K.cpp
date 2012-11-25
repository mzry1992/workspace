#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r,c;

int main()
{
    while (true)
    {
        scanf("%d%d",&r,&c);
        if (r == 0 && c == 0)   break;
        if ((r*c)%2 == 0)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}

