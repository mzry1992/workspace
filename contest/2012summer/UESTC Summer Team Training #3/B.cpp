#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct oper
{
    int typ,v;
};

int tree[10010];
oper op[10010];
int n,num[10010],tn,tot;
char com[10];

int find_kth(int k)
{
    int idx = 0;
    for (int i = 20; i >= 0; i--)
    {
        idx |= 1<<i;
        if (idx <= tn && tree[idx] < k)
            k -= tree[idx];
        else
            idx ^= 1<<i;
    }
    return idx+1;
}

void update(int k,int v)
{
    for (; k <= tn; k += k&-k)
        tree[k] += v;
}

int read(int k)
{
    int sum = 0;
    for (; k; k^=k&-k)
        sum += tree[k];
    return sum;
}

void output()
{
    if (tot%2 == 1)
        printf("%d\n",num[find_kth(tot/2+1)-1]);
    else
    {
        long long ra = num[find_kth(tot/2)-1];
        int rb = num[find_kth(tot/2+1)-1];
        if ((ra+rb)%2 == 0)
            printf("%lld\n",(ra+rb)/2);
        else
            printf("%.1f\n",(ra+rb)/2.0);
    }
}

int main()
{
    /*tn = 10;
    update(5,1);
    update(6,2);
    update(7,1);
    printf("%d\n",find_kth(0));
    printf("%d\n",find_kth(1));
    printf("%d\n",find_kth(2));
    printf("%d\n",find_kth(3));
    printf("%d\n",find_kth(4));
    printf("%d\n",find_kth(5));*/
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d",com,&op[i].v);
            if (com[0] == 'a')
                op[i].typ = 0;
            else
                op[i].typ = 1;
            num[i] = op[i].v;
        }
        sort(num,num+n);
        tn = unique(num,num+n)-num;
        tot = 0;
        memset(tree,0,sizeof(tree));
        for (int i = 0; i < n; i++)
        {
            op[i].v = lower_bound(num,num+tn,op[i].v)-num+1;
            //printf("HI : %d\n",op[i].v);
            if (op[i].typ == 0)
            {
                update(op[i].v,1);
                tot++;
                output();
            }
            else
            {
                if (read(op[i].v)-read(op[i].v-1) == 0)
                    puts("Wrong!");
                else
                {
                    update(op[i].v,-1);
                    tot--;
                    if (tot == 0)
                        puts("Empty!");
                    else
                        output();
                }
            }
        }
    }
    return 0;
}
