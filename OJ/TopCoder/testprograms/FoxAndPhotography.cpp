#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
using namespace std;

class FoxAndPhotography {
public:
	int getMinimumSwaps(vector <int>, vector <int>);
};

int n;

int FoxAndPhotography::getMinimumSwaps(vector <int> a, vector <int> b) {
	n = a.size();
	vector<pair<int,int> > vb;
	pair<int,int> va[50];
	for (int i = 0;i < n;i++)
		vb.push_back(make_pair(b[i],i));
	sort(vb.begin(),vb.end());
	/*for (int i = 0;i < n;i++)
		printf("(%d,%d) ",vb[i].first,vb[i].second);
	printf("\n");*/
	int step0 = 0;
	for (int i = 0;i < n;i++)
		for (int j = i+1;j < n;j++)
			if (vb[i].second > vb[j].second)
				step0++;
	
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (a[i] < vb[0].first)
			va[cnt++] = make_pair(a[i],i);
	int op = cnt;
	for (int i = 0;i < n;i++)
		if (a[i] >= vb[0].first)
			va[cnt++] = make_pair(a[i],i);
	sort(va+op,va+n);
	int step1 = 0;
	for (int i = 0;i < n;i++)
		for (int j = i+1;j < n;j++)
			if (va[i].second > va[j].second)
				step1++;
	for (int i = 0;i < n;i++)
		if (va[i].first >= vb[i].first)	return -1;
	return abs(step1-step0);
}


//Powered by [KawigiEdit] 2.0!
