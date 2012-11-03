#include <iostream>
#define MAX 19999999
#define NMAX 5000
#define NOTUSE 20100608
using namespace std;

long n,i,j,tsum,result,zero,temp,hash[MAX+123],sum[MAX+123],a[NMAX],b[NMAX],c[NMAX],d[NMAX];

long gethash(long x)
{
     x %= MAX;
     return (x > 0)? x : x+MAX;
}
     
int main()
{
    cin >> n;
    for (i = 1;i <= n;i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    for (i = 0;i <= MAX;i++)
    {
        hash[i] = NOTUSE;
        sum[i] = 0;
    }
    zero = 0;
    for (i = 1;i <= n;i++)
    for (j = 1;j <= n;j++)
    {
        tsum = a[i]+b[j];
        temp = gethash(tsum);
        while ((hash[temp] != NOTUSE) && (hash[temp] != tsum)) temp++;
        hash[temp] = tsum;
        sum[temp]++;
    }
    result = 0;
    for (i = 1;i <= n;i++)
    for (j = 1;j <= n;j++)
    {
        tsum = c[i]+d[j];
        tsum = -tsum;
        temp = gethash(tsum);
        while ((hash[temp] != NOTUSE) && (hash[temp] != tsum)) temp++;
        result += sum[temp];
    }
    cout << result << endl;
    //system("pause");
    return 0;
}
