#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MaxN = 100000;

struct hash_map
{
    const static int mod=6007;
    int head[mod];
    struct hash_tables
    {
        int key;
        int val;
        int next;
    } ele[320];
    int N;
    int getHash(int x)
    {
        return x%mod;
    }
    void init()
    {
        memset(head,255,sizeof(head));
        N=0;
    }
    void clear()
    {
        for (int i = 0; i < N; i++)
            head[getHash(ele[i].key)] = -1;
        N = 0;
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
        ele[N].val=0;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    int& operator [](int x)
    {
        int tmp=fint(x);
        if (tmp==-1)
        {
            insert(x);
            return ele[N-1].val;
        }
        else
            return ele[tmp].val;
    }
};

hash_map color[1000];
int n,m,a[MaxN],len,lazy[1000];
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else
        ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    for (int i = 0;i < 1000;i++)
        color[i].init();
    //n = MaxN,m = MaxN;

    //for (int cas = 1;cas <= 10;cas++)
    while (scanf("%d%d",&n,&m) != EOF)
    {
        len = 110;
        //len = (int)sqrt(1.0*n);

        for (int i = 0;i < 1000;i++)
        {
            lazy[i] = -1;
            color[i].clear();
        }
        for (int i = 0;i < n;i++)
        {
            //a[i] = rand()%1000;
            //scanf("%d",&a[i]);
            a[i] = readint();
            color[i/len][a[i]]++;
        }
        for (int i = 0;i < m;i++)
        {
            int typ,l,r,z;
//            typ = 1+i%2;
//            r = rand()%n;
//            l = rand()%n;
//            if (l > r)  swap(l,r);
//            z = rand()%1000;

            typ = readint();
            l = readint();
            r = readint();
            z = readint();
            if (typ == 1)
            {
                int pl,pr;
                pl = l/len;
                pr = r/len;
                for (int j = pl+1;j < pr;j++)
                {
                    lazy[j] = z;
                    color[j].clear();
                    color[j][z] = len;
                }

                if (pl%len == 0)
                {
                    lazy[pl] = z;
                    color[pl].clear();
                    color[pl][z] = len;
                }
                else
                {
                    color[pl].clear();
                    if (lazy[pl] != -1)
                    {
                        for (int j = pl*len;j < l;j++)
                            a[j] = lazy[pl];
                        color[pl][lazy[pl]] = l-pl*len;
                    }
                    else
                    {
                        for (int j = pl*len;j < l;j++)
                            color[pl][a[j]]++;
                    }

                    lazy[pl] = -1;
                    for (int j = l;j < min(n,(pl+1)*len);j++)
                        a[j] = z;
                    color[pl][z] += min(n,(pl+1)*len)-l;
                }

                if (pr%len == len-1)
                {
                    lazy[pr] = z;
                    color[pr].clear();
                    if ((pr+1)*len < n)
                        color[pr][z] = len;
                    else
                        color[pr][z] = n-pr*len;
                }
                else
                {
                    color[pr].clear();
                    if (lazy[pr] != -1)
                    {
                        for (int j = r+1;j < min(n,(pr+1)*len);j++)
                            a[j] = lazy[pr];
                        color[pr][lazy[pr]] = min(n,(pr+1)*len)-r-1;
                    }
                    else
                    {
                        for (int j = r+1;j < min(n,(pr+1)*len);j++)
                            color[pr][a[j]]++;
                    }

                    lazy[pr] = -1;
                    for (int j = pr*len;j <= r;j++)
                        a[j] = z;
                    color[pr][z] += r+1-pr*len;
                }
            }
            else
            {
                int pl,pr;
                pl = l/len;
                pr = r/len;

                int res = 0;
                for (int j = pl+1;j < pr;j++)
                    res += color[j][z];

                if (pl%len == 0)
                    res += color[pl][z];
                else
                {
                    if (lazy[pl] != -1)
                        res += (lazy[pl] == z)*(min(n,(pl+1)*len)-l);
                    else
                    {
                        for (int j = l;j < min(n,(pl+1)*len);j++)
                            res += (a[j] == z);
                    }
                }

                //cout << "fuck " << res << ' ' << lazy[pl] << ' ' << l << endl;

                if (pr%len == len-1)
                    res += color[pr][z];
                else
                {
                    if (lazy[pr] != -1)
                        res += (lazy[pr] == z)*(r-pr*len+1);
                    else
                    {
                        for (int j = pr*len;j <= r;j++)
                            res += (a[j] == z);
                    }
                }

                cout << pl << ' ' << pr << ' ' << len << ' ' << endl;

                printf("%d\n",res);
            }
        }
    }
	return 0;
}
