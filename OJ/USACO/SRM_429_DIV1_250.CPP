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

class SubrectanglesOfTable {
public:
	vector<long long> getQuantity(vector <string>);
};

long long calc(int x,int y,int n,int m)
{
    long long res = 0;
    res += ((x+1)*(y+1))*((n-x+1)*(m-y+1));
    return res;
}

vector<long long> SubrectanglesOfTable::getQuantity(vector <string> table) {
    vector<long long> res;
    res.resize(26);
    for (int i = 0;i < 26;i++)
        res[i] = 0;
    int n = table.size();
    int m = table[0].size();
    for (int i = 0;i < n;i++)
    for (int j = 0;j < m;j++)
    {
        long long temp = 0;
        temp += calc(i,j,2*n,2*m);
        temp += calc(i+n,j,2*n,2*m);
        temp += calc(i+n,j+m,2*n,2*m);
        temp += calc(i,j+m,2*n,2*m);
        res[table[i][j]-'A'] += temp;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

