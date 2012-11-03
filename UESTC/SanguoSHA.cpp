#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[8];
double res[4],p;

struct node
{
    int cur,kill,sta,sta2;
    //当前玩家，出局状况，身份状况，内奸身份状况。
    node(){}
    node(int _cur,int _kill,int _sta,int _sta2)
        {
            cur = _cur,kill = _kill,sta = _sta,sta2 = _sta2;
        }
    bool checkkill(int pos)
        {
            return (((kill>>pos)&1) == 1);
        }
    int checksta(int pos)
        {
            //0, 1, 2, 3 indicating Lord, Minister, Rebel, and Traitor
            //4 unknow
            if (a[pos] == 0)    return 0;
            if (a[pos] == 3)    return sta2;
            if (((sta>>pos)&1) == 1)    return a[pos];
            return 4;
        }
};

void Gao(node now,int curp,int round)
{
    if (round > 10) return;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        scanf("%lf",&p);
        memset(res,0,sizeof(res));
        Gao(node(0,0,0,4),1.0,1);
        for (int i = 0;i < n;i++)
            printf("%.5f\n",res[i]);
    }
    return 0;
}
