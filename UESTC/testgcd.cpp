#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b) != EOF)
    {
        printf("%d\n",__gcd(a,b));
    }
}
