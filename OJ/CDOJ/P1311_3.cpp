#include <stdio.h>
#include <string.h>
#include <math.h>

int tcase,fcase;
int n,i,j;
char list[1100][30];
struct nodetype
{
       int next;
       char ch;
}node[26];
int ind[26],outd[26];
struct passtype
{
       int next;
       int end;
}pass[1100];

void addpass(int i)
{
     int len,start,end;
     len = strlen(list[i]);
     end = list[i][len-1]-'a'+1;
     start = list[i][0]-'a'+1;
     pass[i].end = end;
     outd[start]++;
     ind[end]++;
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
}

void work()
{
     printf("I am working\n");
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
        }
        for (i = 1;i <= n;i++)
        {
            scanf("%s",&list[i]);
            addpass(i);
        }
    }
    return 0;
}
