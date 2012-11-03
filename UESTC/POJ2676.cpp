#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tcase,fcase;
int sd[10][10];//��������
char tsd[10][10];//���������
int han[10][10],lie[10][10],kua[10][10];//����С��С����1��9��ʹ�����
int flag;//����Ƿ��Ѿ�����

int getb(int x,int y)//��ÿ���
{
    int tx,ty,ans;
    if ((x >= 1) && (x <= 3)) tx = 1;
    if ((x >= 4) && (x <= 6)) tx = 2;
    if ((x >= 7) && (x <= 9)) tx = 3;
    if ((y >= 1) && (y <= 3)) ty = 1;
    if ((y >= 4) && (y <= 6)) ty = 2;
    if ((y >= 7) && (y <= 9)) ty = 3;
    ans = (tx-1)*3+ty;
    return ans;
}

void add(int x,int y,int v)//�ڣ�X,Y����������V
{
     han[x][v] = lie[y][v] = kua[getb(x,y)][v] = true;
     sd[x][y] = v;
}

void del(int x,int y,int v)//�����ڣ�X,Y�����������V
{
     han[x][v] = lie[y][v] = kua[getb(x,y)][v] = false;
     sd[x][y] = 0;
}

void readin()//����
{
     int i,j;
     for (i = 1;i <= 9;i++)
     {
         scanf("%s",&tsd[i]);
         for (j = 1;j <= 9;j++)
             sd[i][j] = tsd[i][j-1]-'0';
     }
}

void output();

void DFS(int nowx,int nowy)//�������ˣ�nowx,nowy��
{
     int tx,ty,i;
     tx = nowx; ty = nowy;
     ty++;//�����һ��Ҫ����������
     if (ty > 9)
     {
            ty -= 9;
            tx++;
     }
     if ((nowx == 10) && (nowy == 1))//����������ˣ���ô����𰸲��ұ���н�
     {
             output();
             flag = true;
     }
     if (flag == true)  return;//����Ѿ��н⣬��ô�˳�
     if (sd[nowx][nowy] != 0)  //������������֣���ô������һ����
     {
                        DFS(tx,ty);
                        return;
     }
     for (i = 1;i <= 9;i++)//ö��1��9
     if (han[nowx][i] == false)
     if (lie[nowy][i] == false)
     if (kua[getb(nowx,nowy)][i] == false)//���������
     {
                             if (flag == true) return;
                             add(nowx,nowy,i);//����
                             DFS(tx,ty);//����
                             del(nowx,nowy,i);//�ָ�
     }
}

void solve()
{
     int i,j;
     memset(han,false,sizeof(han));
     memset(lie,false,sizeof(lie));
     memset(kua,false,sizeof(kua));
     for (i = 1;i <= 9;i++)
     for (j = 1;j <= 9;j++)
         add(i,j,sd[i][j]);//��������֪������
     flag = false;
     DFS(1,1);
}

void output()
{
     int i,j;
     for (i = 1;i <= 9;i++)
     {
         for (j = 1;j <= 9;j++)
             printf("%d",sd[i][j]);
         printf("\n");
     }
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        readin();
        solve();
    }
}
