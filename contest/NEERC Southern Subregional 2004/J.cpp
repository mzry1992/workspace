#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[100];

int main()
{
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> a[i];

    int r = 0;
    for (int i = 63;i >= 0;i--)
    {
        for (int j = r;j < n;j++)
            if (((a[j]>>i)&1) == 1)
            {
                swap(a[r],a[j]);
                break;
            }
        if (((a[r]>>i)&1) == 0) continue;
        for (int j = 0;j < n;j++)
            if (j != r)
                if (((a[j]>>i)&1) == 1)
                    a[j] ^= a[r];
        r++;
    }

    long long ans = 0;
    for (int i = 0;i < n;i++)
        ans = ans^a[i];
    cout << ans << endl;

    return 0;
}

