#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	printf("%d\n",1);
	int l,r;
	l = rand()%10000+10000000;
	r = rand()%(305*365)+60*365+l;
	printf("%d %d\n",l,r);
	return 0;
}
