#include<stdio.h>
using namespace std;
char mp[1001][1001];
int ans[1001][1001];
int n , m;
bool check(int x,int y)
    {
        return x>=0 &&y>=0 && x<n &&y<m;
    }
int main()
    {

        scanf("%d%d",&n,&m);
        for(int i = 0 ; i < n ;i++)
            scanf("%s",mp[i]);
        bool fail = false;
        int tot = 0;
        for(int i = 0 ; i < n && !fail ;i++)
            {
                for(int j = 0 ; j < m; j++)
                    {
                        if(mp[i][j] == 'w' || mp[i][j] == '.') continue;
                        if(check(i-1,j) && check(i+1,j) && mp[i-1][j] == mp[i+1][j] && mp[i+1][j] =='w' && ans[i-1][j] == 0 && ans[i+1][j] == 0)
                            {
                                ans[i-1][j] = ans[i+1][j] = ans[i][j] = ++tot;
                                continue;
                            }
                        if(check(i,j-1) && check(i,j+1) && mp[i][j-1] == mp[i][j+1] && mp[i][j+1] =='w' && ans[i][j-1] == 0 && ans[i][j+1] ==0)
                            {
                                ans[i][j-1] = ans[i][j+1] = ans[i][j] = ++tot;
                                continue;
                            }
                        fail = true;
                        break;

                    }
            }
        for(int i = 0 ; i < n ;i++,putchar('\n'))
            for(int j = 0 ; j < m ;j++)
                printf("%3d ",ans[i][j]);
        for(int i = 0 ; i < n &&!fail;i++)
            for(int j = 0 ; j < m ;j++)
                if(ans[i][j] == 0 && mp[i][j] != '.') {fail = true;break;}


        if(fail) {puts("NO");return 0;}
        puts("YES");

        return 0;
    }
