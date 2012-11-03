#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Trie
{
    Trie *nxt[26];
    int inf;
}tr;
struct information
{
    int la;//0 Chinese;1 Englist;2 Japanese;3 German;
    int typ;//0 pn;1 n;2 vi;3 vt;4 adj;
    int next;
}I[50];
Trie buf[150000];
int bufCt;
int totinf;

void init()
{
    bufCt = 0;
    memset(buf,0,sizeof(buf));
}

void insert(Trie *Tr,char *wd,int ia,int ib)
{
    if (*wd == 0)
    {
        totinf++;
        I[totinf].la = ia;
        I[totinf].typ = ib;
        I[totinf].next = Tr->inf;
        Tr->inf = totinf;
    }
    else
    {
        int p = *wd-'a';
        if (!Tr->nxt[p])
        {
            Tr->nxt[p] = &buf[bufCt++];
            Tr->inf = 0;
        }
        insert(Tr->nxt[p],wd+1,ia,ib);
    }
}

bool find(Trie *Tr,char *wd,int ia,int ib)
{
    if (*wd == 0)
    {
        for (int i = Tr->inf;i != 0;i = I[i].next)
        {
            if (I[i].la == ia)
                if (I[i].typ == ib)
                    return true;
        }
        return false;
    }
    else
    {
        int p = *wd-'a';
        if (!Tr->nxt[p])    return false;
        return find(Tr->nxt[p],wd+1,ia,ib);
    }
}

