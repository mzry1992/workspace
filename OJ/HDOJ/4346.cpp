#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char a[801];
const int mod = 1000000007;
int cnt;

int main()
{
    int totcas = 1;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%s",a);
        n = strlen(a);
        cnt = 1;
        for (int i = 0;i < n;i++)
            if (a[i] == '?')
                cnt = cnt*2%mod;
        bool flag;
        flag = true;
        for (int i = 0;i < n && flag;i++)
            if (a[i] == 'R')
                flag = false;
        if (flag)
            cnt--;
        for (int gl = -1;gl < n;gl++)
            if (gl >= 0 && a[gl] == 'R')
                break;
            else
            {
                for (int gr = n;gr > gl+1;gr--)
                    if (gr < n && a[gr] == 'R')
                        break;
                    else
                    {
                        flag = true;
                        for (int i = gl+1;i < gr && flag;i++)
                            if (a[i] == 'G')
                                flag = false;
                        if (flag)
                            cnt--;
                        int k = gr-gl-1;
                        for (int j = 2;j < k;j += 2)
                            if ((k-1)%(1+j) == 0)
                            {
                                flag = true;
                                for (int i = gl+1;i < gr && flag;i++)
                                {
                                    if ((i-gl-1)%(1+j) == 0)
                                    {
                                        if (a[i] == 'G')
                                            flag = false;
                                    }
                                    else if (a[i] == 'R')
                                        flag = false;
                                }
                                if (flag)
                                    cnt--;
                            }
                    }
            }
        printf("%d\n",(cnt+mod)%mod);
    }
	return 0;
}
