#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int TOP = 100010;
vector<int> fact[TOP];
set<int> tree;
int main(){
    for(int i = 1 ;i <TOP;i++){
        for(int j = 1; j*j <=i ;j++){
            if(i%j != 0) continue;
            int l = j , r = i/j;
            fact[i].push_back(l);
            if(l!=r) fact[i].push_back(r);
        }
    }
    int N ,ans = 0;
    scanf("%d",&N);
    for(int A = 1; A<=N; A++){
        tree.clear();
        for(int x = 1;A*x<=N;x++){
            int By = N - A*x;
            if(tree.find(By)==tree.end()){
                for(int i = 0 ; i < fact[By].size() ; i++)
                    if(fact[By][i] > A)
                        tree.insert(fact[By][i]);
            }
        }
        ans += tree.size();
    }
    printf("%d\n",ans);
    return 0;
}
