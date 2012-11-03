#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[10000],b;
int tot;

void gene(int now,long long sum,int ta,int tb)
{
    if (now > 10)    return;
    if (ta == tb)
    {
        a[tot] = sum;
        tot++;
    }
    gene(now+1,sum*10+4,ta+1,tb);
    gene(now+1,sum*10+7,ta,tb+1);
}

int main()
{
    tot = 0;
    gene(1,4,1,0);
    gene(1,7,0,1);
    sort(a,a+tot);
    cin >> b;
    for (int i = 0;i < tot;i++)
        if (a[i] >= b)
        {
            cout << a[i] << endl;
            break;
        }
}
