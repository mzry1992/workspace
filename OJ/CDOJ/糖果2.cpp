#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
const int esize = 200010;
int ehead[esize];
int enext[esize],eto[esize] , ev[esize];
int ecnt;
void add(int a ,int b ,int c)
{
    ecnt++;
    eto[ecnt] = b;
    enext[ecnt] = ehead[a];
    ev[ecnt] = c;
    ehead[a] = ecnt;
}


stack<int> que;
int dis[esize];
int incnt[esize];
bool inque[esize];

int ncnt;
bool spfa()
{
    memset(inque,0,sizeof(inque));
    memset(dis,0x7f,sizeof(dis));
    dis[0] = 0;
    que.push(0);
    while(!que.empty())
    {
        int ih = que.top();
        inque[ih] = false;
        que.pop();
        for(int ie = ehead[ih] ; ie != -1 ;ie = enext[ie])
        {
            int th = eto[ie];
            if(dis[ih] + ev[ie] < dis[th])
            {
               dis[th] = dis[ih] + ev[ie];
               //if(inque[th]) return false;
               if(!inque[th])
               {
                   inque[th] = true;
                   incnt[th] ++;
                   if(incnt[th] > ncnt)
                       return false;
                   que.push(th);
               }
            }
        }

    }
    return true;
}

int main(int argc, char** argv) {
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n , k;
    memset(ehead,  -1 ,sizeof(ehead));
    cin >> n >> k;
    for(int i = 0 ; i < k;i++)
    {
        int a ,b ,x;
        cin >>x>> a>> b;
        if(x == 1)
        {
            add(a,b,0);
            add(b,a,0);
        }
        else if(x == 2)
        {
            add(a ,b ,-1);
        }
        else if(x == 3)
        {
            add(b,a,0);
        }
        else if(x == 4)
        {
            add(b,a,-1);
        }
        else if(x == 5)
        {
            add(a,b,0);
        }
    }
    for(int i = 1 ;i <= n ; i++)
        add(0,i , -1);
    ncnt = n+1;
    bool ret = spfa();
    if(ret)
    {
        //for(int i = 0 ; i<= n ;i++)
          //  printf("%d: %d\n" , i , dis[i]);
        int ans = 0;
        for(int i = 1 ; i<= n ;i++)
            ans +=dis[i];
        printf("%d\n",-ans);
    }
    else puts("-1");
    return 0;
}
