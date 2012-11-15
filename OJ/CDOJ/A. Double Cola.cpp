#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long sum[1000];
char nam[5][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
    sum[0] = 0;
    long long now = 5;
    for (int i = 1;i <= 50;i++)
    {
        sum[i] = sum[i-1]+now;
        now *= 2;
    }
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;;i++)
        if (sum[i] < n && n <= sum[i+1])
        {
            printf("%s\n",nam[(n-sum[i]-1)/(1<<i)]);
            break;
        }
    }
}
