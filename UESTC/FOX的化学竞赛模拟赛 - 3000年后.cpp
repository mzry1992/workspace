#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int days,n;

bool gao(int now)
{
    if (now%400 == 0)   return true;
    if (now%4 == 0 && now%100 != 0) return true;
    return false;
}

int main()
{
    days = 0;
    for (int i = 1;i <= 3000;i++)
    {
        int tdays = days;
        for (int j = 1;j <= 12;j++)
            if (j != 2)
                days += mon[j];
            else
                days += mon[j]+gao(i);
    }
    while (scanf("%d",&n) != EOF)
        if (n >= days)   printf("False\n");
        else printf("True\n");
}
