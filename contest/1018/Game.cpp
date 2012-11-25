#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int TOP = 100010;
vector<int> fact[TOP];
struct hash_map
{
    const static int mod=10007;
    int head[mod];
    struct hash_tables
    {
        int key;
        int next;
    } ele[100010];
    int N;
    void init()
    {
        N=0;
        memset(head,255,sizeof(head));
    }
    void clear()
    {
        memset(head,255,sizeof(head));
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
        if (fint(x)!=-1)
            return ;
        ele[N].key=x;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
}tree;
int main(){
    for(int i = 1 ;i <TOP;i++){
        for(int j = 1; j*j <=i ;j++){
            if(i%j != 0) continue;
            int l = j , r = i/j;
            fact[i].push_back(l);
            if(l!=r) fact[i].push_back(r);
        }
    }
    int N ,ans = 0;
    scanf("%d",&N);
    for(int A = 1; A<=N; A++){
        tree.clear();
        for(int x = 1;A*x<=N;x++){
            int By = N - A*x;
            if(tree.fint(By)==-1){
                for(int i = 0 ; i < fact[By].size() ; i++)
                    if(fact[By][i] > A)
                        tree.insert(fact[By][i]);
            }
        }
        ans += tree.N;
    }
    printf("%d\n",ans);
    return 0;
}
