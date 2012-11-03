#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    cout << 15 << endl;
    for (int i = 0;i < 15;i++)
    {
         cout << 800 << endl;
         int ts = 0;
         for (int j = 0;j < 800;j++)
         {
             ts += (rand())%20+1;
             printf("%d ",ts);
         }
         printf("\n");
    }
}
