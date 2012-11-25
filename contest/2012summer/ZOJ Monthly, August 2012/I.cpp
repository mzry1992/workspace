#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;

map<string,int> namelist;
int cnt;
int n,f[100000];
set<int> num[100000];

char com[20],name[20];

int getid(char s[])
{
    if (namelist.find(s) == namelist.end())
    {
        f[cnt] = cnt;
        num[cnt].clear();
        namelist[s] = cnt++;
    }
    return namelist[s];
}

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        namelist.clear();
        cnt = 0;

        for (int i = 0;i < n;i++)
        {
            scanf("%s%s",com,name);
            int ida = findf(getid(name)),idb;

            if (strcmp(com,"arrive") == 0)
            {
                int m;
                scanf("%d",&m);
                for (int i = 0;i < m;i++)
                {
                    int v;
                    scanf("%d",&v);
                    num[ida].insert(v);
                }
            }
            else if (strcmp(com,"share") == 0)
            {
                scanf("%s",name);
                idb = findf(getid(name));
                if (ida != idb)
                {
                    if (num[ida].size() > num[idb].size())
                        swap(ida,idb);
                    for (set<int>::iterator it = num[ida].begin();it != num[ida].end();it++)
                        num[idb].insert(*it);
                    num[ida].clear();
                    f[ida] = idb;
                }
            }
            else
                printf("%d\n",num[ida].size());
        }
    }
	return 0;
}
