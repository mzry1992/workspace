#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct student
{
    char name[100];
    int s;
}s[5000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%s%d",&s[i].name,&s[i].s);

    }
}
