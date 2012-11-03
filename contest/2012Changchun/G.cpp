#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

const int maxn = 110000;

char Ma[maxn*2];
int Mp[maxn*2];
void Manacher(char s[],int len)
{
	int l = 0;
	Ma[l++] = '.';
	Ma[l++] = ',';
	for (int i = 0;i < len;i++)
	{
		Ma[l++] = s[i];
		Ma[l++] = ',';
	}
	Ma[l] = 0;
	int pnow = 0,pid = 0;
	for (int i = 1;i < l;i++)
	{
		if (pnow > i)
			Mp[i] = min(Mp[2*pid-i],pnow-i);
		else
			Mp[i] = 1;
		for (;Ma[i-Mp[i]] == Ma[i+Mp[i]];Mp[i]++);
		if (i+Mp[i] > pnow)
		{
			pnow = i+Mp[i];
			pid = i;
		}
	}
}

char s[maxn*2];
int len;
int p[maxn*2];
const int muts = 129;
uint sum[maxn];
uint mutpower[maxn];

struct hash_map
{
	const static int mod = 300007;
	int head[mod];
	struct hash_tables
	{
		uint key1;
		int key2;
		int key3;
		int next;
	}ele[maxn*10];
	int N;
	void init()
	{
		memset(head,-1,sizeof(head));
		N = 0;
	}
	int totlen[mod];
	void clear()
	{
		for (int i = 0;i < N;i++)
			head[ele[i].key1%mod] = -1;
		N = 0;
	}
	int find(uint x,int len)
	{
		int hashcode = x%mod;
		for (int i = head[hashcode];i != -1;i = ele[i].next)
			if (ele[i].key1 == x && ele[i].key2 == len)
				return ele[i].key3;
		return -1;
	}
	void insert(uint x,int len,int pos)
	{
		int tmp = x%mod;
		ele[N].key1 = x;
		ele[N].key2 = len;
		ele[N].key3 = pos;
		ele[N].next = head[tmp];
		head[tmp] = N++;
	}
};

hash_map hash;

uint gethashcode(int l,int r)
{
	uint ret;
	ret = sum[r];
	if (l)
		ret -= sum[l-1]*mutpower[r-l+1];
	return ret;
}

const int mod = 777777777;
pair<int,long long> res[maxn*10];
int totres;
int m;
int val[26];
long long kth;

struct Trie
{
	int next[maxn][26],end[maxn];
	int L,root;

	int newNode()
	{
		for (int i = 0;i < 26;i++)
			next[L][i] = -1;
		end[L] = 0;
		return L++;
	}

	void Init()
	{
		L = 0;
		root = newNode();
	}

	void Insert(char s[],int now,int l,int r,int midpos)
	{
		uint tmp;
		for (int i = r;i >= l;i--)
		{
			next[now][s[i]-'a'] = newNode();
			now = next[now][s[i]-'a'];
			tmp = gethashcode(i,midpos);
			hash.insert(tmp,midpos-i+1,now);
		}
		end[now]++;
	}

	void DFS(int deep,int now)
	{
		for (int i = 0;i < 26;i++)
			if (next[now][i] != -1)
			{
				for (int j = 0;j < deep;j++)
					printf(" ");
				printf("%c\n",'a'+i);
				DFS(deep+1,next[now][i]);
			}
	}

	void Print()
	{
		DFS(0,root);
	}

	long long Gao(int hash,int mutp,int now)
	{
		int nxtmutp = (long long)mutp*26%mod;
		long long tot = 0;
		for (int i = 0;i < 26;i++)
			if (next[now][i] != -1)
			{
				int nxthash = ((long long)mutp*val[i]+hash)%mod;
				tot += Gao(nxthash,nxtmutp,next[now][i]);
			}
		tot += end[now];
		if (now != root && tot > 0)
			res[totres++] = make_pair(hash,tot);
		return tot;
	}
};
Trie triodd,trieven;

void calc(char s[])
{
	len = strlen(s);
	Manacher(s,len);
	sum[0] = s[0];
	for (int i = 1;i < len;i++)
		sum[i] = sum[i-1]*muts+s[i];

	uint tmp;
	hash.clear();
	triodd.Init();
	for (int i = 0;i < len;i++)
		if (Mp[i*2+2]%2 == 0)
		{
			int pl = Mp[i*2+2]/2;
			int nid = i+1,tripos = triodd.root;
			for (int j = i-pl+1;j <= i;j++)
			{
				tmp = gethashcode(j,i);
				if (hash.find(tmp,i-j+1) != -1)
				{
					nid = j;
					tripos = hash.find(tmp,i-j+1);
					break;
				}
			}
			triodd.Insert(s,tripos,i-pl+1,nid-1,i);
		}

	hash.clear();
	trieven.Init();
	for (int i = 0;i < len;i++)
		if (Mp[i*2+3] > 1)
		{
			int pl = Mp[i*2+3]/2;
			int nid = i+1,tripos = trieven.root;
			for (int j = i-pl+1;j <= i;j++)
			{
				tmp = gethashcode(j,i);
				if (hash.find(tmp,i-j+1) != -1)
				{
					nid = j;
					tripos = hash.find(tmp,i-j+1);
					break;
				}
			}
			trieven.Insert(s,tripos,i-pl+1,nid-1,i);
		}
}

int main()
{
	mutpower[0] = 1;
	for (int i = 1;i < maxn;i++)
		mutpower[i] = mutpower[i-1]*muts;
	hash.init();

	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%*d%d",&m);
		scanf("%s",s);
		calc(s);

		for (int Q = 0;Q < m;Q++)
		{
			scanf("%lld",&kth);
			for (int i = 0;i < 26;i++)
				scanf("%d",&val[i]);
			totres = 0;
			triodd.Gao(0,1,triodd.root);
			trieven.Gao(0,1,trieven.root);

			sort(res,res+totres);
			for (int i = 0;i < totres;i++)
				if (kth > res[i].second)
					kth -= res[i].second;
				else
				{
					printf("%d\n",res[i].first);
					break;
				}
		}
		puts("");
	}
	return 0;
}
