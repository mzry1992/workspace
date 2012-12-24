#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000;

int main()
{
	freopen("data.in", "w", stdout);
	
	srand(20120813);
	
	int T = 99;	
	cout << T << endl;
	
	T -= 8;
	puts("1 1\n2");
	puts("2 1\n2");
	puts("3 1\n2");
	puts("4 1\n2");
	puts("5 1\n2");
	puts("1 1\n1");
	puts("2 1\n1");
	puts("3 1\n1");
	
	-- T;
	puts("999999 100");
	cout << "3";
	for(int i = 1; i <= 99; ++ i)	cout << " " << rand() % 100 + 10;
	puts("");
	
	--T;
	puts("999998 100");
	cout << "3";
	for(int i = 1; i <= 99; ++ i)	cout << " " << rand() % 100 + 10;
	puts("");
	
	while(T --)
	{
		int n = rand() % mod + 1;
		int m = rand() % 100 + 1;
		if(T < 20)	n = mod - rand() % 10, m = 100;
		cout << n << " " << m << endl;
		while(-- m)
		{
			if(n > 5)	cout <<	rand() % mod + 1 << " ";
			else	cout <<	rand() % 200 + 1 << " ";
		}	
		cout << rand() % mod + 1 << endl;
	}
	
	return 0;	
}
