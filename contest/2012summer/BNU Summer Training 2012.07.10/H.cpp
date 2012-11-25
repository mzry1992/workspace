#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

bool res;
int n,a[12],len;
vector<int> use;

void DFS(int now,int nowp,int last)
{
    if (res)    return;
    if (now == 0)
    {
        int tmp = 0;
        for (int i = 0;i < len;i++)
            tmp += (i+2-use[i])/2;
        if (tmp >= a[0])
            res = true;
        return;
    }
    if (nowp == a[now])
    {
        DFS(now-1,0,0);
        return;
    }
    for (int i = last;i < len;i++)
    {
        if (use[i]+now+1 == i+1)
        {
            use[i] += now+1;
                DFS(now,nowp+1,i);
            use[i] -= now+1;
        }
        else if (use[i]+now+1 < i+1)
        {
            use[i] += now+2;
                DFS(now,nowp+1,i);
            use[i] -= now+2;
        }
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        res = false;
        for (len = 1;len <= 12;len++)
        {
            for (int i = 0;i < len;i++)
                use.push_back(0);
            DFS(n-1,0,0);
            if (res == true)
            {
                printf("%d\n",len);
                break;
            }
        }
        if (res == false)
            puts("impossible");
    }
	return 0;
}
