/*
ID: muziriy3
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

void DFS(int lm,int lz,int rm,int rz)
{
    if (lz+rz > n)  return;
    DFS(lm,lz,lm+rm,lz+rz);
    printf("%d/%d\n",lm+rm,lz+rz);
    DFS(lm+rm,lz+rz,rm,rz);
}

int main()
{
    //freopen("frac1.in","r",stdin);
    //freopen("frac1.out","w",stdout);
    scanf("%d",&n);
    printf("%d/%d\n",0,1);
    DFS(0,1,1,1);
    printf("%d/%d\n",1,1);
}
