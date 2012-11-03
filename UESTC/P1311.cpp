#include <stdio.h>
#include <string.h>

int tcase,fcase;
int n,i;
char s[30];
struct nodetype//结点的类型（用邻接表存，这次我把两个数组压一起了，比以前方便多了 
{
       int end;//边的末尾结点 
       int next;//下一个 
       char word[30];//边表示的单词 
}node[2012];//保存邻接表 
int ans[2012];//保存答案   
int totans;//答案计数 
int totnode;//邻接表使用掉了的结点总数 
int in[26], out[26];//保存图的出度入度 
int f[1002];//并查集 

int findf(int i)//寻找根节点 
{
       if (f[i] != i)
              f[i] = findf(f[i]);
       return f[i];
}

 
void addpath(int u,int v,char s[])//添加一条边（终于知道怎么传字符串了） 
{
       int temp,now; 
       temp = node[u].next;//暂时保存邻接表下一个结点 
       now = u;//保存现在所处的结点 
       int f1,f2;
       while (temp != -1 && strcmp(node[temp].word, s) < 0)//找到末尾来 
       {
              now = temp;
              temp = node[temp].next;
       }
       //加到末尾 
       node[totnode].end = v;
       node[totnode].next = temp;
       strcpy(node[totnode].word, s);
       node[now].next = totnode;
       totnode++;
       //更新出度入度 
       in[v]++;
       out[u]++;
       //合并集合（判断图的连通性） 
       f1 = findf(u);
       f2 = findf(v);
       if (f1 != f2)
          f[f1] = f2;
}

int check(int n)// 检查连通性, 和存在欧拉路的充要条件（有向图）。
{
       int i;
       // 检查存在欧拉路的充要条件
       int t1, t2, t3, t4;
       t1 = t2 = t3 = 0;
       for (i = 1; i <= 26; i++)
       {
              if (in[i] == out[i] + 1) t2++;//只存在一个出度比入度少一的结点 
              else 
              if (in[i] + 1 == out[i]) t3++;//只存在一个入度比出度少一的结点 
              else 
              if (in[i] != out[i]) return false;  //如果不是上面的情况，那么必定不存在 
       }
       if ((t2 > 1 ) || (t3 > 1) || (t2 != t3)) return false; 
       int flag,temp,x;
       flag = false;
       temp = -1;
       for (i = 1;i <= 26;i++)//检查连通性，如果整个图都是联通的，那么显然所有的点都在一个树上！ 
       {
              if (in[i]+out[i] > 0)
              {
                     x = findf(i);
                     if (temp == -1) temp = x;
                     else
                     {
                            if (temp != x) return false; //如果不在同一棵树上，那么就不连通了 
                     }
              }
       }
       return true;
}
 
void euler(int now,int tpath) //now为当前遍历到的节点 tpath为now的来源（从那个边遍历过来的）  
{    
       int temp;   
       while(node[now].next != -1)   
       {   
              temp = node[now].next;   
              node[now].next = node[temp].next;//删除使用掉的边  
              euler(node[temp].end,temp);//递归处理   
       }   
       ans[totans++] = tpath; //保存结点（后序记录，所以输出的时候要反向） 
}

void output(bool flag)
{
       int i;
       if (flag)  //如果有答案
       {
              for (i = totans - 2;i >= 1;i--)//逆序输出 
                     printf("%s.", node[ans[i]].word); 
              printf("%s\n", node[ans[0]].word); //输出第一个 
       }
       else
              printf("***\n");//否则无答案 
} 

int main ()
{
       scanf("%d", &tcase);
       for (fcase = 1;fcase <= tcase;fcase++)
       {
              scanf("%d", &n);
              for (i = 1;i <= 26;i++)//初始化 
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
              if (!check(26))//如果不是一个欧拉图 
              {
                     output(false);//输出。 
                     continue;//继续上面的for循环（直接处理下一组数据了） 
              }
              int flag;
              flag = false; 
              for (i = 1; i <= 26; i++)//首先判断是否存在欧拉路 
              {
                     if (out[i] == in[i] + 1)//如果哪个点的出度比入度多1，那么从这个点开始找 
                     {
                            euler(i, -1);
                            flag = true;//标记 
                            break;
                     }
              }
              if (flag == false)//如果没有欧拉路，那么找欧拉回路 
              {
                     for (i = 1; i <= 26; i++)
                            if (out[i])//随便从一个点开始 
                            {
                                   euler(i, -1);//找 
                                   break;
                            }
              }
              output(true);//输出 
       }
}

