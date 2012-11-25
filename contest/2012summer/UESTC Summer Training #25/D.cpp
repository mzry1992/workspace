#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int sp[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
const char col[3] = "wb";
char ms[4][5],me[4][5],tmp[4][5];
int bit[17];

void decode(int msk)
{
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
        {
            if (msk%3 == 0)
                tmp[i][j] = 'w';
            else if (msk%3 == 1)
                tmp[i][j] = 'b';
            else
                tmp[i][j] = '*';
            msk /= 3;
        }
}

int encode(char ch[4][5])
{
    int res = 0;
    for (int i = 3;i >= 0;i--)
        for (int j = 3;j >= 0;j--)
        {
            res *= 3;
            if (ch[i][j] == 'b')
                res += 1;
            else if (ch[i][j] == '*')
                res += 2;
        }
    return res;
}

int change(int msk,int pos,int val)
{
    return msk/bit[pos+1]*bit[pos+1]+val*bit[pos]+msk%bit[pos];
}

bool visit[43046721];

int BFS()
{
    int init = encode(ms),final = encode(me);
    queue<pair<int,int> > Q;
    Q.push(make_pair(init,0));
    memset(visit,false,sizeof(visit));
    visit[init] = true;

    while (!Q.empty())
    {
        pair<int,int> pnow = Q.front();
        int now = pnow.first,step = pnow.second;
        Q.pop();
        if (now == final)
            return step;
        decode(now);
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++)
                if (tmp[i][j] == col[step%2])
                    for (int k = 0;k < 8;k++)
                    {
                        int x = i,y = j;
                        while (true)
                        {
                            x += sp[k][0];
                            y += sp[k][1];
                            if (x < 0 || x >= 4 || y < 0 || y >= 4 || tmp[x][y] != '*')
                                break;
                        }
                        x -= sp[k][0];
                        y -= sp[k][1];
                        if (x == i && y == j)
                            continue;
                        int nxt = change(change(now,i*4+j,2),x*4+y,step%2);
                        if (!visit[nxt])
                        {
                            visit[nxt] = true;
                            Q.push(make_pair(nxt,step+1));
                        }
                    }
    }
    return -1;
}

int main()
{
    bit[0] = 1;
    for (int i = 1;i < 17;i++)
        bit[i] = bit[i-1]*3;
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    for (int i = 0;i < 4;i++)
            scanf("%s",ms[i]);
        for (int i = 0;i < 4;i++)
            scanf("%s",me[i]);
        printf("%d\n",BFS());
	}
	return 0;
}
