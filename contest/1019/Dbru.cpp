#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
long long Gao(long long num, int x){
    if(num/10 == 0) return num;
    long long ret = 0;
    long long mul = 1;
    while(num){
        ret+= (num%10)*mul;
        num/=10;
        mul*=x;
    }
    return Gao(ret,x);
}
int Gao(char num[],int len ,int x){
    if(len == 1) return num[0]-'0';
    num[1]--;//N-10
    int mod = 9-x+1;
    int ten = 1;
    long long pos = 0;
    for(int i = 0 ; i < len ;i++,ten=ten*10%mod){
        pos =(pos + (num[i]-'0')*ten)%mod;
    }
    num[1]++;
    //printf("x = %d pos =%lld\n",x,pos);
    return x+pos;
}
char ts[100010];
int main(){
    while(gets(ts)){
        int len = strlen(ts);
        reverse(ts,ts+len);
        int ret = Gao(ts,len,2);
        printf("%d",Gao(ts,len,1));
        for(int i = 2;i<=9;i++)
           printf(" %d",Gao(ts,len,i));
        puts("");
    }
    return 0;
}
