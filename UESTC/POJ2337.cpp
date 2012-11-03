#include <stdio.h>
#include <string.h>

const int V = 30;
int tcase,fcase;
int n,i;
char s[30];
struct Adj
{
       int end;
       int nxt;
       char word[30];
}adj[2012];
int path[2012];   // ���������Ȼ��С�� ����
int nPath;
int adjN;
int in[V], out[V];
int f[1002];
 
int findf(int x)
{
       if (f[i] != i)         f[i] = findf(f[i]);
       return f[i];
}

void euler(int cur, int edgeN) //cur��ǰ����Ľڵ� edgeN��һ��ѡ��ıߣ�����һ���ڵ�ͨ��edgeN�����cur   
{    
       int i;   
       while(adj[cur].nxt != -1)   
       {   
              i=adj[cur].nxt;   
              adj[cur].nxt=adj[i].nxt;//�൱����ɾ����ʹ���˵ı�   
              euler(adj[i].end,i);   
       }   
       path[nPath++] = edgeN; //�����¼�����Ҫ��������ʱ��ߵ����ȼ������������   
}
 
void addEdge(int u, int v, char s[])
{
       int f1,f2;
       int k = adj[u].nxt;
       int cur = u;
       while (k != -1 && strcmp(adj[k].word, s) < 0)
       {
              cur = k;
              k = adj[k].nxt;
       }
       adj[adjN].end = v;
       adj[adjN].nxt = k;
       strcpy(adj[adjN].word, s);
       adj[cur].nxt = adjN++;
       in[v]++, out[u]++;
       if (findf(u) != findf(v))
       {
          f1 = findf(u);
          f2 = findf(v);
          f[f2] = f1;
       }
}

void init(int n)  // ���Ϊ0~n-1
{
       memset(in, 0, sizeof(in));
       memset(out, 0, sizeof(out));
       adjN = V;
       nPath = 0;
       for (int i = 0; i < n; i++)adj[i].nxt = -1;
}

void output(bool flag)
{
       if (flag)  // ����ŷ��·����ŷ����·
       {
              for (int i = nPath - 2; i > 0; i--)    
                     printf("%s.", adj[path[i]].word); 
              printf("%s\n", adj[path[0]].word); 
       }
       else
       {
              printf("***\n");
       }
}
// �����ͨ��, �ʹ���ŷ��·�ĳ�Ҫ����������ͼ����
bool check(int n)  
{
       int i;
       // ������ŷ��·�ĳ�Ҫ����
       int t1, t2, t3, t4;
       t1 = t2 = t3 = t4 = 0;
       for (i = 0; i < 26; i++)
       {
              if (in[i] == out[i] + 1)t2++;
              else if (in[i] + 1 == out[i])t3++;
              else if (in[i] != out[i]) t4 = 1;  // �ض�������
       }
       if (t4 || t2 > 1 || t3 > 1 || t2 != t3) return false; 
       // �����ͨ��
       int flag = false, tmp = -1, x;
       for (i = 0; i < 26; i++)
       {
              if (in[i] + out[i] > 0)
              {
                     x = findf(i);
                     if (tmp == -1) tmp = x;
                     else
                     {
                            if (tmp != x)return false;
                     }
              }
       }
       return true;
}

int main ()
{
       scanf("%d", &tcase);
       for (fcase = 1;fcase < tcase;fcase++)
       {
              scanf("%d", &n); 
              for (int i = 1; i < 26; i++)
                       f[i] = i;
              for (i = 1; i <= n; i++)
              {
                     scanf("%s", s); 
                     addEdge(s[0] - 'a', s[strlen(s) - 1] - 'a', s);
              }
              if (!check(26))
              {
                     output(false);
                     continue;
              }
              int flag = 0;
              for (i = 0; i < 26; i++)
              {
                     if (out[i] == in[i] + 1)
                     {
                            euler(i, -1);
                            flag = 1;
                            break;
                     }
              }
              if (!flag)
              {
                     for (i = 0; i < 26; i++)
                            if (out[i])
                            {
                                   euler(i, -1);
                                   break;
                            }
              }
              output(true);
       }
}
