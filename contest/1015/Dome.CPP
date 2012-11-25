#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Point{
    double x,y,h;
}v[31];
int n;
double dis(Point &a,Point &b){
    double s1 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return sqrt(s1 + a.h*a.h);
}
double judge(Point &p,int &id){
    double ret =0.0;
    for(int i = 0 ; i<n;i++){
        double td = dis(v[i] , p);
       // printf("td = %f\n",td);
        if(td > ret){
            ret = td; id = i;
        }
    }
    return ret;
}
int main(){
    while(scanf("%d",&n) == 1){
        if(n == 0) break;
        for(int i = 0;i < n ;i++)
            scanf("%lf%lf%lf",&v[i].x,&v[i].y,&v[i].h);
        Point ans;
        ans.x = 0 ; ans.y = 0; ans.h = 0;
        double step = 0.1;
        while(step > 1e-6){
            int id = -1;
            double d = judge(ans,id);
            ans.x += (v[id].x -ans.x)*step;
            ans.y += (v[id].y -ans.y)*step;
            //printf("%.3f %.3f\n",ans.x,ans.y);
            step*=0.998;
        }
        printf("%.3f %.3f\n",ans.x,ans.y);
    }
    return 0;
}
