#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define abs(a) (a)>0?(a):-(a)
using namespace std;
typedef struct sss{int astar,f,xpos,numth;char a[9];}sb;   //��¼��չ״̬
int step[370000],f[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4]={1,-1,3,-3};
struct cmp
{
    bool operator()(const sb &t1,const sb &t2)
    {
        return t1.f>t2.f;
    }
};    //���ȶ��е�������
int as(sb l)
{
    int ans=0;
    for(int i=0;i<9;i++)
    ans+=abs(i/3-(l.a[i]-49)/3)+abs(i%3-(l.a[i]-49)%3);
    return ans;
}      //��ǰ�㵽Ŀ��̬�Ĺ�ֵ
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
}   //����չ��
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
        }    //����ʱ���ǽ�x�����9
        int num=0;
        for(int i=1;i<9;i++)
        {
            if(zt.a[i]=='9')continue;
            for(int j=0;j<i;j++)
            if(zt.a[j]!='9'&&zt.a[i]<zt.a[j])num++;
        }    //��������
        if(num%2)
        {
            printf("unsolvable\n");
            continue;
        }
        zt.astar=as(zt);
        zt.f=zt.astar+2;    //ÿת��һ����g(n)=2,�������ܱ�֤h(n1)-h(n2)<=c(n1,n2)
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
