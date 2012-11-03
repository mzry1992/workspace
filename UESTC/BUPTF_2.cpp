#include<stdio.h> 
#include<iostream> 
#include<algorithm> 
using namespace std; 
const int inf=0x3fffffff; 
struct node{     int num,w; }dp1[1<<20],dp2[1<<20]; 
int a[44],start[22],end[22]; 
bool cmp1(const node a,const node b)
{     if(a.w==b.w)
    	return a.num<b.num;     return a.w<b.w; } 
bool cmp2(const node a,const node b)
{     if(a.num==b.num)
    	return a.w<b.w;     return a.num<b.num; } 
int find(int l,int h,int lim)
{     int low=l,high=h,mid,ans=0;     while(low<=high)
    {         mid=(low+high)>>1;         if(dp2[mid].w<=lim)
        {
       		ans=dp2[mid].w;
       		low=mid+1;
       	}         else 
        	high=mid-1;     }
         return ans; } int main()
{     int n,m,i,left,right,j,k,pre,lim,temp,res,M;     while(scanf("%d%d",&n,&m)!=EOF)
    {         scanf("%d",&k);         for(i=0;i<k;i++)
        	scanf("%d",&a[i]);
        //拆分成两个数组，每组最多20个，这样是2^20的枚举加二分
        //dp的下标用来记录拿了那些物品，每组总共20个，用20位二进制表示         left=k/2;         right=k-left;         for(i=0;i<(1<<left);i++)
        {             dp1[i].num=dp1[i].w=0;             for(j=0;j<left;j++)                 if(i&(1<<j))	//第j个物品已经拿过
                {
                	dp1[i].w+=a[j];
                	dp1[i].num++;
                }         }         for(i=0;i<(1<<right);i++)
        {             dp2[i].num=dp2[i].w=0;             for(j=0;j<right;j++)                 if(i&(1<<j))
                {
                	dp2[i].w+=a[j+left];
                	dp2[i].num++;
                }         }

        //两个背包，第一个对重量排序，另外一个对数量排序         sort(dp1,dp1+(1<<left),cmp1);         sort(dp2,dp2+(1<<right),cmp2);
                 for(i=0;i<=right;i++)
        {
        	start[i]=inf;
        	end[i]=-inf;
        }         for(i=0;i<(1<<right);i++)
        {             start[dp2[i].num]=min(start[dp2[i].num],i);             end[dp2[i].num]=max(end[dp2[i].num],i);         }         pre=-1;         res=0;         for(i=0;i<(1<<left);i++)
        {             if(dp1[i].w>m)
            	break;             if(pre==dp1[i].w)
            	continue;             pre=dp1[i].w;             lim=n-dp1[i].num;             M=m-dp1[i].w;             for(j=0;j<=min(right,lim);j++)
            {
            	temp=find(start[j],end[j],M);
            	res=max(res,temp+dp1[i].w);             }         }
                 printf("%d\n",res);     }     return 0; }
