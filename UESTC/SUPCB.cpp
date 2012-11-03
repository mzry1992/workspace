#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

string s,s1,s2;
const int pos[12] = {3,10,17,24,31,38,50,57,64,71,78,85};
const string numl[10] = {"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011"};
const string numr[10] = {"1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};
string tres;
deque<string> resl,resr,res;
int tot;

char checkl(string s,int l)
{
    string ts = s.substr(l,7);
    for (int i = 0;i < 10;i++)
    if (ts == numl[i])
        return (char)(i+'0');
    return 'A';
}

char checkr(string s,int l)
{
    string ts = s.substr(l,7);
    for (int i = 0;i < 10;i++)
    if (ts == numr[i])
        return (char)(i+'0');
    return 'A';
}

bool check(string cur)
{
    for (int i = 0;i < 12;i++)
    if (cur[i] < '0' || cur[i] > '9') return false;
    int d0,d1;
    int c,cs;
    c = cur[11]-'0';
    d0 = d1 = 0;
    for (int i = 1;i <= 9;i += 2)
        d0 += (cur[i]-'0');
    for (int i = 0;i <= 10;i += 2)
        d1 += (cur[i]-'0');
    cs = 3*d1+d0;
    cs %= 10;
    int tc;
    if (cs == 0)    tc = 0;
    else tc = 10-cs;
    if (tc != c)    return false;
    return true;
}

void DFSL(int now,string cur)
{
    if (resl.size() >= 10)   return;
    if (now == 12)
    {
        if (check(cur) == true)
        {
            if (resl.size() <= 10)
                resl.push_back(cur);
        }
        return;
    }
    bool flag = true;
    for (int i = 0;i < 7;i++)
    if (s[pos[now]+i] == '?')
    {
        flag = false;
        break;
    }
    if (flag == true)
    {
        if (now < 6)
        {
            if (checkl(s,pos[now]) != 'A')
                DFSL(now+1,cur+checkl(s,pos[now]));
        }
        else
        {
            if (checkr(s,pos[now]) != 'A')
                DFSL(now+1,cur+checkr(s,pos[now]));
        }
    }
    else
    {
        if (now < 6)
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numl[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                    DFSL(now+1,cur+(char)(i+'0'));
            }
        }
        else
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numr[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                    DFSL(now+1,cur+(char)(i+'0'));
            }
        }
    }
}

void DFSR(int now,string cur)
{
    if (resr.size() >= 10)   return;
    if (now == 12)
    {
        if (check(cur) == true)
        {
            if (resr.size() <= 10)
                resr.push_back(cur);
        }
        return;
    }
    bool flag = true;
    for (int i = 0;i < 7;i++)
    if (s[pos[now]+i] == '?')
    {
        flag = false;
        break;
    }
    if (flag == true)
    {
        if (now < 6)
        {
            if (checkl(s,pos[now]) != 'A')
                DFSR(now+1,cur+checkl(s,pos[now]));
        }
        else
        {
            if (checkr(s,pos[now]) != 'A')
                DFSR(now+1,cur+checkr(s,pos[now]));
        }
    }
    else
    {
        if (now < 6)
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numl[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                    DFSR(now+1,cur+(char)(i+'0'));
            }
        }
        else
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numr[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                    DFSR(now+1,cur+(char)(i+'0'));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        int tt;
        scanf("%d",&tt);
        cin >> s1 >> s2;
        s = s1+s2;
        if (s.substr(0,3) != "101" || s.substr(45,5) != "01010" || s.substr(92,3) != "101")
        {
            printf("%d %d\n",tt,0);
            continue;
        }
        resl.clear();
        DFSL(0,"");
        string ts = "";
        for (int i = 94;i >= 0;i--)
            ts = ts+s[i];
        s = ts;
        resr.clear();
        DFSR(0,"");
        res.clear();
        for (int i = 0;i < resl.size();i++)
        {
            bool tflag = true;
            for (int j = 0;j < res.size();j++)
            if (res[j] == resl[i])
            {
                tflag = false;
                break;
            }
            if (tflag == true)
                res.push_back(resl[i]);
        }
        for (int i = 0;i < resr.size();i++)
        {
            bool tflag = true;
            for (int j = 0;j < res.size();j++)
            if (res[j] == resr[i])
            {
                tflag = false;
                break;
            }
            if (tflag == true)
                res.push_back(resr[i]);
        }
        sort(res.begin(),res.end());
        printf("%d %d\n",tt,(res.size()>8?9:res.size()));
        for (int i = 0;i < (res.size()>8?8:res.size());i++)
            cout << res[i] << endl;
    }
}
