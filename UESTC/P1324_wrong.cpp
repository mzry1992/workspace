#include <iostream>  
using namespace std;  
  
int tcase,fcase,x,y,b,temp,xyb[9][9],flag;  
bool han[9][9],lie[9][9],kuai[9][9];  
  
int main()  
{  
    xyb[1][1] = 1; xyb[1][2] = 1; xyb[1][3] = 1;  
    xyb[2][1] = 1; xyb[2][2] = 1; xyb[2][3] = 1;  
    xyb[3][1] = 1; xyb[3][2] = 1; xyb[3][3] = 1;  
      
    xyb[4][1] = 4; xyb[4][2] = 4; xyb[4][3] = 4;  
    xyb[5][1] = 4; xyb[5][2] = 4; xyb[5][3] = 4;  
    xyb[6][1] = 4; xyb[6][2] = 4; xyb[6][3] = 4;  
  
    xyb[7][1] = 7; xyb[7][2] = 7; xyb[7][3] = 7;  
    xyb[8][1] = 7; xyb[8][2] = 7; xyb[8][3] = 7;  
    xyb[9][1] = 7; xyb[9][2] = 7; xyb[9][3] = 7;  
      
    xyb[1][4] = 2; xyb[1][5] = 2; xyb[1][6] = 2;  
    xyb[2][4] = 2; xyb[2][5] = 2; xyb[2][6] = 2;  
    xyb[3][4] = 2; xyb[3][5] = 2; xyb[3][6] = 2;  
  
    xyb[4][4] = 5; xyb[4][5] = 5; xyb[4][6] = 5;  
    xyb[5][4] = 5; xyb[5][5] = 5; xyb[5][6] = 5;  
    xyb[6][4] = 5; xyb[6][5] = 5; xyb[6][6] = 5;  
  
    xyb[7][4] = 8; xyb[7][5] = 8; xyb[7][6] = 8;  
    xyb[8][4] = 8; xyb[8][5] = 8; xyb[8][6] = 8;  
    xyb[9][4] = 8; xyb[9][5] = 8; xyb[9][6] = 8;  
      
    xyb[1][7] = 3; xyb[1][8] = 3; xyb[1][9] = 3;  
    xyb[2][7] = 3; xyb[2][8] = 3; xyb[2][9] = 3;  
    xyb[3][7] = 3; xyb[3][8] = 3; xyb[3][9] = 3;  
      
    xyb[4][7] = 6; xyb[4][8] = 6; xyb[4][9] = 6;  
    xyb[5][7] = 6; xyb[5][8] = 6; xyb[5][9] = 6;  
    xyb[6][7] = 6; xyb[6][8] = 6; xyb[6][9] = 6;  
  
    xyb[7][7] = 9; xyb[7][8] = 9; xyb[7][9] = 9;  
    xyb[8][7] = 9; xyb[8][8] = 9; xyb[8][9] = 9;  
    xyb[9][7] = 9; xyb[9][8] = 9; xyb[9][9] = 9;  
    
    cin >> tcase;  
    for (fcase = 1;fcase <= tcase;fcase++)  
    {  
        for (x = 1;x <= 9;x++)  
        for (y = 1;y <= 9;y++)  
        {  
            han[x][y] = true;  
            lie[x][y] = true;  
            kuai[x][y] = true;  
        }  
        flag = true;
        for (x = 1;x <= 9;x++)  
        for (y = 1;y <= 9;y++)  
        {  
            cin >> temp;  
            if (han[x][temp] == true)  
                             han[x][temp] = false;  
            else
                flag = false;
            if (lie[y][temp] == true)  
                             lie[y][temp] = false;  
            else
                flag = false;
            b = xyb[x][y];  
            if (kuai[b][temp] == true)  
                              kuai[b][temp] = false;  
            else
            {
                printf("%d %d\n",&flag,&xyb[x][y]);
                flag = false;
            }
            
        } 
    }  
    system("pause");  
    return 0;  
}  
