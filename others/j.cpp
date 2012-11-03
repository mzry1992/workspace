#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const double inf = 1e100;
struct Point {
    double x,y;
    int id;
    Point() {}
    Point(double _x ,double _y,int _id) {
        x = _x ;
        y = _y;
        id = _id;
    }
};

Point pnt[100010];


double calc_dis(Point &a ,Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
//±ğÍüÁËÅÅĞò
bool operator<(const Point &a ,const Point &b) {
    if(a.y != b.y) return a.x < b.x;
    return a.y < b.y;
}
double Gao(int l ,int r ,Point pnts[] ,int &lid ,int &rid) {
    double ret = inf;
    if(l == r) return ret;
    if(l+1 ==r) {
        if(calc_dis(pnts[l],pnts[l+1]) <ret){
            ret = calc_dis(pnts[l],pnts[l+1]);
            lid = l;
            rid = l+1;
        }
        return ret;
    }
    if(l+2 ==r) {
        if(calc_dis(pnts[l],pnts[l+1]) <ret){
            ret = calc_dis(pnts[l],pnts[l+1]);
            lid = l;rid =l+1;
        }
        if(calc_dis(pnts[l],pnts[l+2]) < ret){
            ret = calc_dis(pnts[l],pnts[l+2]);
            lid = l ; rid = l+2;
        }
        if(calc_dis(pnts[l+1],pnts[l+2]) < ret){
            ret = calc_dis(pnts[l+1],pnts[l+2]);
            lid = l+1;
            rid = l+2;
        }
        return ret;
    }

    int mid = l+r>>1;
    int lid1,rid1,lid2,rid2;
    double lret = Gao(l ,mid,pnts,lid1,rid1);
    double rret = Gao(mid+1, r,pnts,lid2,rid2);
    if(lret < ret){
        ret = lret;
        lid = lid1;
        rid = rid1;
    }
    if(rret <ret){
        ret = rret;
        lid = lid2;
        rid = rid2;
    }

    for(int c = l ; c<=r; c++)
        for(int d = c+1; d <=c+7 && d<=r; d++) {
            //ret = min(ret , );
            if(calc_dis(pnts[c],pnts[d]) <ret){
                ret = calc_dis(pnts[c],pnts[d]);
                lid = c;
                rid = d;
            }
        }
    return ret;
}
int main() {
    int n;
    while(scanf("%d",&n) == 1) {
        if(n == 0)break;
        double ans = inf;
        for(int i = 0 ; i< n ; i++)
            {
                scanf("%lf%lf",&pnt[i].x, &pnt[i].y);
                pnt[i].x = abs(pnt[i].x);
                pnt[i].y = abs(pnt[i].y);
                pnt[i].id = i;
            }
        sort(pnt,pnt+n);
        int lid,rid;
        ans = Gao(0 , n-1 ,pnt,lid,rid);
        printf("%.2f %d %d\n",ans/2,pnt[lid].id , pnt[rid].id);
    }
    return 0;
}
