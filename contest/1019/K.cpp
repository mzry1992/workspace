#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define NMax 1000
using namespace std;
struct node{
    int key , mn , delta;
    int revmark;
    node *p ,*l,*r;
    node *mnpos;
    node(){}
};
node mem[10010];
struct DynamicTree{
    node *nodes;
    int N;
    static void ini_node(node *p){
        p->p = p->l= p->r = NULL;
        p->revmark = 0;
        p->delta = 0;
        p->mn = 0;
        p->key = 0;
        p->mnpos = p;
        p->size = 1;
    }
    static int isroot(node *p){
        return !p->p || (p->p->l!=p && p->p->r!=p);
    }
    DynamicTree(int n){
        N = n;
        nodes = mem;
        for(int i = 0 ;i <= n ;i++)
            ini_node(nodes+i);
    }
    static void inc(node *p ,int d){
        p->key +=d;
        p->mn += d;
        p->delta +=d;
    }
    static void rev(node *p){
        swap(p->l,p->r);
        p->revmark^=1;
    }
    static void down(node *p){
        if(p->delta){
            if(p->l)inc(p->l,p->delta);
            if(p->r)inc(p->r,p->delta);
            p->delta = 0;
        }
        if(p->revmark){
            if(p->l) rev(p->l);
            if(p->r) rev(p->r);
            p->revmark = 0;
        }
    }
    static void update(node *p){
        p->mn = p->key;
        p->mnpos = p;
        p->size = 1;
        if(p->l)
            p->size += p->l->size;
        if(p->r)
            p->size += p->r->size;
        if(p->l && p->l->mn+p->delta>p->mn)
            {
                p->mn = p->l->mn + p->delta;
                p->mnpos = p->l->mnpos;
            }
        if(p->r && p->r->mn+p->delta>p->mn){
            p->mn = p->r->mn+p->delta;
            p->mnpos = p->r->mnpos;
        }

    }
    static void zig(node *p){
        node *x = p->p, *y = x->p;
        p->p = y; x->p = p;
        if(y){
            if(x == y->l) y->l = p;
            else if(x == y->r) y->r = p;
        }
        x->l = p->r;
        if(x->l) x->l->p=x;
        p->r=x;
        update(x);
        update(p);
    }
    static void zag(node *p){
        node *x = p->p, *y = x->p;
        p->p = y; x->p = p;
        if(y){
            if(x == y->l) y->l = p;
            else if(x == y->r) y->r = p;
        }
        x->r = p->l;
        if(x->r) x->r->p=x;
        p->l=x;
        update(x);
        update(p);
    }
    static void Splay(node *p){
        static node *stack[NMax];
        int top = 1;
        stack[0] = p;
        for(node *q=p;!isroot(q);)
            stack[top++] = (q=q->p);
        while(top) down(stack[--top]);
        while(!isroot(p)){
            node *q = p->p;
            if(isroot(q)){
                if(q->l ==p) zig(p);
                else zag(p);
            }else{
                if(q == q->p->l){
                    if(p==q->l){
                        zig(q);zig(p);
                    }else{
                        zag(p);zig(p);
                    }
                }else{
                    if(p == q->r){
                        zag(q);zag(p);
                    }else{
                        zig(p);zag(p);
                    }

                }
            }
        }
    }
    static node* head(node *p){
        for(down(p); p->l;p=p->l) down(p);
        Splay(p);
        return p;
    }
    static node* tail(node *p){
        for(down(p);p->r;p=p->r)down(p);
        Splay(p);
        return p;
    }
    static node *Expose(node *p){
        node *q;
        for(q = NULL ;p;p=p->p){
            Splay(p);
            p->r =q;
            update(q=p);
        }
        return q;
    }
    node *getNode(int id){
        return id>=1 && id<=N?nodes+id:NULL;
    }
    int getID(node *p){
        return p?p-nodes:-1;
    }
    static int AskMinPos(node *p){
        return getID(Expose(p)->mnpos);
    }
    int AskMin(int id){
        return AskMin(getNode(id));
    }
    static void Change(node *p,int a){
        Splay(p);
        p->key = a;
        update(p);
    }
    void Change(int id,int a){
        Change(getNode(id),a);
    }
    static void ChangeRoot(node *p){
        rev(Expose(p));
    }
    void ChangeRoot(int id){
        ChangeRoot(getNode(id));
    }
    void Merge(int p ,int q){
        Merge(getNode(p) , getNode(q));
    }
    static void Cut(node *p){
        Splay(p);
        if(p->l){
            p->l->p = p->p;
            p->p= p->l=NULL;
        }else p->p = NUL;
    }
    void Cut(int id){Cut(getNode(id));}
    static node *LCA(node *p , node *q){
        node *x = head(Expose(p));
        node *y = Expose(q) , *z=head(y);
        if(x == z) return y;
        return NULL;
    }
    int LCA(int p ,int q){
        return getID(LCA(getNode(p) , getNode(q)));
    }
    static node *getRoot(node *p){
        return head(Expose(p));
    }

    int getRoot(int id){return getID(getRoot(getNode(id)));}
    int getSize(int id){
        return getNode(getRoot(id))->size;
    }
};
DynamicTree tr = DynamicTree(0);
bool ext[210][210];
int main(){
    int n , m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i< n ;i++){
        scanf("%d",&val[i]);
        val[i]*=24;
    }
    for(int i = 0 ; i < m;i++){
        int l ,r ,v;
        scanf("%d%d%d",&l,&r,&v);
        if(tr.getRoot(l) != tr.getRoot(r)){
            tr.Merge(l,r);
            ans += v;
            puts("-1");
            continue;
        }
        tr.Expose(nodes+l);
        node *r = tr.getEdge(nodes+r);
        if(r->key > v) {
            ans -= r->key;
            tr.Cut(tr.getID(r));
            tr.ChangeRoot(l);
            tr.ChangeRoot(r);
            tr.Merge(l,r);
            ans += v;
        }
        if(tr.getSize(l) != n){
            puts("-1");
            continue;
        }
        printf("%.2f\n",ans/24.0);
    }
}
