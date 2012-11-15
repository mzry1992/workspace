#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    freopen("out.txt","r",stdin);
    freopen("out_47.txt","w",stdout);
    int t;
    scanf("%d",&t);
    cout << "1" << endl;
    for (int ft = 1;ft <= t;ft++)
    {
        int n,m;
        scanf("%d%d",&n,&m);

        if (ft == 47)
            cout << 20 << ' ' << 20 << endl;
        int a,b,c;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);

        if (ft == 47)
        if (i <= 20)
            cout << a << ' ' << b << ' ' << c <<endl;
        }
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);

        if (ft == 47)
        if (i <= 20)
            cout << a << ' ' << b << ' ' << c <<endl;
        }
        scanf("%d%d%d",&a,&b,&c);
        if (ft == 47)
            cout << a << ' ' << b << ' ' << c <<endl;
    }
}
