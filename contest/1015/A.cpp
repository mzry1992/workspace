#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int left ,right;
}arr[2000];
int cnt[30];
vector< pair<  int,pair<char,int> > > ans;
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        ans.clear();
        if(n == 0)break;
        int sum = 0;
        for(int i= 0; i< n;i++)
            {
                scanf("%d",&cnt[i]);
                sum += cnt[i];
            }
        sum += n;
        int top = sum-1 , bot = 0;
        for(int i = 0 ; i < n;i++){
            if(i %2 ==0){
                arr[bot].left = i;
                arr[bot++].right = 0;
                for(int j = cnt[i] ;j>=1;j--){
                    arr[top].left = i;
                    arr[top].right = j;
                    top--;
                }
            }else{
                arr[top].left = i;
                arr[top--].right = 0;
                for(int j = 1;j<=cnt[i];j++){
                    arr[bot].left = i;
                    arr[bot].right = j;
                    bot++;
                }
            }
         }
        puts("");
        for(int i =1 ;i <= sum;i++){
            printf("(%c%d, %d)",arr[i-1].left+'a' ,arr[i-1].right,i-1);
            if(i == sum) {puts("");break;}
            if(i%8==0) puts("");
            else if( i!= sum)
                putchar(' ');
        }
    }
    return 0;
}
