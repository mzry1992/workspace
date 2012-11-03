#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int n;
string a,b,c,d;
set<string> s;
set<string>::iterator it;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        cin >> a;
        cin >> b;
        cin >> c;
        d = c;
        s.clear();
        int res;
        res = 0;
        bool isres;
        while (true)
        {
            res++;
            for (int i = 0;i < n;i++)
            {
                d[2*i] = b[i];
                d[2*i+1] = a[i];
            }
            it = s.find(d);
            if (it != s.end())
            {
                res = -1;
                break;
            }
            s.insert(d);
            if (c == d)
                break;
            for (int i = 0;i < n;i++)
            {
                a[i] = d[i];
                b[i] = d[n+i];
            }
        }
        printf("%d %d\n",ft,res);
    }
}
