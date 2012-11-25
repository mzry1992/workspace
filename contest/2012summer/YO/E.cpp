#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n,tw[6],a[6],w[6],sum[6];
double maxw,res;

double getsum(int l,int r)
{
    if (l == 0)
        return (double)sum[r];
    return (double)sum[r]-sum[l-1];
}

vector<pair<double,double> > DFS(int l,int r,double midpos)
{
    vector<pair<double,double> > res;
    if (l == r)
    {
        res.push_back(make_pair(midpos,midpos));
        return res;
    }
    vector<pair<double,double> > resl,resr;
    double lmidpos,rmidpos,wl,wr;
    for (int i = l+1;i <= r;i++)
    {
        wl = getsum(l,i-1),wr = getsum(i,r);
        rmidpos = 1.0/(wr/wl+1);
        lmidpos = 1.0-rmidpos;
        rmidpos = midpos+rmidpos;
        lmidpos = midpos-lmidpos;
        resl = DFS(l,i-1,lmidpos);
        resr = DFS(i,r,rmidpos);
        for (int j = 0;j < resl.size();j++)
            for (int k = 0;k < resr.size();k++)
                res.push_back(make_pair(min(resl[j].first,resr[k].first),max(resl[j].second,resr[k].second)));
    }
    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%lf",&maxw);
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
	    {
            scanf("%d",&tw[i]);
            a[i] = i;
	    }
	    res = -1;
	    vector<pair<double,double> > tmp;
	    do
	    {
	        for (int i = 0;i < n;i++)
                w[i] = tw[a[i]];
            sum[0] = w[0];
            for (int i = 1;i < n;i++)
                sum[i] = sum[i-1]+w[i];
            tmp = DFS(0,n-1,0);
            for (int i = 0;i < tmp.size();i++)
                if (tmp[i].second-tmp[i].first < maxw)
                    res = max(res,tmp[i].second-tmp[i].first);
	    }
	    while (next_permutation(a,a+n));
	    if (res == -1)
            puts("-1");
        else
            printf("%.10f\n",res);
	}
	return 0;
}
