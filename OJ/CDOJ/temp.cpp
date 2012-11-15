#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define abs(a) (a)>0?(a):-(a)
using namespace std;
typedef struct sss{int astar,f,xpos,numth;char a[9];}sb;   //记录扩展状态
int step[370000],f[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4]={1,-1,3,-3};
struct cmp
{
    bool operator()(const sb &t1,const sb &t2)
    {
        return t1.f>t2.f;
    }
};    //优先队列的排序函数
int as(sb l)
{
    int ans=0;
    for(int i=0;i<9;i++)
    ans+=abs(i/3-(l.a[i]-49)/3)+abs(i%3-(l.a[i]-49)%3);
    return ans;
}      //求当前点到目标态的估值
int kangtuo(sb l)
{
    int ans=1;
    for(int i=0;i<9;i++)
    {
        int temp=l.a[i]-49;
        for(int j=0;j<i;j++)
        {
            if(l.a[j]<l.a[i])
            temp--;
        }
        ans+=temp*f[8-i];
    }
    return ans;
}   //康托展开
int main()
{
    sb zt;
    char ch[100];
    while(gets(ch))
    {
        int len=strlen(ch),ppp=0;
        for(int i=0;i<len;i++)
        {
            if(ch[i]=='x')
            {zt.a[ppp]='9';zt.xpos=ppp++;}
            if(ch[i]>'0'&&ch[i]<'9')
            zt.a[ppp++]=ch[i];
        }    //输入时我是将x处理成9
        int num=0;
        for(int i=1;i<9;i++)
        {
            if(zt.a[i]=='9')continue;
            for(int j=0;j<i;j++)
            if(zt.a[j]!='9'&&zt.a[i]<zt.a[j])num++;
        }    //求逆序数
        if(num%2)
        {
            printf("unsolvable\n");
            continue;
        }
        zt.astar=as(zt);
        zt.f=zt.astar+2;    //每转移一步，g(n)=2,这样才能保证h(n1)-h(n2)<=c(n1,n2)
        zt.numth=kangtuo(zt);
        for(int i=0;i<370000;i++)
        step[i]=0;
        step[zt.numth]=2;
        priority_queue<sb,vector<sb>,cmp> Q;
        Q.push(zt);
        while(!Q.empty())
        {
            zt=Q.top();
            Q.pop();
            if(zt.astar==0)
            break;
            for(int i=0;i<4;i++)
            {
                if(i==0&&zt.xpos%3==2)continue;
                if(i==1&&zt.xpos%3==0)continue;
                sb temp=zt;
                temp.xpos=zt.xpos+dir[i];
                if(temp.xpos>=0&&temp.xpos<9)
                {
                    temp.a[zt.xpos]=zt.a[temp.xpos];
                    temp.a[temp.xpos]='9';
                    int th=kangtuo(temp);
                    if(step[th]==0||step[th]>step[zt.numth]+2)
                    {
                        step[th]=step[zt.numth]+2;
                        temp.numth=th;
                        temp.astar=as(temp);
                        temp.f=temp.astar+step[th];
                        Q.push(temp);
                    }
                }
            }
        }
        printf("%d\n",(step[1]-2)/2);
    }
}
