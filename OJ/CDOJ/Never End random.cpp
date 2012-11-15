#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("Never End.in","w",stdout);
    for (int ft = 1;ft <= 50;ft++)
    {
        cout << 500 << ' ' << 500 << endl;
        int map[600][600];
        for (int i = 0;i < 500;i++)
        for (int j = 0;j < 500;j++)
            map[i][j] = rand()%3 < 1 ? 1 : 0;
        map[rand()%250][rand()%250+250] = 2;
        map[rand()%250+250][rand()%250] = 3;
        for (int i = 0;i < 500;i++)
        {
            for (int j = 0;j < 500;j++)
            if (map[i][j] == 0) cout << ' ';
            else if (map[i][j] == 1) cout << '#';
            else if (map[i][j] == 2) cout << '|';
            else cout << 'E';
            cout << endl;
        }
    }
}
