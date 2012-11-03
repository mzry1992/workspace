#include <iostream>
using namespace std;

int tcase,fcase,x,y,b,temp,flag;
bool han[9][9],lie[9][9],kuai[9][9];

int getb(int x,int y)
{
    int tx,ty,ans;
    if ((x >= 1) && (x <= 3)) tx = 1;
    if ((x >= 4) && (x <= 6)) tx = 2;
    if ((x >= 7) && (x <= 9)) tx = 3;
    if ((y >= 1) && (y <= 3)) ty = 1;
    if ((y >= 4) && (y <= 6)) ty = 2;
    if ((y >= 7) && (y <= 9)) ty = 3;
    ans = (tx-1)*3+ty;
    return ans;
}

int main()
{
    cin >> tcase;
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        for (x = 1;x <= 9;x++)
        for (y = 1;y <= 9;y++)
        {
            han[x][y] = true;
            lie[x][y] = true;
            kuai[x][y] = true;
        }
        for (x = 1;x <= 9;x++)
        for (y = 1;y <= 9;y++)
        {
            cin >> temp;
            if (han[x][temp] == true)
                             han[x][temp] = false;
            if (lie[y][temp] == true)
                             lie[y][temp] = false;
            b = getb(x,y);
            if (kuai[b][temp] == true)
                              kuai[b][temp] = false;
        }         
        flag = 0;
        for (x = 1;x <= 9;x++)
        for (y = 1;y <= 9;y++)
        {
            if (han[x][y] == true) flag = 1;
            if (lie[x][y] == true) flag = 1;
            if (kuai[x][y] == true) flag = 1;
        }
        cout << "Case " << fcase << ":" << endl;
        if (flag == 0)
           cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    //system("pause");
    return 0;
}
