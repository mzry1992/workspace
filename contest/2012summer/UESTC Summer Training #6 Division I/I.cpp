#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;

int nextNum;
int genRand()
{
    nextNum = (nextNum * 32771 + 12347) % 32768;
    return nextNum;
}
int testRand()
{
    return (nextNum * 32771 + 12347) % 32768;
}

struct XML
{
    int type;
    string value;
    map<string,int> attlist;
    vector<XML> children;
};

int now;
int len;
char buf[1000000],tbuf[100000];

void init()
{
    nextNum = 1;
    len = now = 0;
}

XML document;

XML getXML()
{
    XML res;
    res.type = 0;
    res.value = "";
    res.attlist.clear();
    res.children.clear();
    while (buf[now] <= 32)
        now++;
    if (buf[now] == '<')
    {
        now++;
        while (buf[now] <= 32)  now++;
        while (buf[now] > 32 && buf[now] != '>')
        {
            res.value.push_back(buf[now]);
            now++;
        }
        while (buf[now] <= 32)  now++;

        if (res.value == "noreply")
        {
            res.type = 2;
            while (buf[now] != '>') now++;
            now++;
            return res;
        }

        if (buf[now] == '>')
            now++;
        else
        {
            while (true)
            {
                string tmp = "";
                while (buf[now] > 32 && buf[now] != '=')
                {
                    tmp.push_back(buf[now]);
                    now++;
                }
                while (buf[now] <= 32)  now++;
                now++;
                string tmp2 = "";
                while (buf[now] > 32 && buf[now] != '>')
                {
                    tmp2.push_back(buf[now]);
                    now++;
                }
                while (buf[now] <= 32)  now++;
                tmp2 = tmp2.substr(1,tmp2.size()-2);
                int tmp3 = 0;
                sscanf(tmp2.c_str(),"%d",&tmp3);
                res.attlist[tmp] = tmp3;
                if (buf[now] == '>')
                {
                    now++;
                    break;
                }
            }
        }
    }
    else
    {
        string tmp = "";
        while (true)
        {
            if (buf[now] == '<')
                break;
            tmp.push_back(buf[now]);
            now++;
        }
        int npos = tmp.size()-1;
        while (tmp[npos] <= 32)
            npos--;
        tmp = tmp.substr(0,npos+1);
        res.type = 3;
        res.value = tmp;
        return res;
    }
    while (true)
    {
        while (buf[now] <= 32)  now++;
        if (buf[now] == '<' && buf[now+1] == '/')
        {
            now++;
            while (buf[now] != '>') now++;
            now++;
            return res;
        }
        else
            res.children.push_back(getXML());
    }
}

void DFS(XML now,int deep)
{
    for (int i = 0; i < deep; i++)
        printf("  ");
    printf("%d %s\n",now.type,now.value.c_str());
    for (int i = 0; i < now.children.size(); i++)
        DFS(now.children[i],deep+1);
}

const char endflag[10] = "config";
int n;

struct rule
{
    int interv,wait;
    string keyword;
    vector<string> reply;
};
rule r[60],def;
int totr;

bool check(char a,char b)
{
    if (a >= 'A' && a <= 'Z')   a = a-'A'+'a';
    if (b >= 'A' && b <= 'Z')   b = b-'A'+'a';
    return a == b;
}

bool check(char* s,string key)
{
    int len = strlen(s);
    for (int i = 0; i+key.size() <= len; i++)
    {
        bool flag = true;
        for (int j = 0; j < key.size() && flag; j++)
            if (!check(key[j],s[i+j]))
                flag = false;
        if (flag)   return true;
    }
    return false;
}

struct PostTime
{
    int h,m,s,wait,interv;
    bool operator < (const PostTime& b)const
    {
        return h*3600+m*60+s < b.h*3600+b.m*60+b.s;
    }
    void post()
    {
        int tim = h*3600+m*60+s+wait;
        if (tim >= 86400)
            tim -= 86400;
        printf("%02d:",tim/3600);
        tim -= 3600*(tim/3600);
        printf("%02d:%02d",tim/60,tim%60);
    }
};

