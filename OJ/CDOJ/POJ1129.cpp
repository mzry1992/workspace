//POJ1129

#include <iostream>
using namespace std;

int n,map[30][30],i,j,col[30];
char st[100];

int can(int now,int i) //判断对now染第i种颜色是否可行 
{
    int j;
    for (j = 1;j <= n;j++)
        if (map[now][j] == 1)
           if (col[j] == col[now]) return 1;
    return 0;
}

int dfs(int now,int tcol) //DFS 过程 
{
    int i;
    if (now > n) return 0;  
    if (now == 1) //第一次搜索时对col数组清零 
    {
            for (i = 1;i <= n;i++)
                col[i] = 0;
    }
    for (i = 1;i <= tcol;i++) //枚举颜色 
    {
        col[now] = i; //标记第now个节点颜色为i 
        if (can(now,i) == 0) //判断是否可行 
           if (dfs(now+1,tcol) == 0) return 0; //搜索下一个节点，如果后面的节点都处理完，则返回0 
    }
    return 1; //如果没有解，那么返回1 
}

int main()
{
    cin >> n;
    while (n != 0)
    {
          for (i = 1;i <= n;i++)
          for (j = 1;j <= n;j++)
              map[i][j] = 0;
          for (i = 1;i <= n;i++)
          {
              cin >> st;
              j = 2;
              while (st[j] != '\0')
              {
                    map[i][st[j]-'A'+1] = 1;
                    j++;
              }
          }
          //枚举4个颜色 
          if (dfs(1,1) == 0)
             cout << "1 channel needed." << endl;
          else
          if (dfs(1,2) == 0)
              cout << "2 channels needed." << endl;
          else
          if (dfs(1,3) == 0)
              cout << "3 channels needed." << endl;
          else
          if (dfs(1,4) == 0)
              cout << "4 channels needed." << endl;
          cin >> n;
    }
    return 0;
}
