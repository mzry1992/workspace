#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct OP
{
    int a,xa[2],ya[2];
    int b,xb[2],yb[2];
    OP(){}
    OP(int _a,int _xa1,int _xa2,int _ya1,int _ya2,
       int _b,int _xb1,int _xb2,int _yb1,int _yb2)
    {
        a = _a;
        xa[0] = _xa1;
        xa[1] = _xa2;
        ya[0] = _ya1;
        ya[1] = _ya2;

        b = _b;
        xb[0] = _xb1;
        xb[1] = _xb2;
        yb[0] = _yb1;
        yb[1] = _yb2;
//        printf("%d [ ",a);
//        if (xa[0] == xa[1])
//            printf("%d ,",xa[0]);
//        else
//            printf("%d..%d ,",xa[0],xa[1]);
//        if (ya[0] == ya[1])
//            printf("%d ]",ya[0]);
//        else
//            printf("%d..%d ]",ya[0],ya[1]);
//
//        printf(" ---> %d [ ",b);
//        if (xb[0] == xb[1])
//            printf("%d ,",xb[0]);
//        else
//            printf("%d..%d ,",xb[0],xb[1]);
//        if (yb[0] == yb[1])
//            printf("%d ]\n",yb[0]);
//        else
//            printf("%d..%d ]\n",yb[0],yb[1]);
    }
    OP(int _a)
    {
        a = _a;
        b = -1;
//        printf("C   (%d)\n",a);
    }
};

vector<OP> nima[9];

struct Rubik
{
    int face[6][3][3],tmp[6][3][3];
    void init()
    {
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 3;j++)
                for (int k = 0;k < 3;k++)
                    face[i][j][k] = i*100+j*10+k;
    }
    bool complete()
    {
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 3;j++)
                for (int k = 0;k < 3;k++)
                    if (face[i][j][k] != i*100+j*10+k)
                        return false;
        return true;
    }
    void backup()
    {
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 3;j++)
                for (int k = 0;k < 3;k++)
                    tmp[i][j][k] = face[i][j][k];
    }
    void end()
    {
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 3;j++)
                for (int k = 0;k < 3;k++)
                    face[i][j][k] = tmp[i][j][k];
    }
    void C(int id)
    {
        backup();
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
                tmp[id][i][j] = face[id][2-j][i];
        end();
        backup();
    }
    int tv[3];
    void run(OP op)
    {
        if (op.b == -1)
            C(op.a);
        else
        {

            if (op.xb[0] == op.xb[1])
            {
                int td = 1;
                if (op.yb[0] > op.yb[1])    td = -1;
                int cnt = 0;
                for (int i = op.yb[0];i != op.yb[1]+td;i += td)
                    tv[cnt++] = face[op.b][op.xb[0]][i];
            }
            else
            {
                int td = 1;
                if (op.xb[0] > op.xb[1])    td = -1;
                int cnt = 0;
                for (int i = op.xb[0];i != op.xb[1]+td;i += td)
                    tv[cnt++] = face[op.b][i][op.yb[0]];
            }

//            for (int i = 0;i < 3;i++)
//                cout << tv[i] << ' ';
//            cout << endl;

            if (op.xa[0] == op.xa[1])
            {
                int td = 1;
                if (op.ya[0] > op.ya[1])    td = -1;
                int cnt = 0;
                for (int i = op.ya[0];i != op.ya[1]+td;i += td)
                    tmp[op.a][op.xa[0]][i] = tv[cnt++];
            }
            else
            {
                int td = 1;
                if (op.xa[0] > op.xa[1])    td = -1;
                int cnt = 0;
                for (int i = op.xa[0];i != op.xa[1]+td;i += td)
                    tmp[op.a][i][op.ya[0]] = tv[cnt++];
            }

        }
    }
    void gao(int id)
    {
        if (id > 8)
        {
            id -= 9;
            for (int i = 0;i < 3;i++)
                gao(id);
            return;
        }

        backup();
        for (int i = 0;i < nima[id].size();i++)
        {
            //cout << "Gao id = " << id << ' ' << nima[id][i].a << ' ' << nima[id][i].b << endl;
            run(nima[id][i]);
        }
        end();

    }

    void view()
    {
        cout << "=======================" << endl;
        for (int i = 0;i < 6;i++)
        {
            cout << "face : " << i << endl;
            for (int j = 0;j < 3;j++,puts(""))
                for (int k = 0;k < 3;k++)
                    printf("%03d ",face[i][j][k]);
        }
    }
};

