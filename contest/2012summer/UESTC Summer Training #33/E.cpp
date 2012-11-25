#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;

set<vector<int> > visit;
vector<int> now,nxt,tt;
int tmp[20];

int main()
{
    int n = 9;
    for (int i = 1;i <= n;i++)
        now.push_back(i);
    queue<vector<int> > Q;
    Q.push(now);
    visit.insert(now);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = 0;i < n;i++)
            now.push_back(now[i]);
//            for (int i = 0;i < n;i++)
//                printf("%d ",now[i]);
//            printf("\n");
//            printf("---------------\n");
        for (int i = 0;i < n;i++)
        {
            reverse(now.begin()+i,now.begin()+i+4);
            nxt.clear();
            for (int j = 0;j < n;j++)
                nxt.push_back(now[i+j]);
            for (int j = 0;j < n;j++)
                if (nxt[j] == 1)
                {
                    tt.clear();
                    for (int k = 0;k < n;k++)
                        tt.push_back(nxt[(j+k)%n]);
//            for (int k = 0;k < n;k++)
//                printf("%d ",tt[k]);
//            printf("\n");
                    //reverse(nxt.begin(),nxt.begin()+j);
                    //reverse(nxt.begin()+j,nxt.end());
                    //reverse(nxt.begin(),nxt.end());
                    if (visit.find(tt) == visit.end())
                    {
                        visit.insert(tt);
                        Q.push(tt);
                    }
                    break;
                }
            reverse(now.begin()+i,now.begin()+i+4);
        }
    }
    now.clear();
    for (int i = 1;i <= n;i++)
        now.push_back(i);
    int ans = 0;
    do
    {
        if (visit.find(now) == visit.end())
        {
            ans++;
            if (ans <= 10)
            {
            for (int i = 0;i < n;i++)
                printf("%d ",now[i]);
            printf("\n");
            }
        }
    }while (next_permutation(now.begin()+1,now.end()));
    printf("%d\n",ans);
	return 0;
}
