#include <iostream>
#include <cassert>

using namespace std;

int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	
//	int start = clock();
	
	int T;	cin >> T;
	assert(T >= 1 && T <= 100);
	for(int cas = 1; cas <= T; ++ cas)
	{
		int n, m;
		cin >> n >> m;
		assert(n >= 1 && n <= 1000000);
		assert(m >= 1 && m <= 100);
		int dmin = 1000000 + 10, d;
		for(int i = 0; i < m; ++ i)
		{
			cin >> d;
			assert(d >= 1 && d <= 1000000);
			dmin = min(d, dmin);	
		}
		cout << "Case #" << cas << ": " << (n / dmin % 2 ? "Bob" : "Alice") << endl;
	}
	
//	cout << clock() - start << endl;	
}
