#include <iostream>
using namespace std;

int n,m;
int map[300][300],c[300][300],b[300][300],pre[300],d[300];//b���浱ǰ������c���������map����ͼ��pre����ǰ���ߣ�d������� 
int ans;

bool find()//Ѱ������· 
{
     int head,tail;
     int i,j,k;
     int visit[300];
     memset(visit,false,sizeof(visit));
     visit[1] = true;
     head = tail = 1;
     d[1] = 1;
     pre[1] = 1;
     while (head <= tail)//BFS
     {
           for (i = 2;i <= n;i++)
           if (visit[i] == false)
           if (c[d[head]][i] > 0)
           {
                             visit[i] = true;
                             pre[i] = d[head];
                             tail++;
                             d[tail] = i;
                             if (i == n)
                                return true;
           }
           head++;
     }
     return false;
}

void solve()
{
     int i,j,k;
     while (find() == true)//���������· 
     {
           int min = 0x7fffffff;
           for (i = n;i != 1;i = pre[i])//�ҵ����� 
           if (min > c[pre[i]][i])
              min = c[pre[i]][i];
           for (i = n;i != 1;i = pre[i])//������·�޸� 
           {
               b[pre[i]][i] += min;//���� 
               b[i][pre[i]] = -b[pre[i]][i];//���� 
               c[pre[i]][i] = map[pre[i]][i]-b[pre[i]][i];//���� 
               c[i][pre[i]] = b[pre[i]][i];//���� 
           }
     }
     ans = 0;
     for (i = 1;i < n;i++)
     if (map[i][n] != 0)
        ans += b[i][n];
}

int main()
{
    int i,j,ta,tb,tc;
    while (scanf("%d%d",&m,&n) == 2)
    {
          memset(c,0,sizeof(c));
          memset(b,0,sizeof(b));
          memset(map,0,sizeof(map));
          for (i = 1;i <= m;i++)
          {
              scanf("%d%d%d",&ta,&tb,&tc);
              map[ta][tb] += tc;
              c[ta][tb] = map[ta][tb];
          }
          solve();
          printf("%d\n",ans);
    }
    return 0;   
}
