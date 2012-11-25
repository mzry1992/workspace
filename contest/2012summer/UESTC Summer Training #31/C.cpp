#include<cstdio>
#include<algorithm>
using namespace std;
double tcro[22][22],cro[22];
bool calced[22][22];
double calc(int a,int b)
{
    if (b>21)
        return -1;
    if (calced[a][b])
        return tcro[a][b];
    calced[a][b]=1;
    double &ret=tcro[a][b]=0;
    if (a<b)
        return ret=1;
    for (int j=1;j<=6;j++)
        ret+=calc(a,b+j)/6;
    if (a==b)
        return ret=max(ret,0.0);
    return ret;
}
double bigman[22];
int main()
{
    for (int i=0;i<22;i++)
        cro[i]=calc(i,0);
    bigman[21]=-cro[21];
    for (int j=20;j>=0;j--)
    {
        bigman[j]=0;
        for (int i=1;i<=6;i++)
            if (j+i<=21)
                bigman[j]+=bigman[j+i]/6;
            else
                bigman[j]+=-1.0/6;
        if (j)
            bigman[j]=max(-cro[j],bigman[j]);
    }
    for (int j=0;j<22;j++)
        printf("%d %f\n",j,bigman[j]);
}
