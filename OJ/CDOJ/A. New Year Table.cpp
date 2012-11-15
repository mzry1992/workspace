#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
int n,R,r;

bool Gao()
{
    if (r > R)  return false;
    if (n == 1) return true;
    if (r*2 > R)    return false;
    if (r*2 == R)   return n == 2;
    double theta = pi/n;
    double maxr = (double)R/(1.0+1.0/sin(theta));
    return r <= maxr+1e-12;
}

int main()
{
    while (scanf("%d%d%d",&n,&R,&r) != EOF)
        printf("%s\n",Gao()?"YES":"NO");
    return 0;
}
