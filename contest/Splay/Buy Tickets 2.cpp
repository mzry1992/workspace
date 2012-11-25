#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAXN = 200001;

int post[MAXN];
int value[MAXN];

struct Node {
	Node() : value(-1){};
	int left, right, num, value;
};

Node array[3 * MAXN];

int result[MAXN];

void BuildTree(int v, int l, int r) {
	array[v].left = l;
	array[v].right = r;
	array[v].num = r - l + 1;
	array[v].value = -1;

	if (l >= r) return;

	int mid = (l + r) / 2;

	BuildTree(2 * v, l , mid);
	BuildTree(2 * v + 1, mid + 1, r);
}

void Insert(int v, int i, int pos)
{
	array[v].num--;

	if (array[v].left == array[v].right) {
		array[v].value = value[i];
		result[array[v].left] = value[i];
		return;
	}

	if (array[2 * v].num > pos) {
		Insert(2 * v, i, pos);
	} else {
		Insert(2 * v + 1, i, pos - array[2 * v].num);
	}
}

int main() {
//	freopen("input","r",stdin);

    freopen("data.in","r",stdin);
    freopen("2.out","w",stdout);
	int N;
	while (cin >> N) {
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &post[i], &value[i]);
		}

		BuildTree(1, 1, N);

		for (int i = N; i >= 1; i--) {
			Insert(1, i, post[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (i != N) {
				printf("%d\n", result[i]);
			} else {
				printf("%d\n", result[i]);
			}
		}

	}
	return 0;
}
