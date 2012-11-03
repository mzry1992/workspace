#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
using namespace std;
const double inf = 1e100;
struct Node
{
    double x,y;
    int id;
}pt[100005];
int Y_sort[100005];
double MinN(double a,double b)
{
    if(a<b) return a;
    else return b;
}
inline double Distance(Node &a,Node &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 int CMP_X(const void *a,const void *b)
{
    if(((Node*)a)->x<((Node*)b)->x) return -1;
    else return 1;
}
int CMP_Y(const void *a,const void *b)
{
    if(pt[(*(int*)a)].y<pt[(*(int*)b)].y) return -1;
    else return 1;
}
double Nearest_Point_Distance(int first,int end,int &lid,int &rid)//first end 指点在pt数组中的下标，并假设pt已经按x排序
{
    if(end-first==1) {
    lid = first;
    rid = first+1;
    return Distance(pt[first],pt[first+1]);
    }
    else if(end-first==2) {
        double ret = inf;
        double l1 = Distance(pt[first],pt[first+1]);
        double l2 = Distance(pt[first+1],pt[first+2]);
        double l3 = Distance(pt[first],pt[first+2]);
        if(ret > l1){
            ret = l1;
            lid = first;
            rid = first+1;
        }
        if(ret > l2){
            ret = l2;
            lid = first+1;
            rid = first+2;
        }
        if(ret > l3){
            ret = l3;
            lid = first;
            rid = first+2;
        }
        return ret;
    }
    int mid=(first+end)/2;
    int lid1 ,rid1;
    int lid2,rid2;
    double l1 = Nearest_Point_Distance(first,mid,lid1,rid1);
    double l2 = Nearest_Point_Distance(mid+1,end,lid2,rid2);
    double min_dist=inf;
    if(l1 < min_dist){
        min_dist = l1;
        lid = lid1;
        rid = rid1;
    }
    if(l2 < min_dist){
        min_dist = l2;
        lid = lid2;
        rid = rid2;
    }
    int Y_end=0;
    for(int i=mid;i>=first&&(pt[mid].x-pt[i].x)<min_dist;i--)
    {
        Y_sort[Y_end++]=i;
    }
    for(int i=mid+1;i<=end&&(pt[i].x-pt[mid+1].x)<min_dist;i++)
    {
        Y_sort[Y_end++]=i;
    }
    qsort(Y_sort,Y_end,sizeof(Y_sort[0]),CMP_Y);
    /*for(int i=0;i<Y_end;i++)
    {
        for(int j=1;j<8&&i+j<Y_end;j++)
        {
            min_dist=MinN(min_dist,Distance(pt[Y_sort[i]],pt[Y_sort[i+j]]));
        }
    }*/
    for(int i=0;i<Y_end;i++)//上面那种也可以，但貌似速度慢点
    {
        for(int j=i+1;j<Y_end&&pt[Y_sort[j]].y-pt[Y_sort[i]].y<min_dist;j++)
        {
            double ll = Distance(pt[Y_sort[i]],pt[Y_sort[j]]);
            if(ll < min_dist){
                min_dist = ll;
                lid = Y_sort[i];
                rid = Y_sort[j];
            }
        }
    }
    return min_dist;
}
int trans[100010];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n == 0)break;
        double ans = inf;
        for(int i = 0 ; i< n ; i++)
        {
            scanf("%lf%lf",&pt[i].x, &pt[i].y);
            trans[i] = 1;
            if (pt[i].x < 0 && pt[i].y >= 0)
            {
                pt[i].x = abs(pt[i].x);
                trans[i] = 2;
            }
            else if (pt[i].x >= 0 && pt[i].y < 0)
            {
                pt[i].y = abs(pt[i].y);
                trans[i] = 3;
            }
            else if (pt[i].x < 0 && pt[i].y < 0)
            {
                pt[i].x = abs(pt[i].x);
                pt[i].y = abs(pt[i].y);
                trans[i] = 4;
            }
            pt[i].id = i;
        }
        qsort(pt,n,sizeof(pt[0]),CMP_X);
        int lid,rid;
        ans = Nearest_Point_Distance(0 , n-1,lid,rid);
        //printf("%.3f\n",ans);
        lid = pt[lid].id;
        rid = pt[rid].id;
        printf("%d %d %d %d\n",lid+1,trans[lid],rid+1,5-trans[rid]);
    }
    return 0;
}
