#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Task
{
    int id,s,p;
    long long t;
    bool operator < (const Task& b)const
    {
        if (t == b.t)
            return p > b.p;
        return t < b.t;
    }
};
struct Inq
{
    int id,s,p;
    Inq() {}
    Inq(int _id,int _s,int _p)
    {
        id = _id;
        s = _s;
        p = _p;
    }
    bool operator < (const Inq& b)const
    {
        return p < b.p;
    }
};
Task ta[50010],a[50010];
int n;
long long endtime;

long long check(int prio,int n)
{
	int specialid;
    for (int i = 0; i < n; i++)
    {
        a[i] = ta[i];
        if (a[i].p == -1)
		{
			specialid = a[i].id;
            a[i].p = prio;
		}
    }

    //end of all
    a[n].t = 1000000000000000000LL;
    a[n++].p = -1;
    sort(a,a+n);

    priority_queue<Inq> Q;

    for (int i = 0; i < n; i++)
    {
        //add task
        Q.push(Inq(a[i].id,a[i].s,a[i].p));

        if (a[i].t != a[i+1].t)
        {
            //end of time a[i].t
            //do some work from a[i].t to a[i+1].t
            long long len = a[i+1].t-a[i].t;
            while (!Q.empty())
            {
                Inq now = Q.top();
                Q.pop();
                if (now.s > len)
                {
                    now.s -= len;
                    Q.push(now);
                    break;
                }
                else
                {
                    len -= now.s;
					if (now.id == specialid)
					{
						return a[i+1].t-len;
					}

                    if (len == 0)
                        break;
                }
            }
        }
    }
	return -1;
}

long long res[50010];
void run(int prio,int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = ta[i];
        if (a[i].p == -1)
            a[i].p = prio;
    }

    //end of all
    a[n].t = 1000000000000000000LL;
    a[n++].p = -1;
    sort(a,a+n);

    priority_queue<Inq> Q;

    for (int i = 0; i < n; i++)
    {
        //add task
        Q.push(Inq(a[i].id,a[i].s,a[i].p));

        if (a[i].t != a[i+1].t)
        {
            //end of time a[i].t
            //do some work from a[i].t to a[i+1].t
            long long len = a[i+1].t-a[i].t;
            while (!Q.empty())
            {
                Inq now = Q.top();
                Q.pop();
                if (now.s > len)
                {
                    now.s -= len;
                    Q.push(now);
                    break;
                }
                else
                {
                    len -= now.s;

					res[now.id] = a[i+1].t-len;

                    if (len == 0)
                        break;
                }
            }
        }
    }

	printf("%d\n",prio);
	for (int i = 0;i < n-1;i++)
		printf("%I64d ",res[i]);
	printf("\n");
}


int pp[50010],totpp,ap[50010],totap;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    while (scanf("%d",&n) != EOF)
    {
		totpp = 0;
        for (int i = 0; i < n; i++)
        {
            ta[i].id = i;
            scanf("%I64d%d%d",&ta[i].t,&ta[i].s,&ta[i].p);
			if (ta[i].p != -1)
				pp[totpp++] = ta[i].p;
        }
		scanf("%I64d",&endtime);

		sort(pp,pp+totpp);
		totap = 0;
		if (pp[0] > 1)
			ap[totap++] = 1;
		for (int i = 0;i < totpp;i++)
			if (i+1 != totpp && pp[i]+1 < pp[i+1])
				ap[totap++] = pp[i]+1;
		if (pp[totpp-1] < 1000000000)
			ap[totap++] = 1000000000;

        int l = 0,r = totap,mid;
        while (l < r)
        {
            mid = l+r>>1;
			if (check(ap[mid],n) > endtime)
				l = mid+1;
			else
				r = mid;
        }

		run(ap[l],n);

    }
    return 0;
}

