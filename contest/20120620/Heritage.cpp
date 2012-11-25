#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long a[20];

int main()
{
    long long mut = 2;
    a[1] = 2;
    for (int i = 2;i <= 18;i++)
    {
        a[i] = mut+1;
        mut *= a[i];
    }
    for (int i = 1;i <= 18;i++)
        printf("%lld ",a[i]);
    printf("\n");
    while (scanf("%d",&n) != EOF)
    {

    }
	return 0;
}
