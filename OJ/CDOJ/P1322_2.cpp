#include <stdio.h>
#define MAX 1000//������� 
#define MAXV 519921005//MAXV�������ֵ 

int tcase,fcase;//���������� 
int n,m,i,j,k,a,b,e,q;
int map[MAX][MAX];//��ԭʼ�ı����� 
int tasko[11000],taska[11000],taskb[11000];//����Q������ 
int delnode[MAX],totd,node[MAX],tnode[MAX];//��Խ���ӳ����������ص����� 
int newnodelist[MAX],tottemp,ys[MAX];//�µĽ��˳�򡢽���ӳ�� 
int newmap[MAX][MAX];//�µı߱� 
int ans[11000],totans,now;//�������д� 

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
                map[i][j] = MAXV;//���߸���ֵ 
            node[i] = true;//��ǽ��Iδ��ɾ�� 
            map[i][i] = 0;//��I���Լ��ľ���Ϊ0 
        }
        for (i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&a,&b,&e);//���� 
            if (map[a][b] > e)//������رߣ�ȡ��С������ 
            {
               map[a][b] = e;
               map[b][a] = e;
            }
        }
        //�ȶ�����������ߴ��� 
        scanf("%d",&q);
        totd = 0;//����ɾ���ĵ��� 
        for (i = 1;i <= q;i++)
        {
            scanf("%d",&tasko[i]);
            if (tasko[i] == 0)
                      scanf("%d %d",&taska[i],&taskb[i]);
            if (tasko[i] == 1)//�����ɾ����� 
            {
                      scanf("%d",&taska[i]);
                      totd++;
                      delnode[totd] = taska[i];//���뵽��Ҫɾ���Ľ���б� 
                      node[taska[i]] = false;//��Ǵ˵㱻ɾ 
            }
        }
        tottemp = 0;//�����ж��ٸ����δ��ɾ 
        for (i = 1;i <= n;i++)
        if (node[i] == true)//������Iδ��ɾ 
        {
                    tottemp++;
                    newnodelist[tottemp] = i;//��δ��ɾ�Ľ����뵽�½��˳���ǰ�� 
        }
        for (i = 1;i <= totd;i++)//����ɾ�ĵ㰴��ɾ����˳���������뵽�µĽ��˳�� 
            newnodelist[n+1-i] = delnode[i];
        for (i = 1;i <= n;i++)//����ӳ���ϵ 
        {
            ys[newnodelist[i]] = i;
            tnode[i] = false;//��Ǹõ㲻���� 
        }
        for (i = 1;i <= n;i++)//ת�浽�µ��ڽӾ����С� 
        for (j = 1;j <= n;j++)
            newmap[i][j] = map[newnodelist[i]][newnodelist[j]];
        totans = 0;//����ѯ�����·���������� 
        for (k = 1;k <= tottemp;k++)//���1�����tottemp����δ��ɾ���Ľ�㣬���������I����Jֻ�������1�����tottemp�����·�� 
        {
            for (i = 1;i <= n;i++)
            for (j = 1;j <= n;j++)
            if (newmap[i][j] > newmap[i][k]+newmap[k][j])
                newmap[i][j] = newmap[i][k]+newmap[k][j];
            tnode[k] = true;//��ǽ��Kδ��ɾ�� 
        }
        now = tottemp;//���ڣ�δ��ɾ���Ľ��һ���н��1�����now 
        for (k = q;k >= 1;k--)//���ǽ������������ɾ���������������ӽ������� 
        {
            if (tasko[k] == 0)//����ѯ�����·���� 
            {
                           totans++;
                           ans[totans] = newmap[ys[taska[k]]][ys[taskb[k]]];//ͨ��ӳ���ϵ�ҵ����· 
                           if (ans[totans] == MAXV) ans[totans] = -1;//���û��ͨ·����ô���-1 
                           if ((tnode[ys[taska[k]]] == false) || (tnode[ys[taskb[k]]] == false))//����Ҫע�⣡���Ҫ���ĳ���˵㱻�ݻ٣���ô�Ͳ��������· 
                              ans[totans] = -1;
            }
            else
            {//����ɾ����Ĳ��������������ǽ�����˹��������Կ��Կ��������ӽ��Ĳ��� 
                           now++;//���ӽ�� 
                           tnode[now] = true;//��ǽ��û�б��ݻ� 
                           for (i = 1;i <= n;i++)//������I�����Jֻ�������1��now�����· 
                           for (j = 1;j <= n;j++)
                           if (newmap[i][j] > newmap[i][now]+newmap[now][j])
                              newmap[i][j] = newmap[i][now]+newmap[now][j];
            }
        }
        for (i = totans;i >= 1;i--)//ans�д洢�Ĵ�������ģ��������ҲҪ���� 
            printf("%d\n",ans[i]);
        printf("\n");//ע������Ҫ���еĿ��� 
    }
    return 0;
}
            
        
        
