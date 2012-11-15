#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n;
string dic[100],s,ts,res,le,tres;
bool del[100];

void DFS(int now)
{
    for (int i = 0;i < n;i++)
        if (now >= dic[i].size())
            if (res.substr(now-dic[i].size(),dic[i].size()) == dic[i])
                return;
    if (now == res.size())
    {
        int countle = 0;
        for (int i = 0;i < res.size();i++)
            if (res[i] == le[0])
                countle++;
        for (int i = 0;i < tres.size();i++)
            if (tres[i] == le[0])
                countle--;
        if (countle == 0)
        {
            if (tres > res) tres = res;
        }
        else if (countle > 0)
            tres = res;
        return;
    }
    if (res[now] != '*')    DFS(now+1);
    else
    {
        for (int i = 0;i < 26;i++)
            if ('a'+i != s[now])
            {
                res[now] = 'a'+i;
                DFS(now+1);
                res[now] = '*';
            }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
    {
        cin >> dic[i];
        for (int j = 0;j < dic[i].size();j++)
            if (dic[i][j] >= 'A' && dic[i][j] <= 'Z')
                dic[i][j] = dic[i][j]-'A'+'a';
    }
    cin >> ts;
    s = ts;
    for (int i = 0;i < s.size();i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i]-'A'+'a';
    cin >> le;
    memset(del,false,sizeof(del));
    for (int i = 0;i < s.size();i++)
        for (int j = 0;j < n;j++)
            if (s.size()-i >= dic[j].size())
                if (s.substr(i,dic[j].size()) == dic[j])
                    for (int k = i;k < i+dic[j].size();k++)
                        del[k] = true;
    tres = res = s;
    for (int i = 0;i < s.size();i++)
        if (del[i] == true)
        {
            tres[i] = 'z';
            res[i] = '*';
        }
    DFS(0);
    for (int i = 0;i < ts.size();i++)
        if (ts[i] >= 'A' && ts[i] <= 'Z')
            tres[i] = tres[i]-'a'+'A';
    cout << tres << endl;
}
