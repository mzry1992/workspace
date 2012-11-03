#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int euler[3000001];

void init()
{
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for (int i = 2;i <= 3000000;i++)
    {
        if (!euler[i])
        {
            for (int j = i;j <= 3000000;j += i)
            {
                if (!euler[j])
                    euler[j] = j;
                euler[j] = euler[j]/i*(i-1);
            }
        }
    }
}

int a,b;
long long res;

int main()
{
    init();
    while (scanf("%d%d",&a,&b) != EOF)
    {
        res = 0;
        for (int i = a;i <= b;i++)  res = res+(long long)euler[i];
        cout << res << endl;
    }
}
