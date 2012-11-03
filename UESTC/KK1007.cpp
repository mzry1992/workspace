#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int du[110];
bool mrk[110];
bool map[110][110];
int main()
{
    int n,m,a,b;
    int cas=0;
    while (scanf("%d%d%d%d",&n,&m,&a,&b)>0,n||m||a||b)
    {
        memset(map,false,sizeof(map));
        memset(du,0,sizeof(du));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            du[x]++;du[y]++;
            map[x][y]=map[y][x]=true;
        }
        int size=n;
        memset(mrk,false,sizeof(mrk));
        while (true)
        {
            int pos=-1;
            for (int i=0;i<n;i++)
            {
                if (!mrk[i] && (du[i]<a || du[i]>size-1-b))
                {
                    pos=i;mrk[i]=true;size--;break;
                }
            }
            if (pos==-1) break;
            for (int i=0;i<n;i++)
            {
                if (map[i][pos])
                {
                    map[i][pos]=false;du[i]--;
                }
            }
        }
        printf("Case #%d: %d\n",++cas,size);
    }
}
