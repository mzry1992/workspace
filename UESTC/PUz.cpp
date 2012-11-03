#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a,b,v;
    while (scanf("%d%d%d",&a,&b,&v) != EOF)
    {
        printf("%d\n",(v-a)/(a-b)+1+(((v-a)%(a-b) == 0)?0:1));
    }
}
