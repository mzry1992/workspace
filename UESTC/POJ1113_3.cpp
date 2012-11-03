//POJ1113

#include <iostream> 
#include <cmath> 
#include <algorithm> 
using namespace std;
#define PI 3.141592653589793238462633832795
#define eps 1e-8
#define MAX 3000

struct point//���������� 
{
       int x;
       int y;
       double cross;//���� 
}points[MAX];
int s[MAX];//����͹�� 
int n,l,top;
double sum;

bool cmpyx(struct point a,struct point b)//��xy�������� 
{
     if (a.y == b.y)
        return (a.x < b.x);
     return (a.y < b.y);
}

bool cmpcross(struct point a,struct point b)//���������� 
{
     if (a.cross == b.cross)
        return (a.x < b.x);
     return (a.cross < b.cross);
}

int left(int a,int b,int c,int d)//�ж��Ƿ���ת 
{
    int x1,y1,x2,y2;
    x1 = points[b].x-points[a].x;
    y1 = points[b].y-points[a].y;
    x2 = points[d].x-points[c].x;
    y2 = points[d].y-points[c].y;
    if ((x1*y2-x2*y1) > 0)
       return 0;         
    return 1;
}


void cross()//���㼫�� 
{ 
    int i; 
    double x,y; 
    for(i=1;i<n;i++) 
    { 
        x = (points[i].x-points[0].x); 
        y = (points[i].y-points[0].y); 
        points[i].cross = acos((x/(sqrt(x*x+y*y))));
    } 
} 

void sortpoints()//�Ե����� 
{
     sort(points,points+n,cmpyx);
     cross();
     sort(points,points+n,cmpcross);
}

void Graham()//Graham�㷨��͹�� 
{
     int i;
     s[0] = 0;
     s[1] = 1;
     s[2] = 2;
     top = 2;
     for (i = 3;i < n;i++)
     {
         while (left(s[top-1],s[top],s[top],i) != 0)
               top--;
         top++;
         s[top] = i;
     }
}

double dist(int top,int top2)//��������ľ��� 
{ 
    double x = (points[top].x - points[top2].x)*(points[top].x - points[top2].x); 
    double y = (points[top].y - points[top2].y)*(points[top].y - points[top2].y); 
    return sqrt(x + y); 
} 

int main()
{
    int i;
    cin >> n >> l;
    for (i = 0;i < n;i++)
        cin >> points[i].x >> points[i].y;
    sortpoints();//���� 
    Graham();//��͹�� 
    sum = 0;
    for (i = 0;i < top;i++)
        sum = sum+dist(s[i],s[i+1]);//����͹�����ܳ� 
    sum += dist(s[top],s[0]);
    sum += 2*PI*l;//����һ��Բ 
    printf("%d\n",(int)(sum+0.5));
    return 0;
}
