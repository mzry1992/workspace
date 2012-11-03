#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,tot;
string s[2500*4],tmp;

bool aaaa()
{
    for (int i = 0;i < n;i++)
        if (!(s[4*i] == s[4*i+1] && s[4*i+1] == s[4*i+2] && s[4*i+2] == s[4*i+3]))
            return false;
    return true;
}

bool aabb()
{
    for (int i = 0;i < n;i++)
        if (!(s[4*i] == s[4*i+1] && s[4*i+2] == s[4*i+3]))
            return false;
    return true;
}

bool abab()
{
    for (int i = 0;i < n;i++)
        if (!(s[4*i] == s[4*i+2] && s[4*i+1] == s[4*i+3]))
            return false;
    return true;
}

bool abba()
{
    for (int i = 0;i < n;i++)
        if (!(s[4*i] == s[4*i+3] && s[4*i+1] == s[4*i+2]))
            return false;
    return true;
}

void Gao()
{
    bool flag = true;
    for (int i = 0; i < 4*n; i++)
    {
        cin >> tmp;
        tot = 0;
        for (int j = tmp.size()-1; j >= 0; j--)
            if (tmp[j] == 'a' || tmp[j] == 'e' || tmp[j] == 'i' || tmp[j] == 'o' || tmp[j] == 'u')
            {
                tot++;
                if (tot == k)
                    s[i] = tmp.substr(j,tmp.size()-j);
            }
        if (tot < k)
            flag = false;
    }
    if (flag == false)
    {
        puts("NO");
        return;
    }
    if (aaaa())
    {
        puts("aaaa");
        return;
    }
    if (aabb())
    {
        puts("aabb");
        return;
    }
    if (abab())
    {
        puts("abab");
        return;
    }
    if (abba())
    {
        puts("abba");
        return;
    }
    puts("NO");
}

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
        Gao();
    return 0;
}
