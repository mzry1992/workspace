#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b;

int main()
{
    scanf("%d%d",&a,&b);
    if (b > a)
    {
        if (b-a < 300)
            puts("1");
        else if (b-a < 900)
            puts("2");
        else if (b-a < 1800)
            puts("3");
        else
            puts("4");
    }
    else
        puts("0");
    return 0;
}

