#include <iostream>
#include <cstdio>
using namespace std;

int n,s;

int main()
{
    while (scanf("%d%d",&n,&s) != EOF)
    {
        printf("%d\n",s/(n+1));
    }
}
