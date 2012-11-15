#include<iostream>//Size Banlanced Treeģ��
#include<cstdio>
#define MAX 100000
using namespace std;
typedef struct TREE
{
	long key,left,right,num;
	long k;//������Ϣ
}TREE;
TREE Tree[MAX];
long keep[MAX],end;//�������ÿռ��ջ
long Root,top;//�����ڵ� Ԥ�ƿռ䶨λ
void Right_Turn(long &Root)  //����
{
	long k=Tree[Root].left;
	Tree[Root].left=Tree[k].right;
	Tree[k].right=Root;
	Tree[k].num=Tree[Root].num;//ת��ȥ�Ľڵ�����Ϊ��ǰ�˴��ڵ��num
	Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;
	Root=k;
}
void Left_Turn(long &Root) //����
{
	long k=Tree[Root].right;
	Tree[Root].right=Tree[k].left;
	Tree[k].left=Root;
	Tree[k].num=Tree[Root].num;
	Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;
	Root=k;
}
void Check_Blance(long &Root,bool flag)//ƽ�⺯��
{
	if (flag==false)//��߱�ǿ�Ʋ���
	{
		if (Tree[Tree[Tree[Root].left].left].num>Tree[Tree[Root].right].num) //������������������������
			Right_Turn(Root);
		else if (Tree[Tree[Tree[Root].left].right].num>Tree[Tree[Root].right].num)//����������������������
		{
			Left_Turn(Tree[Root].left);
			Right_Turn(Root);
		}
		else return; //ƽ��
	}
	else //�ұ�
	{
		if (Tree[Tree[Tree[Root].right].right].num>Tree[Tree[Root].left].num) //ͬ��
			Left_Turn(Root);
		else if (Tree[Tree[Tree[Root].right].left].num>Tree[Tree[Root].left].num)
		{
			Right_Turn(Tree[Root].right);
			Left_Turn(Root);
		}
		else return;
	}
	Check_Blance(Tree[Root].left,false);//�����������������ƽ��
	Check_Blance(Tree[Root].right,true);//������
	Check_Blance(Root,true);//���ڵ�������
	Check_Blance(Root,false);//������
}
void Insert(long &Root,long key,long note) //����
{
	if (Root==0) //��ײ����
	{
		if (end>0) Root=keep[--end];//�������վ����ʣ�࣬�����û���վ��
		else Root=++top;//��֮ʹ��Ԥ�ÿռ�
		Tree[Root].key=key;
		Tree[Root].num=1;
		Tree[Root].right=0;
		Tree[Root].left=0;
		Tree[Root].k=note;//������Ϣ
	}
	else
	{
		Tree[Root].num++;
		if (key<Tree[Root].key)  Insert(Tree[Root].left,key,note);
		if (key>Tree[Root].key)  Insert(Tree[Root].right,key,note);
		Check_Blance(Root,key>=Tree[Root].key); //ÿ�β����ƽ�����ѹ��ջ��
	}
}
long Del_first()//ɾ����С��
{
	long temp=Root,cur=Root;
	while (Tree[temp].left!=0) //�ߵ�����
	{
		Tree[temp].num--;
		cur=temp;
		temp=Tree[temp].left;
	}
	if (temp!=Root) Tree[cur].left=Tree[temp].right;//����Ϊ��
	else if (Tree[temp].right!=0)//����������
		Root=Tree[temp].right;
	else Root=0;//��Ϊ��
	return temp;
}
long Del_back()//ɾ������
{
	long temp=Root,cur=Root;
	while (Tree[temp].right!=0)//�ߵ�����
	{
		Tree[temp].num--;
		cur=temp;
		temp=Tree[temp].right;
	}
	if (temp!=Root) Tree[cur].right=Tree[temp].left;//������
	else if (Tree[temp].left!=0)//����������
		Root=Tree[temp].left;
	else Root=0;//����
	return temp;
}
long Delete(long &Root,long key)//��Root������ɾ���ؼ�ֵΪkey��Ԫ��
{
	Tree[Root].num--;//��������
	if (key>Tree[Root].key&&Tree[Root].right) return Delete(Tree[Root].right,key);//�����жϽ�ʡʱ��
	else if (key<Tree[Root].key&&Tree[Root].left) return Delete(Tree[Root].left,key);
	else//���㵽ɾ���Ľڵ����û���ҵ�ɾ���ģ���ʱɾ�����һ���ڵ�
	{
		if (!Tree[Root].left||!Tree[Root].right)//��������һ��Ϊ�գ�����Ϊ�վ���Ҷ��ֱ��fuck��
		{
			long temp=Root;//��¼�ڵ�����
			Root=Tree[Root].left+Tree[Root].right;
			return temp;//����ɾ���ڵ������
		}
		else
		{
			long temp=Delete(Tree[Root].left,Tree[Root].key+1);//�ҵ�����������ɾ��
			long change=Tree[Root].key;
			long useful=Tree[Root].k;//��¼�ڵ���������Ϣ���˴����ƶ��ڵ㣬��������������ɽ��������������ĵ��������㣩
			Tree[Root].key=Tree[temp].key;//�ֶ��ı�����ڵ���������Ϣ
			Tree[Root].k=Tree[temp].k;//�洢������Ϣ
			Tree[temp].k=useful;
			Tree[temp].key=change;//�ֶ���¼������Ϣ
			return temp;//����ɾ���Ľڵ㣨tempΪ���������Ľڵ㣬������������ʱ��ʱɾ���ڵ�ģ�
		}
	}
}
long Find (long Root,long key)//���ҹؼ�ֵkey��Ԫ��
{
	if (key>Tree[Root].key&&Tree[Root].right!=0) return Find(Tree[Root].right,key);
	else if (key<Tree[Root].key&&Tree[Root].left) return Find(Tree[Root].left,key);
	else return Root;
}
long Rank(long Root,long key)//ȷ���ؼ�ֵΪkey�Ľڵ������
{
	if (Root==0) return 1;
	else if (key>Tree[Root].key) return Rank(Tree[Root].right,key)+Tree[Tree[Root].left].num+1;//�����������ļ�����
	else return Rank(Tree[Root].left,key);
}
long Select(long Root,long Rank)//�ҵ�������rank��Ԫ��
{
	if (Rank==Tree[Tree[Root].left].num+1)//�˽ڵ�Ϊ����
		return Root;
	else if (Rank<=Tree[Tree[Root].left].num)
		return Select(Tree[Root].left,Rank);
	else return Select(Tree[Root].right,Rank-Tree[Tree[Root].left].num-1);//������������
}
void Mid_sequence(long path)//�������
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}//����
	if (Tree[path].left) Mid_sequence(Tree[path].left);
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
	if (Tree[path].right) Mid_sequence(Tree[path].right);
}
void Pre_sequence(long path)//�������
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
	if (Tree[path].left)
		Pre_sequence(Tree[path].left);
	if (Tree[path].right)
		Pre_sequence(Tree[path].right);
}
void Back_sequence(long path)//�������
{
	if (path==0) {printf("top=%d %d",Tree[path].key,Tree[path].k);return ;}
	if (Tree[path].left)
		Pre_sequence(Tree[path].left);
	if (Tree[path].right)
		Pre_sequence(Tree[path].right);
	printf(" (%d %d) ",Tree[path].key,Tree[path].num);
}
void Print(int dep,int path) //��״ͼ��ӡ
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
		else if (order==1)//��������
		{
			scanf("%ld %ld",&k,&p);
			Insert(Root,p,k);
		}
		else if (order==2)//ɾ������
		{
			k=Del_back();
			printf("Deleted biggest node %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;
		}
		else if (order==3)//ɾ����С��
		{
			k=Del_first();
			printf("Deleted smallest node %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;//��¼�����ַ
		}
		else if (order==4) //�ҵ��ؼ�ֵΪp��
		{
			cin>>p;
			k=Find(Root,p);
			printf("find num:%ld %ld\n",Tree[k].key,Tree[k].k);
		}
		else if (order==5) //ȷ���ؼ�ֵΪp�Ľڵ������
		{
			cin>>p;
			k=Rank(Root,p);
			printf("%ld rank:%ld\n",p,k);
		}
		else if (order==6) //�ҵ�����Ϊp�����Ľڵ�
		{
			cin>>p;
			k=Select(Root,p);
			printf("Ranking %ld is:%ld\n",p,Tree[k].key);
		}
		else if (order==7) //ɾ��һ��Ԫ�ط��ص�ַ
		{
			cin>>p;
			k=Delete(Root,p);
			printf("Deleted %ld %ld\n",Tree[k].key,Tree[k].k);
			if (end<MAX) keep[end++]=k;
		}
		Pre_sequence(Root);//����
		printf("\n");
		Mid_sequence(Root);//����
		printf("\n");
		Back_sequence(Root);//����
		printf("\n");
		Print(1,Root);//��״ͼ��ӡ
		printf("\n");
	}
	return 0;
}
