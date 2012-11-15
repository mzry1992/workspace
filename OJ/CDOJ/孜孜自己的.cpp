#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("zizinihao.txt","w",stdout);
    //cout << 100 << endl;
    for (int i = 1;i <= 1005;i++)
    {
        //cout << "80 10000 1 2"<< endl;
        printf("%d %d\n",10000,rand()%100000+1);
        for (int j = 1;j <= 10000;j++)
        {
            printf("%d ",rand()%10000+1);
        }
        puts("");
    }
}
