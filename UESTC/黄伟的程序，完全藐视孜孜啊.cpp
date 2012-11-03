// D:\C代码\C++参考\

# include <math.h>
# include <float.h>
# include <ctype.h>
# include <stdio.h>
//# include <malloc.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <algorithm>
# include <streambuf>
# include <string>
# include <queue>
# include <deque>
# include <stack>
# include <functional>
# include <bitset>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <numeric>
# include <utility>
# include <sstream>
# include <iomanip>
# include <cstdio>
# include <cstdlib>
# include <cctype>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <ctime>

# define For(i,a)   for((i)=0;i<a;(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;

const int oo=1<<30;
const double eps=1e-7;
const int N=1    ;
const int M=1      ;
const int P=3119 ;

struct edge
{
	int num,idx;
	edge *next;
};

edge *p[P],e[P];
int a[P];
int num;
short int dp[3001][3001];
int n;

int main()
{
    freopen("我没有下限.txt","r",stdin);
    freopen("out1.txt","w",stdout);
	int i,j,k;
	int tmp;
	int I,J,K;
	int tp;
	edge *jp;
	int flag;
	int mx,mi,mj;
	int _=1;
	while( (~scanf("%d",&n) ) )
	{
		if( _++ != 1)
			puts("");
		num = 0;
		mx = 1;
		mi = mj =0;
		MEM(p);
		For(i,n)
			scanf("%d",a+i);
		for(j=n-1;j>=0;j--)
		{
			for(i=0 ; i<j;i++)
			{
				tmp = a[i] + a[j];
				tp = tmp%P;
				k = -1;
				if( tp<0 )
					tp+=P;
				for( jp = p[tp] ; jp ; jp = jp->next)
					if( jp->num == tmp )
					{
						k = jp->idx;
						break;
					}
				if( ~k )
					dp[i][j] = dp[j][k]+1;
				else
					dp[i][j] = 2;
				if( dp[i][j] > mx )
				{
					mx = dp[i][j];
					mi = i;
					mj = j;
				}
			}
			tmp = a[j];
			tp  = tmp%P;
			k   = -1;
			if( tp<0 )
				tp+=P;
			for( jp = p[tp] ; jp ; jp = jp->next)
				if( jp->num == tmp )
				{
					k = jp->idx = j;
					break;
				}
			if( -1 == k )
			{
				e[num].num = tmp;
				e[num].idx = j;
				e[num].next = p[tp];
				p[tp] = &e[num++];
			}
		}
		printf("%d\n",mx);
		For(i,mx)
		{
			printf( i? " %d":"%d",a[mi]);
			K = a[mi]+a[mj];
			mi = mj;
			tmp = mx-i-1;
			for(j=mi+1;j<n ;j++)
				if( dp[mi][j] == tmp && K==a[j] )
				{
					mj = j;
					break;
				}
		}
		puts("");
	}
    return 0;
}
