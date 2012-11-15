//POJ1125

#include <iostream>
using namespace std;

int n,i,j,k,q,t,map[200][200];

int main()
{
    cin >> n;
    while (n != 0)
    {
          for (i = 1;i <= n;i++)
          for (j = 1;j <= n;j++)
              map[i][j] = -1;
          for (i = 1;i <= n;i++)
          {
              cin >> k;
              for (t = 1;t <= k;t++)
              {
                  cin >> j >> q;
                  map[i][j] = q;
              }
          }
          for (k = 1;k <= n;k++) //Floyd��ע��ѭ��Ƕ�ף��������� 
          for (i = 1;i <= n;i++)
          for (j = 1;j <= n;j++)
          if ((map[i][k] != -1) && (map[k][j] != -1))
          {
                         if (map[i][j] == -1)
                            map[i][j] = map[i][k]+map[k][j];
                         else
                         if (map[i][j] > map[i][k]+map[k][j])
                            map[i][j] = map[i][k]+map[k][j];
          }
          bool flag,tflag; //flag��¼�Ƿ��д𰸣�tflag��¼��I�����Ƿ���������N-1�˶���ϵ�� 
          int tmax,result,ans;
          flag = false;
          result = 0;
          ans = 0;
          for (i = 1;i <= n;i++)
          {
              tflag = false;
              tmax = 0;
              for (j = 1;j <= n;j++)
              if (i != j)
              {
                    if (map[i][j] == -1) //���������ϵ���ϣ���ô���TFLAG�����Ƴ�ѭ�� 
                    {
                                  tflag = true;
                                  break;
                    }
                    if (tmax < map[i][j]) //����������ֵ 
                       tmax = map[i][j];
              }
              if (tflag == false) //���ȫ��������ϵ�� 
              {
                        if (flag == false) //��ô���´� 
                        {
                                 flag = true;
                                 result = tmax;
                                 ans = i;
                        }
                        else
                            if (result > tmax)
                            {
                                       result = tmax;
                                       ans = i;
                            }
              }
          }
          if (flag == true)
             cout << ans << ' ' << result << endl;
          else
              cout << "disjoint" << endl;
          cin >> n;
    }
    return 0;
}
