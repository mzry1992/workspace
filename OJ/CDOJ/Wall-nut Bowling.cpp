#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

template<typename Type>
struct SBNode{
    int   size;
    Type  key;
    SBNode<Type>* lchild, *rchild;
    SBNode(){}
    SBNode( SBNode<Type>*l, SBNode<Type>*r, int s, Type k ):
        lchild(l), rchild(r), size(s), key(k) {}
};

template<typename Type>
class SBTree{
    private:
        SBNode<Type>* root;
        SBNode<Type>* _null;

        void left_rotate ( SBNode<Type>*& root );
        void right_rotate( SBNode<Type>*& root );
        void maintain( SBNode<Type>*& root, bool style );
        void insert( SBNode<Type>*& root, Type key );
        void erase ( SBNode<Type>*& root, Type key );
        void clear ( SBNode<Type>* root );
        void travel( SBNode<Type>* root );

    public:
        SBTree ();
        ~SBTree();

        void insert( Type key );       //  插入元素
        void erase ( Type key );       //  删除元素
        Type get_rank( int k  );       //  获得第 k 个元素
        Type get_min();                //  获得最小元素
        Type get_max();                //  获得最大元素
        void clear();                  //  清空
        void travel();                 //  遍历
};

template<typename Type>
Type SBTree<Type>::get_rank( int k ){
    SBNode<Type>* tmp= root;
	while(true)
	{
		if(tmp->lchild&&tmp->lchild->size+1==k) break;
		else if(tmp->lchild&&k<=tmp->lchild->size) tmp=tmp->lchild;
		else
		{
			k=k-(tmp->lchild?tmp->lchild->size:0)-1;
			tmp=tmp->rchild;
		}
	}
    return tmp->key;
}

template<typename Type>
void SBTree<Type>::clear( SBNode<Type>* root ){
    if( root!= _null ){
        clear( root->lchild );
        clear( root->rchild );
        delete root; }
}

template<typename Type>
void SBTree<Type>::clear(){
    clear(root); delete _null; }

template<typename Type>
void SBTree<Type>::travel( SBNode<Type>* root ){
    if( root!= _null ){
        travel( root->lchild );
        cout << root->key << "  ";
        travel( root->rchild ); }
}

template<typename Type>
void SBTree<Type>::travel(){
    travel( root ); }

template<typename Type>
Type SBTree<Type>::get_min(){
    if( root== _null ) return Type(-1,-1,-1);
    SBNode<Type>* tmp= root;
    while( tmp->lchild!= _null ) tmp= tmp->lchild;
    return tmp->key;
}

template<typename Type>
Type SBTree<Type>::get_max(){
    if( root== _null ) return Type();
    SBNode<Type>* tmp= root;
    while( tmp->rchild!= _null ) tmp= tmp->rchild;
    return tmp->key;
}

template<typename Type>
void SBTree<Type>::erase( Type key ){
    erase( root, key ); }

template<typename Type>
void SBTree<Type>::erase( SBNode<Type>*& root, Type key ){
    if( root== _null ) return;    root->size--;
    if( root->key== key ){
        SBNode<Type>* tmp;
        if( root->lchild!= _null && root->rchild== _null ){
            tmp= root;  root= tmp->lchild; delete tmp; }
        else if( root->lchild== _null && root->rchild== _null ){
            tmp= root; root= _null; delete tmp; }
        else {
            tmp= root->rchild;
            while( tmp->lchild!= _null ) tmp= tmp->lchild;
            root->key= tmp->key; erase( root->rchild, tmp->key );}
    }
    else if( key< root->key ) erase( root->lchild, key );
    else erase( root->rchild, key );
}

template<typename Type>
void SBTree<Type>::insert( SBNode<Type>*& root, Type key ){
    if( root== _null ){
     root= new SBNode<Type>( _null, _null, 1, key ); return; }
    root->size++;
    if( key< root->key ) insert( root->lchild, key );
    else if( key> root->key)                insert( root->rchild, key );
    else
        root->key->sum++;
    maintain( root, key>= root->key );
}

template<typename Type>
void SBTree<Type>::insert( Type key ){
    insert( root, key ); }