void solve(char *s)
{
    int l = strlen(s);
    char words[20][50];
    int cntw,ptrn;
    cntw = ptrn = 0;
    for (int i = 0;i < l;i++)
    {
        if (s[i] == ' ')
        {
            if (i > 0)
                if (s[i-1] != ' ')
                {
                    words[cntw][ptrn] = '\0';
                    cntw++;
                    ptrn = 0;
                }
        }
        else
        {
            words[cntw][ptrn] = s[i];
            ptrn++;
        }
    }
    words[cntw][ptrn] = '\0';
    cntw++;
    ptrn = 0;
    //for (int i = 0;i < cntw;i++)
    //    cout << '|' << words[i] << '|' << endl;
    if (cntw == 3)
    if (strlen(words[1]) == 3)
    if (words[1][0] == 's' && words[1][1] == 'h' && words[1][2] == 'i')
    if (find(&tr,words[0],0,0))
    if (find(&tr,words[2],0,1))
    {
        printf("Chinese\n");
        return;
    }
    if (cntw == 2)
    if (find(&tr,words[0],0,0))
    if (find(&tr,words[1],0,2))
    {
        printf("Chinese\n");
        return;
    }
    if (cntw == 3)
    if (find(&tr,words[0],0,0))
    if (find(&tr,words[1],0,3))
    if (find(&tr,words[2],0,1))
    {
        printf("Chinese\n");
        return;
    }
    if (cntw == 2)
    if (strlen(words[0]) == 2)
    if (words[0][0] == 'n')
    if (words[0][1] == 'i')
    if (strlen(words[1]) == 3)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (words[1][2] == 'o')
    {
        printf("Chinese\n");
        return;
    }
    if (cntw == 2)
    if (find(&tr,words[0],1,0))
    if (find(&tr,words[1],1,2))
    {
        printf("English\n");
        return;
    }
    if (cntw == 3)
    if (find(&tr,words[0],1,0))
    if (find(&tr,words[1],1,3))
    if (find(&tr,words[2],1,1))
    {
        printf("English\n");
        return;
    }
    if (cntw == 4)
    if (strlen(words[0]) == 5)
    if (words[0][0] == 't')
    if (words[0][1] == 'h')
    if (words[0][2] == 'e')
    if (words[0][3] == 'r')
    if (words[0][4] == 'e')
    if (strlen(words[1]) == 2)
    if (words[1][0] == 'i')
    if (words[1][1] == 's')
    if (strlen(words[2]) == 1)
    if (words[2][0] == 'a')
    if (find(&tr,words[3],1,1))
    {
        printf("English\n");
        return;
    }
    if (cntw == 3)
    if (strlen(words[0]) == 5)
    if (words[0][0] == 'h')
    if (words[0][1] == 'a')
    if (words[0][2] == 'p')
    if (words[0][3] == 'p')
    if (words[0][4] == 'y')
    if (strlen(words[1]) == 3)
    if (words[1][0] == 'n')
    if (words[1][1] == 'e')
    if (words[1][2] == 'w')
    if (strlen(words[2]) == 4)
    if (words[2][0] == 'y')
    if (words[2][1] == 'e')
    if (words[2][2] == 'a')
    if (words[2][3] == 'r')
    {
        printf("English\n");
        return;
    }
    if (cntw == 4)
    if (strlen(words[1]) == 2)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (strlen(words[3]) == 4)
    if (words[3][0] == 'd')
    if (words[3][1] == 'e')
    if (words[3][2] == 's')
    if (words[3][3] == 'u')
    if (find(&tr,words[0],2,0))
    if (find(&tr,words[2],2,1))
    {
        printf("Japanese\n");
        return;
    }
    if (cntw == 4)
    if (strlen(words[1]) == 2)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (strlen(words[3]) == 2)
    if (words[3][0] == 'd')
    if (words[3][1] == 'a')
    if (find(&tr,words[0],2,0))
    if (find(&tr,words[2],2,1))
    {
        printf("Japanese\n");
        return;
    }
    if (cntw == 5)
    if (strlen(words[1]) == 2)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (strlen(words[3]) == 2)
    if (words[3][0] == 'g')
    if (words[3][1] == 'a')
    if (find(&tr,words[0],2,0))
    if (find(&tr,words[2],2,1))
    if (find(&tr,words[4],2,4))
    {
        printf("Japanese\n");
        return;
    }
    if (cntw == 2)
    if (strlen(words[1]) == 6)
    if (words[1][0] == 's')
    if (words[1][1] == 'a')
    if (words[1][2] == 'i')
    if (words[1][3] == 'k')
    if (words[1][4] == 'o')
    if (words[1][5] == 'u')
    if (find(&tr,words[0],2,1))
    {
        printf("Japanese\n");
        return;
    }
    if (cntw == 2)
    if (strlen(words[0]) == 3)
    if (words[0][0] == 'y')
    if (words[0][1] == 'o')
    if (words[0][2] == 'i')
    if (strlen(words[1]) == 8)
    if (words[1][0] == 'o')
    if (words[1][1] == 't')
    if (words[1][2] == 'o')
    if (words[1][3] == 's')
    if (words[1][4] == 'h')
    if (words[1][5] == 'i')
    if (words[1][6] == 'w')
    if (words[1][7] == 'o')
    {
        printf("Japanese\n");
        return;
    }
    if (cntw == 4)
    if (strlen(words[0]) == 3)
    if (words[0][0] == 'i')
    if (words[0][1] == 'c')
    if (words[0][2] == 'h')
    if (strlen(words[1]) == 4)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (words[1][2] == 'b')
    if (words[1][3] == 'e')
    if (strlen(words[2]) == 3)
    if (words[2][0] == 'e')
    if (words[2][1] == 'i')
    if (words[2][2] == 'n')
    if (find(&tr,words[3],3,1))
    {
        printf("German\n");
        return;
    }
    if (cntw == 3)
    if (strlen(words[0]) == 3)
    if (words[0][0] == 'i')
    if (words[0][1] == 'c')
    if (words[0][2] == 'h')
    if (strlen(words[1]) == 3)
    if (words[1][0] == 'b')
    if (words[1][1] == 'i')
    if (words[1][2] == 'n')
    if (find(&tr,words[2],3,1))
    {
        printf("German\n");
        return;
    }
    if (cntw == 3)
    if (strlen(words[0]) == 3)
    if (words[0][0] == 'i')
    if (words[0][1] == 'c')
    if (words[0][2] == 'h')
    if (strlen(words[1]) == 6)
    if (words[1][0] == 'h')
    if (words[1][1] == 'e')
    if (words[1][2] == 'i')
    if (words[1][3] == 's')
    if (words[1][4] == 's')
    if (words[1][5] == 'e')
    if (find(&tr,words[2],3,1))
    {
        printf("German\n");
        return;
    }
    if (cntw == 3)
    if (strlen(words[0]) == 2)
    if (words[0][0] == 'd')
    if (words[0][1] == 'u')
    if (strlen(words[1]) == 4)
    if (words[1][0] == 'h')
    if (words[1][1] == 'a')
    if (words[1][2] == 's')
    if (words[1][3] == 't')
    if (find(&tr,words[2],3,1))
    {
        printf("German\n");
        return;
    }
    printf("I don't know.\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int tn,tm;
        for (int i = 0;i < 26;i++)
            tr.nxt[i] = NULL;
        tr.inf = 0;
        totinf = 0;
        init();
        scanf("%d%d",&tn,&tm);
        char s1[20],s2[20],s3[20];
        for (int i = 1;i <= tn;i++)
        {
            scanf("%s%s%s",&s1,&s2,&s3);
            int ta,tb;
            if (s1[0] == 'C')   ta = 0;
            if (s1[0] == 'E')   ta = 1;
            if (s1[0] == 'J')   ta = 2;
            if (s1[0] == 'G')   ta = 3;
            if (s2[1] == 'p')   tb = 0;
            if (s2[1] == 'n')   tb = 1;
            if (s2[1] == 'v')
                if (s2[2] == 'i')   tb = 2;
                else                tb = 3;
            if (s2[1] == 'a')   tb = 4;
            //cout << "insert " << ' ' << s3 << ' ' << ta << ' ' << tb << endl;
            //cout << find(&tr,s3,ta,tb) << ' ' << true << endl;
            for (int j = 0;j < strlen(s3);j++)
            if (('A' <= s3[j]) && (s3[j] <= 'Z'))
                s3[j] = s3[j]-'A'+'a';
            insert(&tr,s3,ta,tb);
            //cout << find(&tr,s3,ta,tb) << endl;
        }
        char s[50];
        printf("Case #%d:\n",ft);
        gets(s);
        for (int i = 1;i <= tm;i++)
        {
            gets(s);
            for (int j = 0;j < strlen(s);j++)
            if (('A' <= s[j]) && (s[j] <= 'Z'))
                s[j] = s[j]-'A'+'a';
            solve(s);
        }
    }
}
