#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	freopen("C-test.in","w",stdout);
	cout << 10 << endl;
	for (int i = 0;i < 10;i++)
	{
	    cout << 500 << ' ';
	    for (int j = 0;j < 500;j++)
            cout << (long long)rand()*rand() << ' ';
        cout << endl;
	}
	return 0;
}
