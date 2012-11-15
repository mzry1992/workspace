#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[200000],tot;
int num[10],tnum[10];

void DFS()
{
    if (tnum[0] == num[0]+1)
    {
        if (tnum[tnum[0]] == 0) return;
        tot++;
        int temp = 0;
        for (int i = tnum[0];i >= 1;i--)
            temp = temp*10+tnum[i];
        a[tot] = temp;
        //printf("%d\n",temp);
        //system("pause");
        return;
    }
    int depth = tnum[0];
    if (num[depth]+tnum[depth] <= 9)
    {
        tnum[0]++;
        tnum[tnum[0]] = num[depth]+tnum[depth];
        DFS();
        tnum[0]--;
        tnum[tnum[0]] = 0;
    }
    if (num[depth] != 0)
    if (tnum[depth]-num[depth] >= 0)
    {
        tnum[0]++;
        tnum[tnum[0]] = tnum[depth]-num[depth];
        DFS();
        tnum[0]--;
        tnum[tnum[0]] = 0;
    }
}

void getmore(int now)
{
    int temp = now;
    num[0] = 0;
    while (temp > 0)
    {
        num[0]++;
        num[num[0]] = temp%10;
        temp /= 10;
    }
    while (num[0] < 8)
    {
        for (int i = 0;i <= 9;i++)
        {
            tnum[0] = 1; tnum[1] = i;
            DFS();
        }
        num[0]++;
    }
}

int find(int val)
{
    int l,r,mid;
    l = 1; r = tot;
    while (l < r)
    {
        mid = (l+r+1)/2;
        if (a[mid] == val) return mid;
        if (a[mid] > val)
            r = mid-1;
        else
            l = mid;
    }
    return l;
}

int main()
{
    tot = 1;
    a[1] = 7;
    int pre = 1;
    while (pre <= tot)
    {
        getmore(a[pre]);
        pre++;
    }
    sort(a+1,a+tot+1);
    //cout << tot << endl;
    for (int i = 1027;i <= 1100;i++)
        printf("%d %d\n",i-27,a[i]);
    int l,r;
    while (scanf("%d%d",&l,&r) != EOF)
    {
        int tl,tr;
        tl = find(l);
        if (a[tl] < l) tl++;
        tr = find(r);
        if (a[tr] > r) tr--;
        printf("%d\n",tr-tl+1);
    }
}

