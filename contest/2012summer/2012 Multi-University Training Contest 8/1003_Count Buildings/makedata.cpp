/*************************************************************************
Author: ziki
Created Time: 2012/8/10 20:34:06
File Name: gen.cpp
Description: 
 ************************************************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
#include <ctime>


using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define zero(a) memset(a, 0, sizeof(a))
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

int main()
{
	freopen("data.in","w",stdout);
	srand((long)time(NULL));
	int T = 100000;
	cout << T << '\n';
	for (int i = 0; i < 2000; ++i)
	{
		int n = rand() % 2000 + 1, a = rand() % n + 1, b = rand() % n + 1;
		cout << n << ' ' << a << ' ' << b << '\n';
	}
	for (int i = 0; i < 88000; ++i) {
		int n = 2000, a = rand() % 10 + 1, b = rand() % 10 + 1;
		cout << n << ' ' << a << ' ' << b << '\n';
	}
	for (int i = 0; i < 9998; ++i) {
		int n = 2000, a = rand() % n + 1, b = rand() % n + 1;
		cout << n << ' ' << a << ' ' << b << '\n';
	}
	cout << "40 12 30\n";
	cout << "2000 1600 1600\n";
	return 0;
}
