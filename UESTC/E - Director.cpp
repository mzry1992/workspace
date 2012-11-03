#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n,used[26];
string tmp;
vector<string> dica[26],dicb[26];
bool first;

void output(string a,string b)
{
    if (first == false) printf(", ");
    first = false;
    cout << a << ' ' << b;
}

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < 26;i++)
    {
        dica[i].clear();
        dicb[i].clear();
    }
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        dica[tmp[0]-'A'].push_back(tmp);
    }
    for (int i = 0;i < n;i++)
    {
        cin >> tmp;
        dicb[tmp[0]-'A'].push_back(tmp);
    }
    for (int i = 0;i < 26;i++)
    {
        sort(dica[i].begin(),dica[i].end());
        sort(dicb[i].begin(),dicb[i].end());
        used[i] = 0;
    }
    first = true;
    for (int i = 0;i < 26;i++)
    {
        int pre = 0;
        for (int j = 0;j < i;j++)
            pre += dicb[j].size()-used[j];
        int leave = dicb[i].size()-used[i];
        int l,mid,r;
        mid = min((int)dica[i].size(),leave);
        l = min(pre,(int)dica[i].size()-mid);
        r = dica[i].size()-mid-l;
        for (int j = 0;j < l;j++)
            for (int k = 0;k < i;k++)
                if (used[k] < dicb[k].size())
                {
                    output(dica[i][j],dicb[k][used[k]]);
                    used[k]++;
                    break;
                }
        for (int j = 0;j < mid;j++)
        {
            output(dica[i][l+j],dicb[i][used[i]]);
            used[i]++;
        }
        for (int j = 0;j < r;j++)
            for (int k = i+1;k < 26;k++)
                if (dicb[k].size()-used[k] > dica[k].size())
                {
                    output(dica[i][l+mid+j],dicb[k][used[k]]);
                    used[k]++;
                    break;
                }
    }
    printf("\n");
}
