#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int NMax  =300010;
const int NSIZE = 300010+100;
const int ESIZE = 300010*2+100;
const long long inf = 1LL<<50;
struct node{
	long long key,mn,delta;
	int revmark;
	node *p,*l,*r;
	node(){}
};
node mem[NSIZE];
struct DynamicTree{
	node *nodes;
	int N;
	static void ini_node(node *p){
		p->p=p->l=p->r=NULL;
		p->revmark=0;p->delta=0;p->mn=0;p->key=0;
	}
	static int isroot(node *p){return !p->p || (p->p->l!=p && p->p->r!=p);}
	DynamicTree(int n){
		N=n;
		nodes=mem;
		for (int i=0;i<=n;i++)ini_node(nodes+i);
	}
	static void inc(node *p,long long d){
		p->key+=d;p->mn+=d;p->delta+=d;
	}
	static void rev(node *p){
		swap(p->l,p->r);
		p->revmark^=1;
	}
	static void down(node *p){
		if (p->delta){
			if (p->l)inc(p->l,p->delta);
			if (p->r)inc(p->r,p->delta);
			p->delta=0;
		}
		if (p->revmark){
			if (p->l)rev(p->l);
			if (p->r)rev(p->r);
			p->revmark=0;
		}
	}
	static void update(node *p){
		p->mn=p->key;
		if (p->l && p->l->mn+p->delta>p->mn){p->mn=p->l->mn+p->delta;}
		if (p->r && p->r->mn+p->delta>p->mn){p->mn=p->r->mn+p->delta;}
	}
	static void zig(node *p){
		node *x=p->p,*y=x->p;
		p->p=y;x->p=p;
		if (y){
			if (x==y->l)y->l=p;
			else if (x==y->r)y->r=p;
		}
		x->l=p->r;if (x->l)x->l->p=x;
		p->r=x;
		update(x);
		update(p);
	}
	static void zag(node *p){
		node *x=p->p,*y=x->p;
		p->p=y;x->p=p;
		if (y){
			if (x==y->l)y->l=p;
			else if (x==y->r)y->r=p;
		}
		x->r=p->l;if (x->r)x->r->p=x;
		p->l=x;
		update(x);
		update(p);
	}
	static void Splay(node *p){
		static node *stack[NMax];
		int top=1;
		stack[0]=p;
		for (node *q=p;!isroot(q);)stack[top++]=(q=q->p);
		while (top)down(stack[--top]);
		while (!isroot(p)){
			node *q=p->p;
			if (isroot(q)){
				if (q->l==p)zig(p);
				else zag(p);
			}else{
				if (q==q->p->l){
					if (p==q->l){
						zig(q);zig(p);
					}else{
						zag(p);zig(p);
					}
				}else{
					if (p==q->r){
						zag(q);zag(p);
					}else{
						zig(p);zag(p);
					}
				}
			}
		}
	}
	static node* head(node *p){
        //printf("p_add %d\n",p);
		for (down(p);p->l;p=p->l)down(p);
		Splay(p);
		return p;
	}
	static node *tail(node *p){
		for (down(p);p->r;p=p->r)down(p);
		Splay(p);
		return p;
	}
	static node *prev(node *p){
		Splay(p);
		if (!p->l)return NULL;
		node *q=p->l;
		for (;q->r;q=q->r)down(q);
		Splay(q);
		return q;
	}
	static node *next(node *p){
		Splay(p);
		if (!p->r)return NULL;
		node *q=p->r;
		for (;q->l;q=q->l)down(q);
		Splay(q);
		return q;
	}
    node *Expose(node *p){
		node *q;
		for (q=NULL;p;p=p->p){
           // printf("expose = %d\n",(int)(p-nodes));
			Splay(p);
			p->r=q;
			update(q=p);
			//printf("mv = %d\n",p->mn);

		}
		//puts("end");
		return q;
	}
	static node *Expose2(node *p){
		node *q;
		for (q=NULL;p;p=p->p){
			Splay(p);
			if(p->p == NULL)
                {
                    printf("%I64d\n" , max(max(p->r? p->r->mn:-inf , q? q->mn : -inf)  , p->key+p->delta));
                }
			p->r=q;
			update(q=p);
		}
		return q;
	}
	node *getNode(int id){return id>=1&&id<=N?nodes+id:NULL;}
	int getId(node *p){return p?p-nodes:-1;}
	void Increase(node *p,long long d){
		inc(Expose(p),d);
	}
	void Increase(int id,long long d){Increase(getNode(id),d);}
	static void Change(node *p,long long a){
		Splay(p);
		p->key=a;
		update(p);
	}
	void Change(int id,long long a){Change(getNode(id),a);}
	void ChangeRoot(node *p){
		rev(Expose(p));
	}
	void ChangeRoot(int id){ChangeRoot(getNode(id));}
	static node *getParent(node *p){
		Splay(p);
		if (p->l)return prev(p);
		return p->p;
	}
	int getParent(int id){return getId(getParent(getNode(id)));}
	node *getRoot(node *p){
		return head(Expose(p));
	}
	int getRoot(int id){
        return getId(getRoot(getNode(id)));
	}
	static void Merge(node *p,node *q){
		Splay(q);
		q->p=p;
	}
	void Merge(int p,int q){Merge(getNode(p),getNode(q));}
	static void Cut(node *p){
		Splay(p);
		if (p->l){
			p->l->p=p->p;
			p->p=p->l=NULL;
		}else p->p=NULL;
	}
	void Cut(int id){Cut(getNode(id));}
	node *LCA(node *p,node *q){
		node *x=head(Expose(p));
		node *y=Expose(q),*z=head(y);
		if (x==z)return y;
		return NULL;
	}
	int LCA(int p,int q){return getId(LCA(getNode(p),getNode(q)));}
};
DynamicTree tr = DynamicTree(0);