int TimeDist(PostTime& a,PostTime& b)
{
    if (a < b)
        return 86400-(b.h-a.h)*3600-(b.m-a.m)*60-(b.s-a.s);
    return (a.h-b.h)*3600+(a.m-b.m)*60+(a.s-b.s);
}

int main()
{
    freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    gets(tbuf);
    for (int cas = 1;cas <= totcas;cas++)
    {
        if (cas > 1)
            puts("");
        init();
        int flagcnt = 0;
        while (gets(tbuf))
        {
            bool check = false;
            for (int i = 0; tbuf[i] != 0 && !check; i++)
            {
                buf[len++] = tbuf[i];
                if (i >= 6)
                {
                    bool check2 = true;
                    for (int j = 0; j < 6 && check2; j++)
                        if (tbuf[i-6+j] != endflag[j])
                            check2 = false;
                    if (check2)
                        check = true;
                }
            }
            if (check)
                flagcnt++;
            if (flagcnt == 2)   break;
        }
        document = getXML();
        //DFS(document,0);
        totr = 0;
        for (int i = 0; i < document.children.size(); i++)
            if (document.children[i].value == "default")
            {
                def.reply.clear();

                def.interv = document.children[i].attlist["interval"];
                def.wait = document.children[i].attlist["wait"];

                for (int j = 0; j < document.children[i].children.size(); j++)
                    if (document.children[i].children[j].value == "reply")
                        def.reply.push_back(document.children[i].children[j].children[0].value);
                    else
                        def.reply.push_back(" ");
            }
        for (int i = 0; i < document.children.size(); i++)
            if (document.children[i].value == "rule")
            {
                r[totr].reply.clear();

                if (document.children[i].attlist.find("interval") == document.children[i].attlist.end())
                    r[totr].interv = def.interv;
                else
                    r[totr].interv = document.children[i].attlist["interval"];
                if (document.children[i].attlist.find("wait") == document.children[i].attlist.end())
                    r[totr].wait = def.wait;
                else
                    r[totr].wait = document.children[i].attlist["wait"];
                for (int j = 0; j < document.children[i].children.size(); j++)
                    if (document.children[i].children[j].value == "keyword")
                        r[totr].keyword = document.children[i].children[j].children[0].value;
                    else if (document.children[i].children[j].value == "reply")
                        r[totr].reply.push_back(document.children[i].children[j].children[0].value);
                    else
                        r[totr].reply.push_back(" ");
                totr++;
            }

        PostTime lastpost,newpost;
        lastpost.h = lastpost.m = lastpost.s = lastpost.interv = lastpost.wait = 0;
        scanf("%d",&n);
        gets(tbuf);
        for (int i = 0; i < n; i++)
        {
            gets(tbuf);
            int npos;
            int hh,mm,ss;
            sscanf(tbuf,"%d:%d:%d%n",&newpost.h,&newpost.m,&newpost.s,&npos);

            bool flag = false;
            for (int j = 0; j < totr; j++)
            {
                if (r[j].reply.size() == 0) continue;

                if (check(tbuf+npos,r[j].keyword) == true)
                {
                    flag = true;
                    newpost.interv = r[j].interv;
                    newpost.wait = r[j].wait;
                    if (TimeDist(lastpost,newpost)+newpost.wait >= lastpost.interv+lastpost.wait)
                    {
                        int rnd = 0;
                        if (r[j].reply.size() > 1)
                            rnd = genRand()%r[j].reply.size();

                        if (r[j].reply[rnd] == " ")
                            continue;
                        lastpost = newpost;
                        lastpost.post();
                        printf(" %s\n",r[j].reply[rnd].c_str());
                    }
                    break;
                }
            }
            if (flag == false)
            {
                if (def.reply.size() == 0)  continue;

                newpost.interv = def.interv;
                newpost.wait = def.wait;
                if (TimeDist(lastpost,newpost)+newpost.wait >= lastpost.interv+lastpost.wait)
                {
                    int rnd = 0;
                    if (def.reply.size() > 1)
                        rnd = genRand()%def.reply.size();

                    if (def.reply[rnd] == " ")
                        continue;
                    lastpost = newpost;
                    lastpost.post();
                    printf(" %s\n",def.reply[rnd].c_str());
                }
            }
        }
    }
    return 0;
}
