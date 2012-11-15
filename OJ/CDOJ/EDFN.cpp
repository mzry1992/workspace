#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("5.txt","r",stdin);
    freopen("55.txt","w",stdout);
    long long a,b,c;
    long long d,e,f;
    a = 2;
    b = 3;
    c = 1;
    int ft = 3;
    printf("if (i==%d) printf(\"",ft);
    bool isfirst = true;
    while (scanf("%lld%lld",&d,&e) != EOF)
    {
        //cout << a << ' ' << b << ' ' << c <<' ' << d << ' ' << e << endl;
        f = 1;
        for (int i = 1;i <= e;i++)
        {
            if (isfirst == false)   printf(" ");
            isfirst = false;
            printf("%lld",d);
            f *= d;
        }
        c *= f;
        if (c == a+b)
        {
            ft++;
            printf("\\n\");\n");
            printf("if (i==%d) printf(\"",ft);
            isfirst = true;
            a = b;
            b = c;
            c = 1;
        }
    }
}
