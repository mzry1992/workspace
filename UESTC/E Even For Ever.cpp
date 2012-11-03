#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int s;
bool flag;

void Gao(int s,int deep,int suma,double sumb,int last)
{
    if (flag == true)   return;
    if (s == suma)
    {
        if (sumb == 1.0)
            flag = true;
        return;
    }
    if (sumb >= 1.0)    return;
    int op,ed;
    op = max(last,(int)floor(1.0/(1.0-sumb)));
    ed = min(s-suma,(int)ceil(sqrt((double)(s-suma)/(1.0-sumb))));
    for (int i = op;i <= ed;i++)
        Gao(s,deep+1,suma+i,sumb+1/(double)i,i);
}

int main()
{
    freopen("Even For Ever.txt","w",stdout);
    for (int s = 1;s <= 1000;s++)
    {
        flag = false;
        Gao(s,0,0,0.0,1);
        printf("%d %d\n",s,flag);
    }
}
