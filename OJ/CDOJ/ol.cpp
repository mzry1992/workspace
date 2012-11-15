#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int prime[10000 ],tot;
bool isprime[1000000];

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 100000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 100000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

int ol(int n)
{
	int res = n;
	for (int i = 1;i <= tot;i++)
		if (n%prime[i] == 0)
		{
			while (n%prime[i] == 0)
				n /= prime[i];
			res = (res/prime[i])*(prime[i]-1);
		}
	if (n != 1)
		res = (res/n)*(n-1);
	return res;
}

int main()
{
    getprime();
	int t;
	while (scanf("%d",&t) != EOF)
		cout << ol(t) << endl;
    //system("pause");
}

