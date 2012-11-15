#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int n,len;
bool select[110];
char s[110][110],com[110];
set<char> separator;
const char separators[] = "/~!@#$%^&*()-+=";
int rangea,rangeb;
char pattern[110],str[110],lasp[110];
int plen,slen,lplen;
string tpa,tstr;

int main()
{
    separator.clear();
    for (int i = 0;i < strlen(separators);i++)
        separator.insert(separators[i]);
    scanf("%d",&n);
    gets(s[0]);
    for (int i = 1;i <= n;i++)
        gets(s[i]);
    bool first = true;
    while (gets(com))
    {
        if (first == false) puts("");
        first = false;
        len = strlen(com);
        memset(select,false,sizeof(select));
        if (com[1] == '%')
        {
            rangea = 1;
            rangeb = n;
        }
        else
            sscanf(com,":%d,%ds",&rangea,&rangeb);
        for (int i = 0;i < len;i++)
            if (com[i] == 's')
            {
                plen = 0;
                for (int j = i+2;j < len;j++)
                    if (separator.find(com[j]) == separator.end())
                        pattern[plen++] = com[j];
                    else
                    {
                        slen = 0;
                        for (int k = j+1;k < len;k++)
                            if (separator.find(com[k]) == separator.end())
                                str[slen++] = com[k];
                            else
                                break;
                        break;
                    }
                break;
            }
        if (plen == 0)
        {
            plen = lplen;
            for (int i = 0;i < lplen;i++)
                pattern[i] = lasp[i];
        }
        else
        {
            lplen = plen;
            for (int i = 0;i < lplen;i++)
                lasp[i] = pattern[i];
        }
        pattern[plen] = 0;
        tpa = pattern;
        str[slen] = 0;
        tstr = str;
        bool flag = false;
        for (int id = rangea;id <= rangeb;id++)
        {
            bool check = false;
            string tmps = s[id];
            string res = "";
            /*cout << "Id = " << id << endl;
            cout << tmps << endl;
            cout << "Pa = " << tpa << endl;*/
            if (tmps == tpa)
            {
                res = tstr;
                check = true;
            }
            else
            {
                for (int i = 0;i < tmps.size();)
                    if (i <= tmps.size()-tpa.size() && tmps.substr(i,tpa.size()) == tpa)
                    {
                        res += tstr;
                        check = true;
                        i += tpa.size();
                    }
                    else
                    {
                        res += tmps[i];
                        i++;
                    }
            }
            if (check == true)
            {
                flag = select[id] = true;
                for (int i = 0;i < res.size();i++)
                    s[id][i] = res[i];
                s[id][res.size()] = 0;
            }
        }
        if (flag == false)
            puts("Pattern not found");
        else
        {
            for (int i = rangea;i <= rangeb;i++)
                if (select[i] == true)
                    printf("%4d  %s\n",i,s[i]);
        }
    }
    return 0;
}
