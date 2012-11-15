#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int w,tots,res;
char s[1100][1100],tmp[1100];

int Gao(int l,int r,map<string,int> gl,set<string> fa)
{
    int res = 0,nl,nr;
    map<string,int> now = gl;
    set<string> used,tfa = fa;
    if (s[l+1][0] == '{')
        nl = l+2;
    else
    {
        nl = l+3;
        tfa.insert(s[l+1]);
    }
    nr = r-1;
    for (int i = nl;i < nr;)
    {
        if (strcmp(s[i],"struct") == 0)
        {
            bool hasname = true;
            int tl = i+3,tot = 1;
            if (s[i+1][0] == '{')
            {
                hasname = false;
                tl = i+2;
            }
            else
                if (now.find(s[i+1]) != now.end() ||
                    tfa.find(s[i+1]) != tfa.end())  return -1;
            for (int j = tl;;j++)
            {
                if (s[j][0] == '{') tot++;
                else if (s[j][0] == '}')    tot--;
                if (tot == 0)
                {
                    int noww = Gao(i,j+1,now,tfa);
                    if (hasname == true)
                        now[s[i+1]] = noww;
                    if (noww == -1)
                        return -1;
                    for (int k = j+1;;k++)
                        if (s[k][0] == ';')
                        {
                            i = k+1;
                            break;
                        }
                        else
                        {
                            if (s[k][0] != ',')
                            {
                                if (used.find(s[k]) != used.end())
                                    return -1;
                                used.insert(s[k]);
                                res += noww;
                            }
                        }
                    break;
                }
            }
        }
        else
        {
            if (tfa.find(s[i]) != tfa.end())
                return -1;
            int noww = now[s[i]];
            for (int j = i+1;;j++)
                if (s[j][0] == ';')
                {
                    i = j+1;
                    break;
                }
                else
                {
                    if (s[j][0] != ',')
                    {
                        if (used.find(s[j]) != used.end())  return -1;
                        used.insert(s[j]);
                        res += noww;
                    }
                }
        }
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&w);
        tots = 0;
        while (true)
        {
            scanf("%s",tmp);
            if (strcmp(tmp,"$") != 0)
            {
                int len = strlen(tmp);
                int prei = 0;
                for (int i = 0;i <= len;i++)
                    if (i == len || tmp[i] == '{' || tmp[i] == '}' || tmp[i] == ',' || tmp[i] == ';')
                    {
                        if (prei < i)
                        {
                            for (int j = prei;j < i;j++)
                                s[tots][j-prei] = tmp[j];
                            s[tots][i-prei] = 0;
                            tots++;
                        }
                        if (i < len)
                        {
                            s[tots][0] = tmp[i];
                            s[tots][1] = 0;
                            tots++;
                        }
                        prei = i+1;
                    }
            }
            else
                break;
        }
        map<string,int> tmp;
        tmp.clear();
        tmp["T1"] = 1/w+(((1%w)==0)?0:1);
        tmp["T2"] = 2/w+(((2%w)==0)?0:1);
        tmp["T3"] = 3/w+(((3%w)==0)?0:1);
        tmp["T4"] = 4/w+(((4%w)==0)?0:1);
        tmp["T5"] = 5/w+(((5%w)==0)?0:1);
        tmp["T6"] = 6/w+(((6%w)==0)?0:1);
        tmp["T7"] = 7/w+(((7%w)==0)?0:1);
        tmp["T8"] = 8/w+(((8%w)==0)?0:1);
        tmp["T9"] = 9/w+(((9%w)==0)?0:1);
        set<string> tmp2;
        tmp2.clear();
        res = Gao(0,tots-1,tmp,tmp2);
        if (res == -1)
            puts("error");
        else
            printf("%d\n",res*w);
    }
    return 0;
}
