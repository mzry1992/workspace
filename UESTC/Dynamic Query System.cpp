#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;
char com[10];
int x;
const int inf=~0U>>1;
struct node
{
	int key,size,num,sum;
	node*c[2];
	node(int _key,int _size,int _num,int _sum,node*_c)
	:key(_key),size(_size),num(_num),sum(_sum)
	{c[0]=c[1]=_c;}
	void rz(){size=c[0]->size+c[1]->size+1;sum=c[0]->sum+c[1]->sum+num;}
}TNull(0,0,0,0,0),*Null=&TNull;
class SBT
{
	node*root;
	int top;
	void rot(node*&t,bool d)
	{
		node*p=t->c[d];
		t->c[d]=p->c[!d];
		p->c[!d]=t;
		t->rz();p->rz();
		t=p;
	}
	void maintain(node*&t,bool d)
	{
		if(t==Null) return;
		node*p=t->c[d];
		if(p->c[d]->size>t->c[!d]->size)
			rot(t,d);
		else if(p->c[!d]->size>t->c[!d]->size)
			{
				rot(p,!d);
				rot(t,d);
			}
		else return;
		maintain(t->c[0],0);
		maintain(t->c[1],1);
		maintain(t,0);
		maintain(t,1);
	}
	void insert(node*&t,int x)
	{
		if(t==Null)
		{t=new node(x,1,1,1,Null);return;}
		if(t->key==x)
		{
		    t->num++;
		    t->rz();
		    return;
		}
		bool d=x>t->key;
		insert(t->c[d],x);
		maintain(t,d);
		t->rz();
	}
	void remove(node*&t,int x)
	{
		if(t==Null) return;
		int d;
		if(t->key==x)
		{
		    if (t->num > 1) t->num--;
		    else
		    {
                if(t->c[1]==Null)
                {delete t;t=t->c[0];return;}
                if(t->c[0]==Null)
                {delete t;t=t->c[1];return;}
                node*p=t->c[1];while(p->c[0]!=Null)p=p->c[0];
                t->key=p->key;
                remove(t->c[1],p->key);d=1;
		    }
		}
		else
		{
			d=x>t->key;
			remove(t->c[d],x);
		}
		maintain(t,1-d);
		t->rz();
	}
	int select(node*t,int k)
	{
		int r=t->c[0]->size;
		if(k==r) return t->key;
		if(k<r) return select(t->c[0],k);
		return select(t->c[1],k-r-1);
	}
	int rank(node*t,int x)
	{
		int r=t->c[0]->size;
		if(x==t->key) return r;
		if(x<t->key) return rank(t->c[0],x);
		return r+1+rank(t->c[1],x);
	}
	int lessthan(node*t,int x)
	{
		int r=t->c[0]->sum;
		if(x==t->key) return r;
		if(x<t->key) return lessthan(t->c[0],x);
		return r+1+lessthan(t->c[1],x);
	}
	int getmax(node*t)
	{
	    if (t != null)
        	if( root )
	{
		MaxOutput(root->right);
		printf("%d ",root->data);
		MaxOutput(root->left);
	}
	}
	public:
	SBT()
	{
		Null->c[0]=Null->c[1]=Null;
	 	root=Null;
	}
	void Insert(int x)
	{
		insert(root,x);
	}
	void Remove(int x)
	{
		remove(root,x);
	}
	int Select(int k)
	{
		if(k>root->size) return inf;
		return select(root,k-1);
	}
	int Rank(int x)
	{
		return rank(root,x);
	}
	int getMax()
	{
	    getmax(root);
	}
	int size(){return root->size;}
	int sum(){return root->sum;}
	int Lessthan(int x)
	{
	    if (x > getMax())   return sum();
	    return lessthan(root,x);
	}
};


int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        SBT *T=new SBT;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",com);
            if (strcmp(com,"I") == 0)//插入
            {
                scanf("%d",&x);
                T->Insert(x);
            }
            else if (strcmp(com,"R") == 0)//删除
            {
                scanf("%d",&x);
                T->Remove(x);
            }
            else if (strcmp(com,"S") == 0)//求size
            {
                printf("%d\n",T->sum());
            }
            else if (strcmp(com,"L") == 0)//求<X的个数
            {
                scanf("%d",&x);
                printf("%d\n",T->Lessthan(x));
            }
            else if (strcmp(com,"W") == 0)//求第k大
            {
                scanf("%d",&x);
                int tmp=T->Select(x);
                if(tmp==inf) printf("-1\n");
                else printf("%d\n",tmp);
            }
            else if (strcmp(com,"W") == 0)//求x的个数
            {
                scanf("%d",&x);
            }
            else if (strcmp(com,"MI") == 0)//getmin
            {

            }
            else if (strcmp(com,"MA") == 0)//getmax
            {

            }
        }
    }
}
