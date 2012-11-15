#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
struct point//�� 
{
       int x,y;
}p[110000],s[110000];//p����㣬s����͹�� 
int top;//͹���ĵ��� 
int ans;

int left(point a,point b,point c)//�ò���ж�b��c����a�Ƿ���ת 
{
     int x1,x2,y1,y2;
     x1 = b.x-a.x;
     y1 = b.y-a.y;
     x2 = c.x-a.x;
     y2 = c.y-a.y;
     return x1*y2-x2*y1;
}

bool cmpxy(point a,point b)//��xy����Ƚϵ�a���b�Ĵ�С 
{
     if (a.x == b.x)//���x������ͬ 
        return (a.y < b.y);//�Ƚ�y���� 
     return (a.x < b.x); 
}

bool cmpcross(point a,point b)//����ת�����жϵ�a���b�Ĵ�С 
{  
     int temp;
     temp = left(p[1],a,b);
     if (temp > 0)      return true;//�����ת����ôa��bС 
     if (temp < 0)      return false;//�����ת����ôa��b�� 
     if (temp == 0)//�����ͬһ������ 
        return a.x < b.x;//��ôx����С�ĸ�С 
}  
  
void sortwithcross()//����  
{  
     int i;
     sort(p+1,p+n+1,cmpxy);//�ҵ������±��1��ʼ������sort��Ҫ���Ų1��  
     sort(p+2,p+n+1,cmpcross);//ֻ��Ҫ��2��n��Щ�㣬���Կ�ʼ��p+2  
}  

void readin()
{
     int i;
     for (i = 1;i <= n;i++)
         scanf("%d %d",&p[i].x,&p[i].y);
     sortwithcross();
}

int dist2(point a,point b)//��ab����ľ����ƽ�� 
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
     if (n > 2)//��������������2����ô��͹�� 
     {
         s[1] = p[1];    s[2] = p[2];//�Ȱ�ǰ3����ѹ��ջ�� 
         top = 2;//ջ�� 
         for (i = 3;i <= n;i++)
         {
             while (top > 1)
             {   
                     temp = left(s[top-1],s[top],p[i]);
                     if (temp <= 0)                     top--;
                     if (temp > 0)   break;
             }
             top++;//i����ջ 
             s[top] = p[i];
         }//�����͹�� 
         len = top;//��͹���Ľ���� 
         top++;//n-1����ջ����Ϊn��϶���ջ���� 
         s[top] = p[n-1];
         //����͹����ѭ��˳����n-2��1���������͹����ͬ 
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
         //��ʱs�б������������͹������β������ 
         for (i = 1;i < top;i++)
         for (j = i+1;j <= top;j++)
         if (ans < dist2(s[i],s[j]))//���´� 
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
