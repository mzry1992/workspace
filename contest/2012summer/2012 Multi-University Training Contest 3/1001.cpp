#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long A,B;

bool check()
{
    for (int i = 2; (long long)i*(long long)i <= A; i++)
        if (A%i == 0)
        {
            while (A%i == 0)
                A /= i;
            if (B%i != 0)
                return false;
        }
    if (B%A != 0)   return false;
    return true;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%I64d%I64d",&A,&B);
        printf("Case #%d: ",cas);
        if (check())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
