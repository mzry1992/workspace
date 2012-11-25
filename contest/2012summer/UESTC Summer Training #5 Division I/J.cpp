#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

bool visit[10];
int n,a[10];

int main()
{
    for (int n = 2;n <= 10;n++)
    {
        for (int i = 0;i < n;i++)
            a[i] = i;
        int cnt = 0;
        do
        {
            memset(visit,false,sizeof(visit));
            bool flag = true;
            for (int i = 1;i < n && flag;i++)
            {
                if (visit[abs(a[i]-a[i-1])] == true)
                    flag = false;
                visit[abs(a[i]-a[i-1])] = true;
            }
            if (flag)
            {
                //for (int i = 0;i < n;i++)
                //    printf("%d ",a[i]+1);
                //printf("\n");
                cnt++;
            }
        }while (next_permutation(a,a+n));
        printf("%d\n",cnt);
    }
	return 0;
}
