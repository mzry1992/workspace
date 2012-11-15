#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{-1,-1},{1,1},{-1,1},{1,-1}};
int m,n,d,L[25][25],a[25*25][25*25],b[25*25],tot;

bool safe(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d",&m,&n,&d);
        if (m == 0 && n == 0 && d == 0) break;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&L[i][j]);
        tot = n*m;
        memset(a,0,sizeof(a));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                a[i*m+j][i*m+j] = 1;
                b[i*m+j] = L[i][j];
                for (int k = 0;k <= d;k++)
                {
                    int tx = k;
                    int ty = d-k;
                    for (int q = 0;q < 4;q++)
                        if (safe(i+tx*step[q][0],j+ty*step[q][1]) == true)
                            a[i*m+j][(i+tx*step[q][0])*m+(j+ty*step[q][1])] = 1;
                }
            }
        bool hasres = true;
        for (int i = 0;i < tot;i++)
        {
            if (a[i][i] == 0)
                for (int j = i;j < tot;j++)
                    if (a[j][i] != 0)
                    {
                        for (int k = 0;k < tot;k++)
                            swap(a[i][k],a[j][k]);
                        swap(b[i],b[j]);
                        break;
                    }
            if (a[i][i] == 1)
            {
                for (int j = 0;j < tot;j++)
                    if (i != j && a[j][i] != 0)
                    {
                        b[j] = b[j]^b[i];
                        for (int k = 0;k < tot;k++)
                            a[j][k] = a[j][k]^a[i][k];
                    }
            }
        }
        /*freopen("out.txt","w",stdout);
        for (int j = 0;j < tot;j++)
        {
            for (int k = 0;k < tot;k++)
                cout << a[j][k] << ' ';
            cout << " = " << b[j] << endl;
        }*/
        for (int i = 0;i < tot;i++)
        {
            bool flag = true;
            for (int j = 0;j < tot;j++)
                if (a[i][j] != 0)   flag = false;
            if (flag == true && b[i] == 1)
                hasres = false;
        }
        if (hasres == true) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
