#include <iostream>
#include <cmath>
using namespace std;

int* prime = new int[78600];
bool* record = new bool[1000100];
bool isPrime(int n)
{
	if(n < 2)return false;
	if(n == 2) return true;
	else if(n %2 == 0) return false;
	int k = (int)sqrt((double)n);
	int i,j;
	for(i = 3; i<= k; i+=2)
	{
		if(n%i == 0)return false;
	}
	return true;
}
int main()
{
	int i,j=0;
	for(i=0;i<1000100;++i)record[i] = true;
	for(i=0;i<=1000100;++i)
	{
		if(isPrime(i))
		{
			record[i] = false;
			prime[j] = i;
			j++;
		}
	}


    for (i = 1;i <= 100;i++)
        cout << prime[i] << ' ' ;

	int N;
	while(1)
	{
		bool haveresult = false;
		cin >> N;
		if(N == 0)
			break;
		for(i = 1; i<= 78600; ++i)
		{
			if(!record[prime[i]] && !record[N-prime[i]])
			{
				printf("%d = %d + %d\n",N,prime[i],N-prime[i]);
				haveresult = true;
				break;
			}
		}
		if(!haveresult)
			cout<< "Goldbach's conjecture is wrong."<<endl;

	}
	return 0;
}

