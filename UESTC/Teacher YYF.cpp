#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct tire
{
    int next[26];
    //"n.", "pron.", "adj.", "adv.", "prep.", "art.", "vt." and "vi." + "v."
    // 1     2        3       4       5        6       7         8       9
    int key;
}t[120000];
int tott;
int n,m;
char word[50],wkey[50];
char s[50];

int getkey(char key[])
{
    if (key[0] == 'n')  return 1;
    if (key[0] == 'p')
        if (key[2] == 'o')  return 2;
        else    return 5;
    if (key[0] == 'a')
        if (key[2] == 'j')  return 3;
        else if (key[2] == 'v') return 4;
        else    return 6;
    if (key[1] == 't')
        return 7;
    else if (key[1] == 'i')
        return 8;
    else    return 9;
}

int find(char word[])
{
    int now = 0;
    for (int i = 0;i < strlen(word);i++)
    {
        int pos = word[i]-'a';
        now = t[now].next[pos];
    }
    return t[now].key;
}

void insert(char word[],int key)
{
    int now = 0;
    for (int i = 0;i < strlen(word);i++)
    {
        int pos = (word[i] >= 'a')?(word[i]-'a'):(word[i]-'A');
        if (t[now].next[pos] == -1)
        {
            tott++;
            for (int i = 0;i < 26;i++)
                t[tott].next[i] = -1;
            t[tott].key = 0;
            t[now].next[pos] = tott;
        }
        now = t[now].next[pos];
    }
    t[now].key = key;
}

int wtype[50];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        tott = 0;
        for (int i = 0;i < 26;i++)
            t[tott].next[i] = -1;
        t[tott].key = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%s",word,wkey);
            insert(word,getkey(wkey));
        }
        gets(s);
        for (int i = 1;i <= m;i++)
        {
            gets(s);
            for (int j = 0;j < strlen(s);j++)
            {
                if (s[j] >= 'a' && s[j] <= 'z')
                    continue;
                if (s[j] >= 'A' && s[j] <= 'Z')
                    s[j] = s[j]-'A'+'a';
                else s[j] = ' ';
            }
            int tl = strlen(s);
            s[tl] = ' ';
            s[tl+1] = 0;
            int totword = 0;
            int l,r;
            l = 0;
            char ts[50];
            int len;
            while (true)
            {
                if (s[l] != ' ')
                {
                    int r = l;
                    len = 0;
                    while (s[r] != ' ')
                    {
                        ts[len] = s[r];
                        len++;
                        r++;
                    }
                    ts[len] = 0;
                    totword++;
                    wtype[totword] = find(ts);
                    l = r;
                }
                l++;
                if (l == strlen(s)) break;
            }
            bool flag=true,sub=false,obj=false;
            for (int i=1;i<=totword;i++)
            {
                if (wtype[i]==5)
                {
                    if (wtype[i+1]==6 || wtype[i+2]==1)
                    {
                        for (int j=i+3;j<=totword;j++)
                            wtype[j-3]=wtype[j];
                        totword-=3;
                    }
                    else
                    {
                        flag=false;break;
                    }
                }
            }
            if (!flag)
            {
                puts("NO");continue;
            }
            for (int i=1;i<=totword;i++)
            {
                if (wtype[i]==4)
                {
                    if (wtype[i+1]>=7)
                    {
                        for (int j=i+1;j<=totword;j++)
                            wtype[j-1]=wtype[j];
                        totword--;
                    }
                    else
                    {
                        flag=false;break;
                    }
                }
            }
            if (!flag)
            {
                puts("NO");continue;
            }
            for (int i=1;i<=totword;i++)
            {
                if (wtype[i]==1)
                {
                    if (wtype[i-1]==6)
                    {
                        wtype[i]=2;
                        for (int j=i;j<=totword;j++)
                            wtype[j-1]=wtype[j];
                        totword--;
                    }
                    else if (wtype[i-1]==3 && wtype[i-2]==6)
                    {
                        wtype[i]=2;
                        for (int j=i;j<=totword;j++)
                            wtype[j-2]=wtype[j];
                        totword-=2;
                    }
                    else
                    {
                        flag=false;break;
                    }
                }
            }
            if (!flag)
            {
                puts("NO");continue;
            }
            if (totword==2)
            {
                if (wtype[1]==2 && (wtype[2]==8 || wtype[2]==9))
                {
                    puts("YES");continue;
                }
                else puts("NO");
            }
            else if (totword==3)
            {
                if (wtype[1]==2 && wtype[3]==2 && (wtype[2]==7 || wtype[2]==9))
                {
                    puts("YES");continue;
                }
                else puts("NO");
            }
            else puts("NO");
        }
    }
}
