#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

vector<int> now;
map<vector<int>,int> chk;

char a[100100];
int n,zero,one,unknow;

int Gao(vector<int> now,int player)
{
    int minres,maxres,res;
    maxres = 0;
    minres = 3;
    if (now.size() == 2)
    {
        res = now[0]*2+now[1];
        return res;
    }
    for (int i = 0;i < now.size();i++)
    {
        vector<int> tmp;
        for (int j = 0;j < now.size();j++)
            if (j != i)
                tmp.push_back(now[j]);
        res = Gao(tmp,!player);
        minres = min(minres,res);
        maxres = max(maxres,res);
    }
    if (player == 0)    return minres;
    else    return maxres;
}

int main()
{
    vector<int> count(4);
    for (int len = 6;len < 7;len++)
        for (int i = 0;i < 1<<len;i++)
        {
            now.resize(len);
            for (int j = 0;j < len;j++)
                now[j] = ((i>>j)&1);

            for (int j = 0;j < 4;j++)
                count[j] = 0;
            for (int j = 1;j < len;j++)
                count[now[j-1]*2+now[j]]++;
            int res = Gao(now,0);
            printf("%d\n",res);
        }

    while (scanf("%s",a) != EOF)
    {
        n = strlen(a);
        zero = one = unknow = 0;
        for (int i = 0;i < n;i++)
            if (a[i] == '0')
                zero++;
            else if (a[i] == '1')
                one++;
            else
                unknow++;
    }
    return 0;
}

