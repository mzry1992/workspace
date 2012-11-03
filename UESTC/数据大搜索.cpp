#include <iostream>
#include <cstdio>
using namespace std;

char now;
bool flag;
int out;

int main()
{
    int t;
    scanf("%d\n",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        out = 0;
        flag = false;
        while (true)
        {
            now = getchar();
            if (now == '\n')    break;
            if (now >= '0' && now <= '9')
            {
                if (flag == false)
                {
                    out = 0;
                    flag = true;
                }
                out = out*10+now-'0';
            }
            else
            {
                if (flag == true)
                {
                    flag = false;
                    printf("%d ",out);
                }
            }
        }
        if (flag == true)   printf("%d ",out);
        printf("\n");
    }
}
