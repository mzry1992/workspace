#include<iostream>
using namespace std;
__int64 X,Y;
__int64 x,y,m,n,L;
__int64 A,B,D;

__int64 gcd(__int64 a, __int64 b)
{
        __int64 temp,tempx,tempy;
        if(b == 0)
        {
             X = 1; Y = 0;
             return a;
        }
        temp = gcd(b, a % b);
        tempx = X; tempy = Y;
        X = tempy; Y = tempx - (a / b) * tempy;
        return temp;
}

int main()
{
    scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&L);
    if(n > m)
    {
         A = n - m;
         B = x - y;
    }
    else
    {
        A = m -n;
        B = y -x;
    }
    D = gcd(L,A);
    if(B % D != 0) {printf("Impossible\n"); return 0;}
    L = L / D;
    Y = (Y * (B / D))% L;
    if(Y < 0) Y += L;
    printf("%I64d\n",Y);
    return 0;
}
