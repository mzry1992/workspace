#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("DPC.txt","w",stdout);
    printf("%d %d %d\n",100,100,50);
    for (int i = 1;i <= 99;i++)
        printf("%d %d\n",i,i+1);
    printf("%d %d\n",100,1);
    printf("%d %d %d\n",100,20000,70);
    for (int i = 1;i <= 20000;i++)
        printf("%d %d\n",rand()%100+1,rand()%100+1);
}
