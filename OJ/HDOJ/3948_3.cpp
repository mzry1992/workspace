#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
using namespace std;

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

int power(int x,int y,int mod)
{
    int res = 1;
    for (long long a = x%mod; y; y>>=1,a = a*a%mod)
        if (y&1)
            res = a*res%mod;
    return res%mod;
}

int getInv(int x,int mod)
{
    return power(x,mod-2,mod);
}

char s[maxn*2];
int len;
int p[maxn*2];
const int muts = 127;
const int mods = 1000000007;
int sum[maxn];
int mutpower[maxn];

struct hash_map
{
    const static int mod = 300007;
    int head[mod];
    struct hash_tables
    {
        int key;
        int next;
    } ele[maxn*10];
    int N;
    int getHash(int x)
    {
        return x%mod;
    }
    void init()
    {
        memset(head,-1,sizeof(head));
        N = 0;
    }
    void clear()
    {
        for (int i = 0; i < N; i++)
            head[getHash(ele[i].key)] = -1;
        N = 0;
    }
    int fint(int x)
    {
        for (int i = head[getHash(x)]; i != -1; i = ele[i].next)
            if (ele[i].key == x)
                return i;
        return -1;
    }
    void insert(int x)
    {
        int tmp = getHash(x);
        ele[N].key = x;
        ele[N].next = head[tmp];
        head[tmp] = N++;
    }
};

hash_map hash;

int gethashcode(int l,int r)
{
    int ret;
    ret= sum[r];
    if (l)
        ret-= sum[l-1];
    if (ret < 0)
        ret += mods;
    ret= (long long)ret*getInv(mutpower[l],mods)%mods;
    return ret;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    //totcas = 20;
    hash.init();
    for (int cas = 1; cas <= totcas; cas++)
    {
        //for (int i = 0;i < maxn-10;i++)
        //    s[i] = rand()%1+'a';
        //s[maxn-10] = 0;
        scanf("%s",s);
        len = strlen(s);
        Manacher(s,len);

        sum[0] = s[0];
        mutpower[0] = 1;
        for (int i = 1; i < len; i++)
        {
            mutpower[i] = (long long)mutpower[i-1]*muts%mods;
            sum[i] = (sum[i-1]+(long long)s[i]*mutpower[i])%mods;
        }
        int res = 0;
        int tmp;

        //for (int i = 0;i < len*2+2;i++)
        //    printf("%2d ",Mp[i]);
        //printf("\n");

        //for (int i = 0; i < len; i++)
        //    printf("%d\n",gethashcode(i,i).first);
        hash.clear();
        //odd
        for (int i = 0; i < len; i++)
            if (Mp[i*2+2]%2 == 0)
            {
                int pl = Mp[i*2+2]/2;
                for (int j = i-pl+1; j <= i; j++)
                {
                    tmp = gethashcode(j,i);
                    if (hash.fint(tmp) != -1)    break;
                    hash.insert(tmp);
                }
            }
        res += hash.N;

        hash.clear();
        //even
        for (int i = 0; i < len; i++)
            if (Mp[i*2+3] > 1)
            {
                int pl = Mp[i*2+3]/2;
                for (int j = i-pl+1; j <= i; j++)
                {
                    tmp = gethashcode(j,i);
                    if (hash.fint(tmp) != -1)    break;
                    hash.insert(tmp);
                }
            }
        res += hash.N;

        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