template<typename Type>
SBTree<Type>::SBTree(){
    _null= new SBNode<Type>();
    root= _null;
    root->lchild= root->rchild= _null;
    root->size= 0;
}

template<typename Type>
SBTree<Type>::~SBTree(){
    clear();
}

template<typename Type>
void SBTree<Type>::left_rotate( SBNode<Type>*& root ){
    SBNode<Type>* tmp= root->rchild;
    root->rchild= tmp->lchild;  tmp->lchild= root;
    tmp->size= root->size;
    root->size= root->lchild->size+ root->rchild->size+ 1;
    root= tmp;
}

template<typename Type>
void SBTree<Type>::right_rotate( SBNode<Type>*& root ){
    SBNode<Type>* tmp= root->lchild;
    root->lchild= tmp->rchild;  tmp->rchild= root;
    tmp->size= root->size;
    root->size= root->lchild->size+ root->rchild->size+ 1;
    root= tmp;
}

template<typename Type>
void SBTree<Type>::maintain( SBNode<Type>*& root, bool style ){
    if( root== _null ) return;
    if( !style ){
        if( root->lchild->lchild->size> root->rchild->size )
        right_rotate( root );
        else if( root->lchild->rchild->size> root->rchild->size ){
            left_rotate( root->lchild );
            right_rotate( root );
           }else return;
        }
    else {
        if( root->rchild->rchild->size> root->lchild->size )
        left_rotate( root );
        else if( root->rchild->lchild->size> root->lchild->size ){
            right_rotate( root->rchild );
            left_rotate( root );
        }else return;
    }
   maintain(root->lchild, false);  maintain(root->rchild, true);
   maintain(root, false);          maintain(root, true);
}

struct node
{
    int key,sum,pos;
    bool operator < (const node &a) const
    {
        return key < a.key;
    }
    node(int _key,int _sum,int _pos)
    {
        key = _key;
        sum = _sum;
        pos = _pos;
    }
};
SBTree<node> rootH[2010],rootX1[200010],rootX2[200010];
int n,m,k,maxx;
struct zomb
{
    int x,y;
    int x1,x2;
}z[200100];
int tx1[200100],tx2[200100];
int ls1[200100],ls2[200100];
int totx1,totx2;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        maxx = 0;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&z[i].x,&z[i].y);
            maxx = max(z[i].x,maxx);
        }
        for (int i = 1;i <= m;i++)
        {
            z[i].x1 = z[i].x+z[i].y;
            z[i].x2 = z[i].y-z[i].x+maxx;
            tx1[i] = z[i].x1;
            tx2[i] = z[i].x2;
        }
        sort(tx1+1,tx1+1+m);
        sort(tx2+1,tx2+1+m);
        totx1 = totx2 = 1;
        ls1[1] = tx1[1];
        ls2[1] = tx2[1];
        for (int i = 2;i <= m;i++)
        {
            if (tx1[i] != tx1[i-1])
            {
                totx1++;
                ls1[totx1] = tx1[i];
            }
            if (tx2[i] != tx2[i-1])
            {
                totx2++;
                ls2[totx2] = tx2[i];
            }
        }
        for (int i = 1;i <= m;i++)
        {
            int *pos = lower_bound(ls1+1,ls1+1+totx1,z[i].x1);
            z[i].x1 = (int)(pos-ls1);
            pos = lower_bound(ls2+1,ls2+1+totx2,z[i].x2);
            z[i].x2 = (int)(pos-ls2);
        }
        for (int i = 1;i <= n;i++)      rootH[i].clear();
        for (int i = 1;i <= totx1;i++)  rootX1[i].clear();
        for (int i = 1;i <= totx2;i++)  rootX2[i].clear();
        for (int i = 1;i <= m;i++)
        {
            rootH[z[i].y].insert(node(z[i].x,1,i));
            rootX1[z[i].x1].insert(node(z[i].x2,1,i));
            rootX2[z[i].x2].insert(node(z[i].x1,1,i));
        }
        int res = 0;
        for (int i = 1;i <= k;i++)
        {
            int c;
            scanf("%d",&c);
            node temp = rootH[c].get_min();
            cout << temp.key << ' ' << temp.sum << ' ' << temp.pos << endl;
        }
    }
}
