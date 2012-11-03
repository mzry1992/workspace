#include <stdio.h>

int tcase,fcase;
int n,m,i,j,a,b,flag;
int map[210][210];//����������������ϵ�����õ����ڽӱߴ洢�� 
int indegree[210];//����������� 
int ans[210];//�����
int AOV[210];//������������ 

int solve()//��Ҫ���� 
{
     int i,j,k,use[210];
     for (i = 1;i <= n;i++)//��ǽ��I�Ƿ��Ѿ�ɾ�� 
         use[i] = false;
     for (i = 1;i <= n;i++)//��Ҫ�ҵ�N�������뵽���������� 
     {
         for (j = n;j >= 1;j--)//�������Ҫ�����ȿ��ǽ���Ŵ�Ľ�� 
         if (use[j] == false)
             if (indegree[j] == 0) break;
         if (j == 0)//���û���ҵ����Ϊ0�Ľ�� 
         {
               flag = false;//����޽� 
               return 0;//�˳� 
         }
         AOV[i] = j;//������뵽���������� 
         use[j] = true;//���J�㱻ɾ�� 
         for (k = 1;k <= map[j][0];k++)//��J�������ĵ����ȼ�1 
             indegree[map[j][k]]--;
     }
     j = n;//�������ΪN 
     for (i = 1;i <= n;i++)//��������˳�������� 
     {
         ans[AOV[i]] = j;//��AOV[I]��������ΪJ 
         j--;//��һ��������ΪJ-1 
     }
     return 0;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n;i++)//��ʼ���ڽӱ������������� 
        {
            map[i][0] = 0;
            indegree[i] = 0;
        }
        for (i = 1;i <= m;i++)//�������� 
        {
            scanf("%d %d",&a,&b);
            map[b][0]++;//����һ���������෴��ͼ 
            map[b][map[b][0]] = a;
            indegree[a]++;
        }
        flag = true;//����Ƿ��н� 
        solve();//���� 
        if (flag == true)//����н⣬��ô������������������ 
        {
                 for (i = 1;i < n;i++)
                     printf("%d ",ans[i]);
                 printf("%d\n",ans[n]);//ע�����һ�������������û�пո񣬷����PE 
        }
        else
            printf("-1\n");//�������-1 
    }
    return 0;
}
