#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

char tmp[22];
int s[3][22];

//R(Red Joker), B(Black joker), 2, A, K, Q, J, T(10), 9, 8, 7, 6, 5, 4, 3.
//Each rank of standard card has 4 cards.
int getid(char ch)
{
    if (ch == 'R')  return 14;
    if (ch == 'B')  return 13;
    if (ch == '2')  return 12;
    if (ch == 'A')  return 11;
    if (ch == 'K')  return 10;
    if (ch == 'Q')  return 9;
    if (ch == 'J')  return 8;
    if (ch == 'T')  return 7;
    return ch-'3';
}

int tot[15];
//第i个牌型长度为j的最优值
int best[14][20];
bool flag;
int att;

int sum;

void getinfo(int id,int len,int sta,int& typ1,int& typ2,int& val)
{
    for (int i = 0; i < 15; i++)
        tot[i] = 0;
    sum = 0;
    for (int i = 0; i < len; i++)
        if (((sta>>i)&1) == 1)
        {
            tot[s[id][i]]++;
            sum++;
        }
    //0.  Single card - ranking from 3 (low) up to red joker (high) as explained above.
    if (sum == 1)
    {
        for (int i = 0; i < 15; i++)
            if (tot[i] > 0)
            {
                typ1 = 0;
                typ2 = 1;
                val = i;
                return;
            }
    }
    //1.  Pair - two cards of the same rank, from 3 (low) up to 2 (high), for example 3-3, A-A.
    if (sum == 2)
    {
        for (int i = 0; i < 15; i++)
            if (tot[i] > 1)
            {
                typ1 = 1;
                typ2 = 1;
                val = i;
                return;
            }
    }
    //2.  Triplet - three cards of the same rank, for example 9-9-9.
    if (sum == 3)
    {
        for (int i = 0; i < 15; i++)
            if (tot[i] > 2)
            {
                typ1 = 2;
                typ2 = 1;
                val = i;
                return;
            }
    }
    //3.  Triplet with an attached card - a triplet with a single card added, the single card must be
    //different from the triplet, for example 6-6-6-8. These rank according to the rank of the triplet -
    //so for example 9-9-9-3 beats 8-8-8-A.
    if (sum == 4)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 0)
                att++;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 2)
                if (att > 1)
                {
                    typ1 = 3;
                    typ2 = 1;
                    val = i;
                    return;
                }
    }
    //4.  Triplet with an attached pair - a triplet with a pair added, the ranking being determined by
    //the rank of the triplet - for example Q-Q-Q-6-6 beats 10-10-10-K-K.
    if (sum == 5)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 1)
                att++;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 2)
                if (att > 1)
                {
                    typ1 = 4;
                    typ2 = 1;
                    val = i;
                    return;
                }
    }
    //5.  Sequence - at least five cards of consecutive rank, from 3 up to ace - for example 8-9-10-J-Q.
    //2 and jokers cannot be used.
    if (sum >= 5)
    {
        for (int j = 0; j+sum < 13; j++)
        {
            flag = true;
            for (int k = 0; k < sum; k++)
                if (tot[j+k] < 1)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                typ1 = 5;
                typ2 = sum;
                val = j;
                return;
            }
        }
    }
    //6.  Sequence of pairs - at least three pairs of consecutive ranks, from 3 up to A. 2 and jokers
    //cannot be used. For example 10-10-J-J-Q-Q-K-K.
    if (sum%2 == 0 && sum/2 >= 3)
    {
        int i = sum/2;
        for (int j = 0; j+i < 13; j++)
        {
            flag = true;
            for (int k = 0; k < i; k++)
                if (tot[j+k] < 2)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                typ1 = 6;
                typ2 = i;
                val = j;
                return;
            }
        }
    }
    //7.  Sequence of triplets - at least two triplets of consecutive ranks from 3 up to A. 2 cannot be
    //used. For example 4-4-4-5-5-5.
    if (sum%3 == 0 && sum/3 >= 2)
    {
        int i = sum/3;
        for (int j = 0; j+i < 13; j++)
        {
            flag = true;
            for (int k = 0; k < i; k++)
                if (tot[j+k] < 3)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                typ1 = 7;
                typ2 = i;
                val = j;
                return;
            }
        }
    }
    //8.  Sequence of triplets with attached cards - an extra card is added to each triplet. Only the
    //triplets have to be in sequence, for example 7-7-7-8-8-8-3-6. The attached cards must be different
    //from all the triplets and from each other. Although triplets of 2 cannot be included in the triplets
    //sequence, a 2 or a joker or one of each can be attached, but not both jokers.
    if (sum%4 == 0 && sum/4 >= 2)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 0)
                att++;
        if (tot[13] == 1 && tot[14] == 1)
            att--;
        int i = sum/4;
        if (att == i*2)
        {
            for (int j = 0; j+i < 13; j++)
            {
                flag = true;
                for (int k = 0; k < i; k++)
                    if (tot[j+k] < 3)
                    {
                        flag = false;
                        break;
                    }
                if (flag == true)
                {
                    typ1 = 8;
                    typ2 = i;
                    val = j;
                    return;
                }
            }
        }
    }
    //9.  Sequence of triplets with attached pairs - an extra pair is attached to each triplet. Only
    //the triplets have to be in sequence - for example 8-8-8-9-9-9-4-4-J-J. The pairs must be different
    //in rank from each other and from all the triplets. Although triplets of 2 cannot be included in
    //the triplets sequence, a pair of 2 can be attached. Note that attached single cards and attached
    //pairs cannot be mixed - for example 3-3-3-4-4-4-6-7-7 is not valid.
    if (sum%5 == 0 && sum/5 >= 2)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 1)
                att++;
        int i = sum/5;
        if (att == i*2)
        {
            for (int j = 0; j+i < 13; j++)
            {
                flag = true;
                for (int k = 0; k < i; k++)
                    if (tot[j+k] < 3)
                    {
                        flag = false;
                        break;
                    }
                if (flag == true)
                {
                    typ1 = 9;
                    typ2 = i;
                    val = j;
                    return;
                }
            }
        }
    }
    //10.  Bomb - four cards of the same rank. A bomb can beat everything except a rocket or a bomb with
    //higher rank.
    if (sum == 4)
    {
        for (int i = 0; i < 15; i++)
            if (tot[i] > 3)
            {
                typ1 = 10;
                typ2 = 1;
                val = i;
                return;
            }
    }
    //11.  Rocket - a pair of jokers. It is the highest combination and beats anything else, including bombs.
    if (sum == 2)
    {
        if (tot[13] == 1 && tot[14] == 1)
        {
            typ1 = 11;
            typ2 = 1;
            val = 1;
            return;
        }
    }
    //12.  Quadplex set - there are two types: a quad (four cards of the same rank) with two single cards of
    //different ranks attached, such as 6-6-6-6-8-9, or a quad with two pairs of different ranks attached,
    //such as J-J-J-J-9-9-Q-Q. 2 and jokers can be attached, but you cannot use both jokers in one quadplex
    //set. Quadplex sets are ranked according to the rank of the quad. Note that a quadplex set can only beat
    //a lower quadplex set of the same type, and cannot beat any other type of combination. Also a quadplex
    //set can be beaten by a bomb made of lower ranked cards.
    if (sum == 6)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 0)
                att++;
        if (tot[13] > 0 && tot[14] > 0)
            att--;
        if (att == 3)
            for (int i = 0; i < 15; i++)
                if (tot[i] > 3)
                {
                    typ1 = 12;
                    typ2 = 2;
                    val = i;
                    return;
                }
    }
    if (sum == 8)
    {
        att = 0;
        for (int i = 0; i < 15; i++)
            if (tot[i] > 1)
                att++;
        if (att == 3)
            for (int i = 0; i < 15; i++)
                if (tot[i] > 3)
                {
                    typ1 = 13;
                    typ2 = 2;
                    val = i;
                    return;
                }
    }
    typ1 = -1;
}

