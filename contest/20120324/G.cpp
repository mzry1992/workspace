#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int totrk = 2;
const int rkmod[2] = {10007,3011};
const int rkmul[2] = {29,26};

struct hash_map
{
    const static int mod = 10007;
    const static int totele = 100007;
    int head[mod];
    struct hash_tables
    {
        int key1,key2,key3,next;
    } ele[totele];
    int N;
    int getHash(int x1,int x2,int x3)
    {
        return (x1*x2+x3)%mod;
    }
    void init()
    {
        memset(head,255,sizeof(head));
        N = 0;
    }
    void clear()
    {
        for (int i = 0; i < N; i++)
            head[getHash(ele[i].key1,ele[i].key2,ele[i].key3)] = -1;
        N = 0;
    }
    int find(int x1,int x2,int x3)
    {
        for (int i = head[getHash(x1,x2,x3)]; i != -1; i = ele[i].next)
            if (ele[i].key1 == x1 && ele[i].key2 == x2 && ele[i].key3 == x3)    return i;
        return -1;
    }
    void insert(int x1,int x2,int x3)
    {
        int tmp = getHash(x1,x2,x3);
        ele[N].key1 = x1;
        ele[N].key2 = x2;
        ele[N].key3 = x3;
        ele[N].next = head[tmp];
        head[tmp] = N++;
    }
};

int n;
char w1[110],w2[110],s[100001];
int len1,len2,lens,dif[110],next[110],pnow,minlen;
int hash[2],totres,res[110],reslen,respos;
hash_map rk[100];

void gao(int len,int pos)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < totrk; j++)   hash[j] = 0;
        for (int j = 0; j < len2; j++)
            for (int k = 0; k < totrk; k++)
                hash[k] = (hash[k]*rkmul[k]+(w2[j]-'A'+dif[(i+j)%len]+1)%26)%rkmod[k];
        if (rk[len-1].find(hash[0],hash[1],i) != -1)
        {
            totres++;
            reslen = len;
            respos = pos;
            for (int k = 0; k < reslen; k++)
                res[k] = dif[k];
        }
    }
}

int main()
{
    for (int k = 0; k < 100; k++)
        rk[k].init();
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%s%s%s",w1,w2,s);
        len1 = strlen(w1);
        len2 = strlen(w2);
        lens = strlen(s);

        for (int k = 0; k < 100; k++)
            rk[k].clear();
        for (int i = 0; i+len2 <= lens; i++)
        {
            for (int j = 0; j < totrk; j++)   hash[j] = 0;
            for (int j = 0; j < len2; j++)
                for (int k = 0; k < totrk; k++)
                    hash[k] = (hash[k]*rkmul[k]+s[i+j]-'A')%rkmod[k];
            for (int k = 1; k <= 100; k++)
                rk[k-1].insert(hash[0],hash[1],i%k);
        }
        totres = 0;
        for (int i = 0; i+len1 <= lens; i++)
        {
            for (int j = 0; j < len1; j++)
                dif[j] = (s[i+j]-'A'-(w1[j]-'A')+25)%26;
            pnow = next[0] = -1;
            for (int j = 1; j < len1; j++)
            {
                while (pnow >= 0 && dif[pnow+1] != dif[j])    pnow = next[pnow];
                if (dif[pnow+1] == dif[j]) pnow++;
                next[j] = pnow;
            }
            minlen = len1-next[len1-1]-1;
            if (minlen <= n)
                gao(minlen,i);
            if (len1%minlen != 0 && len1 <= n)
                gao(len1,i);
            if (totres > 1)
                break;
        }
        if (totres == 0)    puts("impossible");
        else if (totres > 1)   puts("ambiguous");
        else
        {
            int op = (reslen-respos%reslen+reslen)%reslen;
            for (int i = 0;i < lens;i++,op = (op+1)%reslen)
                printf("%c",(s[i]-'A'-(res[op]+1)+26)%26+'A');
            puts("");
        }
    }
    return 0;
}
