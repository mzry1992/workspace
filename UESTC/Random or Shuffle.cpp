#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n;
string s;
map<string,int> M;
map<string,int>::iterator it;
int a[110000],tree[880000];
int list[110000];

void update(int n,int l,int r,int x)
{
    //cout<<n<<" "<<l<<" "<<r<<endl;
    if (l==r)
    {
        tree[n]++;
        return ;
    }
    if (x<=(l+r)/2) update(n*2,l,(l+r)/2,x);
        else update(n*2+1,(l+r)/2+1,r,x);
    tree[n]=min(tree[n*2],tree[n*2+1]);
    return ;
}
int main()
{
    freopen("Random or Shuffle.in","r",stdin);
    freopen("Random or Shuffle.out1","w",stdout);
    while (scanf("%d\n",&n) != EOF)
    {
        memset(tree,0,sizeof(tree));
        memset(a,0,sizeof(a));
        M.clear();
        int cnt = 0;
        for (int i = 1;i <= n;i++)
        {
            getline(cin,s);
            it = M.find(s);
            if (it == M.end())
            {
                cnt++;
                M[s] = cnt;
                list[i] = cnt;
            }
            else
                list[i] = it->second;
        }

        bool flag = true;
        for (int i = 1;i <= n;i++)
        {
            if (flag == false)
                continue;
            int aa = list[i];
            //cout<<tree[1]<<endl;
            if (tree[1]<a[aa])
            {
                flag=false;
            }
            else
            {
                update(1,1,cnt,aa);
                a[aa]++;
            }

        }
        if (flag == true)
            printf("Either\n");
        else
            printf("Random\n");
    }
}
