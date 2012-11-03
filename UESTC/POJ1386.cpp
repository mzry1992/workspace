#include <stdio.h>
#include <string.h>
#include <math.h>

int tcase,fcase;
int n,i,j;
char list[1100];
struct nodetype
{
       int next;
       char ch;
}node[26];
int ind[26],outd[26],f[26];
struct passtype
{
       int next;
       int end;
}pass[110000];

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

void addpass(int i)
{
     int len,start,end,f1,f2;
     len = strlen(list);
     end = list[len-1]-'a'+1;
     start = list[0]-'a'+1;
     pass[i].end = end;
     outd[start]++;
     ind[end]++;
     f1 = findf(start);
     f2 = findf(end);
     if (f1 != f2)
        f[end] = start;
     if (node[start].next == 0)
     {
                                node[start].next = i;
                                pass[i].next = 0;
     }
     else
     {
                                int temp;
                                temp = node[start].next;
                                node[start].next = i;
                                pass[i].next = temp;
     }
}


int check()
{
    int i,tf,fl1,fl2;
    for (i = 1;i <= 26;i++)
        f[i] = findf(i);
    tf = findf(1);
    for (i = 2;i <= 26;i++)
    if (findf(i) != tf)    return false; 
    fl1 = fl2 = 0;
    for (i = 1;i <= 26;i++)
    {
        if (ind[i] == outd[i])    continue;
        if (ind[i] == outd[i]+1)
        {
                   fl1++;
                   if (fl1 > 1)  return false;
                   continue;
        }
        if (ind[i]+1 == outd[i])
        {
                   fl2++;
                   if (fl2 > 1)  return false;
                   continue;
        }
        return false;
    }
    if (fl1+fl2 == 1) return false;
    return true;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d",&n);
        for (i = 1;i <= 26;i++)
        {
            node[i].ch = 'a'+i-1;
            node[i].next = 0;
            ind[i] = 0;
            outd[i] = 0;
            f[i] = 0;
        }
        for (i = 1;i <= n;i++)
        {
            scanf("%s",&list);
            addpass(i);
        }
        if (check() == true)
           printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
