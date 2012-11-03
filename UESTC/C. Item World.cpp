#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
struct wp
{
    char name[20],typ[20];
    int a[3],size;
}w[101];
struct resi
{
    char name[20],typ[20],liv[20];
    int add;
}r[1001],rr[3][1001];
int sum[1001];

int getid(char *s)
{
    if (strcmp(s,"weapon") == 0 || strcmp(s,"gladiator") == 0)  return 0;
    if (strcmp(s,"armor") == 0 || strcmp(s,"sentry") == 0)  return 1;
    return 2;
}

bool cmpatk(resi a,resi b)
{
    if (getid(a.typ) == 0 && getid(b.typ) == 0)
        return a.add > b.add;
    else if (getid(a.typ) == 0) return true;
    else if (getid(b.typ) == 0) return false;
    return a.add > b.add;
}
bool cmpdef(resi a,resi b)
{
    if (getid(a.typ) == 1 && getid(b.typ) == 1)
        return a.add > b.add;
    else if (getid(a.typ) == 1) return true;
    else if (getid(b.typ) == 1) return false;
    return a.add > b.add;
}
bool cmpres(resi a,resi b)
{
    if (getid(a.typ) == 2 && getid(b.typ) == 2)
        return a.add > b.add;
    else if (getid(a.typ) == 2) return true;
    else if (getid(b.typ) == 2) return false;
    return a.add > b.add;
}
int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s%s%d%d%d%d",w[i].name,w[i].typ,&w[i].a[0],&w[i].a[1],&w[i].a[2],&w[i].size);
        scanf("%d",&k);
        for (int i = 0;i < k;i++)
        {
            scanf("%s%s%d%s",r[i].name,r[i].typ,&r[i].add,r[i].liv);
            for (int j = 0;j < n;j++)
                if (strcmp(w[j].name,r[i].liv) == 0)
                    w[j].a[getid(r[i].typ)] -= r[i].add;
        }
        int maxatk = 0,atkid;
        sort(r,r+k,cmpatk);
        int totatk = 0;
        for (int i = 0;i < k;i++)
            if (getid(r[i].typ) == 0)
                totatk++;
            else
                break;
        sum[0] = r[0].add;
        for (int i = 1;i < totatk;i++)
            sum[i] = sum[i-1]+r[i].add;
        for (int i = 0;i < n;i++)
            if (getid(w[i].typ) == 0)
            {
                if (w[i].size >= totatk)
                    w[i].size = totatk;
                w[i].a[0] += sum[totatk-1];
                if (w[i].a[0] > maxatk)
                {
                    maxatk = w[i].a[0];
                    atkid = i;
                }
            }
        printf("%s %d",w[atkid].name,w[atkid].size);
        for (int i = 0;i < w[atkid].size;i++)
            printf(" %s",r[i].name);
        printf("\n");
        int maxdef = 0,defid;
        sort(r,r+k,cmpdef);
        int totdef = 0;
        for (int i = 0;i < k;i++)
            if (getid(r[i].typ) == 1)
                totdef++;
            else
                break;
        sum[0] = r[0].add;
        for (int i = 1;i < totdef;i++)
            sum[i] = sum[i-1]+r[i].add;
        for (int i = 0;i < n;i++)
            if (getid(w[i].typ) == 1)
            {
                if (w[i].size >= totdef)
                    w[i].size = totdef;
                w[i].a[0] += sum[totdef-1];
                if (w[i].a[0] > maxdef)
                {
                    maxdef = w[i].a[0];
                    defid = i;
                }
            }
        printf("%s %d",w[defid].name,w[defid].size);
        for (int i = 0;i < w[defid].size;i++)
            printf(" %s",r[i].name);
        printf("\n");
        int maxres = 0,resid;
        sort(r,r+k,cmpres);
        int totres = 0;
        for (int i = 0;i < k;i++)
            if (getid(r[i].typ) == 2)
                totres++;
            else
                break;
        sum[0] = r[0].add;
        for (int i = 1;i < totres;i++)
            sum[i] = sum[i-1]+r[i].add;
        for (int i = 0;i < n;i++)
            if (getid(w[i].typ) == 2)
            {
                if (w[i].size >= totres)
                    w[i].size = totres;
                w[i].a[0] += sum[totres-1];
                if (w[i].a[0] > maxres)
                {
                    maxres = w[i].a[0];
                    resid = i;
                }
            }
        printf("%s %d",w[resid].name,w[resid].size);
        for (int i = 0;i < w[resid].size;i++)
            printf(" %s",r[i].name);
        printf("\n");
    }
    return 0;
}
