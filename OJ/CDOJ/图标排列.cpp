#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[100001],now;
long long res;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        res = 0;
        now = n-1;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d",&a[i]);
            if (a[i] >= 2)
            {
                res += (long long)now;
                now -= 2;
            }
        }
        cout << res << endl;
    }
}
