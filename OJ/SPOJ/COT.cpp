#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 210000;
struct Node
{
	int size,key,mx;

	Node *c[2];
	Node *p,*fa;
	Node *head;
}mem[MaxN],*cur,*nil,*pos[MaxN];

int n,m;

int main(int argc, char const *argv[])
{

	return 0;
}