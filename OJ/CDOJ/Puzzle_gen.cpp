#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("Puzzle.in","w",stdout);
    cout << 30 << endl;
    for (int ft = 0;ft < 30;ft++)
    {
        int w,b,g;
        w = b = g = 0;
        for (int i = 0;i < 4;i++)
        {
            for (int j = 0;j < 6;j++)
            {
                while (true)
                {
                    int rn = rand()%3;
                    if (rn == 0)
                    {
                        if (w < 8)
                        {
                            printf("W");
                            w++;
                            break;
                        }
                    }
                    else if (rn == 1)
                    {
                        if (b < 8)
                        {
                            printf("B");
                            b++;
                            break;
                        }
                    }
                    else
                    {
                        if (g < 8)
                        {
                            printf("G");
                            g++;
                            break;
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