int typ1,typ2,val;

void GetMax(int id)
{
    for (int sta = 1;sta < (1<<17);sta++)
    {
        getinfo(id,17,sta,typ1,typ2,val);
        if (typ1 != -1)
            best[typ1][typ2] = max(best[typ1][typ2],val);
    }
}

void output(int sta)
{
    for (int i = 0; i < 20; i++)
        cout << "  " << (((sta>>i)&1) == 1);
    cout << endl;
}

bool inq[1<<20];
int can[1<<20];
queue<int> Q;

void PreBFS()
{
    for (int sta = 1; sta < (1<<20); sta++)
    {
        getinfo(0,20,sta,typ1,typ2,val);
        if (typ1 == -1)
            can[sta] = 0;//不合法
        else
        {
            if (best[11][1] == 1)
                can[sta] = 1;//对方有火箭
            else if (typ1 != 10 && best[10][1] != -1)
                can[sta] = 1;//对方有炸弹我们没有
            else if (val < best[typ1][typ2])
                can[sta] = 1;//对方比我们大
            else
                can[sta] = 2;//我们更大
        }
    }
}

bool check(int sta,int full)
{
    if (sta == full)
        return can[sta] != 0;
    return can[sta] == 2;
}

bool BFS()
{
    PreBFS();
    while (!Q.empty())
        Q.pop();
    int full = (1<<20)-1,now,sta,upd;
    memset(inq,false,sizeof(inq));
    inq[full] = true;
    Q.push(full);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now == 0)   return true;
        for (sta = now;sta > 0;sta = (sta-1)&now)
            if (inq[now-sta] == false)
                if (check(sta,now) == true)
                    if (inq[now-sta] == false)
                    {
                        inq[now-sta] = true;
                        Q.push(now-sta);
                    }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%s",tmp);
            for (int j = 0; j < strlen(tmp); j++)
                s[i][j] = getid(tmp[j]);
        }
        sort(s[0],s[0]+20);
        sort(s[1],s[1]+17);
        sort(s[2],s[2]+17);
        memset(best,-1,sizeof(best));
        for (int i = 1; i < 3; i++)
            GetMax(i);
        printf("Case %d: ",ft);
        if (BFS() == true)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
