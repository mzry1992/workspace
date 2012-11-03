#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int ans;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        ans = 0;
        for (int i = 0;i <= n/3;i++)
            ans += (n-i*3)/2+1;
        printf("%d\n",ans);
    }
}
