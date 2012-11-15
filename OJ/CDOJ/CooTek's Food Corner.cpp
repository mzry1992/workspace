#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char com[5];
int l,r,tree[1000500];

int read(int k)
{
    int sum = 0;
    for (;k;k ^= k&-k)
        sum += tree[k];
    return sum;
}

void updata(int k,int v)
{
    for (;k < 1000500;k += k&-k)
        tree[k] += v;
}

int main()
{
    while (scanf("%s%d%d",com,&l,&r) != EOF)
    {
        if (com[0] == 'q')
            printf("%d\n",read(r)-read(l-1));
        else
        {
            if (com[0] == 'c')    r = -r;
            updata(l,r);
        }
    }
    return 0;
}
