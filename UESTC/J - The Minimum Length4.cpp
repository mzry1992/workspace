#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxL = 1001000;
struct KMP
{
    int next[MaxL],l;
    char W[MaxL];
    void initKMP()
    {
        l = strlen(W);
        int j = -1;
        next[0] = -1;
        for (int i = 1;i < l;i++)
        {
            while (j > -1 && W[i] != W[j+1])    j = next[j];
            if (W[i] == W[j+1]) j++;
            next[i] =j;
        }
    }
}g;

int main()
{
    while (scanf("%s",g.W) != EOF)
    {
        g.initKMP();
        printf("%d\n",g.l-1-g.next[g.l-1]);
    }
}

