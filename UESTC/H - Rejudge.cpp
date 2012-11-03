#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
using namespace std;

int name[1005];
int ans[1005];
int x[1005];
map<string,int> m;
map<string,int>::iterator it;
string tname,tans;
int totm;
int use[1005];

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        totm = 0;
        m.clear();
        for (int i = 0;i < n;i++)
        {
            cin >> tname >> tans;
            it = m.find(tname);
            if (it == m.end())
            {
                totm++;
                m[tname] = totm;
            }
            name[i] = m[tname];
            if (tans == "AC")   ans[i] = 1;
            if (tans == "CE")   ans[i] = 2;
            if (tans == "WA")   ans[i] = 3;
            if (tans == "TL")   ans[i] = 4;
            if (tans == "ML")   ans[i] = 5;
            if (tans != "AC" && tans != "CE")
                scanf("%d",&x[i]);
        }
        int ma,mb;
        ma = mb = 0;
        memset(use,0,sizeof(use));
        for (int i = 0;i < n;i++)
        {
            if (ans[i] == 2)    continue;
            if (ans[i] == 1)
            {
                if (use[name[i]] == 0)  use[name[i]] = 1;
                continue;
            }
            if (x[i] == 6)
            if (use[name[i]] == 0)  use[name[i]] = 1;
            if (x[i] == 7)
                use[name[i]] = 2;
        }
        for (int i = 1;i <= totm;i++)
        {
            if (use[i] >= 2)    ma++;
            if (use[i] >= 1)    mb++;
        }
        printf("%d %d\n",ma,mb);
    }
    return 0;
}
