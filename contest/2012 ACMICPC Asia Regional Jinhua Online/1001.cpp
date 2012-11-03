#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int MaxN = 100000;
struct Point
{
    double x,y,r;
    int id;
    bool del;
};

bool cmpX(const Point& a,const Point& b)
{
    return a.x < b.x;
}

bool cmpY(const Point& a,const Point& b)
{
    return a.y < b.y;
}

int cnt[MaxN];
bool Div[MaxN];

void BuildKD(int deep,int l,int r,Point p[])
{
    if (l > r)	return;
    int mid = l+r>>1;
    Div[mid] = deep%2;
    cnt[mid] = r-l+1;
    nth_element(p+l,p+mid,p+r+1,Div[mid]?cmpX:cmpY);
    BuildKD(deep+1,l,mid-1,p);
    BuildKD(deep+1,mid+1,r,p);
}

queue<int> Q;
int totnode;

int Find(int l,int r,Point a,Point p[])
{
	totnode++;
	if (l > r)	return 0;
	int mid = l+r>>1;
	if (cnt[mid] == 0)	return 0;

	int totdel = 0;

	if (p[mid].del == false)
		if (fabs(p[mid].x-a.x) <= a.r && fabs(p[mid].y-a.y) <= a.r)
		{
			p[mid].del = true;
			Q.push(p[mid].id);
			totdel++;
		}
	
	double dl = Div[mid]?(a.x-p[mid].x):(a.y-p[mid].y);
	int l1,l2,r1,r2;
	l1 = l,l2 = mid+1;
	r1 = mid-1,r2 = r;

	if (dl > 0)
        swap(l1,l2),swap(r1,r2);

    totdel += Find(l1,r1,a,p);
    if (dl <= a.r)
        totdel += Find(l2,r2,a,p);

	cnt[mid] -= totdel;

    return totdel;
}

Point p[MaxN],tp[MaxN];
int n;

int main()
{
    int cas = 1;
    //while (true)
    {
		n = MaxN;
        //scanf("%d",&n);
        //if (n == 0)	break;
        for (int i = 0; i < n; i++)
        {
            p[i].id = i;
            double tx,ty;
            tx = rand()%1000000000;
			ty = rand()%1000000000;
			p[i].r = rand()%100000;
			//scanf("%lf%lf%lf",&tx,&ty,&p[i].r);
            p[i].r *= sqrt(2);
            p[i].x = tx-ty;
            p[i].y = tx+ty;
            p[i].del = false;
            tp[i] = p[i];
        }
        BuildKD(0,0,n-1,tp);

        printf("Case #%d:\n",cas++);
        int q = MaxN;
        //scanf("%d",&q);
        for (int i = 0; i < q; i++)
        {
            int id;
            id = rand()%n+1;
			//scanf("%d",&id);
			//printf("id = %d\n",id);
            int res = 0;
            id--;
			totnode = 0;
            Q.push(id);
            while (!Q.empty())
            {
                int now = Q.front();
                Q.pop();
				if (p[now].del == true)	continue;
				p[now].del = true;
				res += Find(0,n-1,p[now],tp);
            }
			printf("totnode = %d\n",totnode);
            printf("%d\n",res);
        }
    }
    return 0;
}
