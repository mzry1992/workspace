#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 200000000;
int N;
bool isPrime[MaxN+1];
int prime[100000000];
//int be[200000000];

void getPrime(int n)
{
    N=0;
    isPrime[0]=isPrime[1]=1;
    for (int i=2; i<n; ++i)
    {
        if (!isPrime[i])
        {
            prime[N++]=i;
        	//be[i]=++N;
		}
        for (int j=0; j<N && prime[j]<n/i+1; ++j)
        {
 	       int k=i*prime[j];
            isPrime[k]=1;
          //  be[k]=j+1;
          if (i%prime[j] == 0)
            break;
        }
    }
}

int main()
{
    getPrime(MaxN);
    printf("%d\n",N);
    return 0;
}
