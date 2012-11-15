#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char s[110],t[110],m;
void solve(char s[],int k){
    int i,x=strlen(s)-1;
    if (!x || k==m) return;
    if ((k+1)%2) {
        for (i=0;i<x+1;i++)
            t[i]=s[x-i];
        for (i=0;i<x+1;i++)
            s[i]=t[i];
    }
    for (i=x-1;i>-1;i--)
        if (s[x]>s[i]) x=i;
    for (i=0;i<x;i++)
        t[i]=s[i];
    t[x]='\0';

}
int main(){
    int T,cas,n,m;
    scanf("%d",&T);
    for (cas=1;cas<=t;cas++){
        scanf("%d%d%s",&n,&m,s);
        solve(s,m);
        printf("Case %d: %s\n",cas,t);
    }
}
