#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char s[110000];
int n,a[110000],op[110000],top,nowop,xa,xb;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%s",s);
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        top = 0;
        op[top++] = 0;
        nowop = 0;
        xa = xb = 0;
        for (int i = 0;s[i] != 0;i++)
        {
            if (s[i] == 'x')
            {
                if (i == 0 || s[i-1] == '+' || s[i-1] == '(')
                {
                    if (nowop == 0) xa++;
                    else
                        xb++;
                }
                else
                {
                    if (nowop == 0) xb++;
                    else
                        xa++;
                }
            }
            else if (s[i] == '(')
            {
                if (i == 0 || s[i-1] == '+' || s[i-1]=='(')
                    op[top++] = 0;
                else
                {
                    op[top++] = 1;
                    if (nowop == 0) nowop = 1;
                    else
                        nowop = 0;
                }
            }
            else if (s[i] == ')')
            {
                if (op[top-1] == 1)
                {
                    if (nowop == 0) nowop = 1;
                    else    nowop = 0;
                }
                top--;
            }
        }
        long long res = 0;
        for (int i = 0;i < xb;i++)
            res -= a[i];
        for (int i = xb;i < n;i++)
            res += a[i];
        printf("%lld\n",res);
        //printf("%d %d\n",xa,xb);
	}
	return 0;
}
