#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int n;
struct rank
{
    string nam;
    int tot;
    int pen;
}r[120];

bool cmp(rank a,rank b)
{
    if (a.tot == b.tot)
    {
        if (a.pen == b.pen)
            return a.nam < b.nam;
        return a.pen < b.pen;
    }
    return a.tot > b.tot;
}

int main()
{
    int t;
    cin >> t;
    for (int ft = 1;ft <= t;ft++)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> r[i].nam >> r[i].tot >> r[i].pen;
        sort(r+1,r+1+n,cmp);
        printf("%s\n",r[1].nam.c_str());
    }
}
