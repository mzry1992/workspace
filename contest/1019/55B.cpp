#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<long long> a;
char op[3];
long long res;

void Gao(vector<long long> a)
{
    if (a.size() == 1)
    {
        if (res == -1)
            res = a[0];
        else
            res = min(res,a[0]);
        return;
    }
    vector<long long> tmp;
    for (int i = 0;i < a.size();i++)
        for (int j = i+1;j < a.size();j++)
        {
            tmp.clear();
            for (int k = 0;k < a.size();k++)
                if (k != i && k != j)
                    tmp.push_back(a[k]);
            if (op[4-a.size()] == '+')
                tmp.push_back(a[i]+a[j]);
            else
                tmp.push_back(a[i]*a[j]);
            Gao(tmp);
        }
}

int main()
{
    a.resize(4);
    for (int i = 0;i < 4;i++)
        cin >> a[i];
    for (int i = 0;i < 3;i++)
        scanf(" %c",&op[i]);
    res = -1;
    Gao(a);
    cout << res << endl;
    return 0;
}
