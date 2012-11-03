#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	freopen("data.in","w",stdout);
	srand(time(0));
	printf("200000\n");
	for (int i = 1;i <= 200000;i++)
        printf("%d %d\n",rand()%i,rand());
	return 0;
}
