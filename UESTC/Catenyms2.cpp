#include <stdio.h>
#include <string.h>

int tcase,fcase;
int n,i;
char s[30];
struct nodetype
{
       int end;
       int next;
       char word[30];
}node[2012];
int ans[2012];   // ????????? ??
int totans;
int totnode;
int in[26], out[26];
int f[1002];

int findf(int i)
{
       if (f[i] != i)
              f[i] = findf(f[i]);
       return f[i];
}

void euler(int now, int edgeN) //cur??????? edgeN???????,????????edgeN???cur
{
       int i;
       while(node[now].next != -1)
       {
              i=node[now].next;
              node[now].next=node[i].next;//????????????
              euler(node[i].end,i);
       }
       ans[totans++] = edgeN; //????,??????????????,?????
}

void addpath(int u, int v, char s[])
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
       node[now].next = totnode++;
       in[v]++;
       out[u]++;
       f1 = findf(u);
       f2 = findf(v);
       if (f1 != f2)
          f[f1] = f2;
}

void output(bool flag)
{
       if (flag)  // ???????????
       {
              for (int i = totans - 2; i >= 1; i--)
              {
                     printf("%s.", node[ans[i]].word);
              }
              printf("%s\n", node[ans[0]].word);
       }
       else
       {
              printf("***\n");
       }
}
// ?????, ???????????(???)?
bool check(int n)
{
       int i;
       // ????????????
       int t1, t2, t3, t4;
       t1 = t2 = t3 = t4 = 0;
       for (i = 1; i <= 26; i++)
       {
              if (in[i] == out[i] + 1)t2++;
              else if (in[i] + 1 == out[i])t3++;
              else if (in[i] != out[i]) t4 = 1;  // ?????
       }
       if (t4 || t2 > 1 || t3 > 1 || t2 != t3) return false;
       // ?????
       int flag = false, tmp = -1, x;
       for (i = 1; i <= 26; i++)
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
              totans = 0;
              for (i = 1; i <= n; i++)
              {
                     scanf("%s", s);
                     addpath(s[0] - 'a'+1, s[strlen(s) - 1] - 'a'+1, s);
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

