#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int gcd(int a,int b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

struct fs
{
    int a,b;
    void init(int _a,int _b)
    {
        a = _a;
        b = _b;
    }
    void easy()
    {
        int gcd = gcd(a,b);
        a /= gcd;
        b /= gcd;
    }
    void dec(fs t)
    {
        int _a,_b;
        _b = t.b*b;
        _a = a*t.b-t.a*b;
        a = _a;
        b = _b;
        if (a == 0) b = 1;
        else easy(a,b);
    }
}

int main()
{

}
