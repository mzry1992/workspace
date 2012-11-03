#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int idx[200100],v[200100];
char com[200100];

int main()
{
    freopen("1503.in","w",stdout);
    int n,mi;
    n = 200100;
    mi = 10000;
    for (int i = 0;i < n;i++)
        idx[i] = i;
    random_shuffle(idx,idx+n);
    int cnt = 0;
    for (int i = 0;i < 100000;i++)
    {
        com[cnt] = 'I';
        v[cnt++] = rand()%100000;
    }
    for (int i = 0;i < 100;i++)
    {
        com[cnt] = 'A';
        if (rand()%2 == 1)  com[cnt] = 'S';
        v[cnt++] = rand()%1000;
    }
    for (int i = 0;i < 100000;i++)
    {
        com[cnt] = 'F';
        v[cnt++] = rand()%500+1;
    }
    printf("%d %d\n",n,mi);
    for (int i = 0;i < 200100;i++)
        printf("%c %d\n",com[idx[i]],v[idx[i]]);
	return 0;
}
