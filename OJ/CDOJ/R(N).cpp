#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int n,res,tmp,v;
set<int> p;

int main()
{
    p.clear();
    for (int i = 0;i*i <= 1000000000;i++)
        p.insert(i*i);
    while (scanf("%d",&n) != EOF)
    {
        res = 0;
        for (int i = 0;i*i <= n;i++)
        {
            tmp = n-i*i;
            if (p.find(tmp) != p.end())
                res += ((i == 0)?1:2)*((tmp == 0)?1:2);
        }
        printf("%d\n",res);
    }
}
