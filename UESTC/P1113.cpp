#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
struct point
{
       int x,y;
}p[110000],s[110000];
int top;
int ans;

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
     int i;
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

void solve()
{
     int i,j,len;
     ans = 0;
     if (n > 2)
     {
         s[1] = p[1];    s[2] = p[2];   s[3] = p[3];
         top = 3;
         for (i = 4;i <= n;i++)
         {
               while ((top > 0) && (left(s[top-1],s[top],p[i]) <= 0))
                         top--;
               top++;
               s[top] = p[i];
         }
         len = top;
         top++;
         s[top] = p[n-1];
         for (i = n-2; i >= 1;i--)
         {
               while ((top != len) && (left(s[top-1],s[top],p[i]) <= 0))
                         top--;
               top++;
               s[top] = p[i];
         }
         ans = 0;
         for (i = 1;i <= top;i++)
         for (j = i;j <= top;j++)
         if ((s[j].x-s[i].x)*(s[j].x-s[i].x)+(s[j].y-s[i].y)*(s[j].y-s[i].y) > ans)
            ans = (s[j].x-s[i].x)*(s[j].x-s[i].x)+(s[j].y-s[i].y)*(s[j].y-s[i].y);
         
         cout << "----------------------------" << endl;
         for (i = 1;i <= top;i++)
             cout << s[i].x << ' ' << s[i].y << endl;
         cout << "----------------------------" << endl;
         
     }
     else
     if (n == 2)
         ans = (p[1].x-p[2].x)*(p[1].x-p[2].x)+(p[1].y-p[2].y)*(p[1].y-p[2].y);
}

void output()
{
     printf("%d\n",ans);
}

int main()
{
    readin();
    solve();
    output();
    system("pause");
}
