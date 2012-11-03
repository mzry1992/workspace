//POJ1062

#include <iostream>
using namespace std;

int m,n,p[150],l[150],x,i,j,t,w,map[150][150],f[150],ans,result,um,dm,minm,maxm;

int main()
{
    cin >> m >> n;
    for (i = 1;i <= n;i++)
    for (j = 1;j <= n;j++)
        map[i][j] = -1;
    maxm = -19921005; //地位最大的人的地位 
    minm = 19921005;  //地位最小的人的地位 
    for (i = 1;i <= n;i++)
    {
        cin >> p[i] >> l[i] >> x;
        if (l[i] < minm)    minm = l[i];
        if (l[i] > maxm)    maxm = l[i];
        for (j = 1;j <= x;j++)
        {
            cin >> t >> w;
            map[i][t] = w;
        }
    }
    ans = 1234567890; //答案 
    for (dm = minm;dm <= maxm;dm++) //枚举地位下限 
    {
        um = dm+m; //地位上限 
        for (i = 1;i <= n;i++)
            f[i] = 19921005;
        f[1] = p[1];
        for (i = 1;i <= n;i++)
        for (j = 1;j <= n;j++)
        if (map[i][j] != -1) //判断I与J是否可以交换 
        if ((l[1] >= dm) && (l[1] <= um)) //判断地位是否合法 
        if ((l[i] >= dm) && (l[i] <= um))
        if ((l[j] >= dm) && (l[j] <= um))
        if (f[j] > f[i]-p[i]+map[i][j]+p[j]) //松弛操作 
           f[j] = f[i]-p[i]+map[i][j]+p[j];
        result = f[1];
        for (i = 2;i <= n;i++)
        if (result > f[i])
           result = f[i];  
        if (ans > result) ans = result; //更新答案 
    }   
    cout << ans << endl;
    //system("pause");
    return 0;
}
    
