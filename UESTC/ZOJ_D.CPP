#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char tab[70][7]={"000000","000001","000010","000011","000100","000101","000110","000111","001000","001001","001010","001011","001100","001101","001110","001111","010000","010001","010010","010011","010100","010101","010110","010111","011000","011001","011010","011011","011100","011101","011110","011111","100000","100001","100010","100011","100100","100101","100110","100111","101000","101001","101010","101011","101100","101101","101110","101111","110000","110001","110010","110011","110100","110101","110110","110111","111000","111001","111010","111011","111100","111101","111110","111111"};

struct node
{
    int mark;
    node *next[256],*fail;
    node()
    {
        fail=NULL;
        mark=0;
        memset(next,NULL,sizeof(next));
    }
}*q[50005];

char st[1000010];
void insert(char st[],node *root)
{
    int i=0;
    node *tmp=root;
    while (st[i])
    {
        if (tmp->next[st[i]]==NULL)
            tmp->next[st[i]]=new node();
        tmp=tmp->next[st[i]];
        i++;
    }
    tmp->mark++;
}

void build_AC_automation(node *root)
{
    int head=0,tail=1;
    root->fail=NULL;
    q[head]=root;
    while (head<tail)
    {
        node *tmp=q[head];
        node *p=NULL;
        head++;
        for (int i=0;i<256;i++)
        {
            if (tmp->next[i]!=NULL)
            {
                if (tmp==root) tmp->next[i]->fail=root;
                else
                {
                    p=tmp->fail;
                    while (p!=NULL)
                    {
                        if (p->next[i]!=NULL)
                        {
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if (p==NULL) tmp->next[i]->fail=root;
                }
                q[tail++]=tmp->next[i];
            }
        }
    }
}

int query(char st[],node *root)
{
    int i=0,ans=0;
    node *p=root;
    while (st[i])
    {
        while (p->next[st[i]]==NULL && p!=root) p=p->fail;
        p=p->next[st[i]];
        if (p==NULL) p=root;
        node *tmp=p;
        while (tmp!=root && tmp->mark!=-1)
        {
            ans+=tmp->mark;
            tmp->mark=-1;
            tmp=tmp->fail;
        }
        i++;
    }
    return ans;
}


int main()
{
    int n;
    while (scanf("%d",&n)>0)
    {
        char s[20000],t[20000];
        node *root=new node();
        char tmp[20000];
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            memset(tmp,0,sizeof(tmp));
            for (int j=0;j<len;j++)
            {
                char ch=s[j];
                int di;
                if (ch>='A' && ch<='Z') di=ch-'A';
                else if (ch>='a' && ch<='z') di=ch-'a'+26;
                else if (ch>='0' && ch<='9') di=ch-'0'+52;
                else if (ch=='+') di=62;
                else if (ch=='/') di=63;
                else break;
                strcat(tmp,tab[di]);
            }
            int equal=0;
            for (int j=len-1;j>=0;j--)
            {
                if (s[j]=='=') equal++;
                else break;
            }
            //puts(tmp);
            //printf("%d\n",strlen(tmp));
            int poi=0;
            int lent=strlen(tmp);
            int cntt=lent/24;
            int now=0,key;
            for (int j=0;j<cntt;j++)
            {
                for (int k=1;k<=3;k++)
                {
                    key=0;
                    for (int l=now;l<now+8;l++)
                        key=key*2+tmp[l]-'0';
                    now+=8;
                    t[poi++]=key;
                }
            }
            int q=3-equal;
            //printf("%d\n",q);
            if (q==1 || q==2)
            {
                now=cntt*24;
                for (int j=0;j<q;j++)
                {
                    for (int l=now;l<now+8;l++)
                        key=key*2+tmp[l]-'0';
                    now+=8;
                    t[poi++]=key;
                }
            }
            t[poi]=0;
            insert(t,root);
        }
        build_AC_automation(root);
        int querycnt;
        scanf("%d",&querycnt);
        for (int i=0;i<querycnt;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            memset(tmp,0,sizeof(tmp));
            for (int j=0;j<len;j++)
            {
                char ch=s[j];
                int di;
                if (ch>='A' && ch<='Z') di=ch-'A';
                else if (ch>='a' && ch<='z') di=ch-'a'+26;
                else if (ch>='0' && ch<='9') di=ch-'0'+52;
                else if (ch=='+') di=62;
                else if (ch=='/') di=63;
                else break;
                strcat(tmp,tab[di]);
            }
            int equal=0;
            for (int j=len-1;j>=0;j--)
            {
                if (s[j]=='=') equal++;
                else break;
            }
            //puts(tmp);
            //printf("%d\n",strlen(tmp));
            int poi=0;
            int lent=strlen(tmp);
            int cntt=lent/24;
            int now=0,key;
            for (int j=0;j<cntt;j++)
            {
                for (int k=1;k<=3;k++)
                {
                    key=0;
                    for (int l=now;l<now+8;l++)
                        key=key*2+tmp[l]-'0';
                    now+=8;
                    t[poi++]=key;
                }
            }
            int q=3-equal;
            //printf("%d\n",q);
            if (q==1 || q==2)
            {
                now=cntt*24;
                for (int j=0;j<q;j++)
                {
                    for (int l=now;l<now+8;l++)
                        key=key*2+tmp[l]-'0';
                    now+=8;
                    t[poi++]=key;
                }
            }
            t[poi]=0;
            //puts("");
            //printf("%s###\n",t);
            printf("%d\n",query(t,root));
        }
        puts("");
    }
}
