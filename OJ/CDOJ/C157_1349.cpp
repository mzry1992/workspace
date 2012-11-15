#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int tcase,fcase;
int n,i;
char s[30],ts[30];
struct nodetype
{
       int end;
       int next;
       char word[30];
}node[2012];
int totnode;
int in[26], out[26];
int f[1002]; 
int order;

int findf(int i)
{
       if (f[i] != i)
              f[i] = findf(f[i]);
       return f[i];
}

 
void addpath(int u,int v,char s[],int order)
{
       int temp,now; 
       temp = node[u].next;
       now = u;
       int f1,f2;
       while (temp != -1 && strcmp(node[temp].word, s) < 0)
       {
              now = temp;
              temp = node[temp].next;
       }
       node[totnode].end = v;
       node[totnode].next = temp;
       strcpy(node[totnode].word, s);
       node[now].next = totnode;
       totnode++;
       if (order == 0)
       {
                 in[v]++;
                 out[u]++;
       }
       f1 = findf(u);
       f2 = findf(v);
       if (f1 != f2)
          f[f1] = f2;
}

int check(int n)
{
       int i;
       int t1, t2, t3, t4;
       t1 = t2 = t3 = 0;
       for (i = 1; i <= 26; i++)
       {
              if (in[i] == out[i] + 1) t2++;
              else 
              if (in[i] + 1 == out[i]) t3++;
              else 
              if (in[i] != out[i]) return false; 
       }
       if ((t2 > 1 ) || (t3 > 1) || (t2 != t3)) return false; 
       int flag,temp,x;
       flag = false;
       temp = -1;
       for (i = 1;i <= 26;i++)
       {
              if (in[i]+out[i] > 0)
              {
                     x = findf(i);
                     if (temp == -1) temp = x;
                     else
                            if (temp != x) return false;
              }
       }
       return true;
}

void output(bool flag)
{
       int i;
       printf("Case %d: ",fcase);
       if (flag)
          printf("Well done!\n");
       else
           printf("Poor boy!\n");
} 

int main ()
{
       scanf("%d", &tcase);
       for (fcase = 1;fcase <= tcase;fcase++)
       {
              scanf("%d", &n);
              for (i = 1;i <= 26;i++)
              {
                  in[i] = out[i] = 0;
                  f[i] = i;
                  node[i].next = -1;
              }
              totnode = 26;
              for (i = 1; i <= n; i++)
              {
                     scanf("%s%d",&s,&order); 
                     addpath(s[0] - 'a'+1, s[strlen(s) - 1] - 'a'+1, s, 0);
                     if (order == 1)
                     {
                               int j;
                               for (j = 0;j < strlen(s);j++)
                                   ts[j] = s[strlen(s)-1-j];
                               ts[strlen(s)] = '\0';
                               addpath(ts[0] - 'a'+1, ts[strlen(ts) - 1] - 'a'+1, ts, 1);
                     }
              }
              if (!check(26))
                     output(false);
              else
              output(true);
       }
}

