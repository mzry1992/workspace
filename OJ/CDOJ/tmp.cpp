#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    string res = "Hello, World";
    for (int i = res.length()-1;i >= 0;i--)
        printf("%d ",res[i]);
    printf("\n");
    //72 101 108 108 111 44 32 87 111 114 108 100
    return 0;
}
