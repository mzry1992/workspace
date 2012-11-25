#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

const double eps = 1e-10;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Vill
{
    char name[10];
    int namelen;
    double p,x,y;
};
struct Edge
{
    int from,to,next;
    double theta;
};

int head[100];
Vill vill[100];
Edge edge[5000*2];
int n,m,L;
map<string,int> nameid;
char uname[10],vname[10];
int u,v;

double Calctheta(Vill a,Vill b)
{
    double x,y;
    x = b.x-a.x;
    y = b.y-a.y;
    return atan2(y,x);
}

void addedge(int u,int v)
{
    edge[L].from = u;
    edge[L].to = v;
    edge[L].theta = Calctheta(vill[u],vill[v]);
    if (head[u] == -1 || cmp(edge[L].theta,edge[head[u]].theta) < 0)
    {
        edge[L].next = head[u];
        head[u] = L++;
        return;
    }
    for (int i = head[u];; i = edge[i].next)
    {
        if (edge[i].next == -1 || cmp(edge[L].theta,edge[edge[i].next].theta) < 0)
        {
            edge[L].next = edge[i].next;
            edge[i].next = L++;
            return;
        }
    }
}

double CalcArea(int efrom,int eto)
{
    return (vill[efrom].x*vill[eto].y-vill[efrom].y*vill[eto].x)/2.0;
}

double etheta[100][5000];
int eto[100][5000];
int ecnt[100];

double res,area,popu,newtheta,nowtheta,tres;
int stu,stv,nowu,nowv,pos,newu,newv;

bool visit[100];
bool vis[100][100];

int resseq[1000],totres;

char ts[10000],ns[10000],s[10000];
int tslen,nslen,slen;

bool check(char a[],int alen,char b[],int blen)
{
    for (int i = 0; i < min(alen,blen); i++)
        if (a[i] > b[i])    return true;
        else if (a[i] < b[i])   return false;
    return alen > blen;
}

void getress()
{
    tslen = 0;
    for (int i = 0; i < totres; i++)
    {
        nslen = 0;
        for (int j = 0; j < totres; j++)
        {
            for (int k = 0; k < vill[resseq[(i+j)%totres]].namelen; k++)
                ns[nslen++] = vill[resseq[(i+j)%totres]].name[k];
            ns[nslen++] = ' ';
        }
        ns[--nslen] = 0;
        if (tslen == 0 || check(ts,tslen,ns,nslen) == true)
        {
            tslen = nslen;
            for (int j = 0; j < tslen; j++)
                ts[j] = ns[j];
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        nameid.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s%lf%lf%lf",vill[i].name,&vill[i].p,&vill[i].x,&vill[i].y);
            nameid[vill[i].name] = i;
            vill[i].namelen = strlen(vill[i].name);
            head[i] = -1;
        }
        int minid = 0;
        for (int i = 1; i < n; i++)
            if (cmp(vill[minid].x,vill[i].x) > 0)
                minid = i;
        scanf("%d",&m);
        L = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%s%s",uname,vname);
            u = nameid[uname];
            v = nameid[vname];
            addedge(u,v);
            addedge(v,u);
        }
        for (int i = 0; i < n; i++)
        {
            ecnt[i] = 0;
            for (int j = head[i]; j != -1; j = edge[j].next)
            {
                etheta[i][ecnt[i]] = edge[j].theta;
                eto[i][ecnt[i]] = edge[j].to;
                ecnt[i]++;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                vis[i][j] = false;
        res = 1e100;
        slen = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < ecnt[i]; j++)
            {
                stu = i;
                stv = eto[i][j];
                if (vis[stu][stv] == true)  continue;
                area = popu = 0;
                nowu = stu;
                nowv = stv;
                nowtheta = etheta[i][j];
                for (int k = 0; k < n; k++)
                    visit[k] = false;
                totres = 0;
                while (true)
                {
                    if (nowu == minid && cmp(nowtheta,etheta[nowu][ecnt[nowu]-1]) == 0)
                    {
                        popu = 1e100;
                        break;
                    }
                    resseq[totres++] = nowu;
                    area += CalcArea(nowu,nowv);
                    vis[nowu][nowv] = true;
                    if (visit[nowu] == false)
                        popu += vill[nowu].p;
                    visit[nowu] = true;
                    nowtheta += pi;
                    if (cmp(nowtheta,pi) > 0)
                        nowtheta -= 2*pi;
                    pos = (int)(lower_bound(etheta[nowv],etheta[nowv]+ecnt[nowv],nowtheta-eps)-etheta[nowv]);
                    pos = (pos-1+ecnt[nowv])%ecnt[nowv];
                    newu = nowv;
                    newv = eto[newu][pos];
                    newtheta = etheta[newu][pos];
                    nowu = newu;
                    nowv = newv;
                    nowtheta = newtheta;
                    if (nowu == stu && nowv == stv) break;
                }
                if (cmp(area,0) == 0)   continue;
                area = fabs(area);
                tres = popu/area;
                getress();
                if (cmp(res,tres) > 0)
                {
                    res = tres;
                    if (slen == 0 || check(s,slen,ts,tslen) == true)
                    {
                        slen = tslen;
                        for (int j = 0; j < slen; j++)
                            s[j] = ts[j];
                    }
                }
                else if (cmp(res,tres) == 0)
                {
                    if (slen == 0 || check(s,slen,ts,tslen) == true)
                    {
                        slen = tslen;
                        for (int j = 0; j < slen; j++)
                            s[j] = ts[j];
                    }
                }
            }
        printf("%.3f %s\n",res,s);
    }
    return 0;
}
