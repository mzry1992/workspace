#include <iostream>
using namespace std;

char map[50][50];
int i,j;

int main()
{
    for (i = 1;i <= 50;i++)
    for (j = 1;j <= 50;j++)
        map[i][j] = 'A';
    map[1][1] = '$';
    map[50][50] = '!';
    for (i = 1;i <= 50;i++)
    {
        for (j = 1;j <= 50;j++)
            cout << map[i][j];
        cout << endl;
    }
    system("pause");
}
