#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int s[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
int k,n,m,x,y;
map<pair<int,int>,int > mp2;
map<pair<int,int>,int > mp;
map<pair<int,int>,int >::iterator it;

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d%d",&k,&n,&m);
        if (k == 0 && n == 0 && m == 0) break;
        mp.clear();
        mp2.clear();
        for (int i = 0;i < k;i++)
        {
            scanf("%d%d",&x,&y);
            mp[make_pair(x,y)]++;
            mp2[make_pair(x,y)]++;
        }
        int res = 0,count;
        for (it = mp2.begin();it != mp2.end();it++)
        {
            x = it->first.first;
            y = it->first.second;
            count = it->second-1;
            for (int i = 0;i < 4;i++)
                count += mp[make_pair(x+s[i][0],y+s[i][1])];
            if (count < 2)
                res += it->second;
        }
        printf("Case %d: %d\n",++ft,res);
    }
    return 0;
}
