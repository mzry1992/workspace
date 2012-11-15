#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int *a = (int*)malloc(40);
	printf("%d\n",sizeof(a)/sizeof(a[0]));
    return 0;
}
