#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;

char key;

int main()
{
    while (true)
    {
        printf("XXXXXXXXXXXXXXXXXXXXX\n");
        key = getch();
        if (key == '0') break;
        else
        if (key == '1') system("cls");
        else    continue;
    }
}
