#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int n;
struct Point
{
    int x,y;
}p[100001],tp;
map<int,int> Q[100001];
int len;
map<int,int>::iterator it,itend;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for (int i = 1;i <= n;i++)
            Q[i].clear();
        len = 1;
        Q[1][p[1].x] = p[1].y;
        for (int i = 2;i <= n;i++)
        {
            int l = 0;
            int r = len;
            /*
            cout << len << endl;
            for (int j = 1;j <= len;j++)
            {
                cout << j << " : " ;
                for (it = Q[j].begin();it != Q[j].end();it++)
                    cout << '(' << it->first << ',' << it->second << ") ";
                cout << endl;
            }
            */
            int mid;
            while (l < r)
            {
                mid = (l+r+1)/2;
                if (mid == 0)
                {
                    l = mid;
                    continue;
                }
                if (Q[mid].begin()->first >= p[i].x)
                {
                    r = mid-1;
                    continue;
                }
                it = Q[mid].lower_bound(p[i].x);
                it--;
                if (it->second < p[i].y)    l = mid;
                else r = mid-1;
            }
            if (l == len)   len++;
            l++;
            it = Q[l].find(p[i].x);
            if (it != Q[l].end())
                p[i].y = min(p[i].y,it->second);
            itend = it = Q[l].lower_bound(p[i].x);
            while (true)
            {
                if (itend == Q[l].end())   break;
                if (itend->second <= p[i].y)   break;
                itend++;
            }
            if (itend != it)
                Q[l].erase(it,itend);
            it = Q[l].find(p[i].x);
            if (it == Q[l].end())
                Q[l][p[i].x] = p[i].y;
            else if (it->second > p[i].y)
                Q[l][p[i].x] = p[i].y;
        }
        printf("%d\n",len);
    }
}
