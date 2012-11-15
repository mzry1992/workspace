#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef map<pair<int,int>,int> result;
typedef vector<int> function;
typedef map<pair<int,int>,int>::iterator resultit;

result Gao(int n,function f)
{
    function newf;
    result res,tres;
    if (n == 1)
    {
        if (f.size() == 0)
            res[make_pair(1,0)] = 1;
        else
        {
            newf.resize(f.size()-1);
            for (int i = 0;i < newf.size();i++)
                newf[i] = f[i];
            tres = Gao(f[newf.size()],newf);
            for (resultit it = tres.begin();it != tres.end();it++)
                res[make_pair(it->first.first+1,it->first.second)] = it->second;
        }
    }
    else if (n == 2)
    {
        if (f.size() == 0)
            res[make_pair(0,1)] = 1;
        else
        {
            newf.resize(f.size()-1);
            for (int i = 0;i < newf.size();i++)
                newf[i] = f[i];
            tres = Gao(f[newf.size()],newf);
            for (resultit it = tres.begin();it != tres.end();it++)
                res[make_pair(it->first.first,it->first.second+1)] = it->second;
        }
    }
    else
    {
        newf = f;
        newf.push_back(n-2);
        return Gao(n-1,newf);
    }
    return res;
}

result res;
function tmp;

int main()
{
    for (int n = 1;n <= 10;n++)
    {
        tmp.clear();
        res = Gao(n,tmp);
        for (resultit it = res.begin();it != res.end();it++)
            printf("%d*a^%d*b^%d+",it->second,it->first.first,it->first.second);
        printf("\n");
    }
    return 0;
}
