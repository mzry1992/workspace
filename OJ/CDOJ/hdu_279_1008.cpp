#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

char map[6][8];
struct queue
{
       char now[6][8];
       int work[100],tw;
}d[100000];

bool ok(int x)
{
     if (d[x].now[0][2] != d[x].now[0][3])  return false;     
     if (d[x].now[0][3] != d[x].now[1][2])  return false;     
     if (d[x].now[1][2] != d[x].now[1][3])  return false;     
     
     if (d[x].now[2][0] != d[x].now[2][1])  return false;     
     if (d[x].now[2][1] != d[x].now[3][0])  return false;     
     if (d[x].now[3][0] != d[x].now[3][1])  return false;    
      
     if (d[x].now[2][2] != d[x].now[2][3])  return false;     
     if (d[x].now[2][3] != d[x].now[3][2])  return false;     
     if (d[x].now[3][2] != d[x].now[3][3])  return false;     
     
     if (d[x].now[2][4] != d[x].now[2][5])  return false;     
     if (d[x].now[2][5] != d[x].now[3][4])  return false;     
     if (d[x].now[3][4] != d[x].now[3][5])  return false;     
     
     if (d[x].now[2][6] != d[x].now[2][7])  return false;     
     if (d[x].now[2][7] != d[x].now[3][6])  return false;     
     if (d[x].now[3][6] != d[x].now[3][7])  return false;    
      
     if (d[x].now[4][2] != d[x].now[4][3])  return false;     
     if (d[x].now[4][3] != d[x].now[5][2])  return false;     
     if (d[x].now[5][2] != d[x].now[5][3])  return false;     
     
     return true;
}

void output(int x)
{
     int i;
     for (i = 1;i <= d[x].tw;i++)
         printf("%c",'X'+d[x].work[i]-1);
     printf("\n");
}

void solve()
{
     int head,tail;
     int i,j,w,hash;
     char temp[6][8];
     head = tail = 0;
     for (i = 0;i < 6;i++)
     for (j = 0;j < 8;j++)
         d[0].now[i][j] = map[i][j];
     d[0].tw = 0;
     while (head <= tail)
     {
           if (ok(head) == true)
           {
                        output(head);
                        return;
           }
           
           output(head);
           
           for (i = 0;i < 6;i++)
           for (j = 0;j < 8;j++)
                   map[i][j] = d[head].now[i][j];
           w = d[head].tw;
     
           //X-axis
           if (!((d[head].work[w] == 1) && (d[head].work[w-1] == 1) && (d[head].work[w-2] == 1)))
           {
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   temp[i][j] = d[head].now[i][j];
               temp[0][3] = map[3][6];
               temp[1][3] = map[2][6];
               for (i = 2;i <= 5;i++)
                   temp[i][3] = map[i-2][3];
               temp[2][6] = map[5][3];
               temp[3][6] = map[4][3];
               j = temp[2][4];
               temp[2][4] = temp[2][5];
               temp[2][5] = temp[3][5];
               temp[3][5] = temp[3][4];
               temp[3][4] = j;
               
               tail++;
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   d[tail].now[i][j] = temp[i][j];
               d[tail].tw = w+1;
               for (i = 1;i <= w;i++)
                   d[tail].work[i] = d[head].work[i];
               d[tail].work[w+1] = 1;
           }
           
           //Y-axis
           if (!((d[head].work[w] == 2) && (d[head].work[w-1] == 2) && (d[head].work[w-2] == 2)))
           {
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   temp[i][j] = d[head].now[i][j];
               temp[2][0] = map[2][6];
               temp[2][1] = map[2][7];
               for (i = 2;i <= 7;i++)
                   temp[2][i] = map[2][i-2];
               
               j = temp[0][2];
               temp[0][2] = temp[0][3];
               temp[0][3] = temp[1][3];
               temp[1][3] = temp[1][2];
               temp[1][2] = j;
               tail++;
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   d[tail].now[i][j] = temp[i][j];
               d[tail].tw = w+1;
               for (i = 1;i <= w;i++)
                   d[tail].work[i] = d[head].work[i];
               d[tail].work[w+1] = 2;
           /*
           cout << "Y ----------------" << endl;
           for (i = 0;i < 6;i++)
           {
               for (j = 0;j < 8;j++)
                   cout << map[i][j] ;
               cout << endl;
           }
           system("pause");
           
           for (i = 0;i < 6;i++)
           {
               for (j = 0;j < 8;j++)
                   cout << temp[i][j] ;
               cout << endl;
           }
           system("pause");
           */
           
           }
           
           //Z-axis
           if (!((d[head].work[w] == 3) && (d[head].work[w-1] == 3) && (d[head].work[w-2] == 3)))
           {
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   temp[i][j] = d[head].now[i][j];
               j = temp[2][2];
               temp[2][2] = temp[2][3];
               temp[2][3] = temp[3][3];
               temp[3][3] = temp[3][2];
               temp[3][2] = j;
               temp[2][1] = map[1][3];
               temp[3][1] = map[1][2];
               temp[4][2] = map[2][1];
               temp[4][3] = map[3][1];
               temp[2][4] = map[4][3];
               temp[3][4] = map[4][2];
               temp[1][2] = map[2][4];
               temp[1][3] = map[3][4];
               tail++;
               for (i = 0;i < 6;i++)
               for (j = 0;j < 8;j++)
                   d[tail].now[i][j] = temp[i][j];
               d[tail].tw = w+1;
               for (i = 1;i <= w;i++)
                   d[tail].work[i] = d[head].work[i];
               d[tail].work[w+1] = 3;
           }
           head++;
     }
}    

int main()
{
    int i,j;
    while (true)
    {
        for (i = 0;i < 6;i++)    
            scanf("%s",&map[i]);
        if (map[0][2] == '.')   break;
        solve();
        scanf("%s",&map[6]);
    }
    return 0;
}
