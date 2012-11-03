#include <iostream>
#include <cstdio>
using namespace std;

long long n;
unsigned long long a[100],s[100];

int main()
{
    a[0] = 1;
    s[0] = 0;
    for (int i = 1;i <= 63;i++)
    {
        a[i] = a[i-1]*2;
        s[i] = s[i-1]+a[i]-1;
    }
    bool flag = true;
    while (cin >> n)
    {
        if (!flag)
            puts("");
        flag = false;
        for (int i = 1;i <= 62;i++)
        if ((s[i] <= n) && (n < s[i+1]))
        {
            cout << i << endl;
            cout << n-s[i-1];
            for (int j = i-1;j >= 1;j--)
                cout << ' ' << a[j]-1;
            puts("");
            break;
        }
    }
}
