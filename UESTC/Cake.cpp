#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
    }
};

int n,mod,tn;
Point p[310],tp[310];
vector<int> c[310];
int totc;

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool grahamScanCmp(Point a,Point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int CalcDis(int a,int b)
{
    return (abs(p[a].x+p[b].x)*abs(p[a].y+p[b].y))%mod;
}

int main()
{
    while (scanf("%d%d",&tn,&mod) != EOF)
    {
        for (int i = 0; i < tn; i++)
            scanf("%d%d",&tp[i].x,&tp[i].y);
        grahamScan(tp,tn,p,n);
        if (n != tn)
        {
            puts("I can't cut.");
            continue;
        }
        totc = 0;
        c[0].clear();
        for (int i = 0; i < n; i++)
            c[0].push_back(i);
        totc++;
        int res = 0,tres,nowres,u,v;
        for (int tc = 0; tc < n-3;)
        {
            for (int i = 0; i < totc; i++)
                if (c[i].size() > 3)
                {
                    tres = mod;
                    for (int j = 0; j < c[i].size(); j++)
                        for (int k = 0;k < c[i].size();k++)
                            if (j != k && (j+1)%c[i].size() != k && (k+1)%c[i].size() != j)
                            {
                                nowres = CalcDis(c[i][j],c[i][k]);
                                if (nowres < tres)
                                {
                                    tres = nowres;
                                    u = j;
                                    v = k;
                                }
                            }
                    c[totc].clear();
                    for (int j = u;;j = (j+1)%c[i].size())
                    {
                        c[totc].push_back(c[i][j]);
                        if (j == v)
                            break;
                    }
                    totc++;

                    c[totc].clear();
                    for (int j = v;;j = (j+1)%c[i].size())
                    {
                        c[totc].push_back(c[i][j]);
                        if (j == u)
                            break;
                    }

                    swap(c[totc],c[i]);
                    res += tres;
                    tc++;
                }
            /*for (int i = 0;i < totc;i++)
            {
                cout << "Part : " << i << endl;
                for (int j = 0;j < c[i].size();j++)
                    cout << c[i][j] << ' ';
                cout << endl;
            }*/
        }
        printf("%d\n",res);
    }
    return 0;
}
