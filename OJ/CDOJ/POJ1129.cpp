//POJ1129

#include <iostream>
using namespace std;

int n,map[30][30],i,j,col[30];
char st[100];

int can(int now,int i) //�ж϶�nowȾ��i����ɫ�Ƿ���� 
{
    int j;
    for (j = 1;j <= n;j++)
        if (map[now][j] == 1)
           if (col[j] == col[now]) return 1;
    return 0;
}

int dfs(int now,int tcol) //DFS ���� 
{
    int i;
    if (now > n) return 0;  
    if (now == 1) //��һ������ʱ��col�������� 
    {
            for (i = 1;i <= n;i++)
                col[i] = 0;
    }
    for (i = 1;i <= tcol;i++) //ö����ɫ 
    {
        col[now] = i; //��ǵ�now���ڵ���ɫΪi 
        if (can(now,i) == 0) //�ж��Ƿ���� 
           if (dfs(now+1,tcol) == 0) return 0; //������һ���ڵ㣬�������Ľڵ㶼�����꣬�򷵻�0 
    }
    return 1; //���û�н⣬��ô����1 
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
          //ö��4����ɫ 
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
