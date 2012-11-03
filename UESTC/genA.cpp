#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char nam[5000][20];

int main()
{
    for (int i = 0;i < 5000;i++)
    {
        int ti = i;
        for (int j = 0;j < 15;j++)
        {
            nam[i][j] = 'a'+ ti%26;
            ti /= 26;
        }
        nam[i][15] = 0;
    }
    freopen("a.txt","w",stdout);
    for (int T = 1;T <= 1;T++)
    {
        cout << 100 << endl;
        int now = 100;
        for (int i = 0;i < 100;i++)
        {
            cout << nam[i] << ":" << nam[i+1];
            for (int j = 1;j < 10;j++)
            {
                cout << ",";
                now++;
                cout << nam[now];
            }
            cout << "." << endl;;
        }
    }
    cout << 0 << endl;
}
