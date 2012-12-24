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

using namespace std;

class PastingPaintingDivOne
{
public:
    vector<long long> countColors(vector <string>, int);
};

char board[1000][1000];
int getid(char ch)
{
    if (ch == 'R')  return 0;
    if (ch == 'G')  return 1;
    if (ch == 'B')  return 2;
    return 3;
}

vector<long long> PastingPaintingDivOne::countColors(vector <string> clip, int T)
{
    int n = clip.size();
    int m = clip[0].size();

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            board[i][j] = '.';
    for (int i = 0; i+n <= 1000 && i+m <= 1000; i++)
    {
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (clip[x][y] != '.')
                    board[i+x][i+y] = clip[x][y];
        T--;
        if (T == 0) break;
    }
    vector<long long> ans;
    ans.resize(4);
    ans[0] = ans[1] = ans[2] = ans[3] = 0;
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            ans[getid(board[i][j])]++;
    for (int i = 0; i < 1000; i++)
        ans[getid(board[500][i])] += T;
    ans.pop_back();
    return ans;
}

int main()
{
    return 0;
}

//Powered by [KawigiEdit] 2.0!
