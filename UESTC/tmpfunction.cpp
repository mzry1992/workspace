#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

struct combination
{
    int sta,typ1,typ2,val;
    combination() {}
    combination(int _sta,int _typ1,int _typ2,int _val)
    {
        sta = _sta;
        typ1 = _typ1;
        typ2 = _typ2;
        val = _val;
    }
};

combination c[1<<20];
int totc;

int best[14][20];

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

//i连续出现了j次的sta
int seq[15][5],sta,att[20],totatt,attsta;
bool used[15],flag;
int catt[20];

//void getallatt(sta,1,8,j-i+1,0,-1)
void getallatt(int sta,int typ0,int typ1,int typ2,int val,int now,int last)
{
    if (now == typ2)
    {
        if (catt[now-1] == 14 && catt[now-2] == 13) return;
        attsta = 0;
        for (int i = 0; i < typ2; i++)
            attsta = attsta|seq[catt[i]][typ0];
        c[totc++] = combination(attsta|sta,typ1,typ2,val);
    }
    else
    {
        for (int j = last+1; j < totatt; j++)
        {
            catt[now] = att[j];
            getallatt(sta,typ0,typ1,typ2,val,now+1,j);
        }
    }
}

void getall(int id,int len)
{
    totc = 0;
    memset(seq,0,sizeof(seq));
    for (int i = 0; i < len; i++)
        if (i == 0 || s[id][i] != s[id][i-1])
        {
            //3 4 4 4
            //  ^
            sta = 0;
            for (int j = i; j < len && s[id][j] == s[id][i]; j++)
            {
                sta = sta|(1<<j);
                seq[s[id][i]][j-i+1] = sta;
            }
        }
    //0.  Single card - ranking from 3 (low) up to red joker (high) as explained above.
    for (int i = 0; i < 15; i++)
        if (seq[i][1] > 0)
            c[totc++] = combination(seq[i][1],0,1,i);
    //1.  Pair - two cards of the same rank, from 3 (low) up to 2 (high), for example 3-3, A-A.
    for (int i = 0; i < 15; i++)
        if (seq[i][2] > 0)
            c[totc++] = combination(seq[i][2],1,1,i);
    //2.  Triplet - three cards of the same rank, for example 9-9-9.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            c[totc++] = combination(seq[i][3],2,1,i);
    //3.  Triplet with an attached card - a triplet with a single card added, the single card must
    //be different from the triplet, for example 6-6-6-8. These rank according to the rank of the
    //triplet - so for example 9-9-9-3 beats 8-8-8-A.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = 0; j < 15; j++)
                if (i != j && seq[j][1] > 0)
                {
                    sta = seq[i][3]|seq[j][1];
                    c[totc++] = combination(sta,3,1,i);
                }
    //4.  Triplet with an attached pair - a triplet with a pair added, the ranking being determined
    //by the rank of the triplet - for example Q-Q-Q-6-6 beats 10-10-10-K-K.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = 0; j < 15; j++)
                if (i != j && seq[j][2] > 0)
                {
                    sta = seq[i][3]|seq[j][2];
                    c[totc++] = combination(sta,4,1,i);
                }
    //5.  Sequence - at least five cards of consecutive rank, from 3 up to ace - for example 8-9-10-J-Q. 2 and
    //jokers cannot be used.
    for (int i = 0; i < 15; i++)
        if (seq[i][1] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][1] > 0; j++)
            {
                sta = sta|seq[j][1];
                if (j-i+1 >= 5)
                    c[totc++] = combination(sta,5,j-i+1,i);
            }
        }
    //6.  Sequence of pairs - at least three pairs of consecutive ranks, from 3 up to A. 2 and jokers cannot be
    //used. For example 10-10-J-J-Q-Q-K-K.
    for (int i = 0; i < 15; i++)
        if (seq[i][2] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][2] > 0; j++)
            {
                sta = sta|seq[j][2];
                if (j-i+1 >= 3)
                    c[totc++] = combination(sta,6,j-i+1,i);
            }
        }
    //7.  Sequence of triplets - at least two triplets of consecutive ranks from 3 up to A. 2 cannot be used.
    //For example 4-4-4-5-5-5.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
        {
            sta = 0;
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
            {
                sta = sta|seq[j][3];
                if (j-i+1 >= 2)
                    c[totc++] = combination(sta,7,j-i+1,i);
            }
        }
    //8.  Sequence of triplets with attached cards - an extra card is added to each triplet. Only the triplets
    //have to be in sequence, for example 7-7-7-8-8-8-3-6. The attached cards must be different from all the
    //triplets and from each other. Although triplets of 2 cannot be included in the triplets sequence, a 2 or
    //a joker or one of each can be attached, but not both jokers.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
                if (j-i+1 >= 2)
                {
                    flag = true;
                    memset(used,false,sizeof(used));
                    sta = 0;
                    for (int k = i; k <= j; k++)
                    {
                        sta = sta|seq[k][3];
                        used[k] = true;
                    }
                    totatt = 0;
                    for (int k = 0; k < 15; k++)
                        if (seq[k][1] > 0 && used[k] == false)
                            att[totatt++] = k;
                    if (totatt >= j-i+1)
                        getallatt(sta,1,8,j-i+1,i,0,-1);
                }
    //9.  Sequence of triplets with attached pairs - an extra pair is attached to each triplet. Only the
    //triplets have to be in sequence - for example 8-8-8-9-9-9-4-4-J-J. The pairs must be different in rank
    //from each other and from all the triplets. Although triplets of 2 cannot be included in the triplets
    //sequence, a pair of 2 can be attached. Note that attached single cards and attached pairs cannot be
    //mixed - for example 3-3-3-4-4-4-6-7-7 is not valid.
    for (int i = 0; i < 15; i++)
        if (seq[i][3] > 0)
            for (int j = i; j < 12 && seq[j][3] > 0; j++)
                if (j-i+1 >= 2)
                {
                    flag = true;
                    memset(used,false,sizeof(used));
                    sta = 0;
                    for (int k = i; k <= j; k++)
                    {
                        sta = sta|seq[k][3];
                        used[k] = true;
                    }
                    totatt = 0;
                    for (int k = 0; k < 15; k++)
                        if (seq[k][2] > 0 && used[k] == false)
                            att[totatt++] = k;
                    if (totatt >= j-i+1)
                        getallatt(sta,2,9,j-i+1,i,0,-1);
                }
    //10.  Bomb - four cards of the same rank. A bomb can beat everything except a rocket or a bomb
    //with higher rank.
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
            c[totc++] = combination(seq[i][4],10,1,i);
    //11.  Rocket - a pair of jokers. It is the highest combination and beats anything else, including
    //bombs.
    if (seq[13][1] > 0 && seq[14][1] > 0)
        c[totc++] = combination(seq[13][1]|seq[14][1],11,1,1);
    //12.  Quadplex set - there are two types: a quad (four cards of the same rank) with two single cards of
    //different ranks attached, such as 6-6-6-6-8-9, or a quad with two pairs of different ranks attached,
    //such as J-J-J-J-9-9-Q-Q. 2 and jokers can be attached, but you cannot use both jokers in one quadplex
    //set. Quadplex sets are ranked according to the rank of the quad. Note that a quadplex set can only beat
    //a lower quadplex set of the same type, and cannot beat any other type of combination. Also a quadplex
    //set can be beaten by a bomb made of lower ranked cards.
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
        {
            sta = seq[i][4];
            totatt = 0;
            for (int k = 0; k < 15; k++)
                if (k != i && seq[k][1] > 0)
                    att[totatt++] = k;
            if (totatt >= 2)
                getallatt(sta,1,12,2,i,0,-1);
        }
    for (int i = 0; i < 15; i++)
        if (seq[i][4] > 0)
        {
            sta = seq[i][4];
            totatt = 0;
            for (int k = 0; k < 15; k++)
                if (k != i && seq[k][2] > 0)
                    att[totatt++] = k;
            if (totatt >= 2)
                getallatt(sta,2,13,2,i,0,-1);
        }
}

void output(int sta)
{
    for (int i = 0; i < 20; i++)
        cout << (((sta>>i)&1) == 1);
    cout << endl;
}

int main()
{
    while (scanf("%s",tmp) != EOF)
    {
        int len = strlen(tmp);
        for (int i = 0;i < len;i++)
            s[0][i] = getid(tmp[i]);
        sort(s[0],s[0]+len);
        getall(0,len);
        for (int i = 0;i < totc;i++)
        {
            output(c[i].sta);
            cout << c[i].typ1 << ' ' << c[i].typ2 << ' ' << c[i].val << endl;
        }
    }
    return 0;
}

