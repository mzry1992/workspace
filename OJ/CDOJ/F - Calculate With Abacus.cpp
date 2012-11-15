#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int x,y;
char map[10][10];
int sum,num;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&x,&y);
        for (int i = 0;i < 8;i++)
            scanf("%s",map[i]);
        sum = (x+y)*(y-x+1)/2;
        num = 0;
        int base = 1;
        for (int i = 5;i >= 0;i--)
        {
            if (map[0][i] == '|')
                num += base*5;
            for (int j = 3;j < 8;j++)
            if (map[j][i] == '|')
                num += (j-3)*base;
            base *= 10;
        }
        if (num != sum)
            printf("Mistake\n");
        else
            printf("No mistake\n");
    }
}
