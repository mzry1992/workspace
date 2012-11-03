#include<stdio.h>
int father[60000],more[60000],num[60000];
int find(int i)
{
    int k;
    if (father[i]==i) return i;
    k=find(father[i]);
    more[i]+=more[father[i]];
    return father[i]=k;
}
int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++)
    {
        father[i]=i;
        more[i]=0;
        num[i]=0;
    }
    int flag=0;
    for (int i=0; i<m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (find(a)!=find(b))
        {
            int k=find(a);
            father[k]=find(b);
            more[k]=c-more[a]+more[b];
        }
        else
        {
            if (more[a]-more[b]!=c)
            {
                flag=i+1;
                break;
            }
        }

        if (find(a)==find(0) && more[a]-more[0]<0)
            flag=i+1;
        if (find(b)==find(0) && more[b]-more[0]<0)
            flag=i+1;
        if (find(a)==find(0) && more[a]-more[0]>1000000000)
            flag=i+1;
        if (find(b)==find(0) && more[b]-more[0]>1000000000)
            flag=i+1;
        if (flag) break;
    }
    if (flag)
    {
        printf("Impossible after %d statements\n",flag);
        return 0;
    }
    puts("Possible");
    for (int i=0; i<n; i++)
        if (num[find(i)]+more[i]<0)
            num[find(i)]=-more[i];
    for (int i=0;i<n;i++)
        num[i]=num[find(i)]+more[i];
    for (int i=0; i<n; i++)
        if (find(i)!=find(0))
            printf("%d\n",num[i]);
        else
            printf("%d\n",num[i]-num[0]);
    return 0;
}
