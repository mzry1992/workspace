#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b;
bool sg[110][110];

bool DFS(int ta,int tb)
{
    if (ta == 0 && tb == 0) return true;
    bool flag = false;
    if (ta > 0)
    if (DFS(ta-1,tb))
        flag = true;
    if (ta > 0 && tb > 0)
    if (DFS(ta-1,tb-1))
        flag = true;
    if (tb > 0)
    if (DFS(ta,tb-1))
        flag = true;
    if (flag)
        {sg[ta][tb] = true;return false;}
    else
        {sg[ta][tb] = false;return true;}
}
int main()
{
    int t;
    scanf("%d",&t);
    //memset(sg,false,sizeof(sg));
    //DFS(5,5);
    /*for (int i = 0;i <= 5;i++)
    {
        for (int j = 0;j <= 5;j++)
            cout << sg[i][j] << ' ';
        cout << endl;
    }*/
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&a,&b);
        bool flag;
        if (a%2 == 1)   flag = true;
        else
        {
            if (b%2 == 1)   flag = true;
                else
                    flag = false;
        }
        printf("Case #%d: %s\n",ft,flag?"Cc":"Zxh");
    }
}
