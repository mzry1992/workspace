#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char ss[30],st[30],s[30];
bool IDAans;
int Ians;

int abs(int a)
{
    if (a < 0)  a = -a;
    return a;
}

const int tx[9] = {1,1,1,2,2,2,3,3,3};
const int ty[9] = {1,2,3,1,2,3,1,2,3};

int calcf(char *s)
{
    int res = 0;
    for (int i = 1;i <= 9;i++)
    for (int j = 1;j <= 9;j++)
        if (s[(i-1)*2] == st[(j-1)*2])
            res += abs(tx[i-1]-tx[j-1])+abs(ty[i-1]-ty[j-1]);
    return res;
}

int DFS(int step,int depth)
{
    int tg = step;
    int tf = calcf(s);
    if (tg+tf > depth)
        return tg+tf;
    if (tf == 0)
    {
        IDAans = true;
        if (Ians > step)
            Ians = step;
        return step;
    }
    int xpos;
    for (int i = 1;i <= 9;i++)
        if (s[(i-1)*2] == 'x')
            xpos = i;
    char temp[30];
    strcpy(temp,s);
    int res = 19930703;
    if (xpos%3 != 1)
    {
        char tch = s[(xpos-1)*2];
        s[(xpos-1)*2] = s[(xpos-2)*2];
        s[(xpos-2)*2] = tch;
        int kf = calcf(s);
        int tdepth = DFS(step+1,depth);
        if (IDAans)
            return tdepth;
        if (res > tdepth)
            res = tdepth;
        strcpy(s,temp);
    }
    if (xpos%3 != 0)
    {
        char tch = s[(xpos-1)*2];
        s[(xpos-1)*2] = s[(xpos)*2];
        s[(xpos)*2] = tch;
        int kf = calcf(s);
        int tdepth = DFS(step+1,depth);
        if (IDAans)
            return tdepth;
        if (res > tdepth)
            res = tdepth;
        strcpy(s,temp);
    }
    if (xpos-3 > 0)
    {
        char tch = s[(xpos-1)*2];
        s[(xpos-1)*2] = s[(xpos-4)*2];
        s[(xpos-4)*2] = tch;
        int kf = calcf(s);
        int tdepth = DFS(step+1,depth);
        if (IDAans)
            return tdepth;
        if (res > tdepth)
            res = tdepth;
        strcpy(s,temp);

    }
    if (xpos+3 <= 9)
    {
        char tch = s[(xpos-1)*2];
        s[(xpos-1)*2] = s[(xpos+2)*2];
        s[(xpos+2)*2] = tch;
        int kf = calcf(s);
        int tdepth = DFS(step+1,depth);
        if (IDAans)
            return tdepth;
        if (res > tdepth)
            res = tdepth;
        strcpy(s,temp);
    }
    return res;
}

int IDADFS()
{
    int depth = calcf(ss);
    cout << calcf(ss) << endl;
    while (true)
    {
        cout << depth << endl;
        IDAans = false;
        Ians = 19930703;
        strcpy(s,ss);
        depth = DFS(0,depth);
        if (IDAans)
            return Ians;
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        gets(ss);
        gets(st);
        printf("%d\n",IDADFS());
    }
}
