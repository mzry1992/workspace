#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

char gem[10];
int a[6],res;
set<string> hash;
string tmp;
const int rot[24][6] = {{0,1,2,3,4,5},{0,4,2,5,3,1},{0,3,2,1,5,4},{0,5,2,4,1,3},
                        {1,2,3,0,4,5},{1,4,3,5,0,2},{1,0,3,2,5,4},{1,5,3,4,2,0},
                        {2,3,0,1,4,5},{2,4,0,5,1,3},{2,1,0,3,5,4},{2,5,0,4,3,1},
                        {3,0,1,2,4,5},{3,4,1,5,2,0},{3,2,1,0,5,4},{3,5,1,4,0,2},
                        {4,1,5,3,2,0},{4,2,5,0,3,1},{4,3,5,1,0,2},{4,0,5,2,1,3},
                        {5,1,4,3,0,2},{5,0,4,2,3,1},{5,3,4,1,2,0},{5,2,4,0,1,3}};
bool flag;

int main()
{
    scanf("%s",gem);
    for (int i = 0;i < 6;i++)
        a[i] = i;
    res = 0;
    hash.clear();
    tmp.resize(6);
    do
    {
        flag = true;
        for (int fr = 0;fr < 24;fr++)
        {
            for (int i = 0;i < 6;i++)
                tmp[rot[fr][a[i]]] = gem[i];
            if (hash.find(tmp) != hash.end())
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            res++;
            for (int fr = 0;fr < 24;fr++)
            {
                for (int i = 0;i < 6;i++)
                    tmp[rot[fr][a[i]]] = gem[i];
                hash.insert(tmp);
            }
        }
    }while (next_permutation(a,a+6));
    printf("%d\n",res);
    return 0;
}
