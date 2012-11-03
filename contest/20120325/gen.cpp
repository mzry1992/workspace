#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int getnum()
{
    return (rand()*rand()%1000000000+1000000000);
}

void C()
{
    freopen("C.in","w",stdout);
    printf("100000\n");
    for (int i = 0;i < 100000;i++)
        printf("%d %d\n",getnum()%1000000000+1,getnum()%1000000000+1);
    printf("50000\n");
    for (int i = 0;i < 50000;i++)
        printf("%d %d\n",getnum()%1000000000+1,getnum()%1000000000+1);
    printf("-1\n");
}

int main()
{
    C();
	return 0;
}
