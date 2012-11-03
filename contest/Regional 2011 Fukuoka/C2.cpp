#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct seqs
{
    string seq;
    int id;
    seqs(){}
    seqs(string _seq)
    {
        seq = _seq;
    }
    bool operator < (const seqs& b)const
    {
        return seq.length() > b.seq.length();
    }
};

seqs seq[100];
int m;

string dic[21][21];
int totdic[21];

string tmp;

const int maxnode = 2000000;
int n,totres,totnode;
string chg,res,totseq;

void DFS(int now)
{
    if (totres > 1) return;
    if (now == m)
    {
        totres++;
        res = chg;
        return;
    }
    totnode++;
    if (totres > 0 && totnode > maxnode)    return;
    string tmp = chg;
    bool check;
    int len = seq[now].seq.length();
    for (int i = 0;i < totdic[len];i++)
    {
        check = true;
        for (int j = 0;j < len;j++)
        {
            if (chg[seq[now].seq[j]-'A'] != ' ' && chg[seq[now].seq[j]-'A'] != dic[len][i][j])
            {
                check = false;
                break;
            }
            if (chg[dic[len][i][j]-'A'] != ' ' && chg[dic[len][i][j]-'A'] != seq[now].seq[j])
            {
                check = false;
                break;
            }
            chg[seq[now].seq[j]-'A'] = dic[len][i][j];
            chg[dic[len][i][j]-'A'] = seq[now].seq[j];
        }
        if (check == true)
            DFS(now+1);
        chg = tmp;
        if (totres > 1 || (totres > 0 && totnode > maxnode))    return;
    }
}

int main()
{
	while (true)
	{
	    scanf("%d",&n);
	    if (n == 0) break;
	    for (int i = 1;i <= 20;i++)
            totdic[i] = 0;
        m = 0;
	    for (int i = 0;i < n;i++)
	    {
            cin >> tmp;
            dic[tmp.length()][totdic[tmp.length()]++] = tmp;
	    }
	    totseq = "";
        while (true)
        {
            cin >> tmp;
            totseq += tmp;
            if (tmp[tmp.length()-1] == '.')
            {
                tmp = tmp.substr(0,tmp.length()-1);
                seq[m++] = seqs(tmp);
                break;
            }
            totseq += ' ';
            seq[m++] = seqs(tmp);
        }
        for (int i = 0;i < m;i++)
            seq[i].id = i;
        sort(seq,seq+m);
        totres = totnode = 0;
        chg.resize(26);
        for (int i = 0;i < chg.length();i++)
            chg[i] = ' ';
        DFS(0);
        if (totres > 1)
            puts("-.");
        else
        {
            for (int i = 0;i < totseq.length();i++)
                if (totseq[i] >= 'A' && totseq[i] <= 'Z')
                    totseq[i] = res[totseq[i]-'A'];
            puts(totseq.c_str());
        }
	}
	return 0;
}
