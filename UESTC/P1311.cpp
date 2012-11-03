#include <stdio.h>
#include <string.h>

int tcase,fcase;
int n,i;
char s[30];
struct nodetype//�������ͣ����ڽӱ�棬����Ұ���������ѹһ���ˣ�����ǰ������� 
{
       int end;//�ߵ�ĩβ��� 
       int next;//��һ�� 
       char word[30];//�߱�ʾ�ĵ��� 
}node[2012];//�����ڽӱ� 
int ans[2012];//�����   
int totans;//�𰸼��� 
int totnode;//�ڽӱ�ʹ�õ��˵Ľ������ 
int in[26], out[26];//����ͼ�ĳ������ 
int f[1002];//���鼯 

int findf(int i)//Ѱ�Ҹ��ڵ� 
{
       if (f[i] != i)
              f[i] = findf(f[i]);
       return f[i];
}

 
void addpath(int u,int v,char s[])//���һ���ߣ�����֪����ô���ַ����ˣ� 
{
       int temp,now; 
       temp = node[u].next;//��ʱ�����ڽӱ���һ����� 
       now = u;//�������������Ľ�� 
       int f1,f2;
       while (temp != -1 && strcmp(node[temp].word, s) < 0)//�ҵ�ĩβ�� 
       {
              now = temp;
              temp = node[temp].next;
       }
       //�ӵ�ĩβ 
       node[totnode].end = v;
       node[totnode].next = temp;
       strcpy(node[totnode].word, s);
       node[now].next = totnode;
       totnode++;
       //���³������ 
       in[v]++;
       out[u]++;
       //�ϲ����ϣ��ж�ͼ����ͨ�ԣ� 
       f1 = findf(u);
       f2 = findf(v);
       if (f1 != f2)
          f[f1] = f2;
}

int check(int n)// �����ͨ��, �ʹ���ŷ��·�ĳ�Ҫ����������ͼ����
{
       int i;
       // ������ŷ��·�ĳ�Ҫ����
       int t1, t2, t3, t4;
       t1 = t2 = t3 = 0;
       for (i = 1; i <= 26; i++)
       {
              if (in[i] == out[i] + 1) t2++;//ֻ����һ�����ȱ������һ�Ľ�� 
              else 
              if (in[i] + 1 == out[i]) t3++;//ֻ����һ����ȱȳ�����һ�Ľ�� 
              else 
              if (in[i] != out[i]) return false;  //�������������������ô�ض������� 
       }
       if ((t2 > 1 ) || (t3 > 1) || (t2 != t3)) return false; 
       int flag,temp,x;
       flag = false;
       temp = -1;
       for (i = 1;i <= 26;i++)//�����ͨ�ԣ��������ͼ������ͨ�ģ���ô��Ȼ���еĵ㶼��һ�����ϣ� 
       {
              if (in[i]+out[i] > 0)
              {
                     x = findf(i);
                     if (temp == -1) temp = x;
                     else
                     {
                            if (temp != x) return false; //�������ͬһ�����ϣ���ô�Ͳ���ͨ�� 
                     }
              }
       }
       return true;
}
 
void euler(int now,int tpath) //nowΪ��ǰ�������Ľڵ� tpathΪnow����Դ�����Ǹ��߱��������ģ�  
{    
       int temp;   
       while(node[now].next != -1)   
       {   
              temp = node[now].next;   
              node[now].next = node[temp].next;//ɾ��ʹ�õ��ı�  
              euler(node[temp].end,temp);//�ݹ鴦��   
       }   
       ans[totans++] = tpath; //�����㣨�����¼�����������ʱ��Ҫ���� 
}

void output(bool flag)
{
       int i;
       if (flag)  //����д�
       {
              for (i = totans - 2;i >= 1;i--)//������� 
                     printf("%s.", node[ans[i]].word); 
              printf("%s\n", node[ans[0]].word); //�����һ�� 
       }
       else
              printf("***\n");//�����޴� 
} 

int main ()
{
       scanf("%d", &tcase);
       for (fcase = 1;fcase <= tcase;fcase++)
       {
              scanf("%d", &n);
              for (i = 1;i <= 26;i++)//��ʼ�� 
              {
                  in[i] = out[i] = 0;
                  f[i] = i;
                  node[i].next = -1;
              }
              totnode = 26;
              totans = 0;
              for (i = 1; i <= n; i++)
              {
                     scanf("%s", s); 
                     addpath(s[0] - 'a'+1, s[strlen(s) - 1] - 'a'+1, s);
              }
              if (!check(26))//�������һ��ŷ��ͼ 
              {
                     output(false);//����� 
                     continue;//���������forѭ����ֱ�Ӵ�����һ�������ˣ� 
              }
              int flag;
              flag = false; 
              for (i = 1; i <= 26; i++)//�����ж��Ƿ����ŷ��· 
              {
                     if (out[i] == in[i] + 1)//����ĸ���ĳ��ȱ���ȶ�1����ô������㿪ʼ�� 
                     {
                            euler(i, -1);
                            flag = true;//��� 
                            break;
                     }
              }
              if (flag == false)//���û��ŷ��·����ô��ŷ����· 
              {
                     for (i = 1; i <= 26; i++)
                            if (out[i])//����һ���㿪ʼ 
                            {
                                   euler(i, -1);//�� 
                                   break;
                            }
              }
              output(true);//��� 
       }
}

