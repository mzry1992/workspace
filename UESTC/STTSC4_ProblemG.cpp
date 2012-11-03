/*
Problem G

The Lightest Cycle  

Description 

����Given a directed weighted graph who has at least three nodes, can you find the minimal directed weighted cycle with at least three nodes?

Input 

����The input contains a single test case.
����In the first line there is two integer n - the number of nodes in the graph, m - the number of directed edges in the graph. (0 < n <= 100, 0 <= m <= n^2)
����Then m lines follow, each line contains three integers i j k, which means that there is a directed edge coming from node i to node j with a weight of k (0 <= k < 2^15). 
 
Output 

����You should output a single line with a single integer presenting the weight of the cycle you have found or "-1" (without quotes) if there isn't any.

Sample Input 

5 7
4 0 19
0 3 20
4 3 50
2 3 1
3 1 10
1 4 2
1 2 39

Sample Output 

50

Source 
���Ŵ�ѧ���Ľ������ƾ��� �ֳ����� 
*/

//������Ŀ̫ˮ�ˣ���һ������ͼ����С����Ҫ�󻷵Ľڵ����2����
//��ʼ��������ͼ�ˣ����˼��Σ�����֪��������ͼ���������ˣ�һ��FLOYDֱ�Ӹ㶨��
//������Ŀ������������ͼ�����ԣ�FLOYD�㷨�еĽ��dis[i][j]��ʾ��i��j�����·��dis[j][i]��ʾ��j��i�����·��
//����������·��Ȼ������ͬһ��·����Ϊ������ͼ�ˣ������ԣ���һ��FLOYD��Ȼ��ö�ٻ��������˵㣬����������
//���ȣ������һ��������Ȼ�����ж�һ��������Ľڵ����Ƿ����2����һ��ȽϺð죬����ö�����е�kѰ���Ƿ���
//dis[i][k]+dis[k][j]+dis[j][i] = dis[i][j]+dis[j][i]���������������ⷽ����߾��Ǵ�i��k�ٴ�k��j�ٴ�j�ص�
//i�Ļ����ȣ������������Ȼ�����ж�������Ľڵ�������2�����ҵ�������ȥ��ʱ����ʶ������һ�㣬��ϧ����̫���ˣ� 

#include <stdio.h>   

long n,m,i,j,k,q,s,t,e,map[150][150];
long ans,tans;
long dis[150][150]; //dis���� 

int main()
{
    scanf("%ld %ld",&n,&m);
    for (i = 0;i < n;i++)
    for (j = 0;j < n;j++)
        map[i][j] = -1;
    for (i = 1;i <= m;i++)
    {
        scanf("%ld %ld %ld",&s,&t,&e);
        map[s][t] = e;
    }
    for (j = 0;j < n;j++)
    for (k = 0;k < n;k++)
        dis[j][k] = map[j][k];
    for (k = 0;k < n;k++) //��׼��FLOYD��ע��ѭ��Ƕ�ף���������׳��� 
    for (j = 0;j < n;j++)
    for (q = 0;q < n;q++)
    if (dis[j][k] != -1)
    if (dis[k][q] != -1)
    {
       if (dis[j][q] == -1)
          dis[j][q] = dis[j][k]+dis[k][q];
       else
           if (dis[j][q] > dis[j][k]+dis[k][q])
           dis[j][q] = dis[j][k]+dis[k][q];
    }
    ans = -1;
    for (i = 0;i < n;i++) //ö�ٶ˵� 
    for (j = 0;j < n;j++)
    if (i != j)
    if (dis[i][j] != -1)
    if (dis[j][i] != -1)
    {
                  tans = dis[i][j]+dis[j][i]; 
                  if ((map[i][j] != -1) && (map[j][i] != -1))
                  if (tans == map[i][j]+map[j][i]) //ע�������жϻ��ĵ����Ƿ����2�Ǵ���ġ� 
                     break;
                  if (ans == -1)
                     ans = tans;
                  else
                      if (ans > tans)
                         ans = tans;
    }
    printf("%ld\n",ans);
    //getchar();
    //getchar();
    return 0;
}
        
    
 
