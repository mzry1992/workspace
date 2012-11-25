#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

struct seqs
{
    string seq;
    int id;
    seqs(){}
    seqs(string _seq,int _id)
    {
        seq = _seq;
        id = _id;
    }
    bool operator < (const seqs& b) const
    {
        return seq.length() > b.seq.length();
    }
};

const int maxnode = 2000000;
int totnode;
int n,m;
string dic[20];
seqs seq[80];
char mp[26];

bool check(int a,int b)
{
    if (seq[a].seq.length() != dic[b].length()) return false;
    for (int i = 0; i < seq[a].seq.length(); i++)
        if (mp[seq[a].seq[i]-'A'] != '$')
            if (mp[seq[a].seq[i]-'A'] != dic[b][i]-'A')
                return false;
    return true;
}

int totres,pos[100];
char res[100];

void DFS(int now)
{
    if (totres == 2)    return;
    if (now == m)
    {
        //find a res
        totres++;
        int l = 0;
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < seq[pos[i]].seq.length();j++)
                res[l++] = mp[seq[pos[i]].seq[j]-'A']+'A';
            if (i+1 < m)
                res[l++] = ' ';
            else
                res[l++] = '.';
        }
        res[l] = 0;
        return;
    }
    totnode++;
    if (totres > 0 && totnode > maxnode)  return;
    char tmp[26];
    for (int i = 0; i < 26; i++)  tmp[i] = mp[i];
    for (int i = 0; i < n; i++)
        if (check(now,i) == true)
        {
            for (int j = 0; j < seq[now].seq.length(); j++)
                if (mp[seq[now].seq[j]-'A'] == '$')
                    mp[seq[now].seq[j]-'A'] = dic[i][j]-'A';

            bool check = true;
            for (int j = 0; j < 26; j++)
                if (mp[j] != '$')
                    if (mp[mp[j]] != j)
                        if (mp[mp[j]] == '$')
                            mp[mp[j]] = j;
                        else
                        {
                            check = false;
                            break;
                        }

            if (check == true)
                DFS(now+1);

            if (totres > 1 || totnode > maxnode)    return;

            for (int j = 0; j < 26; j++)  mp[j] = tmp[j];
        }
}

bool used[30];
char toc[30];
string gao(string a)
{
    string res = a;
    for (int i=0;i<26;i++)
        toc[i]='`';
    int tot = 0;
    for (int i = 0;i <res.length();i++)
    {
        if (toc[res[i]-'A']=='`')
            toc[res[i]-'A']='A'+tot++;
        res[i]=toc[res[i]-'A'];
    }
    return res;
}

bool check0()
{
    memset(used,false,sizeof(used));
    for (int i = 0;i < m;i++)
    {
        bool check = false;
        for (int j = 0;j < i;j++)
            if (seq[j].seq == seq[i].seq)
            {
                check = true;
                break;
            }
        if (check == true)  continue;
        string ta = gao(seq[i].seq);
        for (int j = 0;j < n;j++)
            if (used[j] == false && ta.length() == dic[j].length())
            {
                string tb = gao(dic[j]);
                if (ta == tb)
                {
                    for (int k = j;k < n;k++)
                        if (dic[k] == dic[j])
                            used[k] = true;
                    check = true;
                    break;
                }
            }
        if (check == false) return false;
    }
    return true;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            cin >> dic[i];
        m = 0;
        while (true)
        {
            string tmp;
            cin >> tmp;
            if (tmp[tmp.length()-1] == '.')
            {
                tmp = tmp.substr(0,tmp.length()-1);
                seq[m] = seqs(tmp,m);
                m++;
                break;
            }
            seq[m] = seqs(tmp,m);
            m++;
        }
        if (check0() == false)
        {
            puts("-.");
            continue;
        }
        sort(seq,seq+m);
        for (int i = 0;i < m;i++)
            pos[seq[i].id] = i;
        for (int i = 0; i < 26; i++)
            mp[i] = '$';
        totres = totnode = 0;
        DFS(0);
        if (totres != 1)
            puts("-.");
        else
            puts(res);
    }
    return 0;
}
