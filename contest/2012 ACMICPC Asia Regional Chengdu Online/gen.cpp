#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> a;

int main()
{
    freopen("data.in","w",stdout);
    for (int cas = 0;cas < 100;cas++)
    {
        int n = 20000;
        printf("%d\n",n);
        a.clear();
        for (int i = 0;i < n;i++)
        {
            int typ;
            if (a.size() == 0)
            {
                typ = rand()%2;
                if (typ == 1)   typ++;
            }
            else
                typ = rand()%3;

            if (typ == 0)
            {
                int val = rand()%1000000000+1;
                while (a.find(val)!=a.end())
                    val=rand()%1000000000+1;
                printf("add %d\n",val);
                a.insert(val);
            }
            else if (typ == 1)
            {
                int val = rand()%a.size();
                for (set<int>::iterator it = a.begin();it != a.end();it++,val--)
                    if (val == 0)
                    {
                        printf("del %d\n",*it);
                        a.erase(*it);
                        break;
                    }
            }
            else
                printf("sum\n");
        }

        puts("");
    }
	return 0;
}
