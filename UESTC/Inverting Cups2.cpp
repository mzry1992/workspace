#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool flag;

unsigned long long Ji(unsigned long long n,unsigned long long m)
{
    if (n%2 == 1 && m%2 == 0)
    {
        flag = true;
        return 0;
    }
    if (m == 1) return n;
    if (n == m*2)   return 2;
    if (m%2 == 0)
    {
        unsigned long long k = m/2;
        unsigned long long j = n/2-k+1;
        if (j == 1) return 1;
        if (j <= k) return 3;
        if (j == k+1)   return 2;
        j -= (k+1);
        return (3+(j-1)/k);
    }
    else
    {
        unsigned long long k = (m+1)/2;
        unsigned long long j = n-m+1;
        if (j == 1) return 1;
        if (j == 2) return m+1;
        if (n%2 == 1)
        {
            j = n-(m+2);
            j /= 2;
            return 3+2*(j/m);
        }
        else
        {
            if (n > m*2)
            {
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            else
            {
                m = n-m;
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            return 0;
        }
    }
}

int main()
{
    unsigned long long a,b;
    while (scanf("%I64u%I64u",&a,&b) != EOF)
    {
        flag = false;
        Ji(a,b);
        if (flag == true)  printf("No Solution!\n");
        else printf("%I64u\n",Ji(a,b));
    }
}
