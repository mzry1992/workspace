#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1100];
int n,a[20];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while (scanf("%s",s) != EOF)
    {
        n = strlen(s)+1;
        for (int i = 0;i < n;i++)
            a[i] = i;
        int res = 0;
        do
        {
            bool flag = true;
            for (int i = 0;i < n-1;i++)
                if (s[i] == 'I')
                {
                    if (a[i+1] < a[i])
                    {
                        flag = false;
                        break;
                    }
                }
                else if (s[i] == 'D')
                {
                    if (a[i+1] > a[i])
                    {
                        flag = false;
                        break;
                    }
                }
            if (flag == true)
                res++;
        }
        while (next_permutation(a,a+n));
        printf("%d\n",res);
    }
    return 0;
}

