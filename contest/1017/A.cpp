#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[200];
char words[1000][200][100];
int totwords[1000];
int wordslen[1000][200];
int buflen,lineid,wordid,maxcol,wid[1000];

int main()
{
    lineid = maxcol = 0;
    while (gets(buf))
    {
        buflen = strlen(buf);
        totwords[lineid] = 0;
        for (int i = 0; i < buflen;)
            if (buf[i] != 32)
            {
                wordid = totwords[lineid];
                sscanf(buf+i,"%s",words[lineid][wordid]);
                wordslen[lineid][wordid] = strlen(words[lineid][wordid]);
                totwords[lineid]++;
                i += wordslen[lineid][wordid];
            }
            else
                i++;
        maxcol = max(maxcol,totwords[lineid]);
        lineid++;
    }
    for (int i = 0; i < maxcol; i++)
    {
        for (int j = 0; j < lineid; j++)
            if (totwords[j] > i)
                wid[i] = max(wid[i],wordslen[j][i]);
        wid[i]++;
    }
    for (int i = 0; i < lineid; i++)
        for (int j = 0; j < totwords[i]; j++)
        {
            if (j+1 < totwords[i])
                printf("%-*s",wid[j],words[i][j]);
            if (j+1 == totwords[i])
            {
                puts(words[i][j]);
                break;
            }
        }
    return 0;
}
