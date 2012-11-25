#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1100];
int n;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            bool flag = true;
            for (int j = 1;buf[j] != 0 && flag;j++)
                if (buf[j-1] == 'C' && buf[j] == 'D')
                    flag = false;
            if (flag)
                res++;
        }
        printf("%d\n",res);
    }
	return 0;
}
