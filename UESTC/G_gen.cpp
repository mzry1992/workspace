#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool isPrime[100000];
int prime[100000];
int L;
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i=2; i<100000; i++)
        if (isPrime[i])
        {
            for (int j=i+i; j<100000; j+=i)
                isPrime[j]=0;
            prime[L++]=i;
        }
}

int main()
{
    freopen("G.in","w",stdout);
    cout << 1000 << endl;
    getPrime();
    for (int ft = 1;ft <= 1000;ft++)
    {
        cout << (rand()*rand())%1000000000+1 << ' ' << (rand()*rand())%1000000000+1 << ' ' << prime[rand()%9500] << endl;
    }
}
