#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    //freopen("XX.txt","w",stdout);
    srand(100);
    for (int i = 1;i <= 5;i++)
    {
        cout << 10 << endl;
        for (int j = 1;j <= 10;j++)
            cout << (rand()%10)+1 << ' ' << (rand()%10)+1 << endl;
    }
}
