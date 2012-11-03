#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
struct point//点 
{
       int x,y;
}p[110000],s[110000];//p保存点，s保存凸包 
int top;//凸包的点数 
int ans;

int left(point a,point b,point c)//用叉积判断b对c关于a是否左转 
{
     int x1,x2,y1,y2;
     x1 = b.x-a.x;
     y1 = b.y-a.y;
     x2 = c.x-a.x;
     y2 = c.y-a.y;
     return x1*y2-x2*y1;
}

bool cmpxy(point a,point b)//按xy坐标比较点a与点b的大小 
{
     if (a.x == b.x)//如果x坐标相同 
        return (a.y < b.y);//比较y坐标 
     return (a.x < b.x); 
}

bool cmpcross(point a,point b)//按左转方向判断点a与点b的大小 
{  
     int temp;
     temp = left(p[1],a,b);
     if (temp > 0)      return true;//如果左转，那么a比b小 
     if (temp < 0)      return false;//如果右转，那么a比b大 
     if (temp == 0)//如果在同一方向上 
        return a.x < b.x;//那么x坐标小的更小 
}  
  
void sortwithcross()//排序  
{  
     int i;
     sort(p+1,p+n+1,cmpxy);//我的数组下标从1开始，所有sort都要向后挪1个  
     sort(p+2,p+n+1,cmpcross);//只需要排2到n这些点，所以开始是p+2  
}  

void readin()
{
     int i;
     for (i = 1;i <= n;i++)
         scanf("%d %d",&p[i].x,&p[i].y);
     sortwithcross();
}

int dist2(point a,point b)//求ab两点的距离的平方 
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
     ans = dist2(p[1],p[2]); 
     if (n > 2)//如果点的数量大于2，那么求凸包 
     {
         s[1] = p[1];    s[2] = p[2];//先把前3个点压入栈中 
         top = 2;//栈顶 
         for (i = 3;i <= n;i++)
         {
             while (top > 1)
             {   
                     temp = left(s[top-1],s[top],p[i]);
                     if (temp <= 0)                     top--;
                     if (temp > 0)   break;
             }
             top++;//i点入栈 
             s[top] = p[i];
         }//求出上凸包 
         len = top;//上凸包的结点数 
         top++;//n-1点入栈（因为n点肯定在栈顶） 
         s[top] = p[n-1];
         //求下凸包，循环顺序是n-2到1，其余和上凸包相同 
         for (i = n-2; i >= 1;i--)
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
         //此时s中保存的是完整的凸包（首尾相连） 
         for (i = 1;i < top;i++)
         for (j = i+1;j <= top;j++)
         if (ans < dist2(s[i],s[j]))//更新答案 
            ans = dist2(s[i],s[j]);
     }
}

void output()
{
     printf("%d\n",ans);
}

int main()
{
    while (scanf("%d",&n) == 1)
    {
        readin();
        solve();
        output();
    }
}
