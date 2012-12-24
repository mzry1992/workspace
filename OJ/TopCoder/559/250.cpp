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

class HyperKnight
{
public:
    long long countCells(int, int, int, int, int);
};

int step[8][2];

long long HyperKnight::countCells(int a, int b, int numRows, int numColumns, int k)
{
    step[0][0] = a;
    step[0][1] = b;
    step[1][0] = a;
    step[1][1] = -b;
    step[2][0] = -a;
    step[2][1] = b;
    step[3][0] = -a;
    step[3][1] = -b;
    step[4][0] = b;
    step[4][1] = a;
    step[5][0] = b;
    step[5][1] = -a;
    step[6][0] = -b;
    step[6][1] = a;
    step[7][0] = -b;
    step[7][1] = -a;

    long long res = 0;
    int full = (1<<8);
    for (int i = 0; i < full; i++)
    {
        int cntbit = 0;
        for (int j = 0; j < 8; j++)
            if (((i>>j)&1) == 1)
                cntbit++;
        if (cntbit == k)
        {
            int minx,miny,maxx,maxy;
            minx = miny = maxx = maxy = 0;
            for (int j = 0; j < 8; j++)
                if (((i>>j)&1) == 1)
                {
                    minx = min(minx,step[j][0]);
                    miny = min(miny,step[j][1]);
                    maxx = max(maxx,step[j][0]);
                    maxy = max(maxy,step[j][1]);
                }

            bool flag = true;
            for (int j = 0; j < 8; j++)
                if (((i>>j)&1) == 0)
                {
                    if (minx <= step[j][0] && step[j][0] <= maxx &&
                            miny <= step[j][1] && step[j][1] <= maxy)
                        flag = false;
                }

            if (flag == true)
            {


                for (int j = 0; j < 8; j++)
                    printf("%d",(((i>>j)&1)));
                printf("\n");
                printf("(%d, %d) (%d, %d)\n",minx,maxx,miny,maxy);

                long long cnt = (long long)(numRows+minx-maxx)*(numColumns+miny-maxy);

				printf("cnt = %lld\n",cnt);

				int tminx,tminy,tmaxx,tmaxy;
				tminx = tminy = -1000000000;
				tmaxx = tmaxy = 1000000000;

                for (int j = 0; j < 8; j++)
                    if (((i>>j)&1) == 0)
                    {
                        if (step[j][0] < 0)
                            tminx = max(tminx,step[j][0]);
                        else
                            tmaxx = min(tmaxx,step[j][0]);

                        if (step[j][1] < 0)
                            tminy = max(tminy,step[j][1]);
                        else
                            tmaxy = min(tmaxy,step[j][1]);
                    }

//				tminx = min(tminx,minx);
//				tminy = min(tminy,miny);
//				tmaxx = max(tmaxx,maxx);
//				tmaxy = max(tmaxy,maxy);

                printf("(%d, %d) (%d, %d)\n",tminx,tmaxx,tminy,tmaxy);

                int rows = numRows+tminx-tmaxx;
                int cols = numColumns+tminy-tmaxy;
                if (rows > 0 && cols > 0)
                    cnt -= (long long)rows*cols;

				printf("cnt = %lld\n",cnt);
                res += cnt;
            }

        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int p0 = 2;
    int p1 = 1;
    int p2 = 8;
    int p3 = 8;
    int p4 = 4;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 20LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 3;
    int p1 = 2;
    int p2 = 8;
    int p3 = 8;
    int p4 = 2;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 16LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 1;
    int p1 = 3;
    int p2 = 7;
    int p3 = 11;
    int p4 = 0;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 0LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 3;
    int p1 = 2;
    int p2 = 10;
    int p3 = 20;
    int p4 = 8;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 56LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 1;
    int p1 = 4;
    int p2 = 100;
    int p3 = 10;
    int p4 = 6;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 564LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 2;
    int p1 = 3;
    int p2 = 1000000000;
    int p3 = 1000000000;
    int p4 = 8;
    HyperKnight * obj = new HyperKnight();
    clock_t start = clock();
    long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p5 = 999999988000000036LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
