#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<vector<int>,bool> flag;

bool DFS(vector<int> s)
{
    sort(s.begin(),s.end());
    if (flag.find(s) != flag.end())
        return flag[s];

    for (int i = 0; i < s.size(); i++)
        if (s[i] > 1)
        {
            vector<int> ts = s;
            for (int j = 2; j <= s[i]; j++)
                if (s[i]%j == 0)
                {
                    ts[i] = s[i]/j;
                    if (DFS(ts) == false)
                    {
                        flag[s] = true;
                        return true;
                    }
                    ts[i] = s[i];
                }
        }
    flag[s] = false;
    return false;
}

int cntfac(int x)
{
    int res = 0;
    for (int i = 2; i <= x; i++)
        while (x%i == 0)
        {
            x /= i;
            res++;
        }
    return res;
}

int main()
{
    vector<int> s;
    for (int l = 2; l <= 6; l++)
        for (int r = l; r <= 6; r++)
        {
            s.clear();
            for (int k = l; k <= r; k++)
                s.push_back(k);

            bool res = DFS(s);
            int res2 = 0;
            for (int k = l;k <= r;k++)
            {
                printf("%d ",cntfac(k));
                res2 = res2^cntfac(k);
            }
            printf("\n");
            printf("l = %d, r = %d, res = %d, %d\n",l,r,res,res2);
        }
    return 0;
}

