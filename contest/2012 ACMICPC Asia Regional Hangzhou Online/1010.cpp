#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int n,L;
int posnum[20005];
long long pos[20005];
int outp[7]={1,2,4,3,5,6,7};
long long res[1<<3];
map<char,int> mp;
struct N
{
    int x,y1,y2;
    int col;
}rect[20005];
struct ANS
{
    int len[1<<3];
    int times[3];
}tree[20000*4];
bool cmp(N k1,N k2)
{
    if(k1.x==k2.x)
        return k1.col<k2.col;
    return k1.x<k2.x;
}
void build(int x,int l,int r)
{
    for (int i=0;i<3;i++)
        tree[x].times[i]=0;
    for (int i=1;i<8;i++)
        tree[x].len[i]=0;
    tree[x].len[0]=pos[r]-pos[l];
    if (l<r-1)
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid,r);
    }
}
void init()
{
    build(1,0,L-1);
}
void update(int x,int l,int r,int s,int t,int c)
{
    if (s<=l && r<=t)
    {
        if (c>0)
            tree[x].times[c-1]++;
        else
            tree[x].times[-c-1]--;
        return ;
    }
    int mid=l+r>>1;
    if (s<mid)
        update(x*2,l,mid,s,t,c);
    if (t>mid)
        update(x*2+1,mid,r,s,t,c);
    for (int i=0;i<8;i++)
        tree[x].len[i]=0;
    for (int i=0;i<8;i++)
    {
        int k=i;
        for (int j=0;j<3;j++)
            if (tree[x*2].times[j])
                k|=1<<j;
        tree[x].len[k]+=tree[x*2].len[i];
        k=i;
        for (int j=0;j<3;j++)
            if (tree[x*2+1].times[j])
                k|=1<<j;
        tree[x].len[k]+=tree[x*2+1].len[i];
    }
}
void update(int s,int t,int c)
{
    update(1,0,L-1,s,t,c);
}
ANS query()
{
    ANS ret;
    for (int i=1;i<8;i++)
        ret.len[i]=0;
    for (int i=0;i<8;i++)
    {
        int k=i;
        for (int j=0;j<3;j++)
            if (tree[1].times[j])
                k|=1<<j;
        ret.len[k]+=tree[1].len[i];
    }
    return ret;
}
int main()
{
    mp['R']=1;mp['G']=2;mp['B']=3;
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int i;
	    int x1,x2,y1,y2;
	    char ch[3];
	    for(i=0;i<n;i++)
	    {
	        scanf("%s%d%d%d%d",ch,&x1,&y1,&x2,&y2);
	        rect[i*2].x=x1;
	        rect[i*2].y1=y1;
	        rect[i*2].y2=y2;
            rect[i*2].col=mp[ch[0]];

            rect[i*2+1].x=x2;
            rect[i*2+1].y1=y1;
	        rect[i*2+1].y2=y2;
            rect[i*2+1].col=-mp[ch[0]];

            posnum[i*2]=y1;
            posnum[i*2+1]=y2;
	    }
	    sort(posnum,posnum+2*n);
	    L=0;
	    posnum[L++]=posnum[0];
	    for(i=1;i<2*n;i++)
            if(posnum[i]!=posnum[i-1])
                posnum[L++]=posnum[i];
        //for(i=0;i<L;i++)
        //    printf("%d ",posnum[i]);
        //puts("");
        for(i=0;i<2*n;i++)
        {
            int l,r,mid;
            l=0;r=L-1;mid=l+r>>1;
            while(l<r)
            {
                mid=l+r>>1;
                if(rect[i].y1>posnum[mid])
                    l=mid+1;
                else
                    r=mid;
            }
            pos[r]=rect[i].y1;
            rect[i].y1=r;

            l=0;r=L-1;mid=l+r>>1;
            while(l<r)
            {
                mid=l+r>>1;
                if(rect[i].y2>posnum[mid])
                    l=mid+1;
                else
                    r=mid;
            }
            pos[r]=rect[i].y2;
            rect[i].y2=r;
        }
        sort(rect,rect+2*n,cmp);
        init();
        memset(res,0,sizeof(res));
        update(rect[0].y1,rect[0].y2,rect[0].col);
        for(i=1;i<2*n;i++)
        {
            long long d=rect[i].x-rect[i-1].x;
            ANS ret=query();
            int j;
            for(j=1;j<8;j++)
                res[j]+=d*ret.len[j];//,printf("%lld ",res[j]);
            update(rect[i].y1,rect[i].y2,rect[i].col);
        }
        printf("Case %d:\n",cas++);
        for(i=0;i<7;i++)
            printf("%I64d\n",res[outp[i]]);
	}
	return 0;
}
