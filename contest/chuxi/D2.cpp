#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

const unsigned int mut = 1000000007;
unsigned int mut4;
int tot,maxlen;
char dic[475254][5],tmp[5],res[10],tres[10];
int len[475254],reslen,treslen;
unsigned int hash[475254],n;
map<unsigned int,int> hdic;

bool mycmp(char a[],char b[],int len)
{
    for (int i = 0; i < len; i++)
        if (a[i] < b[i])    return true;
        else if (a[i] > b[i])   return false;
    return true;
}

void Gao(int pos,unsigned int val)
{
    if (pos == maxlen)
    {
        strcpy(dic[tot],tmp);
        len[tot] = maxlen;
        hash[tot++] = val;
        if (maxlen == 4)
        {
            if (hdic.find(val) == hdic.end())
                hdic[val] = tot-1;
            else
            {
                int id = hdic[val];
                if (maxlen > len[id])   return;
                if (maxlen < len[id] ||
                        mycmp(tmp,dic[id],maxlen))
                    hdic[val] = tot-1;
            }
        }
        return;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        tmp[pos] = i;
        unsigned int nval = val;
        nval *= mut;
        nval += i;
        Gao(pos+1,nval);
    }
}

int main()
{
    mut4 = 1;
    for (int i = 0; i < 4; i++)
        mut4 *= mut;
    tot = 0;
    for (maxlen = 1; maxlen <= 4; maxlen++)
    {
        tmp[maxlen] = 0;
        Gao(0,0);
    }
    int ft = 0;
    while (true)
    {
        scanf("%u",&n);
        if (n == 0) break;
        reslen = 10;
        for (int i = 0; i < tot; i++)
            if (hash[i] == n)
            {
                if (len[i] > reslen) continue;
                if (len[i] < reslen ||
                        mycmp(dic[i],res,len[i]))
                {
                    strcpy(res,dic[i]);
                    reslen = len[i];
                }
            }
        unsigned int nval;
        if (reslen == 10)
        {
            for (int i = 0;len[i] < 4;i++)
            {
                nval = hash[i]*mut4;
                if (hdic.find(n-nval) != hdic.end())
                {
                    int id = hdic[n-nval];
                    strcpy(tres,dic[i]);
                    strcat(tres,dic[id]);
                    treslen = len[i]+len[id];
                    if (treslen > reslen)    continue;
                    if (treslen < reslen ||
                            mycmp(tres,res,treslen))
                    {
                        strcpy(res,tres);
                        reslen = treslen;
                    }
                }
            }
        }
        printf("Case %d: %s\n",++ft,res);
    }
    return 0;
}
