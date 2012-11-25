#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char language[50][50],catalog[50][50],word[50][50];
char buf[200],words[50][50];
int cnt;

bool check(char a[],char b[],char c[])
{
    for (int i = 0; i < n; i++)
        if (strcmp(language[i],a) == 0 &&
                strcmp(catalog[i],b) == 0 &&
                strcmp(word[i],c) == 0)
            return true;
    return false;
}

void check()
{
    if (cnt == 3 &&
            check("Chinese","[pn]",words[0]) &&
            strcmp("shi",words[1]) == 0 &&
            check("Chinese","[n]",words[2]))
        puts("Chinese");
    else if (cnt == 2 &&
             check("Chinese","[pn]",words[0]) &&
             check("Chinese","[vi]",words[1]))
        puts("Chinese");
    else if (cnt == 3 &&
             check("Chinese","[pn]",words[0]) &&
             check("Chinese","[vt]",words[1]) &&
             check("Chinese","[n]",words[2]))
        puts("Chinese");
    else if (cnt == 2 &&
             strcmp("ni",words[0]) == 0 &&
             strcmp("hao",words[1]) == 0)
        puts("Chinese");
    else if (cnt == 2 &&
             check("English","[pn]",words[0]) &&
             check("English","[vi]",words[1]))
        puts("English");
    else if (cnt == 3 &&
             check("English","[pn]",words[0]) &&
             check("English","[vt]",words[1]) &&
             check("English","[n]",words[2]))
        puts("English");
    else if (cnt == 4 &&
             strcmp("There",words[0]) == 0 &&
             strcmp("is",words[1]) == 0 &&
             strcmp("a",words[2]) == 0 &&
             check("English","[n]",words[3]))
        puts("English");
    else if (cnt == 3 &&
             strcmp("Happy",words[0]) == 0 &&
             strcmp("new",words[1]) == 0 &&
             strcmp("year",words[2]) == 0)
        puts("English");
    else if (cnt == 4 &&
             check("Japanese","[pn]",words[0]) &&
             strcmp("ha",words[1]) == 0 &&
             check("Japanese","[n]",words[2]) &&
             strcmp("desu",words[3]) == 0)
        puts("Japanese");
    else if (cnt == 4 &&
             check("Japanese","[pn]",words[0]) &&
             strcmp("ha",words[1]) == 0 &&
             check("Japanese","[n]",words[2]) &&
             strcmp("da",words[3]) == 0)
        puts("Japanese");
    else if (cnt == 6 &&
             check("Japanese","[pn]",words[0]) &&
             strcmp("ha",words[1]) == 0 &&
             check("Japanese","[n]",words[2]) &&
             strcmp("ga",words[3]) == 0 &&
             check("Japanese","[adj]",words[4]) &&
             strcmp("desu",words[5]) == 0)
        puts("Japanese");
    else if (cnt == 2 &&
             check("Japanese","[n]",words[0]) &&
             strcmp("saikou",words[1]) == 0)
        puts("Japanese");
    else if (cnt == 2 &&
             strcmp("yoi",words[0]) == 0 &&
             strcmp("otoshiwo",words[1]) == 0)
        puts("Japanese");
    else if (cnt == 4 &&
             strcmp("Ich",words[0]) == 0 &&
             strcmp("habe",words[1]) == 0 &&
             strcmp("ein",words[2]) == 0 &&
             check("German","[n]",words[3]))
        puts("German");
    else if (cnt == 3 &&
             strcmp("Ich",words[0]) == 0 &&
             strcmp("bin",words[1]) == 0 &&
             check("German","[n]",words[2]))
        puts("German");
    else if (cnt == 3 &&
             strcmp("Ich",words[0]) == 0 &&
             strcmp("heisse",words[1]) == 0 &&
             check("German","[n]",words[2]))
        puts("German");
    else if (cnt == 3 &&
             strcmp("Du",words[0]) == 0 &&
             strcmp("hast",words[1]) == 0 &&
             check("German","[n]",words[2]))
        puts("German");
    else
        puts("I don't know.");
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s%s%s",language[i],catalog[i],word[i]);
        gets(buf);
        printf("Case #%d:\n",cas);
        for (int i = 0; i < m; i++)
        {
            gets(buf);
            int pos = 0,npos;
            cnt = 0;
            while (sscanf(buf+pos,"%s%n",words[cnt],&npos) != EOF)
            {
                pos += npos;
                cnt++;
            }

            check();
        }
    }
    return 0;
}
