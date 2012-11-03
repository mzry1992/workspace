#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

const int maxn = 110000;

char Ma[maxn*2];
int Mp[maxn*2];
void Manacher(char s[],int len)
{
    int l = 0;
    Ma[l++] = '.';
    Ma[l++] = ',';
    for (int i = 0; i < len; i++)
    {
        Ma[l++] = s[i];
        Ma[l++] = ',';
    }
    Ma[l] = 0;
    int pnow = 0,pid = 0;
    for (int i = 1; i < l; i++)
    {
        if (pnow > i)
            Mp[i] = min(Mp[2*pid-i],pnow-i);
        else
            Mp[i] = 1;
        for (; Ma[i-Mp[i]] == Ma[i+Mp[i]]; Mp[i]++);
        if (i+Mp[i] > pnow)
        {
            pnow = i+Mp[i];
            pid = i;
        }
    }
}

char s[maxn*2];
int len;
int p[maxn*2];
const int muts = 129;
uint sum[maxn];
uint mutpower[maxn];

struct hash_map
{
    const static int mod = 300007;
    int head[mod];
    struct hash_tables
    {
        uint key1;
        int key2;
        int next;
    } ele[maxn*10];
    int N;
    void init()
    {
        memset(head,-1,sizeof(head));
        N = 0;
    }
    int totlen[mod];
    void clear()
    {
        for (int i = 0; i < N; i++)
            head[ele[i].key1%mod] = -1;
        N = 0;
    }
    int find(uint x,int len)
    {
        int hashcode = x%mod;
        for (int i = head[hashcode]; i != -1; i = ele[i].next)
            if (ele[i].key1 == x && ele[i].key2 == len)
                return i;
        return -1;
    }
    void insert(uint x,int len)
    {
        int tmp = x%mod;
        ele[N].key1 = x;
        ele[N].key2 = len;
        ele[N].next = head[tmp];
        head[tmp] = N++;
    }
};

hash_map hash;

uint gethashcode(int l,int r)
{
    uint ret;
    ret = sum[r];
    if (l)
        ret -= sum[l-1]*mutpower[r-l+1];
    return ret;
}

int calc(char s[])
{
    len = strlen(s);
    Manacher(s,len);

    sum[0] = s[0];
    for (int i = 1; i < len; i++)
        sum[i] = sum[i-1]*muts+s[i];

    int res = 0;
    uint tmp;
    int nt = 0;
    hash.clear();
    //odd
    for (int i = 0; i < len; i++)
        if (Mp[i*2+2]%2 == 0)
        {
            int pl = Mp[i*2+2]/2;
            if (i+pl < nt || pl == 0)	continue;
            for (int j = i-pl+1; j <= i; j++)
            {
                tmp = gethashcode(j,i);
                if (hash.find(tmp,i-j+1) != -1)	break;
                hash.insert(tmp,i-j+1);
            }
            nt = i+pl;
        }
    res += hash.N;

    nt = 0;
    hash.clear();
    //even
    for (int i = 0; i < len; i++)
        if (Mp[i*2+3] > 1)
        {
            int pl = Mp[i*2+3]/2;
            if (i+pl < nt || pl == 0)	continue;
            for (int j = i-pl+1; j <= i; j++)
            {
                tmp = gethashcode(j,i);
                if (hash.find(tmp,i-j+1) != -1)	break;
                hash.insert(tmp,i-j+1);
            }
            nt = i+pl;
        }
    res += hash.N;
    return res;
}

int main()
{
    mutpower[0] = 1;
    for (int i = 1; i < maxn; i++)
        mutpower[i] = mutpower[i-1]*muts;
    hash.init();

	int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%s",s);

        printf("Case #%d: %d\n",cas,calc(s));
    }
    return 0;
}
