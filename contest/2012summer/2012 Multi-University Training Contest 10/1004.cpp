#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<pair<int,int> > player[101];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 1;i <= 100;i++)
            player[i].clear();
        for (int i = 0;i < n;i++)
        {
            int f,s;
            scanf("%d%d",&f,&s);
            player[s].push_back(make_pair(f,-i));
        }
        for (int i = 1;i <= 100;i++)
            sort(player[i].begin(),player[i].end());
        printf("Case #%d:\n",cas);
        for (int i = 0;i < n;i++)
        {
            pair<int,int> far = make_pair(-1,0);
            int id;
            for (int j = 1;j <= 100;j++)
                if (player[j].size() > 0)
                {
                    pair<int,int> tmp = make_pair(player[j].back().first+j*i,player[j].back().second);
                    if (tmp> far)
                    {
                        id = j;
                        far = tmp;
                    }
                }
            player[id].pop_back();
            if (i > 0)
                printf(" ");
            printf("%d",1-far.second);
        }
        puts("");
	}
	return 0;
}
