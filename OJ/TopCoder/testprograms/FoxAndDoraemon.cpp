#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;

class FoxAndDoraemon {
public:
	int minTime(vector <int>, int);
};

int n,dp[51][51][51];
bool inq[51][51][51];
struct node
{
	int dep,emp,done;
	node(){}
	node(int _dep,int _emp,int _done)
	{
		dep = _dep;
		emp = _emp;
		done = _done;
	}
};

int FoxAndDoraemon::minTime(vector <int> a, int b) {
	n = a.size();
	if (n == 1)	return a[0];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	memset(dp,63,sizeof(dp));
	dp[0][1][0] = 0;
	queue<node> Q;
	memset(inq,false,sizeof(inq));
	Q.push(node(0,1,0));
	inq[0][1][0] = true;
	int res = 0x7fffffff;
	while (!Q.empty())
	{
		node now = Q.front();
		Q.pop();
		int nj = min(now.emp<<1,n);
		int val = dp[now.dep][now.emp][now.done];
		//printf("dep = %d, emp = %d, done = %d, val = %d\n",now.dep,now.emp,now.done,val);
		if (nj >= n-now.done)
		{
			int mx = a[now.done];
			for (int i = now.done;i < n;i++)
				mx = max(mx,a[i]);
			//printf("mx = %d\n",mx);
			res = min(res,max(val,mx+b*(now.dep+1)));
		}
		else
		{
			for (int i = 0;i < nj;i++)
			{
				node ne = node(now.dep+1,nj-i,now.done+i);
				int mx = a[now.done];
				for (int j = now.done;j < now.done+i;j++)
					mx = max(mx,a[j]);
				dp[ne.dep][ne.emp][ne.done] = min(dp[ne.dep][ne.emp][ne.done],max(val,mx+b*ne.dep));
				if (inq[ne.dep][ne.emp][ne.done] == false)
				{
					Q.push(ne);
					inq[ne.dep][ne.emp][ne.done] = true;
				}
			}
		}
	}
	return res;
}


//Powered by [KawigiEdit] 2.0!
