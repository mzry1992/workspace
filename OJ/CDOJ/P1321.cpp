#include <stdio.h>

int tcase,fcase;
int n,m,i,j,k;
int x[11000],y[11000],w[11000];//����ߵ���Ϣ 
int f[110];//��¼�ڵ�I�ĸ��ڵ� 
int use[110];//����MST����Ϣ 
int sum;
bool flag;//���MST�Ƿ�Ψһ�����Ψһ��Ϊtrue�� 

int getsum()//ͨ��use������MST��Ȩֵ�� 
{
    int result = 0,i;
    for (i = 1;i <= n-1;i++)//����MST��N-1���ߣ��ۼӱ�Ȩֵ 
        result += w[use[i]];
    return result;
}
    
int findf(int x)//���鼯�Ĳ��Ҹ��ڵ���� 
{
    if (x != f[x]) f[x] = findf(f[x]);//·��ѹ�� 
    return f[x];
}

int MST()//Kruskal�㷨���� 
{
     int i,j,f1,f2,n1,n2;
     for (i = 1;i <= n;i++)//���ȹ���һ��ɭ�֣�ÿ����ֻ��һ���ڵ� 
         f[i] = i;
     j = 1;//J���浱ǰ������J���� 
     for (i = 1;i <= n-1;i++)//����N-1���� 
     {
         while (1 == 1)
         {
               while (w[j] == 19921005) j++;//���������ǵı�ֱ������ 
               n1 = x[j];
               n2 = y[j];
               f1 = findf(n1);
               f2 = findf(n2);
               if (f1 != f2)//������ṹ�ɻ� 
               {
                  f[f1] = f2;//�ϲ������� 
                  use[i] = j;//MST�ĵ�I����ΪJ 
                  j++;//J++ 
                  break;
               }
               else
                   j++;//������ɻ���ô����������         
         }
     }
     return 0;
}
     
void swap(int i,int j)
{
     int temp;
     temp = x[i]; x[i] = x[j]; x[j] = temp;
     temp = y[i]; y[i] = y[j]; y[j] = temp;
     temp = w[i]; w[i] = w[j]; w[j] = temp;
}

void qsort(int l,int r)//��Ȩֵ���� 
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

int work()//ɾ�߹��� 
{
    int tuse[110],i,j,tsum,tw;
    for (i = 1;i <= n-1;i++)//��¼ԭ�е�MST�ı���Ϣ 
        tuse[i] = use[i];
    for (i = 1;i <= n-1;i++)//ö��N-1���� 
    {
        tw = w[tuse[i]];
        w[tuse[i]] = 19921005;//������������ 
        MST();//���¼���MST 
        tsum = getsum();//�����MST�ı�Ȩֵ�� 
        if (tsum == sum)//�ж���ԭ���ı�Ȩֵ���ǻ����� 
        {
                 flag = false;//���MST��Ψһ�� 
                 return 0;//��֪MST��Ψһ����ô����ɾ���������Ѿ�û�������ˣ�����ֱ���˳����̡� 
        }
        w[tuse[i]] = tw;//�ָ���ɾ���ı� 
    }
    return 0;
}
     
int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= m;i++)
            scanf("%d %d %d",&x[i],&y[i],&w[i]);
        qsort(1,m);//���� 
        flag = true;
        MST();//��һ��MST 
        sum = getsum();
        work();//ɾ�� 
        if (flag == true)//��� 
           printf("%d\n",sum);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
