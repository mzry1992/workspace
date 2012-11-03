#include<cstdio>
#include<cstring>

struct hash_map
{
    const static int mod=1000007;
    int head[mod];
    struct hash_tables
    {
        long long key;
        int next;
        long long dp;
    } ele[1000000];
    int N;
    void init()
    {
        N=0;
        memset(head,255,sizeof(head));
    }
    void clear()
    {
        memset(head,255,sizeof(head[0])*N);
        N=0;
    }
    int getHash(long long x)
    {
        return x%mod;
    }
    int fint(long long x)
    {
        for (int i=head[getHash(x)]; i!=-1; i=ele[i].next)
            if (ele[i].key==x) return i;
        return -1;
    }
    void insert(long long x)
    {
        int tmp=getHash(x);
        ele[N].key=x;
        ele[N].dp=0;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    long long operator [](long long x)
    {
        int tmp=fint(x);
        if (tmp==-1)
        {
            insert(x);
            return ele[N-1].dp;
        }
        else
            return ele[tmp].dp;
    }
    int begin()
    {
        return 0;
    }
    int end()
    {
        return N;
    }
};

hash_map h;

int main()
{
    h.init();
    h[1]=8;
    h[5]=3;
    h[2] += 8;
    h[1]+=8;
    printf("%lld %lld %lld\n",h[1],h[2],h[5]);
}
