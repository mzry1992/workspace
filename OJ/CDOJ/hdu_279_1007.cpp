#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,l[123456],len;
struct rectangle
{
       int x1,y1,x2,y2;
}a[123456];

bool cmp(rectangle a,rectangle b)
{
     if (a.x2 < b.x1)
     if (a.y2 < b.y1)
        return true;
     return false;
}
                     
bool cmp2(rectangle a,rectangle b)
{
     if (a.x2 <= b.x2)
     if (a.y2 <= b.y2)
        return true;
     return false;
}

bool cmpxy(rectangle a,rectangle b)
{
     if (a.x2 == b.x2)
        return a.y2 < b.y2;
     return a.x2 < b.x2;
}

int main()
{
    int i,left,right,mid;
    while (true)
    {
          scanf("%d",&n);
          if (n == 0)    break;
          for (i = 1;i <= n;i++)
              scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
          sort(a+1,a+n+1,cmpxy);
          a[0].x1 = a[0].x2 = a[1].x1-1;
          a[0].y1 = a[0].y2 = a[1].y1-1;
          len = 0;
          l[len] = 0;
          for (i = 1;i <= n;i++)
          {
              if (cmp(a[l[len]],a[i]) == true)
              {
                                      len++;
                                      l[len] = i;
              }
              else
              {
                  left = 0;
                  right = len;
                  while (left < right)
                  {
                        mid = (left+right)/2;
                        if (cmp2(a[i],a[l[mid]]) == true)
                           right = mid;
                        else
                            left = mid+1;
                  }
                  l[left] = i;
              }
          }
          printf("%d\n",len);
    }   
    return 0;
}
