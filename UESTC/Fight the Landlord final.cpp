#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

struct combination
{
    int sta,typ1,typ2,val;
    combination() {}
    combination(int _sta,int _typ1,int _typ2,int _val)
    {
        sta = _sta;
        typ1 = _typ1;
        typ2 = _typ2;
        val = _val;
    }
};

combination c[1<<20];
int totc;

int best[14][25];

char tmp[25];
int s[3][25];

int getid(char ch)
{
    if (ch == 'R')  return 14;
    if (ch == 'B')  return 13;
    if (ch == '2')  return 12;
    if (ch == 'A')  return 11;
    if (ch == 'K')  return 10;
    if (ch == 'Q')  return 9;
    if (ch == 'J')  return 8;
    if (ch == 'T')  return 7;
    return ch-'3';
}

int seq[15][10],sta,att[25],totatt,attsta;
bool used[15],flag;
int catt[25];

void getallatt(int sta,int typ0,int typ1,int typ2,int val,int now,int last)
{
    if (now == typ2)
    {
        if (catt[now-1] == 14 && catt[now-2] == 13) return;
        attsta = 0;
        for (int i = 0; i < typ2; i++)
            attsta = attsta|seq[catt[i]][typ0];
        c[totc++] = combination(attsta|sta,typ1,typ2,val);
    }
    else
    {
        for (int j = last+1; j < totatt; j++)
        {
            catt[now] = att[j];
            getallatt(sta,typ0,typ1,typ2,val,now+1,j);
        }
    }
}

void getall(int id,int len)
{
    totc = 0;
    memset(seq,0,sizeof(seq));
    for (int i = 0; i < len; i++)
        if (i == 0 || s[id][i] != s[id][i-1])
        {
            sta = 0;
            for (int j = i; j < len && s[id][j] == s[id][i]; j++)
            {
                sta = sta|(1<<j);
                seq[s[id][i]][j-i+1] = sta;
            }
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][1] > 0)
            c[totc++] = combination(seq[i][1],0,1,i);
    for (int i = 0; i < 15; i++)
        if (seq[i][2] > 0)
            c[totc++] = combination(seq[i][2],1,1,i);
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            c[totc++] = combination(seq[i][3],2,1,i);
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = 0; j < 15; j++)
                if (i != j && seq[j][1] > 0)
                {
                    sta = seq[i][3]|seq[j][1];
                    c[totc++] = combination(sta,3,1,i);
                }
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = 0; j < 15; j++)
                if (i != j && seq[j][2] > 0)
                {
                    sta = seq[i][3]|seq[j][2];
                    c[totc++] = combination(sta,4,1,i);
                }
    for (int i = 0; i < 15; i++)
        if (seq[i][1] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][1] > 0; j++)
            {
                sta = sta|seq[j][1];
                if (j-i+1 >= 5)
                    c[totc++] = combination(sta,5,j-i+1,i);
            }
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][2] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][2] > 0; j++)
            {
                sta = sta|seq[j][2];
                if (j-i+1 >= 3)
                    c[totc++] = combination(sta,6,j-i+1,i);
            }
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
            {
                sta = sta|seq[j][3];
                if (j-i+1 >= 2)
                    c[totc++] = combination(sta,7,j-i+1,i);
            }
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
                if (j-i+1 >= 2)
                {
                    flag = true;
                    memset(used,false,sizeof(used));
                    sta = 0;
                    for (int k = i; k <= j; k++)
                    {
                        sta = sta|seq[k][3];
                        used[k] = true;
                    }
                    totatt = 0;
                    for (int k = 0; k < 15; k++)
                        if (seq[k][1] > 0 && used[k] == false)
                            att[totatt++] = k;
                    if (totatt >= j-i+1)
                        getallatt(sta,1,8,j-i+1,i,0,-1);
                }
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
                if (j-i+1 >= 2)
                {
                    flag = true;
                    memset(used,false,sizeof(used));
                    sta = 0;
                    for (int k = i; k <= j; k++)
                    {
                        sta = sta|seq[k][3];
                        used[k] = true;
                    }
                    totatt = 0;
                    for (int k = 0; k < 15; k++)
                        if (seq[k][2] > 0 && used[k] == false)
                            att[totatt++] = k;
                    if (totatt >= j-i+1)
                        getallatt(sta,2,9,j-i+1,i,0,-1);
                }
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
            c[totc++] = combination(seq[i][4],10,1,i);
    if (seq[13][1] > 0 && seq[14][1] > 0)
        c[totc++] = combination(seq[13][1]|seq[14][1],11,1,1);
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
        {
            sta = seq[i][4];
            totatt = 0;
            for (int k = 0; k < 15; k++)
                if (k != i && seq[k][1] > 0)
                    att[totatt++] = k;
            if (totatt >= 2)
                getallatt(sta,1,12,2,i,0,-1);
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
        {
            sta = seq[i][4];
            totatt = 0;
            for (int k = 0; k < 15; k++)
                if (k != i && seq[k][2] > 0)
                    att[totatt++] = k;
            if (totatt >= 2)
                getallatt(sta,2,13,2,i,0,-1);
        }
}

bool inq[1<<20];
stack<int> Q;

bool check(int i,int full)
{
    if (c[i].sta == full)
        return true;
    if (best[11][1] != -1)
        return false;
    if (c[i].typ1 == 11)    return true;
    if (c[i].typ1 != 10 && best[10][1] != -1)
        return false;
    if (c[i].val < best[c[i].typ1][c[i].typ2])
        return false;
    return true;
}

int tot[15];

int getupd(int take,int cur)
{
    for (int i = 0;i < 20;i++)
        if (((cur>>i)&1) == 1 && ((take>>i)&1) == 0)
            tot[s[0][i]]++;
    int res = 0;
    for (int i = 0;i < 15;i++)
        res = res|seq[i][tot[i]];
    for (int i = 0;i < 20;i++)
        if (((cur>>i)&1) == 1 && ((take>>i)&1) == 0)
            tot[s[0][i]]--;
    return res;
}

bool BFS()
{
    while (!Q.empty())
        Q.pop();
    int full = (1<<20)-1,now,sta,upd;
    memset(inq,false,sizeof(inq));
    memset(tot,0,sizeof(tot));
    inq[full] = true;
    Q.push(full);
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now == 0)   return true;
        for (int i = 0; i < totc; i++)
            if ((c[i].sta|now) == now)
                if (check(i,now) == true)
                {
                    upd = getupd(c[i].sta,now);
                    if (inq[upd] == true)   continue;
                    inq[upd] = true;
                    Q.push(upd);
                }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%s",tmp);
            for (int j = 0; j < strlen(tmp); j++)
                s[i][j] = getid(tmp[j]);
        }
        sort(s[0],s[0]+20);
        sort(s[1],s[1]+17);
        sort(s[2],s[2]+17);
        memset(best,-1,sizeof(best));
        for (int i = 1; i < 3; i++)
        {
            getall(i,17);
            for (int j = 0; j < totc; j++)
                best[c[j].typ1][c[j].typ2] = max(best[c[j].typ1][c[j].typ2],c[j].val);
        }
        getall(0,20);
        printf("Case %d: ",ft);
        if (BFS() == true)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
