#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> a;
char buf[20];

int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    int n;
    while (scanf("%d",&n) != EOF)
    {
        a.clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            int tmp;
            if (strcmp(buf,"add") == 0)
            {
                scanf("%d",&tmp);
                a.insert(tmp);
            }
            else if (strcmp(buf,"del") == 0)
            {
                scanf("%d",&tmp);
                a.erase(tmp);
            }
            else
            {
                int sum = 0,id = 0;
                for (set<int>::iterator it = a.begin();it != a.end();it++,id++)
                    if (id%5 == 2)
                        sum += *it;
                printf("%d\n",sum);
            }
        }

        puts("");
    }
	return 0;
}
