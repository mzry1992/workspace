#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<string> st,mp;
string s[10100];
char str[120];

int main(){
    bool done;
    int n,m;

    freopen("Random or Shuffle.in","r",stdin);
    freopen("Random or Shuffle.out2","w",stdout);
    while(~scanf("%d",&n)){
        gets(str);
        st.clear();
        for(int i=0;i<n;i++){
            gets(str);
            s[i]=str;
            st.insert(s[i]);
        }
        m=st.size();
        done=false;
        for(int i=0;i<n;i+=m){
            mp.clear();
            for(int j=0;j<m&&i+j<n;j++){
                if(mp.find(s[i+j])!=mp.end()){
                    done=true;
                    break;
                }
                mp.insert(s[i+j]);
            }
            if(done){
                break;
            }
        }

        if(done){
            puts("Random");
        }else{
            puts("Either");
        }
    }

    return 0;
}
