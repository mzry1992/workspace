#include <iostream>
using namespace std;

int t,ft,x[5000],y[5000],i,j,n,flag[5000];

void qsort(int l,int r)
{
     int tl,tr,m,temp;
     tl = l;
     tr = r;
     m = x[(tl+tr)/2];
     do
     {
         while (x[tl] < m) tl++;
         while (x[tr] > m) tr--;
         if (tl <= tr)
         {
                temp = x[tl]; x[tl] = x[tr]; x[tr] = temp;
                temp = y[tl]; y[tl] = y[tr]; y[tr] = temp;
                tl++;
                tr--;
         }
     }
     while (tl <= tr);
     if (tl < r) qsort(tl,r);
     if (l < tr) qsort(l,tr);
}

void qsort2(int l,int r)
{
     int tl,tr,m,temp;
     tl = l;
     tr = r;
     m = y[(tl+tr)/2];
     do
     {
         while (y[tl] < m) tl++;
         while (y[tr] > m) tr--;
         if (tl <= tr)
         {
                temp = y[tl]; y[tl] = y[tr]; y[tr] = temp;
                tl++;
                tr--;
         }
     }
     while (tl <= tr);
     if (tl < r) qsort2(tl,r);
     if (l < tr) qsort2(l,tr);
}

int findbegin()
{
    int i;
    for (i = 1;i <= n;i++)
        if (flag[i] == 0) return i;
    return 0;
}

void solve()
{
     int result = 0,now,i,nx,ny;
     now = findbegin();
     while (now != 0)
     {
           result++;
           flag[now] = 1;
           nx = x[now];
           ny = y[now];
           for (i = now+1;i <= n;i++)
           if (flag[i] != 1)
           if ((x[i] >= nx) && (y[i] >= ny))
           {
                     flag[i] = 1;
                     nx = x[i];
                     ny = y[i];
           }
           now = findbegin();
     }      
     cout << result << endl;
}

int main()
{
    cin >> t;
    for (ft = 1;ft <= t;ft++)
    {
        cin >> n;
        for (i = 1;i <= n;i++)
        {
            cin >> x[i] >> y[i];
            flag[i] = 0;
        }
        qsort(1,n);
        i = 1;
        j = 1;
        while (i <= n)
        {
            while (x[j] == x[i]) j++;
            j--;
            qsort2(i,j);
            i = j+1;
            j = i;
        }
        solve();
    }
    return 0;
}
