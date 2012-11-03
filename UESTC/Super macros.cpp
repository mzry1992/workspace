#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int LineWidth = 300;
const int MaxCom = 1000;

char tmp[LineWidth];
char com[MaxCom][LineWidth];
char output[MaxCom][LineWidth];
int deep[MaxCom];
int totcom,tmplen,tmppre,curid,outline,maxlen,needtab;

int getid(int l,int &la,int &ra)
{
    int tot = 0;
    if (com[l][0] != '(')
    {
        //a
        //? or :
        la = ra = l;
        return l+2;
    }
    else
    {
        //(
        //a
        //)
        //? or :
        tot = 1;
        la = l+1;
        for (int i = l+1;; i++)
        {
            if (com[i][0] == '(')   tot++;
            else if (com[i][0] == ')')  tot--;
            if (tot == 0)
            {
                ra = i-1;
                return i+2;
            }
        }
    }
}

//草泥马的条件表达式树？
struct tree
{
    int lt,rt,id;
};
tree buf[10000];
int totbuf,root;
bool intree[10000];

void getintree(int root)
{
    intree[root] = true;
    if (buf[root].lt == -1)
        return;
    getintree(buf[root].lt);
    getintree(buf[root].rt);
}

void Connect(int root,int ift,int iff)
{
    if (intree[root] == false)  return;
    if (buf[root].lt == -1)
    {
        buf[root].lt = ift;
        buf[root].rt = iff;
        return;
    }
    Connect(buf[root].lt,ift,iff);
    Connect(buf[root].rt,ift,iff);
}

int Gao(int l,int r)
{
    int la,ra,lb,rb,lc,rc,roota,rootb,rootc;
    int tl = l;
    l = getid(l,la,ra);
    if (l > r)
    {
        //(a)
        if (la < ra)
            return Gao(la,ra);
        else
        {
            totbuf++;
            buf[totbuf].lt = buf[totbuf].rt = -1;
            buf[totbuf].id = la;
            return totbuf;
        }
    }
    else
    {
        l = getid(l,lb,rb);
        l = getid(l,lc,rc);
        //a?b:c
        roota = Gao(la,ra);
        rootb = Gao(lb,rb);
        rootc = Gao(lc,rc);

        memset(intree,false,totbuf+1);
        getintree(roota);
        Connect(roota,rootb,rootc);
        return roota;
    }
}

void Make(int root,int deepnow)
{
    if (buf[root].lt == -1)
    {
        deep[outline] = deepnow;
        sprintf(output[outline++],"_r = %s;",com[buf[root].id]);
    }
    else
    {
        //if (a)		\
        //	_r = b;		\
        //else			\
        //	_r = c;
        deep[outline] = deepnow;
        sprintf(output[outline++],"if (%s)",com[buf[root].id]);
        if (buf[buf[root].lt].lt == -1)
            Make(buf[root].lt,deepnow+1);
        else
        {
            deep[outline] = deepnow;
            sprintf(output[outline++],"{");

            Make(buf[root].lt,deepnow+1);

            deep[outline] = deepnow;
            sprintf(output[outline++],"}");
        }
        deep[outline] = deepnow;
        sprintf(output[outline++],"else");

        if (buf[buf[root].rt].lt == -1)
            Make(buf[root].rt,deepnow+1);
        else
        {
            deep[outline] = deepnow;
            sprintf(output[outline++],"{");

            Make(buf[root].rt,deepnow+1);

            deep[outline] = deepnow;
            sprintf(output[outline++],"}");
        }
    }
}

int main()
{
    puts("#ifndef MACROS_H");
    puts("#define MACROS_H");
    puts("");
    totcom = 0;
    while (scanf("%s",tmp) != EOF)
    {
        tmplen = strlen(tmp);
        tmppre = 0;
        for (int i = 0; i <= tmplen; i++)
        {
            //: ( ) ?
            //变量
            if (i == tmplen || tmp[i] == '?' || tmp[i] == ':' || tmp[i] == ';' || tmp[i] == '(' || tmp[i] == ')')
            {
                if (tmppre < i)
                {
                    for (int j = tmppre; j < i; j++)
                        com[totcom][j-tmppre] = tmp[j];
                    com[totcom++][i-tmppre] = 0;
                }
                if (i < tmplen)
                {
                    com[totcom][0] = tmp[i];
                    com[totcom++][1] = 0;
                }
                tmppre = i+1;
            }
        }
    }

    curid = 0;
    tmppre = 0;
    for (int i = 0; i < totcom; i++)
        if (com[i][0] == ';')
        {
            totbuf = 0;
            root = Gao(tmppre,i-1);

            outline = 0;

            deep[outline] = 0;
            sprintf(output[outline++],"#define SuperHacker_function%d()",curid);
            deep[outline] = 1;
            sprintf(output[outline++],"int _r;");

            //遍历表达式树
            Make(root,1);

            deep[outline] = 1;
            sprintf(output[outline++],"_r;");
            //out
            maxlen = 0;
            for (int j = 0; j < outline; j++)
                maxlen = max(maxlen,deep[j]*8+(int)strlen(output[j]));
            maxlen++;
            while (maxlen%8 != 0)   maxlen++;
            for (int j = 0; j < outline; j++)
            {
                if (j == 1)
                    printf("({");
                for (int k = 0; k < deep[j]; k++)
                    printf("\t");
                printf("%s",output[j]);
                tmplen = deep[j]*8+strlen(output[j]);
                needtab = 1;
                tmplen++;
                while (tmplen%8 != 0)   tmplen++;
                needtab += (maxlen-tmplen)/8;
                for (int k = 0; k < needtab; k++)
                    printf("\t");
                if (j == outline-1)
                    printf("})\n");
                else
                    printf("\\\n");
            }
            printf("\n");
            tmppre = i+1;
            curid++;
        }
    puts("#endif /* MACROS_H */");
    return 0;
}
