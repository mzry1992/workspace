// IDA*
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define    SIZE 3

char board[SIZE][SIZE];

//启发函数: 除去x之外到目标的网格距离和
int goal_state[9][2] = {{0,0}, {0,1}, {0,2},
        {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
int h(char board[][SIZE]){
    int cost = 0;
    for(int i=0; i<SIZE; ++i)
        for(int j=0; j<SIZE; ++j){
            if(board[i][j] != SIZE*SIZE){
                cost += abs(i - goal_state[board[i][j]-1][0]) +
                        abs(j - goal_state[board[i][j]-1][1]);
            }
        }
    return cost;
}

int step[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};//u, l, r, d
char op[4] = {'u', 'l', 'r', 'd'};

char solution[1000];
int bound;     //上界
bool ans;    //是否找到答案
int DFS(int x, int y, int dv, char pre_move){// 返回next_bound
    int hv = h(board);
    if(hv + dv > bound)
        return dv + hv;
    if(hv == 0){
        ans = true;
        return dv;
    }

    int next_bound = 1e9;
    for(int i=0; i<4; ++i){
        if(i + pre_move == 3)//与上一步相反的移动
            continue;
        int nx = x + step[i][0];
        int ny = y + step[i][1];
        if(0<=nx && nx<SIZE && 0<=ny && ny<SIZE){
            solution[dv] = i;
            swap(board[x][y], board[nx][ny]);

            int new_bound = DFS(nx, ny, dv+1, i);
            if(ans)
                return new_bound;
            next_bound = min(next_bound, new_bound);

            swap(board[x][y], board[nx][ny]);
        }
    }
    return next_bound;
}

void IDA_star(int sx, int sy){
    ans = false;
    bound = h(board);//初始代价
    while(!ans && bound <= 100)//上限
    {
        cout << bound << endl;
        bound = DFS(sx, sy, 0, -10);
    }
}

int main(){

    int sx, sy;//起始位置
    char c;
    for(int i=0; i<SIZE; ++i)
        for(int j=0; j<SIZE; ++j){
            cin>>c;
            if(c == 'x'){
                board[i][j] = SIZE * SIZE;
                sx = i;
                sy = j;
            }
            else
                board[i][j] = c - '0';
        }

    IDA_star(sx, sy);

    if(ans){
        for(int i=0; i<bound; ++i)
            cout<<op[solution[i]];
    }
    else
        cout<<"unsolvable";

    return 0;
}
