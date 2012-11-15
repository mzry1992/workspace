#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

map<string,int> res;
struct node
{
    string now;
    int step;
    node(){}
    node(string _now,int _step)
        {
            now = _now;
            step = _step;
        }
};
queue<node> Q;

void BFS()
{
    while (!Q.empty())  Q.pop();
}

int main()
{
    res.clear();
    BFS();
}
