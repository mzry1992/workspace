#include<stdio.h>
#include<stdlib.h>
#include<cstring>
int num[100001];
int cnt[100001];
int p[5000011];
int a[5000011];
int fc[5000011];
int gc[5000011];
int gc2[5000011];
int Prime1(int n) {
    memset(a, 0, n * sizeof(a[0]));
    int num = 0, i, j;
    for(i = 2; i < n; ++i) if(!a[i]) {
        p[num++] = i;
        for(j = i+i; j < n; j +=i) {
            a[j] = 1;
            fc[j] = i;
        }
    }
    return num;
}

int main(){
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n ;

    Prime1(5000001);
    for(int i = 0 ; i <= 5000000 ; i++){
        if(!a[i]) gc[i] = 1;
        else{
            gc[i] = gc[i/fc[i]] + 1;
        }
    }
    int cas = 0;
    while(scanf("%d",&n) == 1){
        printf("Test #%d: ",++cas);
       // memset(cnt,0,sizeof(cnt));
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&num[i]);
        for(int i = 0 ; i < n ; i++)
            cnt[i] = gc[num[i]];
        int xo = 0;
        for(int i = 0 ; i < n ;i++)
            xo = xo^cnt[i];
        if(xo == 0){puts("Bob");}
        else{
            int ans = -1;
            for(int i = 0 ; i < n&&ans ==-1 ; i++)
                for(int j = 0 ; j < cnt[i] ; j++)
                    if(((xo^cnt[i])^j) == 0){
                    //if(((xo^cnt[i]) < cnt[i])){
                        ans = i;
                        break;
                    }
            printf("Alice %d\n",ans+1);
        }
    }
    return 0;
}
