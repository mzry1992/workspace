#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char s[160];
char tmp[160],tmp1[160];
bool dp[160][160],flag[160][160];
bool solve(int y,int z){
    //cout<<y<<" "<<z<<endl;
    if (flag[y][z]) return dp[y][z];
    flag[y][z]=1;
    if (z==y) return dp[y][z]=false;
    //cout<<2<<endl;
    char x=s[y];
    int i;
    for (i=y+1;i<z+1;i++)
        if (s[i]!=x) break;
    if (i==z+1)
        return dp[y][z]=true;
    //cout<<3<<endl;
    int a=i-1;
    x=s[z];
    for (i=z-1;i>=0;i--)
        if (s[i]!=x) break;
    int b=i+1;
    if (a==b-1){
        if (a>y && z>b) return dp[y][z]=true;
        else return dp[y][z]=false;
    }
    //cout<<4<<endl;
    if (s[a]==s[b] && solve(a+1,b-1)) return dp[y][z]=true;
    //cout<<a<<" "<<b<<endl;
    for (i=y+1;i<z;i++){
        int k=0;
        k=i;
        if (solve(y,i-1) && solve(i,z)) return dp[y][z]=true;
        //cout<<y<<" "<<i-1<<endl;
        //cout<<i<<" "<<z<<endl;
        //cout<<s.substr(i,s.size()-i)<<endl;
    }
    return dp[y][z]=false;
    //cout<<temp<<endl;
}
int main(){
    while (scanf("%s",s)>0)
    {
        memset(flag,0,sizeof(flag));
        if (solve(0,strlen(s)-1)) printf("solvable\n");
        else printf("unsolvable\n");
    }
}
