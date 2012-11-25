#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,l,v1,v2,b[200000],cnt;
double pro[100001],a[300000],dis;

bool check(double a)
{
    return a < dis;
}

int main()
{
    scanf("%d%d%d%d",&n,&l,&v1,&v2);
    for (int i = 0;i < n;i++)
        scanf("%d",&b[i]);
    sort(b,b+n);
    for (int i = 0;i < n;i++)
    {
        a[i] = (double)b[i];
        a[n+i] = a[i]+(double)2*l;
        a[2*n+i] = a[n+i]+(double)2*l;
    }
    dis = (double)l*(double)v2/(double)(v1+v2);
    cnt = 0;
    memset(pro,0,sizeof(pro));
    int nl,nr;
    double pre,bpre;
    for (int i = 0;i < n;i++)
        if (check(a[i]))
        {
            cnt++;
        }
        else
            break;
    if (cnt == 0)
    {
        pro[0] += a[0]-dis;
        nl = nr = 0;
        pre = a[0]-dis;
        cnt++;
        nr++;
    }
    else
    {
        nl = 0;
        nr = cnt;
        pre = 0;
    }
        bpre = pre;
    for (;nl < n;)
    {
        cout << nl << ' ' << nr << " [" << pre << ' ' << pre+dis << "] " << cnt << endl;
        double d1 = a[nl]-pre;
        double d2 = a[nr]-pre-dis;
        cout << d1 << ' ' << d2 << endl;
        if (d1 <= d2)
        {
            pro[cnt] += d1;
            cout << cnt << " : " << d1 << endl;
            pre += d1;
            cnt--;
            if (cnt == 0)
            {
                pro[0] += a[nr]-a[nl]-dis;
                cout << "0 : " << a[nr]-a[nl]-dis << endl;
                pre = a[nr]-dis;
                nl = nr;
                nr++;
                cnt++;
            }
            else
                nl++;
        }
        else
        {
            pro[cnt] += d2;
            cout << cnt << " : " << d2 << endl;
            pre += d2;
            cnt++;
            nr++;
        }
    }
    cout << pre << ' ' << nl << ' ' << nr << ' ' << cnt << endl;
    while (true)
    {
        double d1 = 2*l-bpre-pre;
        double d2 = a[nr]-a[nr-1];
        cout << d1 << ' ' << d2 << ' ' << pre << ' ' << cnt << endl;
        if (d2 < d1)
        {
            pre += d2;
            pro[cnt] += d2;
            cout << cnt << " : " << d2 << endl;
            cnt++;
            nr++;
        }
        else
        {
            pro[cnt] += d1;
            cout << cnt << " : " << d1 << endl;
            break;
        }
    }
    for (int i = 0;i <= n;i++)
        printf("%.12f\n",pro[i]/(double)(2*l));
	return 0;
}
