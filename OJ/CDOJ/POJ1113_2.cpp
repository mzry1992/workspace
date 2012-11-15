#include <iostream> 
#include <cmath> 
#include <algorithm> 
#include <cstdio>
#define Max 1000 
#define eps 1e-8 // 定义#define eps 1e-8就是用eps表示1e-8，即0.00000001 

#define PI 3.141592654 
using namespace std; 
struct point //顶点

{ 
    double x; 
    double y; 
    double cross; 
}; 
point stack[Max];//储存凸包边缘顶点 

point points[Max]; 
int NumOfVertex;//顶点数 

int size;//stack长度 

double r; 
double sum;//边缘长度 

bool cmpyx(point a,point b)//按照yx坐标排序 

{ 
    if(a.y==b.y) 
        return a.x<b.x; 
    return a.y<b.y; 
} 
bool cmpcross(point a,point b)//按照角度大小排序 

{ 
    if(a.cross == b.cross) 
        return a.x<b.x; 
    return a.cross<b.cross; 
} 
bool judge(point first,point second,point third)

{ 
    double x1,x2,y1,y2,result; 
    x1 = second.x-first.x; 
    x2 = third.x-first.x; 
    y1 = second.y-first.y; 
    y2 = third.y-first.y; 
    result = x1*y2-y1*x2; 
    if(fabs(result)<eps) 
        result = 0; 
    if(result<=0)
        return true; 
    return false; 
} 
void Cross()
{ 
    int i; 
    double x,y; 
    for(i=1;i<NumOfVertex;i++) 
    { 
        x = (points[i].x-points[0].x); 
        y = (points[i].y-points[0].y); 
        points[i].cross = acos((x/(sqrt(x*x+y*y))));

    } 
} 
void Graham()

{ 
    int top=0,i; 
    sort(points,points+NumOfVertex,cmpyx); 
    Cross(); 
    sort(points+1,points+NumOfVertex,cmpcross); 
    for (i = NumOfVertex-1;i >= 0;i--)
        printf("%.0lf %.0lf\n",points[i].x,points[i].y);
    stack[0] = points[0]; 
    size = 1; 
    for (i=1;i<NumOfVertex;i++) 
    { 
        while (size>1&&judge(stack[top-1],stack[top],points[i])) 
        { 
            size--; 
            top--; 
        } 
        stack[++top] = points[i]; 
        size++; 
    } 
} 
double caculate(point top, point top2)

{ 
    double x = (top.x - top2.x) * (top.x - top2.x); 
    double y = (top.y - top2.y) * (top.y - top2.y); 
    return sqrt(x + y); 
} 
int main() 
{ 
    int i; 
    while (scanf("%d%lf",&NumOfVertex,&r)!=EOF) 
    { 
        for(i=0;i<NumOfVertex;i++) 
            scanf("%lf%lf",&points[i].x,&points[i].y); 
        Graham(); 
        sum = 0; 
        for (i=0;i<size-1;i++)

            sum+=caculate(stack[i],stack[i+1]); 
        sum+=caculate(stack[0],stack[size-1]); 
        sum+=2*PI*r; 
        printf("%.0lf\n",sum); 
    } 
    return 0; 
} 

