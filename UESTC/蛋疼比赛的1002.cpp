#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
const string xl[7] = {"","10","1","200","20","2","6"};
const int    yl[7] = {0 , 8  , 2 , 17 , 11 , 5 , 6 };
//                    7    8    2   3   4    5   6
int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        int temp = n;
        if (n == 3)
            cout << "7 7" << endl;
        else if (n == 4)
            cout << "4 11" << endl;
        else if (n == 10)
            cout << "22 11111" << endl;
        else
        {
            cout << xl[n%7];
            n -= yl[n%7];
            for (int i = 1;i <= n/7;i++)
                cout << "8";
            cout << " ";
            if (temp%2 == 0)
            {
                for (int i = 1;i <= temp/2;i++)
                    cout << "1";
                cout << endl;
            }
            else
            {
                cout << "7";
                for (int i = 1;i <= (temp-3)/2;i++)
                    cout << "1";
                cout << endl;
            }
        }
    }
}
