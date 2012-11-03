#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct tree
{
    int next[2];
}buf[80000];
int totbuf,tot[100000],tot2;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        totbuf = 0;
        buf[0].next[0] = buf[0].next[1] = -1;
        int cur = 0;
        for (int i = 31;i >= 0;i--)
        {

        }
    }
    return 0;
}
