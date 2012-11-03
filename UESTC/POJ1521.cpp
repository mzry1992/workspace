#include <stdio.h>
#include <string.h>
#define IS_CHAR 0
#define IS_ROAD 1

char ch[500],s[1000];
int i,j,len,alpha[500],va[500],tot,temp,result,bit;
double ratio;

struct node
{
       int type;
       char word;
       int value;
       int father;
};
struct node tree[1000];
int rootlist[1000],totroot,totnode;

void construct()
{
     int temp1,temp2,temp3,i,j;
     totroot = 0;
     totnode = tot;
     for (i = 1;i <= totnode;i++)
     {
         tree[i].type = IS_CHAR;
         tree[i].word = ch[i];
         tree[i].value = va[i];
         tree[i].father = i;
         totroot++;
         rootlist[totroot] = i;
     }
     while (totroot > 1)
     {
           temp1 = rootlist[1];
           temp2 = rootlist[2];
           totnode++;
           tree[totnode].type = IS_ROAD;
           tree[totnode].value = tree[temp1].value+tree[temp2].value;
           tree[totnode].father = totnode;
           tree[temp1].father = totnode;
           tree[temp2].father = totnode;
           rootlist[1] = totnode;
           rootlist[2] = rootlist[totroot];
           totroot--;
           for (i = 1;i <= totroot;i++)
           for (j = i;j <= totroot;j++)
           {
               temp1 = rootlist[i];
               temp2 = rootlist[j];
               if (tree[temp1].value > tree[temp2].value)
               {
                                     rootlist[i] = temp2;
                                     rootlist[j] = temp1;
               }
           }
     }
}

void clearall()
{
     int i;
     for (i = 0;i <= 500;i++)
         alpha[i] = 0;
}

int main()
{
    gets(s);
    while (1 == 1)
    {  
        clearall();  
        len = strlen(s);
        if ((len == 3) && (s[0] == 'E') && (s[1] == 'N') && (s[2] == 'D')) break;
        for (i = 0;i < len;i++)
            alpha[s[i]]++;
        tot = 0;
        for (i = 1;i <= 500;i++)
        if (alpha[i] != 0)
        {
                     tot++;
                     ch[tot] = i;
                     va[tot] = alpha[i];
        }
        for (i = 1;i <= tot;i++)
        for (j = i;j <= tot;j++)
        if (va[i] > va[j])
        {
                  temp = va[i]; va[i] = va[j]; va[j] = temp;
                  temp = ch[i]; ch[i] = ch[j]; ch[j] = temp;
        }
        construct();
        result = 0;
        for (i = 1;i <= tot;i++)
        {
            temp = i;
            j = 0;
            while (tree[temp].father != temp)
            {
                  temp = tree[temp].father;
                  j++;
            }
            result += j*va[i];
        }
        if (result == 0)      result = len*1;
        bit = 8*len;
        ratio = ((double)bit/(double)result);
        printf("%d %d %.1f\n",bit,result,ratio);
        gets(s);
    }
    return 0;
}
