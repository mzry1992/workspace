#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


int leng(int x)
{
    int ans=0;
    while (x>0)
    {
        ans++;
        x/=10;
    }
    return ans;
}

int getd(int x)
{
    int prev=x%10,now=0;
    x/=10;
    int base=1,num=0;
    while (x>0)
    {
        now=x%10;
        int key=abs(now-prev);
        num=key*base+num;
        base*=10;
        x/=10;
        prev=now;
    }
    return num;
}
int main()
{
    //printf("%d\n",getd(1135));
    freopen("July Number.txt","w",stdout);
    int cnt=1;
    for (int i=1;i<=100000000;i++)
    {
        bool flag=true;
        int x=i;
        if (x==7) printf("1 7\n");
        else
        {
            while (x>=10)
            {
                x=getd(x);
                if (x==7)
                {
                    flag=false;
                    break;
                }
            }
        }
        if (!flag)
        {cnt++;
           printf("%d %d\n",cnt,i);
           if(cnt == 10000)
            break;
        }
    }
    printf("%d\n",cnt);
}
