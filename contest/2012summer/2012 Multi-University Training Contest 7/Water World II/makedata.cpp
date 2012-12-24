#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
int getrand(int l,int r){
    int t = rand(); 
    return (t*1.0*(r-l)/32000)+l;
}
int main() {
    int ti=1,i,T=0;
	freopen("data.in", "w", stdout);
	srand((unsigned)time(NULL));
	
	printf("3 0\n2 3 1\n7 2\n1 3 2 5 2 3 4\n"); 
	
	
	int dataset = 20;
	while(dataset--) {
		int l = 4*ti;
		T++;
        if(dataset>5){
    		l = T * 5;
        }else{
            l = T * 500;
        }
        //l = 10;
		printf("%d %d\n",l,getrand(1,10)); 
		for(i=0;i<l;i++){
        	printf("%d ",1+(getrand(1,T*T*T*T*10)%9999999)); 
        	//printf("%d ",getrand(1,1000000000)); 
        }
        puts("");
	}
	return 0;
}
