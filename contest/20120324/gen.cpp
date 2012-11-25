#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

void G()
{
    freopen("G.in","w",stdout);
    printf("100\n");
    for (int i = 0;i < 100;i++)
        printf("%c",'A');
    printf("\n");
    for (int i = 0;i < 100;i++)
        printf("%c",'A');
    printf("\n");
    for (int i = 0;i < 100000;i++)
        printf("%c",'A');
    printf("\n");
    printf("0\n");
}

int main()
{
    G();
	return 0;
}
