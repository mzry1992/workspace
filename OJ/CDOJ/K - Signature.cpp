#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int sum[1234567];
char tmp[20];

int check(int now)
{
    sprintf(tmp,"%d",now);
    int len = strlen(tmp),res = 0;
    for (int i = 1;i < len-1;i++)
        if (tmp[i] > tmp[i-1] && tmp[i] > tmp[i+1])
            res++;
    return res;
}

void init()
{
    for (int i = 0;i <= 119;i++)
        sum[i] = 0;
    for (int i = 120;i <= 123456;i++)
    {
        sum[i] = sum[i-1]+check(i);
    }
}

int Gao(int x,int y)
{
    if (x < 0)  x = 0;
    else
        x--;
    return sum[y]-sum[x];
}

int main()
{
    init();
    for (int i = 120;i <= 1000;i++)
        if (sum[i] != sum[i-1])
            cout << i << " = " << sum[i]-sum[i-1] << endl;
}
