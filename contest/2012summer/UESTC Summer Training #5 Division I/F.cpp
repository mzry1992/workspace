#include <stdio.h>
#include <string.h>

const int maxn=40010;

int ne[maxn][2];
struct edge
{
    int to,next;
} e[maxn*10];
int cnt,box[maxn];
char s[maxn];
int len;
bool ansflag;

void add(int u,int v)
{
    if (u>len||v==-1) return ;
    e[cnt].to=v;
    e[cnt].next=box[u];
    box[u]=cnt++;
}

int main()
{
    int cas,n;
    int T=0;

    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d %d",&ne[i][0],&ne[i][1]);
        scanf("%s",s);
        ansflag=0;
        cnt=0;
        memset(box,-1,sizeof(box));
        len=strlen(s);
        add(0,1);
        for(int i=0; i<len; i++)
            if (s[i]=='L') s[i]=0;
            else s[i]=1;
        s[len]=1;

        for(int i=0; i<len; i++)
        {
            int j=i;
            while(j<len&&s[j]==s[i]) j++;
            int nowlen=(j-i);
            int mins=(nowlen+1)/2;
            if (nowlen==1)
            {
                for(int p=box[i]; p!=-1; p=e[p].next)
                {
                    int now=e[p].to;
                    add(i+1,ne[now][s[i]]);
                    add(i+2,ne[now][s[i+1]]);
                }
            }
            else
                for(int p=box[i]; p!=-1; p=e[p].next)
                {
                    int now=e[p].to;
                    int haha=-1;
                    for(int k=1; k<=nowlen; k++)
                    {
                        now=ne[now][s[i]];
                        if (now==-1) break;
                        if (k>=mins) add(j,now);
                        if (k==mins-1) haha=now;
                        if (j==len)
                            if (nowlen&1)
                                if (k>=mins-1) ansflag=1;
                    }
                    if (j < len && (nowlen&1)&&haha!=-1)
                        add(j+1,ne[haha][s[j]]);
                }
            /*printf("pos = %d\n",i);
            for (int p = box[i]; p != -1; p = e[p].next)
            {
                printf("%d ",e[p].to);
            }
            printf("\n");*/
        }
        T++;
        printf("Case %d: ",T);
        if (ansflag || box[len-1] != -1 || box[len] != -1) puts("Yes");
        else puts("No");

    }
}
