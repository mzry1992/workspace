#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
map<int,int> res;
map<int,int>::iterator it;
char com[100],a[1000],b[1000];
int c[1000],d[1000];
int totn,tmp;
int ta[3],tb[3],tc[3];

void gao(int x[3],int a,int b,int c,int d)
{
    if (a == 'X' && b == 'Y')
    {
        x[0] = c;
        x[1] = d;
        x[2] = -1;
    }
    else if (a == 'X' && b == 'Z')
    {
        x[0] = c;
        x[1] = -1;
        x[2] = d;
    }
    else
    {
        x[0] = -1;
        x[1] = c;
        x[2] = d;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        totn = 0;
        for (int i = 0; i < m; i++)
        {
            scanf(" %c",&a[totn]);
            scanf("%*c");
            scanf("%d",&c[totn]);
            scanf("%*c");
            scanf("%c",&b[totn]);
            scanf("%*c");
            scanf("%d",&d[totn]);
            if (a[totn] > b[totn])
            {
                swap(a[totn],b[totn]);
                swap(c[totn],d[totn]);
            }
            if (c[totn] > n || d[totn] > n || c[totn] < 1 || d[totn] < 1) continue;
            c[totn]--;
            d[totn]--;
            bool flag = true;
            for (int j = 0; j < totn; j++)
                if (a[j] == a[totn] && b[j] == b[totn] && c[j] == c[totn] && d[j] == d[totn])
                {
                    flag = false;
                    break;
                }
            if (flag == false)  continue;
            totn++;
        }
        res.clear();
        bool flag;
        for (int i = 0; i < totn; i++)
        {
            for (int j = i+1; j < totn; j++)
            {
                if (a[i] == a[j] && b[i] == b[j])   continue;
                gao(ta,a[i],b[i],c[i],d[i]);
                gao(tb,a[j],b[j],c[j],d[j]);
                flag = false;
                for (int k = 0;k < 3;k++)
                    if (ta[k] != -1 && tb[k] != -1 && ta[k] == tb[k])
                    {
                        flag = true;
                        break;
                    }
                if (flag == false)  continue;
                for (int k = 0;k < 3;k++)
                    ta[k] = max(ta[k],tb[k]);
                tmp = ta[0]*1000*1000+ta[1]*1000+ta[2];
                res[tmp]++;
                if (res[tmp] == 2)
                {
                    for (int k = 0;k < 3;k++)
                        cout << tc[k] << ' 'ta[k] << ' ' << tb[k] << endl;
                    cout << "I : " << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << endl;
                    cout << "J : " << a[j] << ' ' << b[j] << ' ' << c[j] << ' ' << d[j] << endl;
                }
            }
        }
        int ans = n*totn;
        for (it = res.begin();it != res.end();it++)
        {
            //cout << it->first << ' ' << it->second << endl;
            if (it->second == 1)
                ans -= 1;
            else if (it->second == 3)
                ans -= 2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
