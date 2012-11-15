#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[20],n,s[20],top;

int col(int a)
{
    if (a >= n) return 1;
    return 0;
}

int val(int a)
{
    return a%n;
}

bool play()
{
    top = 0;
    for (int i = 0;i < 2*n;i++)
    {
        s[top++] = a[i];
    }
        while (true)
        {
            bool flag = false;
            for (int i = 0;i < top-2;i++)
                if (col(s[i]) == col(s[i+2]) ||
                    val(s[i]) == val(s[i+2]))
                    {
                        flag = true;
                        for (int j = i+1;j < top;j++)
                            s[j-1] = s[j];
                        top--;
                        break;
                    }
            if (flag == false)  break;
        }
    if (top == 2)   return true;
    return false;
}

int main()
{
    for (n = 1;n <= 8;n++)
    {
        for (int i = 0;i < 2*n;i++)   a[i] = i;
        sort(a,a+2*n);
        int resa,resb;
        resa = resb = 0;
        do
        {
            resa++;
            if (play() == true) resb++;
        }
        while (next_permutation(a,a+2*n));
        printf("%d %d %d\n",n,resb,resa);
    }
}
