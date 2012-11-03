#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(A,B) ((A<B?A:B))
using namespace std;

int sg[500][500][500];

int DFS(int a,int b,int c)
{
    if (sg[a][b][c] != 0)   return sg[a][b][c];
    bool tsg = false;
    for (int i = 0;i < a;i++)
    if (DFS(i,b,c) == 2)    tsg = true;
    for (int j = 0;j < b;j++)
    if (DFS(a,j,c) == 2)    tsg = true;
    for (int k = 0;k < c;k++)
    if (DFS(a,b,k) == 2)    tsg = true;
    for (int i = 1;i <= MIN(a,b);i++)
    if (DFS(a-i,b-i,c) == 2)    tsg = true;
    for (int i = 1;i <= MIN(a,c);i++)
    if (DFS(a-i,b,c-i) == 2)    tsg = true;
    for (int i = 1;i <= MIN(b,c);i++)
    if (DFS(a,b-i,c-i) == 2)    tsg = true;
    if (tsg == true)
        return 1;
    else
        return 2;
}

int main()
{
    memset(sg,0,sizeof(sg));
    sg[0][0][0] = 2;
    for (int i = 0;i < 300;i++)
    for (int j = 0;j < 300;j++)
    for (int k = 0;k < 300;k++)
    {
        sg[i][j][k] = DFS(i,j,k);
        //if (sg[i][j][k] == 2)
        //    cout << i << ' ' << j << ' ' << k << ' ' << sg[i][j][k] << endl;
    }
}
