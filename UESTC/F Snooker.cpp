#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int abs(int a)
{
    if(a < 0) return -a;
    return a;
}
int n,a,b,now,cur;
int arr[1001];
int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        a = b = cur = 0;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++)
        {
            int t ;
            scanf("%d",&t);
            arr[i] = t;
        }
        int bcnt = 0;
        int csc = 15+2+3+4+5+6+7;
        int s[2] = {0};
        int p = 0 ;
        int ans = n-1;
        for(int i = 0 ; i < n; i++)
        {
            if(arr[i] == 1)
            {
                bcnt++;
                s[p]++;
                csc--;
            }
            bool f2 = false;
            if(bcnt == 15 && arr[i+1] == 0) {f2 = true;bcnt = 16;}

            bool flag= false;
            if(s[p] == s[1-p] && csc == 0) {
                if(arr[i] >=2)
                    {
                        ans = i;
                        break;
                    }
                else { p = 1-p;continue;}
            }
            if(arr[i] >=2)
            {
                if(bcnt == 16)
                {
                    csc-=arr[i];
                }
                if(bcnt == 15)
                {
                    bcnt++;
                }
                s[p] += arr[i];
            }
            //if(csc == 0)
            int maxget = 0;
            //printf("id %d: %d %d-%d now = %d\n" ,i,arr[i] , s[0],s[1], csc);

            if(s[p] < s[1-p])
            {
                //puts("aa");
                if(bcnt == 16) maxget = csc;
                if(bcnt == 15 || f2) maxget = csc + (arr[i] == 0 ? 0 : 7);
                if(bcnt < 15)
                {
                    if(arr[i] == 1)
                    {
                        //maxget = (15 - bcnt)*7+(15-bcnt) + 2+3+4+5+6+7;
                        maxget =  (15-bcnt)*7+7+(15-bcnt) + 2 +3+4+5+6+7;
                    }
                    else if(arr[i] >1)
                    {
                        maxget =  (15-bcnt)*7+(15-bcnt) + 2 +3+4+5+6+7;
                    }
                }
                if(maxget < s[1-p] - s[p])
                {
                    ans = i;
                    break;
                }
            }
            else if(s[p] > s[1-p])
            {
                //puts("bb");
                if(bcnt == 16) maxget = csc;
                else if(bcnt == 15) maxget = csc;
                else if(bcnt < 15){
                    maxget = (15-bcnt)*7+(15-bcnt) + 2 +3+4+5+6+7;
                }
                //printf("maxget = %d\n" ,maxget);
                if(maxget < s[p] - s[1-p])
                {
                    ans = i ;
                    break;
                }
            }
            if(arr[i] == 0)
                    {
                    p = 1-p;
                    }
        }
        printf("%d\n" ,ans+1);
    }
    return 0;
}
