#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,m;
vector<int> a[10],b,res[10];

bool check(vector<int> b,vector<int> a)
{
    for (int i = 0;i < b.size();i++)
        if (b[i] > 0)
        {
            bool flag = false;
            for (int j = 0;j < a.size();j++)
                if (a[j] == b[i])
                    flag = true;
            if (flag == false)
                return false;
        }
        else
        {
            for (int j = 0;j < a.size();j++)
                if (a[j] == -b[i])
                    return false;
        }
    return true;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            int cnt;
            scanf("%d",&cnt);
            a[i].resize(cnt);
            for (int j = 0;j < cnt;j++)
                scanf("%d",&a[i][j]);
        }
        for (int i = 0;i < m;i++)
        {
            int cnt;
            scanf("%d",&cnt);
            b.resize(cnt);
            for (int j = 0;j < cnt;j++)
                scanf("%d",&b[j]);

            cnt = 0;
            for (int j = 0;j < n;j++)
                if (check(b,a[j]))
                    res[cnt++] = a[j];

            printf("%d\n",cnt);
            for (int j = 0;j < cnt;j++)
            {
                printf("%d",res[j].size());
                for (int k = 0;k < res[j].size();k++)
                    printf(" %d",res[j][k]);
                printf("\n");
            }
        }
    }
	return 0;
}
