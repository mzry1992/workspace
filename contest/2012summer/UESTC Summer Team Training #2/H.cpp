#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s[100000],top;

int main()
{
    int cas = 0;
	while (scanf("%d",&n) != EOF)
	{
	    top = 0;
	    int res = 0;
	    for (int i = 0;i < n;i++)
	    {
	        int v;
	        scanf("%d",&v);
	        if (v > 0)
	        {
                while (top > 0 && s[top-1] > v)
                {
                    top--;
                    res++;
                }
                if (top == 0 || s[top-1] < v)
                    s[top++] = v;
	        }
	        else
	        {
	            res += top;
	            top = 0;
	        }
	    }
	    res += top;
	    printf("Case %d: %d\n",++cas,res);
	}
	return 0;
}
