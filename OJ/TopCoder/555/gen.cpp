#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int curpos = 5;
    for (int i = 0;i < 15;i++)
    {
        printf("\"");
        for (int j = 0;j < 37;j++)
        {
            if (rand()%2)
            {
                printf("%d",rand()%2);
            }
            else
            {
                if (curpos == 0)    printf(">"),curpos++;
                else if (curpos == 10)  printf("<"),curpos--;
                else if (rand()%2)
                    printf("<"),curpos--;
                else
                    printf(">"),curpos++;
            }
        }
        printf("\",\n");
    }
	return 0;
}
