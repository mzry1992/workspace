#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int m,n,totl,minl;
vector<pair<int,int> > a[1000],res;
pair<int,int> tp,pos[1000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&m,&n);
        for (int i = 0;i < n;i++)
        {
            a[i].clear();
            if (i > 0)
                a[i].push_back(make_pair(i,0));
            totl = 0;
            while (true)
            {
                scanf("%d%d",&tp.first,&tp.second);
                if (tp.first == 0)  continue;
                a[i].push_back(tp);
                totl += tp.first;
                if (totl == m)  break;
            }
            if (i+1 < n)
                a[i].push_back(make_pair(n-1-i,0));
        }
        m += n-1;
        tp = make_pair(0,0);
        for (int i = 0;i < n;i++)
        {
            pos[i] = make_pair(0,0);
            tp.second += a[i][pos[i].first].second;
        }
        res.clear();
        res.push_back(tp);
        for (int i = 0;i < m;i += minl)
        {
            minl = m;
            for (int j = 0;j < n;j++)
                minl = min(minl,a[j][pos[j].first].first-pos[j].second);
            res[res.size()-1].first += minl;
            tp = make_pair(0,0);
            for (int j = 0;j < n;j++)
            {
                pos[j].second += minl;
                if (pos[j].second == a[j][pos[j].first].first)
                {
                    pos[j].first++;
                    pos[j].second = 0;
                }
                tp.second += a[j][pos[j].first].second;
            }
            res.push_back(tp);
        }
        tp = res[0];
        for (int i = 1;i < res.size()-1;i++)
            if (res[i].second == tp.second)
                tp.first += res[i].first;
            else
            {
                printf("%d %d ",tp.first,tp.second);
                tp = res[i];
            }
        printf("%d %d\n",tp.first,tp.second);
    }
    return 0;
}
