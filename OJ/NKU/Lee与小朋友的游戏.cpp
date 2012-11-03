#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long f[1000];
int n;

int main()
{
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i = 3;i < 1000;i++)
        f[i] = f[i-1]+f[i-3]+1;
    cout << f[999] << endl;
	return 0;
}
