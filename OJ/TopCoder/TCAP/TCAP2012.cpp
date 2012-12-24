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

class TheUniverseUnravels
{
public:
    vector <string> predictCoordinates(vector <string>, vector <string>, vector <int>, vector <int>);
    string ItoStr(int);
    int p[2000][10],n;
    int r[2000][2000];
};

string TheUniverseUnravels::ItoStr(int i)
{
    char buf[20];
    sprintf(buf,"%d",i);
    string s(buf);
    return s;
}

vector <string> TheUniverseUnravels::predictCoordinates(vector <string> coords, vector <string> ranks, vector <int> minDist, vector <int> maxDist)
{
    n = coords.size();
    for (int i = 0; i < n; i++)
    {
        istringstream iss;
        iss.str(coords[i]);
        for (int j = 0; j < 10; j++)
            iss >> p[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        istringstream iss;
        iss.str(ranks[i]);
        for (int j = 0; j < n; j++)
            iss >> r[i][j];
    }

    for (int i = 0;i < n;i++)
        for (int j = 0;j < 10;j++)
            if (p[i][j] == -1)
                p[i][j] = rand()%1001;
    vector<string> res(n);
    for (int i = 0;i < n;i++)
    {
        res[i] = "";
        for (int j = 0;j < 10;j++)
        {
            res[i] += ItoStr(p[i][j]);
            if (j < 9)
                res[i] += " ";
        }
    }
    return res;
}

int main()
{
    TheUniverseUnravels * obj = new TheUniverseUnravels();
    cout << obj->ItoStr(123) << endl;
    return 0;
}
