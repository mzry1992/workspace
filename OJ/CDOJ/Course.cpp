#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

map<string,int> mp;
int n,so;
string nam;

int main()
{
    int t;
    cin >> t;
    for (int ft = 1;ft <= t;ft++)
    {
        int res = 0;
        cin >> n;
        mp.clear();
        for (int i = 1;i <= n;i++)
        {
            cin >> nam >> so;
            if (mp.find(nam) != mp.end())
            {
                if (mp[nam] < so)
                {
                    res++;
                    mp[nam] = so;
                }
            }
            else
                mp[nam] = so;
        }
        printf("%d\n",res);
    }
}
