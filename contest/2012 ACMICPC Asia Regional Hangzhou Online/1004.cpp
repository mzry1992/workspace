#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

long long res;
int n,full,a[32];
int use[5],sgn[5];
bool nuse[5];
vector<pair<string,long long> > b;

void gen(int cnt,int now)
{
    if (now == n)
    {
        if (cnt == 0)   return;
        string tmp = "";
        for (int i = 0; i < cnt; i++)
            if (sgn[i] == 0)
            {
                tmp.push_back('-');
                tmp.push_back('A'+use[i]);
            }
        for (int i = 0; i < cnt; i++)
            if (sgn[i] == 1)
                tmp.push_back('A'+use[i]);

        int mska = 0;
        for (int i = 0; i < cnt; i++)
            if (sgn[i] == 1)
                mska |= 1<<use[i];

        memset(nuse,false,sizeof(nuse));
        for (int i = 0; i < cnt; i++)
            nuse[use[i]] = true;

        int mskb = 0;
        for (int i = 0; i < n; i++)
            if (nuse[i] == false)
                mskb |= 1<<i;


        long long tres = 0;
        tres |= 1LL<<mska;
        for (int j = mskb; j; j = (j-1)&mskb)
            tres |= 1LL<<(mska|j);

        if ((tres&res) == tres)
            b.push_back(make_pair(tmp,tres));
        return;
    }

    gen(cnt,now+1);
    use[cnt] = now;
    sgn[cnt] = 0;
    gen(cnt+1,now+1);
    sgn[cnt] = 1;
    gen(cnt+1,now+1);
}

int maxlen,cnt,id[300],slen[300],sumlen[300];
long long tmsk[300];

bool DFS(int tot,int now,int len,long long msk)
{
    if (msk == res)
    {
        cnt = tot;
        return true;
    }
    if (now == b.size())
        return false;
    if ((msk|tmsk[now]) < res)  return false;
    if (sumlen[now]+len+(b.size()-now) < maxlen) return false;
    int tmp = slen[now]+len+1;
    if ((b[now].second&msk) != b[now].second && tmp <= maxlen)
    {
        id[tot] = now;
        if (DFS(tot+1,now+1,tmp,msk|b[now].second))
            return true;
    }
    return DFS(tot,now+1,len,msk);
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        full = (1<<n);
        res = 0;
        for (int i = 0; i < full; i++)
        {
            int msk = 0;
            for (int j = 0; j < n; j++)
            {
                int t;
                scanf("%d",&t);
                if (t == 1)
                    msk |= 1<<j;
            }
            scanf("%d",&a[msk]);
            if (a[msk] == 1)
                res |= 1LL<<msk;
        }
        if (res == 0)
        {
            puts("-AA");
            continue;
        }
        b.clear();
        gen(0,0);
        sort(b.begin(),b.end());

        int tbn = 1;
        for (int i = 1;i < b.size();i++)
        {
            if (b[i].first.length() >= b[tbn-1].first.length())
                if (b[i].first.substr(0,b[tbn-1].first.length()) == b[tbn-1].first)
                    continue;
            b[tbn++] = b[i];
        }
        b.resize(tbn);
        for (int i = 0; i < b.size(); i++)
            slen[i] = b[i].first.length();
        sumlen[b.size()] = 0;
        for (int i = b.size()-1; i >= 0; i--)
            sumlen[i] = sumlen[i+1]+slen[i];
        tmsk[b.size()] = 0;
        for (int i = b.size()-1; i >= 0; i--)
            tmsk[i] = tmsk[i+1]|b[i].second;

        for (maxlen = 1;; maxlen++)
            if (DFS(0,0,-1,0) == true)
            {
                printf("%s",b[id[0]].first.c_str());
                for (int i = 1; i < cnt; i++)
                    printf("+%s",b[id[i]].first.c_str());
                printf("\n");
                break;
            }
    }
    return 0;
}
