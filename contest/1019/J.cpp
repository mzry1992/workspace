#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
char pass[500010];
char org[500010];
int apr_pass[256];

int time_pass[500010];

int apr_org[256];

int time_org[500010];
vector<int> ans;

int main(){
    while(gets(pass)){
        ans.clear();
        memset(apr_pass , 0 ,sizeof(apr_pass));
        memset(apr_org , 0 , sizeof(apr_org));
        gets(org);
        int len_pass = strlen(pass);
        int len_org = strlen(org);
        for(int  i = 0 ; i <len_pass;i++)
            {
                if(i < len_org)
                    apr_pass[pass[i]]++;
                time_pass[i] = 0;
                time_org[i] = 0;
            }
        for(int i = 0 ;i < len_org; i++)
            {
                apr_org[org[i]] ++;
                //time_org[i] = 0;
            }
        for(int i = 33; i<=126;i++){
            time_org[apr_org[i]]++;
            time_pass[apr_pass[i]]++;
        }
        int diff = 0;
        for(int i =0 ; i <= len_org ;i++)
            diff += abs(time_org[i] - time_pass[i]);

        if(diff == 0)
            ans.push_back(0);
        for(int i = 1 ;i < len_pass-len_org+1;i++){
            //pass[i-1]少一个
            int pre = apr_pass[pass[i-1]]--;
            diff -= abs(time_org[pre] - time_pass[pre]);
            time_pass[pre]--;
            diff += abs(time_org[pre] - time_pass[pre]);

            pre = apr_pass[pass[i-1]];
            diff -= abs(time_org[pre] - time_pass[pre]);
            time_pass[pre]++;
            diff += abs(time_org[pre] - time_pass[pre]);

            //pass[i+len-1]多1个
            pre = apr_pass[pass[i+len_org-1]]++;
            diff -= abs(time_org[pre] - time_pass[pre]);
            time_pass[pre]--;
            diff += abs(time_org[pre] - time_pass[pre]);

            pre = apr_pass[pass[i+len_org-1]];
            diff -= abs(time_org[pre] - time_pass[pre]);
            time_pass[pre]++;
            diff += abs(time_org[pre] - time_pass[pre]);

            if(diff == 0)
                ans.push_back(i);
        }
        if(ans.size() == 0){
            puts("No");
        }else{
            puts("Yes");
            printf("%d",ans[0]);
            for(int i = 1 ;i < ans.size();i++)
                printf(" %d",ans[i]);
            puts("");
        }
    }
    return 0;
}
