#include <iostream>
#define time 9
using namespace std;

long long ans;

int main()
{
    int i;
    ans = 1;
    for (i = 1;i <= time;i++)
        ans *= 2;
    printf("%lld\n",ans);
    return 0;
}
