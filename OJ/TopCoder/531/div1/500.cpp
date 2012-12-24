#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

class MonsterFarm
{
public:
    int numMonsters(vector <string>);
};

int n;
vector<pair<int,int> > ts[50];
vector<int> tmpts;
bool visit[50],end[50],need[50];

const int mod = 1000000007;

void DFS(int now)
{
    need[now] = true;
    for (int i = 0; i < ts[now].size(); i++)
        if (need[ts[now][i].first] == false)
            DFS(ts[now][i].first);
}

int MonsterFarm::numMonsters(vector <string> tr)
{
    n = tr.size();
    for (int i = 0; i < n; i++)
    {
        ts[i].clear();
        tmpts.clear();
        string tmp = tr[i];
        int num = 0;
        for (int j = 0; j <= tmp.length(); j++)
            if (j == tmp.length() || tmp[j] == ' ')
            {
                tmpts.push_back(num-1);
                num = 0;
            }
            else
                num = num*10+tmp[j]-'0';
        sort(tmpts.begin(),tmpts.end());
        int pre = 0;
        for (int j = 0; j <= tmpts.size(); j++)
            if (j == tmpts.size() || tmpts[j] != tmpts[pre])
            {
                ts[i].push_back(make_pair(tmpts[pre],j-pre));
                pre = j;
            }
    }
    memset(need,false,sizeof(need));
    DFS(0);
    for (int i = 0; i < n; i++)
        if (need[i] == true)
            if (ts[i].size() == 1)
            {
                memset(visit,false,sizeof(visit));
                int now = i;
                end[i] = true;
                while (true)
                {
                    visit[now] = true;
                    now = ts[i][0].first;
                    if (ts[now].size() > 1)
                    {
                        end[i] = false;
                        break;
                    }
                    if (visit[now] == true)
                    {
                        break;
                    }
                }
            }
    for (int i = 0;i < n;i++)
    {
        cout << i << ' ' << need[i] << ' ' << end[i] << " :";
        for (int j = 0;j < ts[i].size();j++)
            cout << "(" << ts[i][j].first << "," << ts[i][j].second << ") ";
        cout << endl;
    }
    while (true)
    {
        if (end[0] == true)
        {
            int num = 0;
            for (int i = 0;i < ts[0].size();i++)
                num = (num+ts[0][i].second)%mod;
            return num;
        }
        bool isend = true;
        for (int i = 0; i < n; i++)
            if (need[i] == true)
                if (end[i] == false)
                {
                    bool flag = true;
                    int num = 0;
                    for (int j = 0; j < ts[i].size(); j++)
                    {
                        if (end[ts[i][j].first] == false)
                        {
                            flag = false;
                            break;
                        }
                        num = (num+ts[i][j].second)%mod;
                    }
                    if (flag == true)
                    {
                        isend = false;
                        end[i] = true;
                        for (int j = 0; j < n; j++)
                            for (int k = 0; k < ts[j].size(); k++)
                                if (ts[j][k].first = i)
                                    ts[j][k].second = (int)(((long long)ts[j][k].second*(long long)num)%(long long)mod);
                    }
                }
        if (isend == true)  return -1;
    }
    return 0;
}

//Powered by [KawigiEdit] 2.0!

double test0()
{
    string t0[] = {"1"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    string t0[] = {"1 1"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    string t0[] = {"2", "3", "1"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    string t0[] = {"1", "3 4", "2", "2"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    string t0[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 24;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5()
{
    string t0[] = {"2 3","5 7","2 4","5","6","4","7"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    MonsterFarm * obj = new MonsterFarm();
    clock_t start = clock();
    int my_answer = obj->numMonsters(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main()
{
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
