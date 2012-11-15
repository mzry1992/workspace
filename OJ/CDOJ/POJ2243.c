#include <stdio.h>

const int step[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};//8��������xy����ı仯
int visit[10][10],head,tail,i,j;//visit��¼�����ϸ����״����head��tail�Ƕ��еĶ�ͷ�Ͷ�β
struct Status//�ýṹ�屣��״̬
{
    int x,y,step;
}Q[100000],now;

int BFS(int sx,int sy,int tx,int ty)//BFS�����������ʼ�����Ŀ�����꣬������С����
{
    head = tail = 0;
    Q[head].x = sx; Q[head].y = sy; Q[head].step = 0;//������գ������ʼ��
    for (i = 1;i <= 8;i++)
        for (j = 1;j <= 8;j++)  visit[i][j] = 19930703;//��ʼʱvisit�ڵ�Ԫ��Ϊһ���㹻���ֵ��˵����û�е�����
    visit[sx][sy] = 0;//�����ʼλ�û��ѵĲ���Ϊ0
    while (head <= tail)//������зǿ�
    {
        now = Q[head];  head++;//ȡ������
        if (now.x == tx && now.y == ty) return now.step;//����Ѿ������յ���ô�ͷ�����С�������˳�BFS����
        for (i = 0;i < 8;i++)//��8��������չ
        if (now.x+step[i][0] >= 1 && now.x+step[i][0] <= 8)
        if (now.y+step[i][1] >= 1 && now.y+step[i][1] <= 8)//���ж������Ƿ���������
        if (visit[now.x+step[i][0]][now.y+step[i][1]] > now.step+1)//���ж�һ���Ƿ��ڴ�֮ǰ�Ѿ������
            tail++, Q[tail].x = now.x+step[i][0], Q[tail].y = now.y+step[i][1], Q[tail].step = now.step+1;//�����β
    }
}

int main()
{
    char sa[3],sb[3];
    while (scanf("%s%s",sa,sb) != EOF)
    {
        printf("To get from %s to %s takes %d knight moves.\n",sa,sb,BFS(sa[0]-'a'+1,sa[1]-'0',sb[0]-'a'+1,sb[1]-'0'));
    }
}
