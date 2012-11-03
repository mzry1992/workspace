#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,s,f,t,loop,cur,ts,tt;

int Gao(int s,int f,int t)
{
    if (s == f) return t;
    //s-1,m-1+m-s
    int cur = t%loop;
    if (cur > m-1+m-s)
        return Gao(s,f,m-1+m-1-cur+t);
    if (cur <= s-1)
    {
        if (f >= s)
            return f-1-cur+t;
        else
            return m-1+m-f-cur+t;
    }
    if (cur <= m-1+m-s)
    {
        if (f <= s)
            return m-1+m-f-cur+t;
        else
            return Gao(1,f,m-1+m-1-cur+t);
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        loop = 2*m-2;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d",&s,&f,&t);
            printf("%d\n",Gao(s,f,t));
            //s-1,m-1+m-s
            //0 1 2 3 4 5 6 7 8 9 10
            //1 2 3 4 3 2 1 2 3 4  3 2 1 2 3 4 3 2 1
            //          ^

        }
    }
    return 0;
}
