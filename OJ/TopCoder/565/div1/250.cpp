#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class MonstersValley
{
public:
    long long best[50][101];
    int minimumPrice(vector<long long> dread, vector <int> price)
    {
        int n = dread.size();
        memset(best,-1,sizeof(best));
        best[0][price[0]] = dread[0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= 100; j++)
                if (best[i-1][j] != -1)
                {
                    if (best[i-1][j] >= dread[i])
                        best[i][j] = max(best[i][j],best[i-1][j]);
                    if (j+price[i] <= 100)
                        best[i][j+price[i]] = max(best[i][j+price[i]],best[i-1][j]+dread[i]);
                }
        for (int i = 0;i <= 100;i++)
            if (best[n-1][i] != -1)
                return i;
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
    }
private:
    template <typename T> string print_array(const vector<T> &V)
    {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const int &Expected, const int &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0()
    {
        long Arr0[] = {8, 5, 10};
        vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 1, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        verify_case(0, Arg2, minimumPrice(Arg0, Arg1));
    }
    void test_case_1()
    {
        long Arr0[] = {1, 2, 4, 1000000000};
        vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 1, 1, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 5;
        verify_case(1, Arg2, minimumPrice(Arg0, Arg1));
    }
    void test_case_2()
    {
        long Arr0[] = {200, 107, 105, 206, 307, 400};
        vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 2, 1, 1, 1, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        verify_case(2, Arg2, minimumPrice(Arg0, Arg1));
    }
    void test_case_3()
    {
        long Arr0[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
        vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 5;
        verify_case(3, Arg2, minimumPrice(Arg0, Arg1));
    }

// END CUT HERE

};
//This code is written by kennethsnow.

// BEGIN CUT HERE
int main()
{
    MonstersValley ___test;
    ___test.run_test(-1);
    system("pause");
    return 0;
}
// END CUT HERE
