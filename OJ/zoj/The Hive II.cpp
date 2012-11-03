#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct hash_map
{
    const static int mod=1007;
    int head[mod];
    struct hash_tables
    {
        int key;
        long long val;
        int next;
    } ele[50000];
    int N;
    int getHash(int x)
    {
        return x%mod;
    }
    void clear()
    {
        memset(head,255,sizeof(head));
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
    long long& operator [](int x)
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

int bit[18];

inline int getbit(int sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline int setbit(int sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

/*
      +-+     +-+     +-+     +-+
     /   \   /   \   /   \   /   \
  +-+     +-+     +-+     +-+     +
 /   \   /   \   /   \   /   \   /
+     +-+     +-+     +-+     +-+
 \   /   \   /   \   /   \   /   \
  +-+     +-+     +-+     +-+     +
 /   \   /   \   /   \   /   \   /
+     +-+     +-+     +-+     +-+
 \   /   \   /   \   /   \   /
  +-+     +-+     +-+     +-+
*/

const int ppos[2][4][3] = {{{2,3,4},{6,7,8},{10,11,12},{14,15,16}},
    {{0,1,2},{4,5,6},{8,9,10},{12,13,14}}
};
const int mpos[2][4] = {{1,3,5,7},{0,2,4,6}};

hash_map dp[2];
bool flag;

int n,m;
bool mp[11][8];

int msk,upd,sta[17],s[17],top,w[17],cnt;
long long val;

inline void update(int a,int sta,long long val)
{
    /*printf("     update : sta = ");
    for (int x = 0; x < 17; x++)
        printf("%d",getbit(sta,x));
    printf(" %lld\n",val);*/
    dp[a][sta] += val;
}

int main()
{
    bit[0] = 1;
    for (int i = 1; i < 18; i++)
        bit[i] = bit[i-1]*3;
    flag = 0;

    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(mp,false,sizeof(mp));
        for (int i = 0; i < m; i++)
        {
            char ta,tb;
            scanf(" %c%c",&ta,&tb);
            mp[ta-'A'][tb-'A'] = true;
        }
        dp[flag].clear();
        dp[flag][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 4; k++,flag = !flag)
                {
                    dp[!flag].clear();
                    //cout << i << ' ' << mpos[j][k] << ' ' << dp[flag].N << endl;
                    for (int ele = 0; ele < dp[flag].N; ele++)
                    {
                        msk = dp[flag].ele[ele].key;
                        val = dp[flag].ele[ele].val;
                        //printf("now = [%2d,%2d] sta = ",i,mpos[j][k]);
                        for (int x = 0; x < 17; x++)
                        {
                            sta[x] = getbit(msk,x);
                            //printf("%d",sta[x]);
                        }

                        cnt = 0;
                        for (int x = 0; x < 3; x++)
                            if (sta[ppos[j][k][x]] > 0)
                                cnt++;
                        //printf(" %lld cnt = %d\n",val,cnt);

                        if (sta[0] != 0 || sta[16] != 0)    continue;
                        if (mp[i][mpos[j][k]] == true)
                        {
                            if (cnt == 0)
                                update(!flag,msk,val);
                        }
                        else
                        {
                            upd = msk;
                            for (int x = 0; x < 3; x++)
                                upd = setbit(upd,ppos[j][k][x],0);
                            if (cnt == 0)
                            {
                                for (int x = 0; x < 3; x++)
                                    for (int y = x+1; y < 3; y++)
                                        update(!flag,setbit(setbit(upd,ppos[j][k][x],1),ppos[j][k][y],1),val);
                            }
                            else if (cnt == 1)
                            {
                                for (int x = 0; x < 3; x++)
                                    if (sta[ppos[j][k][x]] != 0)
                                        for (int y = 0; y < 3; y++)
                                            update(!flag,setbit(upd,ppos[j][k][y],sta[ppos[j][k][x]]),val);
                            }
                            else if (cnt == 2)
                            {
                                for (int x = 0; x < 3; x++)
                                    if (sta[ppos[j][k][x]] != 0)
                                        for (int y = x+1; y < 3; y++)
                                            if (sta[ppos[j][k][y]] != 0)
                                                    update(!flag,upd,val);
                            }
                        }
                    }
                }
        long long res = 0;
        for (int ele = 0; ele < dp[flag].N; ele++)
        {
            msk = dp[flag].ele[ele].key;
            val = dp[flag].ele[ele].val;
            cnt = 0;
            for (int i = 0; i < 17; i++)
            {
                sta[i] = getbit(msk,i);
                if (sta[i] > 0)
                    cnt++;
            }
            if (cnt == 0)
                res += val;
        }
        cout << res << endl;
    }
    return 0;
}