int getid(char ch)
{
    if (ch == 'U')  return 0;
    if (ch == 'R')  return 1;
    if (ch == 'F')  return 2;
    if (ch == 'D')  return 3;
    if (ch == 'L')  return 4;
    if (ch == 'B')  return 5;
    if (ch == 'X')  return 6;
    if (ch == 'Y')  return 7;
    if (ch == 'Z')  return 8;

    if (ch == 'u')  return 9;
    if (ch == 'r')  return 10;
    if (ch == 'f')  return 11;
    if (ch == 'd')  return 12;
    if (ch == 'l')  return 13;
    if (ch == 'b')  return 14;
    if (ch == 'x')  return 15;
    if (ch == 'y')  return 16;
    if (ch == 'z')  return 17;
}

char s[300];
int len;
Rubik fuck;

int main()
{
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
    for (int i = 0;i < 9;i++)
        nima[i].clear();

    //cout << "U : " << endl;
    //U
    nima[0].push_back(OP(5));
    nima[0].push_back(OP(1,0,0,0,2,   2,0,0,0,2));
    nima[0].push_back(OP(2,0,0,0,2,   3,0,0,0,2));
    nima[0].push_back(OP(3,0,0,0,2,   4,0,0,0,2));
    nima[0].push_back(OP(4,0,0,0,2,   1,0,0,0,2));

    //cout << "R : " << endl;
    //R
    nima[1].push_back(OP(2));
    nima[1].push_back(OP(1,0,2,2,2,   0,0,2,2,2));
    nima[1].push_back(OP(0,0,2,2,2,   3,2,0,0,0));
    nima[1].push_back(OP(3,0,2,0,0,   5,2,0,2,2));
    nima[1].push_back(OP(5,0,2,2,2,   1,0,2,2,2));

    //cout << "F : " << endl;
    //F
    nima[2].push_back(OP(1));
    nima[2].push_back(OP(2,0,2,0,0,   5,2,2,0,2));
    nima[2].push_back(OP(5,2,2,0,2,   4,2,0,2,2));
    nima[2].push_back(OP(4,0,2,2,2,   0,0,0,0,2));
    nima[2].push_back(OP(0,0,0,0,2,   2,2,0,0,0));

    //cout << "D : " << endl;
    //D
    nima[3].push_back(OP(0));
    nima[3].push_back(OP(1,2,2,0,2,   4,2,2,0,2));
    nima[3].push_back(OP(2,2,2,0,2,   1,2,2,0,2));
    nima[3].push_back(OP(3,2,2,0,2,   2,2,2,0,2));
    nima[3].push_back(OP(4,2,2,0,2,   3,2,2,0,2));

    //cout << "L : " << endl;
    //L
    nima[4].push_back(OP(4));
    nima[4].push_back(OP(1,0,2,0,0,   5,0,2,0,0));
    nima[4].push_back(OP(5,0,2,0,0,   3,2,0,2,2));
    nima[4].push_back(OP(3,0,2,2,2,   0,2,0,0,0));
    nima[4].push_back(OP(0,0,2,0,0,   1,0,2,0,0));

    //cout << "B : " << endl;
    //B
    nima[5].push_back(OP(3));
    nima[5].push_back(OP(5,0,0,0,2,   2,0,2,2,2));
    nima[5].push_back(OP(2,0,2,2,2,   0,2,2,2,0));
    nima[5].push_back(OP(0,2,2,0,2,   4,0,2,0,0));
    nima[5].push_back(OP(4,0,2,0,0,   5,0,0,2,0));

    //cout << "X : " << endl;
    //X
    nima[6].push_back(OP(1,1,1,0,2,   2,1,1,0,2));
    nima[6].push_back(OP(2,1,1,0,2,   3,1,1,0,2));
    nima[6].push_back(OP(3,1,1,0,2,   4,1,1,0,2));
    nima[6].push_back(OP(4,1,1,0,2,   1,1,1,0,2));

    //cout << "Y : " << endl;
    //Y
    nima[7].push_back(OP(1,0,2,1,1,   0,0,2,1,1));
    nima[7].push_back(OP(0,0,2,1,1,   3,2,0,1,1));
    nima[7].push_back(OP(3,0,2,1,1,   5,2,0,1,1));
    nima[7].push_back(OP(5,0,2,1,1,   1,0,2,1,1));

    //cout << "Z : " << endl;
    //Z
    nima[8].push_back(OP(5,1,1,0,2,   2,0,2,1,1));
    nima[8].push_back(OP(2,0,2,1,1,   0,1,1,2,0));
    nima[8].push_back(OP(0,1,1,0,2,   4,0,2,1,1));
    nima[8].push_back(OP(4,0,2,1,1,   5,1,1,2,0));

    int cas = 0;
    while (scanf("%s",s)!=EOF)
    {
        len = strlen(s);
        fuck.init();
        for (int i = 0;i < len;i++)
        {
            fuck.gao(getid(s[i]));

            //fuck.view();
        }

        //fuck.view();

        if (cas > 0)
            puts("");
        cas++;
        if (fuck.complete())
            puts("Yes");
        else
            puts("No");
    }
	return 0;
}
