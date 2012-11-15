#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20000;

void da(int a[],int rank[],int height[],int n,int m)
{
}

int n,a[maxn],rank[maxn],height[maxn];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        da(a,rank,height,n,100);
    }
    return 0;
}

