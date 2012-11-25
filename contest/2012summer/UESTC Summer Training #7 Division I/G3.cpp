#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 3100000;
int n,m,spos;
char a[maxn],b[maxn],c[maxn],ts[maxn];
int pa[maxn],pb[maxn],A[maxn];

int Gao(char a[],int len)
{
	int i = 0,j = 1,k = 0;
	while (i < len && j < len && k < len)
	{
		int cmp = a[(j+k)%len]-a[(i+k)%len];
		if (cmp == 0)
			k++;
		else 
		{
			if (cmp > 0)
				j += k+1;
			else
				i += k+1;
			if (i == j)	j++;
			k = 0;
		}
	}
	return min(i,j);
}

void doit(int pa[])
{
    int len = 0;
    for (int i = 0; i < m; i++)
        ts[len++] = c[i];
    ts[len++] = '#';
    for (int i = 0; i < 2*n; i++)
        ts[len++] = a[i];
    ts[len] = 0;
    int j = 0;
    while (ts[j] == ts[j+1])
        j = j+1;
    A[1] = j;
    int k= 1;
    for (int i = 2;i < len;i++)
    {
        int Len = k+A[k]-1,L = A[i-k];
        if (L < Len-i+1)
            A[i] = L;
        else
        {
            j = std::max(0,Len-i+1);
            while (ts[i+j] == ts[j])
                j++;
            A[i] = j,k = i;
        }
    }
    for (int i = m+1;i < len;i++)
        pa[i-m-1] = A[i];
}

int main(int argc, char const *argv[])
{
	freopen("G.in","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s%s",a,b);

	spos = Gao(b,m);
	for (int i = 0;i < m;i++)
		c[i] = b[(spos+i)%m];
	c[m] = 0;
	puts(c);

	for (int i = 0;i < n;i++)
		a[n+i] = a[i];
	a[n*2] = 0;

	doit(pa);
	reverse(c,c+m);
	reverse(a,a+2*n);
	doit(pb);
	reverse(a,a+2*n);
	reverse(pb,pb+2*n);
	int respos = 0,restim = n+1;
    for (int i = 0; i < n; i++)
        if (pa[i]+pb[i+m-1] >= m-1)
        {
            if (i < restim || n-i < restim)
            {
                respos = i;
                restim = min(i,n-i);
            }
        }
    for (int j = 0; j < n; j++)
        putchar(a[respos+j]);
    puts("");
	return 0;
}