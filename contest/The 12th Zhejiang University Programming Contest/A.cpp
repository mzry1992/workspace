#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,S,W,a[100000],b[100001];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d%d",&N,&S,&W);
        int g = S;
        for (int i=0; i<N; i++)
        {
            a[i] = g;
            if( a[i] == 0 )
            {
                a[i] = g = W;
            }
            if( g%2 == 0 )
            {
                g = (g/2);
            }
            else
            {
                g = (g/2) ^ W;
            }
        }
        b[0] = 0;
        for (int i = 0;i < N;i++)
        {
            if (i > 0)
                a[i] ^= a[i-1];
            b[i+1] = a[i];
        }
        sort(b,b+N+1);
        long long res = (long long)N*(N+1)/2;
        for (int i = 0;i <= N;i++)
        {
            int j;
            for (j = i+1;j <= N && b[i] == b[j];j++);
            res -= (long long)(j-i)*(j-i-1)/2;
            i = j-1;
        }
        cout << res << endl;
    }
    return 0;
}
