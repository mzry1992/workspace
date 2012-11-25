#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char ts[3];
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        long long w,b,tmp;
        long long wb , bw;
        wb = bw = 0;
        w = b =0;
        for(int i = 0; i < n ; i++)
        {
            scanf("%s%lld",ts,&tmp);
            if(ts[1]==0)
            {
                if(ts[0] == 'w') w+=tmp;
                else b+=tmp;
            }
            else if(ts[0] == ts[1])
            {
                if(ts[0] == 'w') w+= tmp+tmp;
                else b += tmp+tmp;
            }
            else
            {
                if(ts[0] == 'w') wb=tmp;
                else bw=tmp;
            }
        }
        int sb=b,sw=w;
        if (wb > bw)
            b += (wb-bw)/2;
        else
            w += (bw-wb+1)/2;
        if(w > b) printf("win ");
        else printf("lose ");
        b=sb;w=sw;
        if (wb>bw)
            b+=(wb-bw+1)/2;
        else
            w+=(bw-wb)/2;
        if(w >= b) puts("win");
        else puts("lose");

    }
    return 0;
}
