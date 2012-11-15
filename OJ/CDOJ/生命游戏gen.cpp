#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

void output(int now)
{
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < 4;j++)
            printf("%d ",(((now>>(i*4+j))&1) == 1)?1:0);
        printf("\n");
    }
}

int main()
{
    freopen("Game of Life.in","w",stdout);
    cout << 20 << endl;
    for (int i = 0;i < 20;i++)
    {
        cout << "10 20 10 20" << endl;
        for (int j = 0;j < 10;j++)
        {
            int now = rand()%65536;
            output(now);
        }
    }
}
