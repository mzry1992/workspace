#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const long long mod = (1LL<<32);

long long hash2(const char *str)
{
    long long res=0;
    for(;*str;++str)
    {
        res*=1000000007;
        res%=mod;
        res+=*str;
        res%=mod;
    }
    return res;
}

unsigned int hash(const char *str)
{
    unsigned int res=0;
    for(;*str;++str)
    {
        res*=1000000007;
        res+=*str;
    }
    return res;
}

char s[10];
unsigned int n;

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%s",s);
        cout << hash(s) << endl;
        cout << hash2(s) << endl;
    }
    return 0;
}
