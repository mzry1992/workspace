#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[40],use[400],vv[400];

void Gao(int deep,int end,int now,int last,int ma)
{
    //cout << deep << ' ' << end << ' ' << now << ' ' << last << ' ' << ma << endl;
    //cout << deep << endl;
    if (end == now)
    {
        for (int i = 0;i < deep;i++)
            printf("a[%d]*%d ",use[i],vv[i]);
        printf("\n");
        return;
    }
    if (now > end)  return;
    for (int i = last+1;i < ma;i++)
        for (int j = 1;now+a[i]*j <= end;j++)
        {
            use[deep] = i;
            vv[deep] = j;
            Gao(deep+1,end,now+a[i]*j,i,ma);
        }
}

int main()
{
    a[1]=2;
    a[2]=2;
    a[3]=4;
    a[4]=4;
    a[5]=8;
    a[6]=12;
    a[7]=20;
    a[8]=32;
    a[9]=60;
    a[10]=104;
    a[11]=188;
    a[12]=344;
    a[13]=632;
    a[14]=1172;
    a[15]=2192;
    a[16]=4096;
    a[17]=7712;
    a[18]=14572;
    a[19]=27596;
    a[20]=52432;
    a[21]=99880;
    a[22]=190652;
    a[23]=364724;
    a[24]=699072;
    a[25]=1342184;
    a[26]=2581112;
    a[27]=4971068;
    a[28]=9586984;
    a[29]=18512792;
    a[30]=35791472;
    freopen("HS.txt","w",stdout);
    for (int i = 14;i <= 14;i++)
    {
        printf("For n = %d , a[%d] = %d\n",i,i,a[i]);
        Gao(0,a[i],0,0,i);
    }
    return 0;
}
