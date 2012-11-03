#include<iostream>//Size Banlanced Tree模板
#include<cstdio>
#define MAX 100000
using namespace std;
typedef struct TREE
{
	long key,left,right,num;
	long k;//附加信息
}TREE;
TREE Tree[MAX];
long keep[MAX],end;//保存闲置空间的栈
long Root,top;//树根节点 预制空间定位
void Right_Turn(long &Root)  //右旋
{
	long k=Tree[Root].left;
	Tree[Root].left=Tree[k].right;
	Tree[k].right=Root;
	Tree[k].num=Tree[Root].num;//转上去的节点数量为先前此处节点的num
	Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;
	Root=k;
}
void Left_Turn(long &Root) //左旋
{
	long k=Tree[Root].right;
	Tree[Root].right=Tree[k].left;
	Tree[k].left=Root;
	Tree[k].num=Tree[Root].num;
	Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;
	Root=k;
}
void Check_Blance(long &Root,bool flag)//平衡函数
{
	if (flag==false)//左边被强势插入
	{
		if (Tree[Tree[Tree[Root].left].left].num>Tree[Tree[Root].right].num) //左子树的左子树大于右子树
			Right_Turn(Root);
		else if (Tree[Tree[Tree[Root].left].right].num>Tree[Tree[Root].right].num)//左子树右子树大于右子树
		{
			Left_Turn(Tree[Root].left);
			Right_Turn(Root);
		}
		else return; //平衡
	}
	else //右边
	{
		if (Tree[Tree[Tree[Root].right].right].num>Tree[Tree[Root].left].num) //同上
			Left_Turn(Root);
		else if (Tree[Tree[Tree[Root].right].left].num>Tree[Tree[Root].left].num)
		{
			Right_Turn(Tree[Root].right);
			Left_Turn(Root);
		}
		else return;
	}
	Check_Blance(Tree[Root].left,false);//检查左子树的左子树平衡
	Check_Blance(Tree[Root].right,true);//右子树
	Check_Blance(Root,true);//根节点右子树
	Check_Blance(Root,false);//左子树
}
void Insert(long &Root,long key,long note) //插入
{
	if (Root==0) //最底层插入
	{
		if (end>0) Root=keep[--end];//如果回收站还有剩余，优先用回收站的
		else Root=++top;//反之使用预置空间
		Tree[Root].key=key;
		Tree[Root].num=1;
		Tree[Root].right=0;
		Tree[Root].left=0;
		Tree[Root].k=note;//附加信息
	}
	else
	{
		Tree[Root].num++;
		if (key<Tree[Root].key)  Insert(Tree[Root].left,key,note);
		if (key>Tree[Root].key)  Insert(Tree[Root].right,key,note);
		Check_Blance(Root,key>=Tree[Root].key); //每次插入把平衡操作压入栈中
	}
}
long Del_first()//删除最小的
{
	long temp=Root,cur=Root;
	while (Tree[temp].left!=0) //走到最左
	{
		Tree[temp].num--;
		cur=temp;
		temp=Tree[temp].left;
	}
	if (temp!=Root) Tree[cur].left=Tree[temp].right;//树不为空
	else if (Tree[temp].right!=0)//右子树不空
		Root=Tree[temp].right;
	else Root=0;//树为空
	return temp;
}
long Del_back()//删除最大的
{
	long temp=Root,cur=Root;
	while (Tree[temp].right!=0)//走到最右
	{
		Tree[temp].num--;
		cur=temp;
		temp=Tree[temp].right;
	}
	if (temp!=Root) Tree[cur].right=Tree[temp].left;//树不空
	else if (Tree[temp].left!=0)//左子树不空
		Root=Tree[temp].left;
	else Root=0;//空树
	return temp;
}
long Delete(long &Root,long key)//在Root的树中删除关键值为key的元素
{
	Tree[Root].num--;//减少数量
	if (key>Tree[Root].key&&Tree[Root].right) return Delete(Tree[Root].right,key);//先行判断节省时间
	else if (key<Tree[Root].key&&Tree[Root].left) return Delete(Tree[Root].left,key);
	else//定点到删除的节点或者没有找到删除的，此时删除最后一个节点
	{
		if (!Tree[Root].left||!Tree[Root].right)//左右子树一个为空，若都为空就是叶子直接fuck掉
		{
			long temp=Root;//记录节点坐标
			Root=Tree[Root].left+Tree[Root].right;
			return temp;//返回删除节点的坐标
		}
		else
		{
			long temp=Delete(Tree[Root].left,Tree[Root].key+1);//找到左子树最大点删除
			long change=Tree[Root].key;
			long useful=Tree[Root].k;//记录节点中有用信息，此处不移动节点，仅仅拷贝数据完成交换（左子树最大的点代替这个点）
			Tree[Root].key=Tree[temp].key;//手动改变替代节点额的有用信息
			Tree[Root].k=Tree[temp].k;//存储有用信息
			Tree[temp].k=useful;
			Tree[temp].key=change;//手动记录有用信息
			return temp;//返回删除的节点（temp为左子树最大的节点，但是里面数据时此时删除节点的）
		}
	}
}
long Find (long Root,long key)//查找关键值key的元素
{
	if (key>Tree[Root].key&&Tree[Root].right!=0) return Find(Tree[Root].right,key);
	else if (key<Tree[Root].key&&Tree[Root].left) return Find(Tree[Root].left,key);
	else return Root;
}
long Rank(long Root,long key)//确定关键值为key的节点的排名
{
	if (Root==0) return 1;
	else if (key>Tree[Root].key) return Rank(Tree[Root].right,key)+Tree[Tree[Root].left].num+1;//加上左子树的继续找
	else return Rank(Tree[Root].left,key);
}
long Select(long Root,long Rank)//找到排名第rank的元素
{
	if (Rank==Tree[Tree[Root].left].num+1)//此节点为所求
		return Root;
	else if (Rank<=Tree[Tree[Root].left].num)
		return Select(Tree[Root].left,Rank);
	else return Select(Tree[Root].right,Rank-Tree[Tree[Root].left].num-1);//右子树继续找
}
void Mid_sequence(long path)//中序遍历
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}//空树
	if (Tree[path].left) Mid_sequence(Tree[path].left);
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
	if (Tree[path].right) Mid_sequence(Tree[path].right);
}
void Pre_sequence(long path)//先序遍历
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
	if (Tree[path].left)
		Pre_sequence(Tree[path].left);
	if (Tree[path].right)
		Pre_sequence(Tree[path].right);
}
void Back_sequence(long path)//后序遍历
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}
	if (Tree[path].left)
		Pre_sequence(Tree[path].left);
	if (Tree[path].right)
		Pre_sequence(Tree[path].right);
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
}
void Print(int dep,int path) //树状图打印
{
	long i,temp=Root;
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}
	for (i=0;i<dep;i++)
		printf("+");
	printf("%d %d\n",Tree[path].key,Tree[path].num);
	if (Tree[path].left) Print(dep+4,Tree[path].left);
	if (Tree[path].right) Print(dep+4,Tree[path].right);
}
int main()
{
	long order,k,p;
	while (1)
	{
		scanf("%ld",&order);
		if (order==0) break;
		else if (order==1)//插入数据
		{
			scanf("%ld %ld",&k,&p);
			Insert(Root,p,k);
		}
		else if (order==2)//删除最大的
		{
			k=Del_back();
			printf("Deleted biggest node %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;
		}
		else if (order==3)//删除最小的
		{
			k=Del_first();
			printf("Deleted smallest node %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;//记录空余地址
		}
		else if (order==4) //找到关键值为p的
		{
			cin>>p;
			k=Find(Root,p);
			printf("find num:%ld %ld\n",Tree[k].key,Tree[k].k);
		}
		else if (order==5) //确定关键值为p的节点的排名
		{
			cin>>p;
			k=Rank(Root,p);
			printf("%ld rank:%ld\n",p,k);
		}
		else if (order==6) //找到排名为p的数的节点
		{
			cin>>p;
			k=Select(Root,p);
			printf("Ranking %ld is:%ld\n",p,Tree[k].key);
		}
		else if (order==7) //删除一个元素返回地址
		{
			cin>>p;
			k=Delete(Root,p);
			printf("Deleted %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;
		}
		Pre_sequence(Root);//先序
		printf("\n");
		Mid_sequence(Root);//中序
		printf("\n");
		Back_sequence(Root);//后序
		printf("\n");
		Print(1,Root);//树状图打印
		printf("\n");
	}
	return 0;
}
