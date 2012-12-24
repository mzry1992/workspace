#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int b0,b1,b2,b3,b4,n,res;

void Add(int& b)
{
    b++;
    res++;
}

void Empty(int& b)
{
    b = 0;
}

void Remove(int& b)
{
    b--;
}

void Move(int& a,int& b)
{
    b += a;
    res += a;
    a = 0;
}

void Gao()
{
    res = 0;

    b0 = n;
    b1 = b2 = b3 = b4 = 0;

    Add(b1);

    while (true)
    {
        if (res > 1000000)  return;
        Add(b1);
        Empty(b4);
        while (b0 > 0)
        {
            while (b0 > 0 && b1 > 0)
            {
                Remove(b0);
                Remove(b1);
                Add(b2);
                Add(b3);
            }
            Add(b4);
            if (b0 == 0 && b1 == 0)
            {
                Move(b3,b4);
                return;
            }
            Move(b3,b1);
        }
        Move(b2,b0);
    }
}

void Gao2()
{
    res = 0;
    b0 = n;
    b1 = b2 = b3 = b4 = 0;
    b1++;
    res++;

    while (true)
    {
        if (res > 1000000000)  return;
        b1++;
        res++;
        b4 = 0;
        while (b0 > 0)
        {
            int tmp = min(b0,b1);
            b0 -= tmp;
            b1 -= tmp;
            b2 += tmp;
            res += tmp;
            b3 += tmp;
            res += tmp;
            b4++;
            res++;
            if (b0 == 0 && b1 == 0)
            {
                b4 += b3;
                res += b3;
                b3 = 0;
                return;
            }
            b1 += b3;
            res += b3;
            b3 = 0;
        }
        b0 += b2;
        res += b2;
        b2 = 0;
    }
}

int main()
{
    /*for (n = 2;n < 100;n += 2)
    {
        Gao2();
        printf("%d %d\n",n,res);
    }*/
    /*for (int i = 1; i < 10; i++)
    {
        n = i*10;
        for (int j = 0; j < 7; j++)
        {
            n = n+5;
            Gao2();
            printf("%d : %d\n",n,res);
            n = n-5;
            n = n*10;
        }
    }*/
    while (scanf("%d",&n) != EOF)
    {
        Gao2();
        printf("%d : %d\n",n,res);
    }
    return 0;
}
