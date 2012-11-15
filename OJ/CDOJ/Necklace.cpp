#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int NSIZE = 50010;


long long tree[NSIZE*4];
void push(int p)
    {
        if(tree[p] != 0)
            {
                tree[p*2] += tree[p];
                tree[p*2+1] += tree[p];
                tree[p] = 0;
            }
    }
void add(int p ,int l ,int r, int al ,int ar, long long av)
    {
        if(ar < l) return;
        if(al > r) return;
        if(al <= l && ar >=r)
            {
                tree[p] += av;
                return;
            }
        push(p);
        int mid = (l+r) >> 1;
        add(p*2, l ,mid ,al ,ar, av);
        add(p*2+1, mid+1, r ,al ,ar, av);
    }
long long ask(int p, int l ,int r,long long ap)
    {
        if(l == r)
            {
                return tree[p];
            }
        push(p);
        int mid = (l+ r) >>1;
        if(ap <mid) return ask(p*2, l,mid, ap);
        else if(ap >=mid) return ask(p*2+1, mid+1, r, ap);
    }
vector< pair<int ,int> > v[50010];
//NODE sa[200010*2];
//int L;
long long ans[200010];
int num[50010];

int pre[1000010];

int main()
    {
        int T;
        scanf("%d",&T);
        for(int ii = 0 ;ii<T;ii++)
            {
                memset(pre, - 1, sizeof(pre));
                int n ;
                scanf("%d",&n);
                for(int i = 0 ; i < n ; i++)
                    {
                        scanf("%d",&num[i]);
                        v[i].clear();
                    }
                int M;
                scanf("%d",&M);
                for(int i = 0 ; i < M ;i++)
                    {
                        int l , r; scanf("%d%d",&l,&r);
                        l--; r--;
                        v[r].push_back(make_pair(i , l));
                        //sa[L++] = NODE(i ,r, l);
                    }
//                sort(sa, sa+L);
                int P = 0;
                for(int i = 0 ; i < n; i++)
                    {
                        add(1 , 0 , n-1 ,pre[num[i]] +1 , i , num[i]);
                        for(int x = 0 ; x <v[i].size();x++)
                            ans[v[i][x].first] = ask(1 , 0 ,n-1  ,v[i][x].second);
                    }
                for(int i = 0 ; i<M;i++)
                    printf("%I64d\n",ans[i]);
            }
        return 0;
    }
