#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    for (int ft = 1;ft <= 10;ft++)
    {
        for (int i = 0;i < 100000;i++)
            putchar(rand()%26+'a');
        printf(" %d\n",ft);
    }
    return 0;
}
