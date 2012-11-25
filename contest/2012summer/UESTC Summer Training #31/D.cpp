#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char typ;
int l,r;
vector<pair<int,int> > a;

int main()
{
    a.clear();
    while (scanf(" %c%d%d",&typ,&l,&r) != EOF)
    {
        if (typ == '+')
        {
            int cnt = 0;
            for (int i = 0;i < a.size();i++)
                if (a[i].first >= l && a[i].second <= r)
                    cnt++;
            printf("%d\n",cnt);
            a.push_back(make_pair(l,r));
        }
        else
        {
            for (int i = 0;i < a.size();i++)
                if (a[i].first == l && a[i].second == r)
                {
                    for (int j = i;j < a.size();j++)
                        a[j] = a[j+1];
                    a.pop_back();
                    break;
                }
        }
    }
	return 0;
}