int ehead[NSIZE] , eto[ESIZE] , enext[ESIZE] ,eval[ESIZE];
int L;

bool vis[NSIZE];
void addedge(int u ,int v ,int c)
    {
        //conn[u].push_back(make_pair(v,c));
        eto[L] = v;
        enext[L] = ehead[u];
        eval[L] = c;
        ehead[u] = L++;
    }
queue< int > que;
void bfs()
    {
        que.push(1);
        vis[1] = true;
        while(!que.empty())
            {
                int x = que.front();
                que.pop();
                for(int e = ehead[x] ; e != -1; e = enext[e])
                    {
                        int y = eto[e];
                        if(vis[y]) continue;
                        vis[y] = true;
                        (tr.nodes+y)->p = tr.nodes+x;
                        //(tr.nodes+y)->key = (tr.nodes+y)->mn = eval[e];
                        que.push(y);
                    }
            }
    }
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    //scanf("%d",&T);
    int pcnt;
    int ca = 0;
    while(scanf("%d",&pcnt) == 1)
        {
            L =0;
            memset(vis,0,sizeof(vis));
            memset(ehead,-1,sizeof(ehead));
            //scanf("%d",&pcnt);
            tr  = DynamicTree(pcnt+1);
            for(int i = 0 ; i< pcnt-1 ; i++)
                {
                    int u ,v,c;
                    scanf("%d%d",&u,&v);
                    //u--;v--;
                    addedge(u,v,c);
                    addedge(v,u,c);
                    //edge.push_back(make_pair(u,v));
                }
            for(int i = 1 ; i <= pcnt;i++)
            {
                long long hi; scanf("%I64d",&hi);
                (tr.nodes+i)->key = (tr.nodes+i)->mn = hi;
            }
            //dfs(1 , 0 , 0);
            bfs();


            int Qn; scanf("%d",&Qn);

            for(int Qi = 0 ;Qi < Qn ;Qi++)
                {
                    int cmd;
                    scanf("%d",&cmd);
                    if(cmd == 1){
                        int x, y;scanf("%d%d",&x,&y);

                        if(tr.getRoot(x) == tr.getRoot(y)){
                            puts("-1");
                            continue;
                        }
                        tr.ChangeRoot(x);
                        tr.ChangeRoot(y);
                        //(tr.nodes+x)->p = tr.nodes+y;
                        tr.Merge(x,y);
                    }else if(cmd == 2){
                        int x, y;scanf("%d%d",&x,&y);


                        if(x == y || (tr.getRoot(x) != tr.getRoot(y))){
                            puts("-1");
                            continue;
                        }

                        tr.ChangeRoot(x);
                        //tr.getParent(y);

                        tr.Cut(y);
                    }else if(cmd == 3){
                        long long w;
                        int x , y; scanf("%I64d%d%d",&w,&x,&y);

                        if(tr.getRoot(x) != tr.getRoot(y)){
                            puts("-1");
                            continue;
                        }
                        int fxy = tr.LCA(x,y);
                        if(tr.getRoot(x) == fxy){
                            tr.Increase(x,w);
                            tr.Increase(y,w);
                            tr.Increase(fxy,-w);
                        }else{
                            tr.Increase(x,w);
                            tr.Increase(y,w);
                            tr.Increase(fxy,-w);
                            tr.Increase(tr.getParent(fxy),-w);
                        }
                    }else if(cmd == 4){
                        int x, y ; scanf("%d%d",&x,&y);

                        if(tr.getRoot(x) != tr.getRoot(y)){
                            puts("-1");
                            continue;
                        }
                        tr.Expose(tr.nodes+x);
                        tr.Expose2(tr.nodes+y);
                    }
                }
            puts("");
            //puts("____________");
        }
	return 0;
}
