#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[4],b[4],c[8];
int d[8],ans[8],q[8];
bool flag;
int cnt;

void DFS2(int now)
{
    if (now == 8)
    {
        int aa = q[0]*10+q[1];
        int bb = q[2]*10+q[3];
        int cc = aa*bb;
        int c1,c2,c3,c4;
        c4 = cc%10; cc /= 10;
        c3 = cc%10; cc /= 10;
        c2 = cc%10; cc /= 10;
        c1 = cc%10; cc /= 10;
        if (q[4] != c1)   return;
        if (q[5] != c2)   return;
        if (q[6] != c3)   return;
        if (q[7] != c4)   return;
        cnt++;
        return;
    }
    if (q[now] != -1)
        DFS2(now+1);
    else
    {
        for (int i = 0;i <= 9;i++)
        {
            int temp = q[now];
            q[now] = i;
            DFS2(now+1);
            q[now] = temp;
        }
    }
}

int check()
{
    cnt = 0;
    for (int i = 0;i < 8;i++)
        q[i] = d[i];
    cout << "check ";
    for (int i = 0;i < 8;i++)
        cout << d[i] << ' ';
    cout << endl;
    DFS2(0);
    return cnt;
}

void DFS(int depth,int remove)
{
    if (depth < 0) return;
    if (flag == true) return;
    int code = check();
    if (code == 0) return;
    if (code == 1)
    {
        for (int i = 0;i < 8;i++)
            ans[i] = d[i];
        flag = true;
        return;
    }
    for (int i = -1;i <= 9;i++)
    {
        int temp = d[depth];
        d[depth] = i;
        if (temp != i) DFS(depth-1,remove+1);
        else DFS(depth-1,remove);
        d[depth] = temp;
    }
}

int main()
{
    int ft = 0;
    while (true)
    {
        ft++;
        scanf("%s",a);
        if (a[0] == '0' && strlen(a) == 1) break;
        scanf("%s%s",b,c);
        d[0] = d[1]= d[2]= d[3]= d[4]= d[5]= d[6]= d[7] = 0;
        for (int i = strlen(a)-1;i >= 0;i--) d[2-strlen(a)+i] = (a[i] == '*')?(-1):(a[i]-'0');
        for (int i = strlen(b)-1;i >= 0;i--) d[4-strlen(b)+i] = (b[i] == '*')?(-1):(b[i]-'0');
        for (int i = strlen(c)-1;i >= 0;i--) d[8-strlen(c)+i] = (c[i] == '*')?(-1):(c[i]-'0');
        flag = false;
        DFS(7,0);
        for (int i = 0;i < 8;i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}
