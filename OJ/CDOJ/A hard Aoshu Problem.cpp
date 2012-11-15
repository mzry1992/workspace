#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s1[20],s2[20],s3[20];
int l1,l2,l3,res,val[26];

void Gao(int part,int pos,int used)
{
    if (part == 0)
    {
        if (pos == l1)
        {
            Gao(part+1,0,used);
            return;
        }
        if (val[s1[pos]-'A'] != -1)
        {
            if (l1 > 1 && pos == 0 && val[s1[pos]-'A'] == 0)    return;
            Gao(part,pos+1,used);
        }
        else
        {
            for (int i = 0;i < 10;i++)
                if (((used>>i)&1) == 0)
                {
                    if (l1 > 1 && pos == 0 && i == 0)   continue;
                    val[s1[pos]-'A'] = i;
                    Gao(part,pos+1,used|(1<<i));
                    val[s1[pos]-'A'] = -1;
                }
        }
    }
    else if (part == 1)
    {
        if (pos == l2)
        {
            Gao(part+1,0,used);
            return;
        }
        if (val[s2[pos]-'A'] != -1)
        {
            if (l2 > 1 && pos == 0 && val[s2[pos]-'A'] == 0)    return;
            Gao(part,pos+1,used);
        }
        else
        {
            for (int i = 0;i < 10;i++)
                if (((used>>i)&1) == 0)
                {
                    if (l2 > 1 && pos == 0 && i == 0)   continue;
                    val[s2[pos]-'A'] = i;
                    Gao(part,pos+1,used|(1<<i));
                    val[s2[pos]-'A'] = -1;
                }
        }
    }
    else if (part == 2)
    {
        if (pos == l3)
        {
            long long a,b,c;
            a = b = c = 0;
            for (int i = 0;i < l1;i++)
                a = a*10+val[s1[i]-'A'];
            for (int i = 0;i < l2;i++)
                b = b*10+val[s2[i]-'A'];
            for (int i = 0;i < l3;i++)
                c = c*10+val[s3[i]-'A'];
            if (a+b == c)   res++;
            if (a-b == c)   res++;
            if (a*b == c)   res++;
            if (b != 0 && a == b*c)   res++;
            return;
        }
        if (val[s3[pos]-'A'] != -1)
        {
            if (l3 > 1 && pos == 0 && val[s3[pos]-'A'] == 0)    return;
            Gao(part,pos+1,used);
        }
        else
        {
            for (int i = 0;i < 10;i++)
                if (((used>>i)&1) == 0)
                {
                    if (l3 > 1 && pos == 0 && i == 0)   continue;
                    val[s3[pos]-'A'] = i;
                    Gao(part,pos+1,used|(1<<i));
                    val[s3[pos]-'A'] = -1;
                }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s%s%s",s1,s2,s3);
        l1 = strlen(s1);
        l2 = strlen(s2);
        l3 = strlen(s3);
        res = 0;
        memset(val,-1,sizeof(val));
        Gao(0,0,0);
        printf("%d\n",res);
    }
    return 0;
}
