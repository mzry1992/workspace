#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n,line1,line2;
char buf[1000000],tmp[1000000];
int id[1000000],tot;
map<string,int> stringid;
int totstring;

bool isSplit(char ch)
{
    return ch == 9 || ch == 10 || ch == 11 || ch == 12 || ch == 13 || ch == 32 ||
            ch == 33 || ch == 44 || ch == 46 || ch == 58 || ch == 59 || ch == 63;
}

bool isEmail(char ch)
{
    if (ch >= 'A' && ch <= 'Z') return true;
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= '0' && ch <= '9') return true;
    if (ch == '-' || ch == '_') return true;
    return false;
}

int getid(char s[])
{
    if (stringid.find(s) == stringid.end())
        stringid[s] = totstring++;
    return stringid[s];
}

void Split()
{
    int pos = 0,npos;
    while (sscanf(buf+pos,"%s%n",tmp,&npos) != EOF)
    {
        pos += npos;
        id[tot++] = getid(tmp);
    }
}

void readfile(int len)
{
    tot = 0;
    for (int i = 0;i < len;i++)
    {
        gets(buf);
        for (int j = 0;buf[j] != 0;j++)
            if (buf[j] == '@')
            {
                for (int k = j+1;buf[k] != 0;k++)
                    if (!isEmail(buf[k]))
                    {
                        if (buf[k] == '.' && isEmail(buf[k+1]))
                            buf[k] = '|';
                        else
                            break;
                    }
                for (int k = j-1;k >= 0;k--)
                    if (!isEmail(buf[k]))
                    {
                        if (buf[k] == '.' && (k == 0 || isEmail(buf[k-1])))
                            buf[k] = '|';
                        else
                            break;
                    }
            }
        for (int j = 0;buf[j] != 0;j++)
            if (isSplit(buf[j]))
                buf[j] = ' ';
        Split();
        //puts(buf);
    }
}

set<vector<int> > hash,hashb;
vector<int> ha;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    scanf("%d%d",&line1,&line2);
	    gets(buf);

	    totstring = 0;
	    stringid.clear();
	    ha.resize(n);
	    hash.clear();
	    hashb.clear();

	    readfile(line1);
	    for (int i = 0;i+n <= tot;i++)
	    {
	        for (int j = 0;j < n;j++)
                ha[j] = id[i+j];
            hash.insert(ha);
	    }
//	    for (int i = 0;i < tot;i++)
//            printf("%d ",id[i]);
//        printf("\n");


	    readfile(line2);
	    for (int i = 0;i+n <= tot;i++)
	    {
	        for (int j = 0;j < n;j++)
                ha[j] = id[i+j];
            hashb.insert(ha);
	    }
//	    for (int i = 0;i < tot;i++)
//            printf("%d ",id[i]);
//        printf("\n");

        int m = hash.size();
	    int l = hashb.size();
	    int s = 0;
	    for (set<vector<int> >::iterator it = hash.begin();it != hash.end();it++)
            if (hashb.find(*it) != hashb.end())
                s++;
        //printf("%d %d %d\n",s,m,l);
        printf("%.2f\n",min((double)s/(double)m,(double)s/(double)l)*100.0);
	}
	return 0;
}
