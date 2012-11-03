#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;
char ss[10];
char an[8];
long long ans;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        gets(ss);
        ans = 0;
        for (int i = 1;i <= 2*n-1;i++)
        {
            gets(ss);
            //int len=strlen(ss);
            long long key=0;
            for (int j=0;j<7;j++)
                key=key*256+ss[j];
            ans = ans^key;
        }
        an[7]=0;
        int j=6;
        while (ans>0)
        {
            an[j]=ans%256;
            j--;
            ans/=256;
        }
        puts(an);
    }
}

