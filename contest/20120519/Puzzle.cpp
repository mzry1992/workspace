#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char mp[60][60];

bool Gaoa(char col)
{
    for (int x = 0; x < n-1; x++)
        for (int y = 0; y < 2*x+1; y += 2)
            if (mp[x][y] != col && mp[x+1][y+1] == col)
                return false;
    for (int x = 0; x < n; x++)
        for (int y = 1; y < 2*x+1; y += 2)
            if (y+1 < 2*x+1 && mp[x][y] != col && mp[x][y+1] == col)
                return false;
    //cout << "A " << col << endl;
    return true;
}

bool Gaob(char col)
{
    for (int x = 0; x < n-1; x++)
        for (int y = 0; y < 2*x+1; y += 2)
            if (mp[x][y] != col && mp[x+1][y+1] == col)
                return false;
    for (int x = 0; x < n; x++)
        for (int y = 1; y < 2*x+1; y += 2)
            if (mp[x][y] != col && mp[x][y-1] == col)
                return false;
    //cout << "B " << col << endl;
    return true;
}

bool Gaoc(char col)
{
    for (int x = 0; x < n; x++)
        for (int y = 1; y < 2*x+1; y += 2)
            if (y+1 < 2*x+1 && mp[x][y] == col && mp[x][y+1] != col)
                return false;
    for (int x = 0; x < n; x++)
        for (int y = 1; y < 2*x+1; y += 2)
            if (mp[x][y] != col && mp[x][y-1] == col)
                return false;
    //cout << "C " << col << endl;
    return true;
}

int main()
{
    int cas = 0;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        bool res = Gaoa('0') | Gaoa('1') | Gaob('0') | Gaob('1') | Gaoc('0') | Gaoc('1');
        printf("Puzzle %d\n",++cas);
        if (res)
            printf("Parts can be separated\n");
        else
            printf("Parts cannot be separated\n");
    }
    return 0;
}
