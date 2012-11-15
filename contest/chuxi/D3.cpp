#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int tot;
char tmp[5],dic[531441][5];
int maxlen;
unsigned int hash[531441],mut;
map<unsigned int,int> mp;

void Gao(int pos,unsigned int hashval)
{
    if (pos == maxlen)
    {
        hash[tot] = hashval;
        strcpy(dic[tot++],tmp);
        if (maxlen == 4)
            if (mp.find(hashval) == mp.end())
                mp[hashval] = tot-1;
        return;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        tmp[pos] = i;
        Gao(pos+1,(hashval*1000000007)+i);
    }
}

void init()
{
    tot = 0;
    mut = 1;
    for (int i = 0; i < 4; i++)
        mut *= 1000000007;
    for (maxlen = 1; maxlen <= 4; maxlen++)
    {
        tmp[maxlen] = 0;
        Gao(0,0);
    }
}

unsigned int n;
char res[9];
bool hasres;

int main()
{
    init();
    int ft = 0;
    while (true)
    {
        scanf("%u",&n);
        if (n == 0) break;
        hasres = false;
        for (int i = 0; i < tot; i++)
            if (hash[i] == n)
            {
                strcpy(res,dic[i]);
                hasres = true;
                break;
            }
        if (hasres == false)
            for (int i = 0; i < tot; i++)
            {
                unsigned int find = n-hash[i]*mut;
                if (mp.find(find) != mp.end())
                {
                    int id = mp[find];
                    strcpy(res,dic[i]);
                    strcat(res,dic[id]);
                    hasres = true;
                    break;
                }
            }
        printf("Case %d: %s\n",++ft,res);
    }
    return 0;
}
