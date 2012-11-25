#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	printf("1\n");

	int n = 5,R = rand()%10+5;
	printf("%d %d\n",n,R);
	for (int i = 0;i < n;i++)
		printf("%d %d\n",rand()%10,rand()%10);

	return 0;
}
