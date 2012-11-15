#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

int n,m,q;
struct Point
{
    double a,b,c,d;
};
Point p[50000],f[50000];

double a,b,c,theta,mt[4][4],tmp[4][4],tmt[4][4],rmt[4][8];
char com[20];

void TRANSLATE()
{
    memset(tmt,0,sizeof(tmt));
    tmt[0][0] = tmt[1][1] = tmt[2][2] = tmt[3][3] = 1;
    tmt[3][0] = a;
    tmt[3][1] = b;
    tmt[3][2] = c;
    memset(tmp,0,sizeof(tmp));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tmp[i][j] += mt[i][k]*tmt[k][j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mt[i][j] = tmp[i][j];
}

void ROTATE()
{
    theta = -theta*pi/180;
    memset(tmt,0,sizeof(tmt));
    tmt[3][3] = 1;
    tmt[0][0] = cos(theta)+(1-cos(theta))*a*a;
    tmt[1][0] = (1-cos(theta))*a*b+c*sin(theta);
    tmt[2][0] = (1-cos(theta))*a*c-b*sin(theta);
    tmt[0][1] = (1-cos(theta))*a*b-c*sin(theta);
    tmt[1][1] = cos(theta)+(1-cos(theta))*b*b;
    tmt[2][1] = (1-cos(theta))*b*c+a*sin(theta);
    tmt[0][2] = (1-cos(theta))*a*c+b*sin(theta);
    tmt[1][2] = (1-cos(theta))*b*c-a*sin(theta);
    tmt[2][2] = cos(theta)+(1-cos(theta))*c*c;
    memset(tmp,0,sizeof(tmp));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tmp[i][j] += mt[i][k]*tmt[k][j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mt[i][j] = tmp[i][j];
}

void SCALE()
{
    memset(tmt,0,sizeof(tmt));
    tmt[0][0] = a;
    tmt[1][1] = b;
    tmt[2][2] = c;
    tmt[3][3] = 1;
    memset(tmp,0,sizeof(tmp));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tmp[i][j] += mt[i][k]*tmt[k][j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mt[i][j] = tmp[i][j];
}

void solvep(Point p)
{
    memset(tmt,0,sizeof(tmt));
    tmt[0][0] = p.a;
    tmt[0][1] = p.b;
    tmt[0][2] = p.c;
    tmt[0][3] = 1;
    memset(tmp,0,sizeof(tmp));
    for (int i = 0; i < 1; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tmp[i][j] += tmt[i][k]*mt[k][j];
    printf("%.2f %.2f %.2f\n",tmp[0][0],tmp[0][1],tmp[0][2]);
}

void solvef(Point f)
{
    memset(tmt,0,sizeof(tmt));
    tmt[0][0] = f.a;
    tmt[1][0] = f.b;
    tmt[2][0] = f.c;
    tmt[3][0] = 0;
    memset(tmp,0,sizeof(tmp));
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 1;j++)
            for (int k = 0;k < 4;k++)
                tmp[i][j] += mt[i][k]*tmt[k][j];
    tmp[3][0] += f.d;
    double kk = tmp[0][0]*tmp[0][0]+tmp[1][0]*tmp[1][0]+tmp[2][0]*tmp[2][0];
    kk = sqrt(1/kk);
    for (int i = 0;i < 4;i++)
        printf("%.2f ",tmp[i][0]*kk);
    printf("\n");
}

void solvermt()
{
    memset(rmt,0,sizeof(rmt));
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
            rmt[i][j] = mt[i][j];
    rmt[0][4] = rmt[1][5] = rmt[2][6] = rmt[3][7] = 1;
    for (int i = 0;i < 4;i++)
    {
        for (int j = i;j < 4;j++)
            if (fabs(rmt[j][i]) > 1e-8)
            {
                for (int k = i;k < 8;k++)
                    swap(rmt[i][k],rmt[j][k]);
                break;
            }
        double tt = rmt[i][i];
        for (int j = i;j < 8;j++)
            rmt[i][j] /= tt;
        for (int j = 0;j < 4;j++)
            if (i != j)
            {
                tt = rmt[j][i];
                for (int k = i;k < 8;k++)
                    rmt[j][k] -= rmt[i][k]*tt;
            }
    }
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
            mt[i][j] = rmt[i][4+j];
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf%lf",&p[i].a,&p[i].b,&p[i].c);
    for (int i = 0; i < m; i++)
        scanf("%lf%lf%lf%lf",&f[i].a,&f[i].b,&f[i].c,&f[i].d);
    memset(mt,0,sizeof(mt));
    mt[0][0] = mt[1][1] = mt[2][2] = mt[3][3] = 1;
    for (int i = 0; i < q; i++)
    {
        scanf("%s",com);
        if (strcmp(com,"TRANSLATE") == 0)
        {
            scanf("%lf%lf%lf",&a,&b,&c);
            TRANSLATE();
        }
        else if (strcmp(com,"ROTATE") == 0)
        {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&theta);
            ROTATE();
        }
        else if (strcmp(com,"SCALE") == 0)
        {
            scanf("%lf%lf%lf",&a,&b,&c);
            SCALE();
        }
    }
    for (int i = 0; i < n; i++)
        solvep(p[i]);
    solvermt();
    for (int i = 0; i < m; i++)
        solvef(f[i]);
    return 0;
}
