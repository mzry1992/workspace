#include <stdio.h>
#define MAX 1000//结点总数 
#define MAXV 519921005//MAXV代表最大值 

int tcase,fcase;//测试数据数 
int n,m,i,j,k,a,b,e,q;
int map[MAX][MAX];//存原始的边数据 
int tasko[11000],taska[11000],taskb[11000];//保存Q条命令 
int delnode[MAX],totd,node[MAX],tnode[MAX];//与对结点的映射重排序相关的数组 
int newnodelist[MAX],tottemp,ys[MAX];//新的结点顺序、结点的映射 
int newmap[MAX][MAX];//新的边表 
int ans[11000],totans,now;//保存所有答案 

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
                map[i][j] = MAXV;//给边赋初值 
            node[i] = true;//标记结点I未被删除 
            map[i][i] = 0;//点I到自己的距离为0 
        }
        for (i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&a,&b,&e);//读入 
            if (map[a][b] > e)//如果有重边，取最小的那条 
            {
               map[a][b] = e;
               map[b][a] = e;
            }
        }
        //先读入命令，再离线处理！ 
        scanf("%d",&q);
        totd = 0;//保存删除的点数 
        for (i = 1;i <= q;i++)
        {
            scanf("%d",&tasko[i]);
            if (tasko[i] == 0)
                      scanf("%d %d",&taska[i],&taskb[i]);
            if (tasko[i] == 1)//如果是删点操作 
            {
                      scanf("%d",&taska[i]);
                      totd++;
                      delnode[totd] = taska[i];//加入到需要删除的结点列表 
                      node[taska[i]] = false;//标记此点被删 
            }
        }
        tottemp = 0;//保存有多少个结点未被删 
        for (i = 1;i <= n;i++)
        if (node[i] == true)//如果结点I未被删 
        {
                    tottemp++;
                    newnodelist[tottemp] = i;//将未被删的结点加入到新结点顺序的前端 
        }
        for (i = 1;i <= totd;i++)//将被删的点按照删除的顺序的逆序加入到新的结点顺序 
            newnodelist[n+1-i] = delnode[i];
        for (i = 1;i <= n;i++)//处理映射关系 
        {
            ys[newnodelist[i]] = i;
            tnode[i] = false;//标记该点不存在 
        }
        for (i = 1;i <= n;i++)//转存到新的邻接矩阵中。 
        for (j = 1;j <= n;j++)
            newmap[i][j] = map[newnodelist[i]][newnodelist[j]];
        totans = 0;//保存询问最短路的命令总数 
        for (k = 1;k <= tottemp;k++)//结点1到结点tottemp都是未被删除的结点，首先求出点I到点J只经过结点1到结点tottemp的最短路径 
        {
            for (i = 1;i <= n;i++)
            for (j = 1;j <= n;j++)
            if (newmap[i][j] > newmap[i][k]+newmap[k][j])
                newmap[i][j] = newmap[i][k]+newmap[k][j];
            tnode[k] = true;//标记结点K未被删除 
        }
        now = tottemp;//现在，未被删除的结点一共有结点1到结点now 
        for (k = q;k >= 1;k--)//我们将命令倒过来，把删除结点操作看成增加结点操作！ 
        {
            if (tasko[k] == 0)//对于询问最短路命令 
            {
                           totans++;
                           ans[totans] = newmap[ys[taska[k]]][ys[taskb[k]]];//通过映射关系找到最短路 
                           if (ans[totans] == MAXV) ans[totans] = -1;//如果没有通路，那么输出-1 
                           if ((tnode[ys[taska[k]]] == false) || (tnode[ys[taskb[k]]] == false))//这里要注意！如果要求的某个端点被摧毁，那么就不存在最短路 
                              ans[totans] = -1;
            }
            else
            {//对于删除点的操作，由于我们是将命令反了过来，所以可以看成是增加结点的操作 
                           now++;//增加结点 
                           tnode[now] = true;//标记结点没有被摧毁 
                           for (i = 1;i <= n;i++)//求出结点I到结点J只经过结点1到now的最短路 
                           for (j = 1;j <= n;j++)
                           if (newmap[i][j] > newmap[i][now]+newmap[now][j])
                              newmap[i][j] = newmap[i][now]+newmap[now][j];
            }
        }
        for (i = totans;i >= 1;i--)//ans中存储的答案是逆序的，所以输出也要逆序 
            printf("%d\n",ans[i]);
        printf("\n");//注意输入要求中的空行 
    }
    return 0;
}
            
        
        
