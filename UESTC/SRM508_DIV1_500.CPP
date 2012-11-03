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
#include <cstring>
using namespace std;

class YetAnotherORProblem {
public:
	int countSequences(vector<long long>);
};

const long long mod = 1000000009LL;

int one[70];

int YetAnotherORProblem::countSequences(vector<long long> R) {
    int n = R.size();
    memset(one,0,sizeof(one));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < 64;j++)
            if (((R[i]>>j)&1) == 1) one[j]++;
    for (int i = 0;i < 64;i++)  cout << one[i] << ' ';
    cout << endl;
}

//Powered by [KawigiEdit] 2.0!

