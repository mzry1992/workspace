#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct player
{
    int tim,id;
    friend bool operator < (const player& a,const player& b)
    {
        return a.tim > b.tim;
    }
};

player a[100];
int n;
vector<int> w[100];

int main()
{
    freopen("tmp.txt","w",stdout);
    for (int i = 0;i < 50;i++)
    {
        long long tmp = (long long)rand()*rand()*rand()*rand()%10000000000000000LL;
            tmp = -tmp;
        cout << tmp << ',';
    }
    cout << endl;
    cout << 10000000000000000LL << endl;
    return 0;
    scanf("%d",&n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i].tim);
        sum += a[i].tim;
        a[i].id = i+1;
    }
    sort(a,a+n);
    sum /= 2;
    int tot = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        tot += a[i].tim;
        if (tot-i >= sum)
        {
            mx = i;
            break;
        }
    }
    if (mx > 0)
    {
        for (int i = 1; i < mx; i++)
            a[i].tim -= 2;
        a[0].tim--;
        a[mx].tim--;
    }
    for (int i = n-1; i >= 0; i--)
        while (a[i].tim > 0)
        {
            int pos = 0;
            for (int j = 0; j <= mx; j++)
                if (i != j && a[j].tim >= a[pos].tim)
                    pos = j;
            a[pos].tim--;
            w[pos].push_back(a[i].id);
            a[i].tim--;
        }
    printf("%d\n",sum);
    for (int i = 0; i <= mx; i++)
    {
        for (int j = 0; j < w[i].size(); j++)
            printf("%d %d\n",a[i].id,w[i][j]);
        if (i < mx)
            printf("%d %d\n",a[i+1].id,a[i].id);
    }
    return 0;
}
