#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

pair<int,int> card[5];
char buf[5];

int getnum(char ch)
{
    if (ch == 'A')  return 1;
    if (ch >= '2' && ch <= '9') return ch-'0';
    if (ch == 'X')  return 10;
    if (ch == 'J')  return 11;
    if (ch == 'Q')  return 12;
    return 13;
}

bool Straight()
{
    for (int i = 2; i < 5; i++)
        if (card[i].first != card[i-1].first+1) return false;
    if (card[0].first == 1 && card[4].first == 13)  return true;
    if (card[1].first != card[0].first+1)   return false;
    return true;
}

bool four(int idx)
{
    for (int i = idx; i < idx+4; i++)
        if (card[i].first != card[idx].first)
            return false;
    return true;
}

bool three(int idx)
{
    for (int i = idx; i < idx+3; i++)
        if (card[i].first != card[idx].first)
            return false;
    return true;
}

bool two(int idx)
{
    for (int i = idx; i < idx+2; i++)
        if (card[i].first != card[idx].first)
            return false;
    return true;
}

bool flush()
{
    for (int i = 0; i < 5 ; i++)
        if (card[i].second != card[0].second)
            return false;
    return true;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        for (int i = 0; i < 5; i++)
        {
            scanf("%s",buf);
            card[i] = make_pair(getnum(buf[1]),buf[0]-'A');
        }
        sort(card,card+5);
        int res = 0;
        if (Straight())
        {
            if (flush())
                res = max(res,1000);
            else
                res = max(res,250);
        }
        if (four(0) || four(1))
            res = max(res,750);
        if ((three(0) && two(3)) ||
                (three(2) && two(0)))
            res = max(res,500);
        if (flush())
            res = max(res,350);
        if (three(0) || three(1) || three(2))
            res = max(res,200);
        if ((two(0) && (two(2) || two(3))) ||
            (two(1) && two(3)))
                res = max(res,100);
        if (two(0) || two(1) || two(2) || two(3))
            res = max(res,50);
        printf("%d\n",res);
    }
    return 0;
}
