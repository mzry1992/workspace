#include <iostream>
using namespace std;

int t,ft,r,c,n,k,link[600];//link保存匹配边 
bool map[600][600],cover[600];//map保存二分图，cover标记一个点是否为饱和点 

void readin() //数据读入 
{
     int i,j;
     cin >> n >> k;
     for (i = 1;i <= n;i++)
     for (j = 1;j <= n;j++)
         map[i][j] = false;
     for (i = 1;i <= k;i++)
     {
         cin >> r >> c;
         map[r][c] = true;
     }
}

bool find(int i) //从i出发，寻找增广链，如果找到返回true，否则返回false 
{
     int k,q;
     for (k = 1;k <= n;k++) //此处可以优化，优先考虑未匹配边可以有限加快速度 
     if ((map[i][k] == true) && (cover[k] == false))
     {
                    q = link[k];
                    link[k] = i;
                    cover[k] = true;
                    if ((q == 0) || (find(q) == true))  return true; //增广操作 
                    link[k] = q;
     }
     return false;
}

void km() //KM算法 
{
     int i,j;
     for (i = 1;i <= n;i++)
         link[i] = 0;
     for (i = 1;i <= n;i++) //枚举每个点 
     {
         for (j = 1;j <= n;j++)
             cover[j] = false;
         find(i);
     }
}
     
void count() //累加答案 
{
     int i,ans;
     ans = 0;
     for (i = 1;i <= n;i++)
     if (link[i] != 0) ans++;
     cout << ans << endl;
}

int main()
{
    cin >> t;
    for (ft = 1;ft <= t;ft++)
    {
        readin();
        km();
        count();
    }
    return 0;
}
