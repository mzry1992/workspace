#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int res[43];
double ans[43];

void Gao(int now,int sum)
{
    if (now == 7)
    {
        res[sum]++;
        return;
    }
    for (int i = 1;i <= 6;i++)
        Gao(now+1,sum+i);
}

int main()
{
    for (int i = 1;i <= 42;i++)
        res[i] = 0;
	Gao(0,0);
	int sum = 0;
	for (int i = 1;i <= 42;i++)
        sum += res[i];
    for (int i = 1;i <= 42;i++)
        ans[i] = (double)res[i]/(double)sum;
    int n;
    while (scanf("%d",&n) != EOF)
    {
        double rr = 0;
        if (n >= 1 && n <= 42)  rr = ans[n];
        printf("%.4f\n",rr);
    }
	return 0;
}
