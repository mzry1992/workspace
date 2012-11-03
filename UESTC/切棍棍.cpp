#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        bool flag = false;
        for (int i = k;i*i <= m;i++)
            if (m%i == 0)
            {
                flag = true;
                break;
            }
        if (flag == false)
            puts("E");
        else
        {
            if (n%2 == 0)
                puts("E");
            else
                puts("A");
        }
    }
    return 0;
}
