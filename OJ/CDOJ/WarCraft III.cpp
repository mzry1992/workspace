#include <iostream>
#include <cstdio>
using namespace std;

int n;
int map[30][30],a[30];
char s[1000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%s",s);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&map[i][j]);
        int res = 0,tres;
        for (int a1 = 1;a1 <= n-4;a1++)
        for (int a2 = a1+1;a2 <= n-3;a2++)
        for (int a3 = a2+1;a3 <= n-2;a3++)
        for (int a4 = a3+1;a4 <= n-1;a4++)
        for (int a5 = a4+1;a5 <= n;a5++)
        {
            tres = a[a1]+a[a2]+a[a3]+a[a4]+a[a5];
            tres += 2*map[a1][a2];
            tres += 2*map[a1][a3];
            tres += 2*map[a1][a4];
            tres += 2*map[a1][a5];
            tres += 2*map[a2][a3];
            tres += 2*map[a2][a4];
            tres += 2*map[a2][a5];
            tres += 2*map[a3][a4];
            tres += 2*map[a3][a5];
            tres += 2*map[a4][a5];
            if (tres > res) res = tres;
        }
        /*int a1,a2,a3,a4,a5;
        for (a1 = 1;a1 <= n-4;a1++)
        {
            cout << a1 << endl;
        for (a2 = a1+1;a2 <= n-3;a2++)
        for (a3 = a2+1;a2 <= n-2;a3++)
        for (a4 = a3+1;a4 <= n-1;a4++)
        for (a5 = a4+1;a5 <= n;a5++)
        {
            int tres = a[a1]+a[a2]+a[a3]+a[a4]+a[a5];
            cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << endl;
            tres += 2*map[a1][a2];
            tres += 2*map[a1][a3];
            tres += 2*map[a1][a4];
            tres += 2*map[a1][a5];
            tres += 2*map[a2][a3];
            tres += 2*map[a2][a4];
            tres += 2*map[a2][a5];
            tres += 2*map[a3][a4];
            tres += 2*map[a3][a5];
            tres += 2*map[a4][a5];
            if (tres > res) res = tres;
        }
        }*/
        printf("Case #%d: %d\n",ft,res);
    }
}
