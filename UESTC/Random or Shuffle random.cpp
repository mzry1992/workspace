#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("Random or Shuffle.in","w",stdout);
    for (int i = 1;i <= 20000;i++)
    {
        int j = rand()%20+1;
        cout << j << endl;
        for (int k = 1;k <= j;k++)
        {
            while (true)
            {
                int cc = rand()%26;
                cout << (char)(cc+'a');
                int p = rand()%5;
                if (p > 2)
                {
                    printf("\n");
                    break;
                }

            }
        }
        printf("\n");
    }
}
