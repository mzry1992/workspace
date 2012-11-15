#include <stdio.h>

int n,m,i,j;
int f1,f2,l;
/*
��������Ĵ��淽ʽ 
*/
struct nodetype//����������ͣ������棩 
{
       int next;//��һ����� 
       int tail;//��¼�����β��� 
       int node;//��¼��ǰ����������Ǹ�ũ�� 
       int dis;//��¼�˵��붥��ľ��� 
}nodelist[100000],no[50000];//nodelistΪ��������no���涥�� 
int totn;//nodelistһ���ж��ٸ��� 
int dis[50000];//SPFA�б����������� 
int start,end;//����ͼ��һ���˵�;�������˵���Զ�ĵ� 

void add(int s,int t,int d)//����һ����s��t����Ϊd�ı� 
{
     totn++;//����+1 
     nodelist[totn].node = t;//��� 
     nodelist[totn].next = 0;//��һ����㣬0����NUL 
     nodelist[totn].dis = d;//���� 
     if (no[s].next == 0)//�����ǰ����ı���Ϊ0��ֱ�Ӽ��ں��� 
                    no[s].tail = no[s].next = totn;
     else
     {
         nodelist[no[s].tail].next = totn;   //������������ĩβ 
         no[s].tail = totn;   //����ĩβָ�� 
     }
}

int SPFA(int s)//SPFA���� 
{
    int d[400000],head,tail,now;//���� 
    int use[50000];//��ǽ�� 
    int i,j,tans;//���ش��õ� 
    for (i = 1;i <= n;i++)//�Ը������鸳��ֵ 
    {
        use[i] = false;
        dis[i] = -19921005;//��ҪŪһ������С��ֵ�����ܻ����ˣ���������Ļ�SPFA��ô�����ɳڲ����أ�ע���£�����һ����������ÿ���ڵ�ֻ����һ�Σ����ԣ����н��ֻ���ɳ�һ�Σ� 
    }
    head = tail = 1;//��ʼ������ 
    d[1] = s;
    use[s] = true;//���S�� 
    dis[s] = 0;//S�㵽S��ľ���϶���0�� 
    while (head <= tail)//������в�Ϊ�� 
    {
          now = d[head];//ȡ����ͷ 
          use[now] = false;//�ͷŽ�� 
          head++;//��ͷ+1 
          for (i = no[now].next;i != 0;i = nodelist[i].next)//ö�ٴ˽��������ڽӵ㣨����C���Ե�forѭ��������ԣ�̫���˳Ծ��ˣ��� 
          {
                if (dis[nodelist[i].node] < nodelist[i].dis+dis[now])//��׼��SPFA�ˣ�ע��������С�ںţ�û��ϵ����ϸ�����£����еĽ��ֻ���ɳ�һ�Σ���ô���������ֵ�趨Ϊ�㹻С��Ȼ���ɳڵ�ʱ����С�ں��жϣ��������Ǿ��ܱ�֤ÿ�����ֻ���ɳ�һ���أ�����������Ļ���ע�⵽�������������ͼ�����ԣ����л�����S-->T-->S���������Ǹ���������������ж�ÿ�����ֻ�ɳ�һ�εĻ�������ѭ���ģ�       
                if (nodelist[i].node != s)//ע�⣬����һ������ÿ�����ֻ�ܹ���һ�Σ����� 
                {//�����SPFAһ���� 
                   dis[nodelist[i].node] = nodelist[i].dis+dis[now];
                   if (use[nodelist[i].node] == false)
                   {
                      use[nodelist[i].node] = true;
                      tail++;
                      d[tail] = nodelist[i].node;
                   }
                }
          }
    }
    j = 0;//��¼��S����Զ�ĵ㵽S��ľ��� 
    tans = 0;//��¼��������ĸ��� 
    for (i = 1;i <= n;i++) 
    if (dis[i] < j)//ע�����ǵı��Ǹ����� 
    {
               j = dis[i];//���� 
               tans = i;
    }
    return tans;//��������� 
}

int main()
{
    scanf("%d %d",&n,&m);
    for (i = 1;i <= n;i++)//���ڽӱ��ʼ�� 
        no[i].next = 0;
    totn = 0; 
    for (i = 1;i <= m;i++)
    {
        scanf("%d %d %d",&f1,&f2,&l);
        getchar();//����Ǹ��ַ�ֱ�Ӻ��Ե��ɣ����ǲ�֪������ô�����ˣ�������û�з��������ĸ��ʲôʵ���ô��� 
        getchar();//��Ҫ����һ���س��� 
        //ע�⣬SPFAҪ��������·������Ŀ���·�����ǲ����Ѿ���ĳɸ�������ô�����ǿ��԰��·������·�𣿶�����������һ���������ԣ�ÿ����ֻ��Ҫ����һ�μ��ɣ����ԣ�����Ҫ���ĸ��������⣬������ǰ�ỹ��Ҫ��SPFA���ԸĶ�һ�� 
        add(f1,f2,-l);//����f1-->f2 
        add(f2,f1,-l);//����f2--f1
    }
    start = SPFA(1);//���ȣ��ҵ�����һ���˵� 
    end = SPFA(start);//Ȼ���ҵ���һ���˵� 
    printf("%d\n",-dis[end]);//����·�ĳ��ȣ����ڱ����Ǹĳ��˸���������Ҫ�Ӹ������������������ 
    return 0;
}
