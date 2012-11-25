#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,int> mp;
char name[6][50];
int cnt[6];
int beat[6][6];
char ts[5000];
string ans ,tans;
bool lose(int a,int b){
    for(int i = 0 ; i < cnt[b];i++)
        if(beat[b][i] == a)
            return true;
    return false;
}
int main()
{
    int a1[6],a2[6];
    int N;
    int T;scanf("%d",&T);
    for(int ii = 1 ;ii<=T;ii++)
    {
        scanf("%d",&N);
        mp.clear();
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%s",name[i]);
            mp[name[i]] = i;
        }
        for(int i = 0 ; i < N; i++)
        {
            scanf("%d",&cnt[i]);
            for(int j = 0; j < cnt[i]; j++)
            {
                scanf("%s",ts);
                beat[i][j] = mp[ts];
            }
        }
        for(int i = 0; i < N; i++)
            a1[i] = i;
        ans = "";
        do
        {
            for(int i = 0 ; i<N;i++)
                a2[i] = i;
            bool fail = false;
            do{
                int p1 = 0 , p2 = 0;
                while(p1 < N && p2 < N){
                    if(lose(a1[p1] ,a2[p2]))
                        p1++;
                    else p2++;
                }
                if(p1 == N) {fail = true;break;}
            }while(next_permutation(a2,a2+N));
            if(fail == false){
                tans = "";
                tans += name[a1[0]];
                for(int i = 1 ; i <N;i++)
                    {
                        tans += " ";
                        tans += name[a1[i]];
                    }
                if(ans == "" || tans < ans)
                    ans = tans;
            }
        }
        while(next_permutation(a1,a1+N));
        printf("Case %d: ",ii);
        if(ans == ""){
            puts("No");
        }else{
            puts("Yes");
            printf("%s\n",ans.c_str());
        }
    }
    return 0;
}

