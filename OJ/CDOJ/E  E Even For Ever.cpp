#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int s,a[400],maxdeep;
bool flag;

int maxdeepget,totnode;

void DFS(int maxdeep,int deep,int sum1,double sum2,int last)
{
    //cout << deep << ' ' << sum1 << ' ' << sum2 << ' ' << last << endl;
    if (deep >= 8) return;
    maxdeepget = max(maxdeepget,deep);
    totnode++;
    //if (flag == true)  return;
    if (sum1 == s)
    {
        if (sum2 == 1.0)
        {
            flag = true;
            printf("%d ",deep);
            for (int i = 0;i < deep;i++)
                printf("%d ",a[i]);
            printf("\n");
        }
        return;
    }
    if (sum2 >= 1.0)    return;
    int op,ed;
    op = max(last,(int)floor(1.0/(1.0-sum2)));
    ed = min(s-sum1,(int)ceil(sqrt((double)(s-sum1)/(1.0-sum2))));
    for (int i = op;i <= ed;i++)
    {
        a[deep] = i;
        DFS(maxdeep,deep+1,sum1+i,sum2+1/(double)i,i);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&s);
        maxdeep = floor(sqrt(s))+1;
        flag = false;
        maxdeepget = 0;
        totnode = 0;
        DFS(maxdeep,0,0,0.0,1);
        //printf("maxdeepget = %d\n",maxdeepget);
        //printf("totnode = %d\n",totnode);
        if (flag == false)  printf("-1\n");
    }
    return 0;
}
