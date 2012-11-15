#include <stdio.h>

int n,m,i;
int x[10100],y[10100],w[10100];//�洢�ߵ���Ϣ 
int ans;//����� 
int f[110];//�������ĸ��ڵ㣨kruskal�㷨�� 

void swap(int i,int j)//������� 
{
     int temp;
     temp = x[i]; x[i] = x[j]; x[j] = temp;
     temp = y[i]; y[i] = y[j]; y[j] = temp;
     temp = w[i]; w[i] = w[j]; w[j] = temp;
}

void qsort(int l,int r)//�������� 
{
     int tl,tr,m;
     tl = l;
     tr = r;
     m = w[(tl+tr)/2];
     while (tl < tr)
     {
           while (w[tl] < m) tl++;
           while (w[tr] > m) tr--;
           if (tl <= tr)
           {
                  swap(tl,tr);
                  tl++;
                  tr--;
           }
     }
     if (tl < r) qsort(tl,r);
     if (l < tr) qsort(l,tr);
}

int findf(int x)//���鼯��Ѱ�Ҹ��ڵ���� 
{
    if (f[x] != x) f[x] = findf(f[x]);//·��ѹ�� 
    return f[x];
}

int solve()//������ 
{
     int min,max;//��¼�������е���С��Ȩֵ������Ȩֵ 
     int i,j;
     int n1,n2,f1,f2; 
     int tot;//���������Ѿ����ڶ������� 
     for (i = 1;i <= m+1-(n-1);i++)//ö����С�� 
     {
         min = w[i];//��С��Ȩֵ 
         for (j = 1;j <= n;j++)//��F���鸳��ֵ 
             f[j] = j;
         j = i;//ȷ������С�ߣ��������е������ߴ�Сһ��������С�ߣ����ԣ�С����С�ߵı�Ӧ�ñ����� 
         tot = 0;
         while (1 == 1)
         {
             n1 = x[j]; 
             n2 = y[j];
             f1 = findf(n1);
             f2 = findf(n2);
             if (f1 != f2)//��������ɻ� 
             {
                    f[f1] = f2;//�ϲ� 
                    tot++;//��������һ 
                    if (tot == n-1)//���ڱ��ǰ���Ȩֵ�������У����ԣ�����һ�������һ������ı� 
                    { 
                          max = w[j];
                          if (max-min < ans) //���´� 
                             ans = max-min;
                          break;//�˳� 
                    }
             }
             j++;//�ж���һ���� 
             if (j > m) //���û�б߿���ѡ���ˣ���ô�˳� 
              break;
             if (w[j]-min >= ans)//�����ʱ�ı�Ȩֵ��ȥ��С��Ȩֵ���ڴ𰸣���ô�϶��޷��õ����Ž⣬�����˳� 
              break;
         }
     }
     return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    while (!((n == 0) && (m == 0)))
    {
          for (i = 1;i <= m;i++)
              scanf("%d %d %d",&x[i],&y[i],&w[i]);
          qsort(1,m);//���� 
          ans = 19921005;//��ans����ֵ 
          solve();//���� 
          if (ans != 19921005)//����д𰸣���ans���޸Ĺ��� 
             printf("%d\n",ans);//��ô����� 
          else
              printf("-1\n",ans);//����˵���޽� 
          scanf("%d %d",&n,&m);
    }
    return 0;
}
