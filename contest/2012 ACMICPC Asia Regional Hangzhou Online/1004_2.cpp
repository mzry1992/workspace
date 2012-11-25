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

int tid[300];
int maxlen,cnt,id[300],slen[300];
long long tmsk[300];
int totnode;
bool hasres;

void DFS(int tot,int now,int len,long long msk)
{
    totnode++;
    //cout << maxlen << ' ' << tot << ' ' << now << ' ' << len << ' ' << msk << endl;
    if (msk == res)
    {
        if (len < maxlen)
        {
            maxlen = len;
            cnt = tot;
            for (int i = 0;i < cnt;i++)
                tid[i] = id[i];
        }
        return;
    }
    if (now == b.size())
        return;
    if ((msk|tmsk[now]) < res)  return;
    int tmp = slen[now]+len+1;
    if ((b[now].second&msk) != b[now].second && tmp <= maxlen)
    {
        id[tot] = now;
        DFS(tot+1,now+1,tmp,msk|b[now].second);
    }
    DFS(tot,now+1,len,msk);
}

int main()
{
    //while (true)
    for (int cas = 1; cas <= 20; cas++)
    {
		n = 5;
        //scanf("%d",&n);
        if (n == 0) break;
        full = (1<<n);
        res = 0;
        for (int i = 0; i < full; i++)
        {
            int msk = 0;
            for (int j = 0; j < n; j++)
            {
                int t;
                t = ((i>>j)&1);
                //scanf("%d",&t);
                if (t == 1)
                    msk |= 1<<j;
            }
            a[msk] = rand()%2;
            //scanf("%d",&a[msk]);
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
        for (int i = 1; i < b.size(); i++)
        {
            if (b[i].first.length() >= b[tbn-1].first.length())
                if (b[i].first.substr(0,b[tbn-1].first.length()) == b[tbn-1].first)
                    continue;
            b[tbn++] = b[i];
        }
        b.resize(tbn);
        for (int i = 0; i < b.size(); i++)
            slen[i] = b[i].first.length();
        tmsk[b.size()] = 0;
        for (int i = b.size()-1; i >= 0; i--)
            tmsk[i] = tmsk[i+1]|b[i].second;

        maxlen = 1000;
        totnode = 0;
        DFS(0,0,-1,0);

        printf("%s",b[tid[0]].first.c_str());
        for (int i = 1; i < cnt; i++)
            printf("+%s",b[tid[i]].first.c_str());
        printf("\n");

        //printf("totnode = %d\n",totnode);
    }
    return 0;
}
