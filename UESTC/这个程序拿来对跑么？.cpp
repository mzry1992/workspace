#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("IDA�ܲ��ܹ���һ���أ����Ǹ��ܸ��ӵ�����~.txt","w",stdout);
    for (int i = 1;i <= 10;i++)
    {
        cout << 5 << endl;
        for (int j = 1;j <= 5;j++)
            cout << rand()%12+1 << ' ';
        cout << endl;
        for (int j = 1;j <= 5;j++)
            cout << rand()%12+1 << ' ';
        cout << endl;
    }
    cout << 0 << endl;
}
