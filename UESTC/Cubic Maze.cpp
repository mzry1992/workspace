#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n,xa,xb,ya,yb,za,zb,ra,rb,da,db,len;
long long tmp;
bool mp[40][40][40];

struct node
{
    int x,y,z,d,r;
    string step;
    node(){}
    node(int _x,int _y,int _z,int _d,int _r,string _step)
        {
            x = _x;
            y = _y;
            z = _z;
            d = _d;
            r = _r;
            step = _step;
        }
};

queue<node> Q;
bool visit[40][40][40][10][10];
node now,updata;

bool CheckIn(int x,int y,int z)
{
    if (x < 0 || x > n-1 || y < 0 || y > n-1 || z < 0 || z > n-1)   return false;
    if (mp[x][y][z] == true)    return false;
    return true;
}

node doF(node now)
{
    //1~3 represents the positive direction of X, Y, Z axis respectively.
    //4~6 represents the negative direction of X, Y, Z axis respectively.
    //F instruction. Move 1 unit along the direct vector.
        node updata = now;
        if (now.d == 0)         updata.x++;
        else if (now.d == 1)    updata.y++;
        else if (now.d == 2)    updata.z++;
        else if (now.d == 3)    updata.x--;
        else if (now.d == 4)    updata.y--;
        else if (now.d == 5)    updata.z--;
        return updata;
    //endF
}

node doL(node now)
{
    //L instruction. Turn the direct vector left 90 degree around the roboctor with the roboctor unchanged.
    //x 0 y 1 z 2 -x 3 -y 4 -z 5
        node updata = now;
        if (now.r == 0)
        {
            //y z -y -z
            //1 2  4  5
            if (now.d == 1)         updata.d = 2;
            else if (now.d == 2)    updata.d = 4;
            else if (now.d == 4)    updata.d = 5;
            else if (now.d == 5)    updata.d = 1;
        }
        else if (now.r == 1)
        {
            //z x -z -x
            //2 0  5  3
            if (now.d == 2)         updata.d = 0;
            else if (now.d == 0)    updata.d = 5;
            else if (now.d == 5)    updata.d = 3;
            else if (now.d == 3)    updata.d = 2;
        }
        else if (now.r == 2)
        {
            //x y -x -y
            //0 1  3  4
            if (now.d == 0)         updata.d = 1;
            else if (now.d == 1)    updata.d = 3;
            else if (now.d == 3)    updata.d = 4;
            else if (now.d == 4)    updata.d = 0;
        }
        else if (now.r == 3)
        {
            //y -z -y z
            //1  5  4 2
            if (now.d == 1)         updata.d = 5;
            else if (now.d == 5)    updata.d = 4;
            else if (now.d == 4)    updata.d = 2;
            else if (now.d == 2)    updata.d = 1;
        }
        else if (now.r == 4)
        {
            //z -x -z x
            //2  3  5 0
            if (now.d == 2)         updata.d = 3;
            else if (now.d == 3)    updata.d = 5;
            else if (now.d == 5)    updata.d = 0;
            else if (now.d == 0)    updata.d = 2;
        }
        else if (now.r == 5)
        {
            //x -y -x y
            //0  4  3 1
            if (now.d == 0)         updata.d = 4;
            else if (now.d == 4)    updata.d = 3;
            else if (now.d == 3)    updata.d = 1;
            else if (now.d == 1)    updata.d = 0;
        }
        return updata;
    //endL
}

node doU(node now)
{
    //U instruction. Change the direct vector to the original roboctor
    //and change the roboctor to the opposite of the original direct vector.
    //x y z -x -y -z
    //0 1 2  3  4  5
        node updata = now;
        updata.d = now.r;
        updata.r = (now.d+3)%6;
        return updata;
    //endU
}

node doB(node now)
{
        node updata = now;
        updata.d = (now.d+3)%6;
        return updata;
}

void BFS()
{
    while (!Q.empty())  Q.pop();
    memset(visit,false,sizeof(visit));
    Q.push(node(xa,ya,za,da,ra,""));
    visit[xa][ya][za][da][ra] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (mp[now.x][now.y][now.z] == true)    continue;
        //cout << now.x << ' '<< now.y << ' ' << now.z << ' '<< now.r << ' '<< now.d << endl;
        if (now.x == xb && now.y == yb && now.z == zb && now.r == rb && now.d == db)
        {
            printf("%d\n",now.step.size());
            printf("%s\n",now.step.c_str());
            return;
        }

            updata = doF(now);
            updata.step = now.step+"F";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }

            updata = doL(now);
            updata.step = now.step+"L";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }

            updata = doL(doL(doL(now)));
            updata.step = now.step+"R";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }

            updata = doU(now);
            updata.step = now.step+"U";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }

            updata = doU(doU(doU(now)));
            updata.step = now.step+"D";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }

            updata = doB(now);
            updata.step = now.step+"B";
            if (CheckIn(updata.x,updata.y,updata.z) == true)
            {
                if (visit[updata.x][updata.y][updata.z][updata.d][updata.r] == false)
                {
                    visit[updata.x][updata.y][updata.z][updata.d][updata.r] = true;
                    Q.push(updata);
                }
            }
    }
    printf("Sorry, I can't get there.\n");
}

int main()
{
    freopen("cubicMaze.in","r",stdin);
    freopen("cubicMaze2.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        scanf("%d%d%d%d%d",&xa,&ya,&za,&da,&ra);
        scanf("%d%d%d%d%d",&xb,&yb,&zb,&db,&rb);
        xa--;   ya--;   za--;   da--;   ra--;
        xb--;   yb--;   zb--;   db--;   rb--;
        memset(mp,false,sizeof(mp));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
            {
                int tmp2;
                scanf("%I64d",&tmp);
                for (int k = 0;k < n;k++)
                {
                    if (k%3==0)
                    {
                        tmp2 = tmp%10;
                        tmp /= 10;
                    }
                    else tmp2 >>= 1;
                    if ((tmp2&1)) mp[j][k][i] = true;
                }
            }
        BFS();
    }
    return 0;
}
