#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    int ans;
    while (true)
    {
        scanf("%d%d",&a,&b);
        if ((a == 0) && (b == 0))
            break;
        while (a%3 != 0)
            a++;
        while (b%3 != 0)
            b--;
        ans = 0;
        if (a <= b)
            ans = (b-a)/3+1;
        printf("%d\n",ans);
    }
}
