#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const char allow[11][10] = {"html", "body", "head" , "title", "ul", "ol", "li", "div", "b", "i", "p"};

int typ[6000];
string val[6000];
int cnt;
char buf[6000],html[6000],dic[6000][6000];
int tot;
int len;
int stack[6000],top,word[6000],totword;

void find()
{
    top = 0;
    for (int j = 0; j < cnt; j++)
        if (typ[j] == 1)
            stack[top++] = j;
        else if (typ[j] == 2)
            top--;
        else
        {
            totword = 0;
            while (typ[j] == 0)
                word[totword++] = j++;
            j--;

            for (int k = 0; k+tot <= totword; k++)
            {
                bool flag = true;
                for (int q = 0;q < tot && flag;q++)
                    if (strcmp(dic[q],val[word[k+q]].c_str()) != 0)
                        flag = false;
                if (flag)
                {
                    for (int q = 0;q < top;q++)
                        printf("<%s>\n",val[stack[q]].c_str());
                    puts("");
                    return;
                }
            }
        }
    puts("No Wrapper");
    puts("");
}

int main()
{
    while (scanf("%s",buf) != EOF)
    {
        len = 0;
        while (true)
        {
            scanf("%s",buf);
            if (strcmp(buf,">>>") == 0)
                break;
            for (int i = 0; buf[i] != 0; i++)
                html[len++] = buf[i];
            html[len++] = ' ';
        }
        html[len] = 0;

        cnt = 0;
        for (int i = 0; i < len;)
            if (html[i] != ' ')
            {
                if (html[i] == '<')
                {
                    i++;
                    while (html[i] == ' ')
                        i++;
                    if (html[i] == '/')
                    {
                        typ[cnt] = 2;
                        i++;
                    }
                    else
                        typ[cnt] = 1;

                    while (html[i] == ' ')
                        i++;
                    val[cnt] = "";
                    while (true)
                    {
                        val[cnt].push_back(html[i++]);
                        if (html[i] == '>' || html[i] == ' ')   break;
                    }

                    while (html[i] != '>')  i++;
                    i++;

                    for (int j = 0; j < val[cnt].length(); j++)
                        if (val[cnt][j] >= 'A' && val[cnt][j] <= 'Z')
                            val[cnt][j] = val[cnt][j]-'A'+'a';
                    bool flag = false;
                    for (int j = 0; j < 11; j++)
                        if (strcmp(allow[j],val[cnt].c_str()) == 0)
                            flag = true;
                    if (flag)
                        cnt++;
                }
                else
                {
                    typ[cnt] = 0;
                    val[cnt] = "";
                    while (true)
                    {
                        val[cnt].push_back(html[i++]);
                        if (i == len || html[i] == ' ' || html[i] == '<')
                            break;
                    }
                    cnt++;
                }
            }
            else
                i++;

//        for (int i = 0; i < cnt; i++)
//            printf("typ = %d : val = |%s|\n",typ[i],val[i].c_str());

        int n;
        scanf("%d",&n);
        gets(buf);
        for (int i = 0; i < n; i++)
        {
            gets(buf);
            tot = 0;
            int pos = 0,npos;
            while (sscanf(buf+pos,"%s%n",dic[tot],&npos) != EOF)
            {
                tot++;
                pos += npos;
            }

            find();
        }
    }
    return 0;
}



