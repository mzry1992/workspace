
struct NetWork{
    int n, K;
    const int MAXN = 64*64*2;
    const int MAXM = MAXN*8;
    const int SIZE_QUEUE = 13;
    int mat[64][64];
    int w[MAXN];
    int cost[MAXM]，cap[MAXM];
    int nxt[MAXM], name[MAXM];
    int st[MAXN];
    int nedges;
    int flow[MAXM];
    int sp[MAXN], from[MAXN];
    int oo = 0x7f7f7f7f;
     
    //循环队列
    struct CicleQueue{
        int _data[two(SIZE_QUEUE)];
        int& operator[](int a){
            return _data[a&two(SIZE_QUEUE)-1];
        }
    };
     
    CicleQueue Q;
    bool spfa(int src, int dst, int n){
        bitset<MAXN> mk;
        mk.reset();
        memset(sp,0x3f,(sizeof sp));
        memset(from,-1,(sizeof from));
         
        mk[src] = true;
        sp[src] = 0;
     
        int qs = 0, qe = 1;
        Q[qs] = src;
        for(;qs != qe;){
            int cur = Q[qs++];
            for(int i = st[cur]; i != -1; i = nxt[i] )if( flow[i] ){
                int son = name[i];
                int better = sp[cur] + cost[i];
                if( better < sp[son] ){
                    sp[son] = better;
                    from[son] = i;
                    if( !mk[ son ] ){
                        mk[son] = true;
                        Q[qe++] = son;
                    }
                }
            }
            mk[cur] = false;
        }
            //判断是否找到了一条最短路
        return from[dst] != -1;
    }
     
    int min_cost_max_flow(int src, int dst, int n){
        int maxflow = 0, mincost = 0;
        for(;;){
            if( !spfa(src, dst, n)){
                return mincost ;
            }
            int aug = oo;
            for(int i = from[dst]; i != -1; i = from[name[i^1]] ){
                checkMin( aug, flow[i] );
            }
            if( !aug ) return mincost;
     
            maxflow += aug;
            mincost += sp[dst] * aug;
            for(int i = from[dst]; i != -1; i = from[name[i^1]] ){
                flow[i] -= aug;
                flow[i^1] += aug;
            }
        }
        return mincost;
    }
     
    void init_edge(){
        memset(nxt,-1,(sizeof nxt));
        memset(st,-1,(sizeof st));
         
        nedges = 0;
    }
    void add_edge(int a, int b, int w, int c){
        cap[nedges] = w;
        cost[nedges] = c;
        name[nedges] = b;
        nxt[nedges] = st[a];
        st[a] = nedges;
        nedges++;
    }
}
