#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long m1,m2,s1,s2;

long long g(long long x)
{
    return x^(x/2);
}

long long h1(long long x)
{
    return x / m1 * m1 + ( x + s1) % m1;
}

long long h2(long long x)
{
    return x / m2 * m2 + ( x + s2) % m2;
}

long long f(long long x)
{
    return g( h2( g( h1( g( x ) ) ) ) );
}

int main()
{
    /*cout << g(3) << endl;
    for (int i = 0;i < 10000;i++)
        if (g(i) == 7908)
            cout << i << endl;
    for (int i = 0;i < 10000;i++)
        if (g(i) == 7841)
            cout << i << endl;
    for (int i = 0;i < 10000;i++)
        if (g(i+2)-g(i) == 7908)
            cout << i << endl;*/
    FILE *fin,*fout;
    long long a,b;
    fin = fopen("G.in","r");
    fout = fopen("G.out","r");
    while (fscanf(fin,"%lld",&a) != EOF)
    {
        fscanf(fout,"%lld",&b);
        if (a < 100)
        {
            printf("%lld %lld\n",a,b);
            printf("fuck %lld ",g(a));
            for (int i = 0;i < 10000;i++)
                if (g(i) == b)
                    printf("%lld\n",i);
        }
    }
	return 0;
}
