#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int la,lb,l;
char a[60000],b[60000],s[120000];
int A[120000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%s%s",a,b);
        la = strlen(a);
        lb = strlen(b);
        l = 0;
        for (int i = 0;i < lb;i++)
            s[l++] = b[i];
        s[l++] = '#';
        for (int i = 0;i < la;i++)
            s[l++] = a[i];
        s[l] = 0;
        int j = 0;
        while (s[j] == s[j+1])
            j++;
        A[1] = j;
        int k = 1;
        for (int i = 2;i < l;i++)
        {
            int Len = k+A[k]-1,L = A[i-k];
            if (L < Len-i+1)
                A[i] = L;
            else
            {
                j = max(0,Len-i+1);
                while (s[i+j] == s[j])
                    j++;
                A[i] = j,k = i;
            }
        }
        int res = 1;
        for (int i = lb+1;i < l;i++)
            if (i+A[i] == l)
                res++;
        printf("%d\n",res);
    }
	return 0;
}
