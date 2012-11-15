#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int tcase,fcase;
int n;
struct point
{
       int x,y;
}p[1100],s[1100];
int top;

int left(point a,point b,point c)
{
     int x1,x2,y1,y2;
     x1 = b.x-a.x;
     y1 = b.y-a.y;
     x2 = c.x-a.x;
     y2 = c.y-a.y;
     return x1*y2-x2*y1;
}

bool cmpxy(point a,point b)
{
     if (a.x == b.x)
        return (a.y < b.y);
     return (a.x < b.x); 
}

bool cmpcross(point a,point b)
{  
     int temp;
     temp = left(p[1],a,b);
     if (temp > 0)      return true;
     if (temp < 0)      return false;
     if (temp == 0)
        return a.x < b.x;
}  
  
void sortwithcross()
{  
     sort(p+1,p+n+1,cmpxy);
     sort(p+2,p+n+1,cmpcross);
}  

void readin()
{
     int i;
     scanf("%d",&n);
     for (i = 1;i <= n;i++)
         scanf("%d %d",&p[i].x,&p[i].y);
     sortwithcross();
}

int dist2(point a,point b)
{
    int temp,x,y;
    x = a.x-b.x;
    y = a.y-b.y;
    temp = x*x+y*y;
    return temp;
}

void solve()
{
     int i,j,len,temp;
     top = 0;
     if (n < 1)       return;
     top++;
     s[1] = p[1];    
     if (n < 2)       return;
     top++;
     s[2] = p[2];
     top = 2;
     for (i = 3;i <= n;i++)
     {
         while (top > 1)
         {
                     temp = left(s[top-1],s[top],p[i]);
                     if (temp <= 0)                     top--;
                     if (temp > 0)   break;
         }
         top++;
         s[top] = p[i];
     }
     len = top;
     for (i = n-1; i >= 1;i--)
     {
         while (top != len)
         {
               temp = left(s[top-1],s[top],p[i]);
               if (temp <= 0)                     top--;
               if (temp > 0)   break;
         }
         top++;
         s[top] = p[i];
     }
}

void output()
{
     int i;
     cout << "---------------------" << endl;
     for (i = 1;i <= top;i++)
         cout << s[i].x << ' ' << s[i].y << endl;
     cout << "---------------------" << endl;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        readin();
        solve();
        output();
    }
}
