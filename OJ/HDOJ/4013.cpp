#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<map>
using namespace std;
const int mod_p = 1000000007;
const int mod_q = 1000000787;
const int con_a = 1234567;
map<int,int> mp;
struct node
{
    int to;
    int next;
};
int ehead[16];
node edge[32];
int L = 0;
void add_edge(int x,int y)
{
    edge[L].to = y;
    edge[L].next = ehead[x];
    ehead[x] = L++;
}

bool vis[16];
int calc(int p,int fa)
{
//printf("vis %d fa =%d\n",p,fa);
    vis[p] = true;
    int arr[16] = {0};
    int al = 0;
    for(int e = ehead[p]; e!= -1; e= edge[e].next)
    {
        if(edge[e].to == fa) continue;
        arr[al++] = calc(edge[e].to,p);
    }
    if(al != 0)
        sort(arr,arr+al);
    int tmp = con_a;
    for(int i = 0 ; i < al ; i++)
        tmp = (((long long)tmp*mod_p)^arr[i])%mod_q;
    return tmp;
}
int conn[16][16];
int n;
bool Gao(int msk)
{
//printf("msk = %d\n",msk);
    L = 0;
    for(int i = 0 ; i < n ; i++)
    {
        ehead[i] = -1;
        vis[i] = 0;
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1; j<n; j++)
            if((msk &(1<<i)) && (msk &(1<<j)) && conn[i][j])
            {
//printf("%d %d added\n",i,j);
                add_edge(i,j);
                add_edge(j,i);
            }
    bool G = false;
// bool ext = false;
    int arr[16];
    int al = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(msk & (1<<i))
        {
            int val = calc(i,-1);
//printf("id = %d val = %d\n",i,val);
            if(mp[val]) return false;
            arr[al++] = val;
            if(G == false)
            {
                G = true;
                for(int j = 0 ; j <n ; j++)
                    if((msk &(1<<j)) && vis[j] == false)
                        return false;
            }
        }
    }
    for(int i = 0 ; i <al ; i++)
        mp[arr[i]] = true;
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ii =1 ; ii<=T; ii++)
    {
        mp.clear();

        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                conn[i][j] = 0;
        for(int i = 0 ; i < n-1; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            --a;
            --b;
            conn[a][b] = conn[b][a] = 1;
        }
        int TOP = (1<<n);
        int ans = 0;
        for(int i = 1 ; i <TOP ; i++)
            if(Gao(i))
            {
                ans++;
            }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
