#include<cstdio>
#include<cstring>

struct hashtable
{
    const static int mod=1000007;
    int head[mod];
    struct hash_tables
    {
        int key,next;
    } ele[1000000];
    int N;
    void init()
    {
        N=0;
        memset(head,255,sizeof(head));
    }
    int getHash(int x)
    {
        return x%mod;
    }
    int fint(int x)
    {
        for (int i=head[getHash(x)]; i!=-1; i=ele[i].next)
            if (ele[i].key==x) return i;
        return -1;
    }
    void insert(int x)
    {
        int tmp=getHash(x);
        ele[N].key=x;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    int hash(int x)
    {
        int tmp=fint(x);
        if (tmp==-1)
        {
            insert(x);
            return N-1;
        }
        else
            return tmp;
    }
};

hashtable h;

int main()
{
    h.init();
    h.hash(1);
    h.hash(5);
    printf("%d %d %d\n",h.hash(1),h.hash(2),h.hash(5));
}

