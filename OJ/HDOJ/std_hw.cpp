/*****************************************
*
* 2011,UESTC_ACM
* std_hw
* By a180285
*
*****************************************/

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# define For(i,a)   for((i)=0;i<(a);(i)++)
# define MAX(x,y)   ((x)>(y)? (x):(y))
# define MIN(x,y)   ((x)<(y)? (x):(y))
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0x7f,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;


template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=100123          ;
const int M=1               ;
const ll P=10000000097ll    ;

char s[N], str[N*2];
int sa[N], rk[N], h[N];
int wa[N], wb[N], wv[N];
int p[N*2];
int sn;


int cmp(int *y,int a,int b,int L)
{
    return y[a]==y[b] && y[a+L]==y[b+L];
}

void da(char *s,int *sa,int len,int dn)
{
    int i,j,p;
    int *x,*y,*t;
    x = wa; y = wb;
    For(i, dn)  rk[i] = 0;
    For(i, len) rk[ x[i]=s[i] ]++;
    For(i, dn)  rk[i+1] += rk[i];
    for(i=len-1; i>=0; i--) sa[ --rk[ x[i] ] ] = i;
    for( j=1,p=1; p<len; j*=2,dn=p)
    {
        For(p, j)   y[p] = len-j + p;
        For(i, len) if(sa[i] >= j)  y[p++] = sa[i] - j;
        For(i, len) wv[i] = x[ y[i] ];
        For(i, dn)  rk[i] = 0;
        For(i, len) rk[ wv[i] ]++;
        For(i, dn)  rk[ i+1 ] += rk[i];
        for(i=len-1; i>=0; i--) sa[ --rk[ wv[i] ] ] = y[i];
        swap(x,y);  x[ sa[0] ] = 0;
        for(p =i =1; i<len; i++)
        {
            p += ! cmp(y, sa[i], sa[i-1], j) ;
            x[ sa[i] ] = p-1;
        }
    }
}

void find_height(char *s,int *sa,int len)
{
    int i,j,k = 0;
    for(i=1; i<=len; i++)
        rk[ sa[i] ] = i;
    For(i, len)
    {
        if( k>0 )
            k--;
        j = sa[ rk[i]-1 ];
        while( s[i+k] == s[j+k] )
            k++;
        h[ rk[i] ] = k;
    }
}

void pk(int up)
{
    int i,j,k,mx,id;
    for(mx=p[0]=0,i=1; i<up; i++)
    {
        if( mx > i )
            p[i] = MIN(p[id*2-i], mx-i);
        else
            p[i] = 1;
        while( str[i+p[i]] == str[i-p[i]] )
            p[i]++;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void pre()
{
    int i,n;
    str[0] = '$';
    str[1] = '#';
    For(i, sn)
    {
        str[i*2 + 2] = s[i];
        str[i*2 + 3] = '#';
    }
    n = 2 * sn + 2;
    str[n] = 0;
    pk(n);
}

void read()
{
    scanf("%s", s);
    sn = strlen(s);
    da(s, sa, sn+1, 128);
    find_height(s, sa, sn);
    pre();
}

int get(int id,int tp)
{
    return p[id*2 + 2 - tp] / 2;
}

int doit()
{
    int i,j,k;
    int gt;
    int ret = 0;
    int da[2] = {0};
    for(i=1; i<=sn; i++)
        For(j, 2)
        {
            gt = get(sa[i], j);
            checkmin(da[j], h[i]);
            ret += MAX(0, gt - da[j]);
            checkmax(da[j], gt);
        }
    return ret;
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        read();
        int ans = doit();
        printf("Case #%d: %d\n", _, ans);
    }

    #ifdef Hw
    printf("%d ms\n", clock());
    #endif
    return 0;
}
