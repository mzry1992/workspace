#include <iostream>
using namespace std;

int casen,fcasen,p,q,i,j;
int visit[100][100],flag,stepx[100],stepy[100];
int move[8][2];

void dfs(int x,int y,int dep)
{
     int i,tx,ty;
     if (flag == 1)
     {
         if (visit[x][y] == 1) 
         {
             stepx[dep] = x;
             stepy[dep] = y;
             visit[x][y] = 0;
             if (dep == p*q)
             {
                     cout << "Scenario #" << fcasen << ":" << endl;
                     for (i = 1;i <= p*q;i++)
                         cout << (char)(stepy[i]-1+'A') << stepx[i];
                     cout << endl << endl;
                     flag = 0;
             }
             else
             for (i = 1;i <= 8;i++)
             {
                 tx = x+move[i][1];
                 ty = y+move[i][2];
                 if ((tx >= 1) && (tx <= p) && (ty >= 1) && (ty <= q))
                    dfs(tx,ty,dep+1);
             }
             visit[x][y] = 1;
         }
     }
}

int main()
{
    move[1][1] = -1;  move[1][2] = -2;
    move[2][1] = 1;  move[2][2] = -2;
    move[3][1] = -2;  move[3][2] = -1;
    move[4][1] = 2;  move[4][2] = -1;
    move[5][1] = -2;  move[5][2] = 1;
    move[6][1] = 2;  move[6][2] = 1;
    move[7][1] = -1;  move[7][2] = 2;
    move[8][1] = 1;  move[8][2] = 2;
    cin >> casen;
    for (fcasen = 1;fcasen <= casen;fcasen++)
    {
        cin >> p >> q;
        for (i = 1;i <= p;i++)
        for (j = 1;j <= q;j++)
            visit[i][j] = 1;
        flag = 1;
        dfs(1,1,1);
        if (flag == 1)
                 cout << "Scenario #" << fcasen << ":" << endl << "impossible" << endl << endl;        
    }
    return 0;
}
    
