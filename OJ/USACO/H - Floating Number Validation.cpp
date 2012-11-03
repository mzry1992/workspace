#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10000];
int t[10000];//1 +- 2 num 3 . 4 eE
int tot;

int gettype(char c)
{
    if (c == '+' || c == '-')   return 1;
    if (c >= '0' && c <= '9')   return 2;
    if (c == '.')   return 3;
    if (c == 'e' || c == 'E')   return 4;
    return -1;
}

int main()
{
    while (true)
    {
        gets(s);
        if (strcmp(s,"#") == 0)    break;
        tot = 0;
        int len = strlen(s);
        int pret = 0;
        bool check = true;
        for (int i = 0;i < len;i++)
        {
            int ttype = gettype(s[i]);
            if (ttype == -1)
            {
                check = false;
                break;
            }
            if (ttype != pret)
            {
                tot++;
                t[tot] = ttype;
                pret = ttype;
            }
            else
            {
                if (ttype != 2)
                {
                    check = false;
                    break;
                }
            }
        }
        if (check == false)
        {
            printf("No\n");
            continue;
        }
        int hase = 0;
        int pose = 0;
        for (int i = 1;i <= tot;i++)
        if (t[i] == 4)
        {
            hase++;
            pose = i;
        }
        if (hase >= 2)
        {
            printf("No\n");
            continue;
        }
        if (hase == 0)
        {
            bool isnum = true;
            int cur = 0;
            int num = 0;
            int dot = 0;
            for (int i = 1;i <= tot;i++)
            {
                if (t[i] == 1)
                {
                    if (cur > 0)
                    {
                        isnum = false;
                        break;
                    }
                    else
                        cur++;
                }
                else
                {
                    if (t[i] == 2)  num++;
                    if (t[i] == 3)  dot++;
                    cur++;
                }
            }
            if (dot >= 2)   isnum = false;
            if (num == 0)   isnum = false;
            if (isnum == false)
                printf("No\n");
            else
                printf("Yes\n");
            continue;
        }
        else
        {
            bool isnum = true;
            int cur = 0;
            int num = 0;
            int dot = 0;
            for (int i = 1;i <= pose-1;i++)
            {
                if (t[i] == 1)
                {
                    if (cur > 0)
                    {
                        isnum = false;
                        break;
                    }
                    else
                        cur++;
                }
                else
                {
                    if (t[i] == 2)  num++;
                    if (t[i] == 3)  dot++;
                    cur++;
                }
            }
            if (dot >= 2)   isnum = false;
            if (num == 0)   isnum = false;
            if (isnum == false)
            {
                printf("No\n");
                continue;
            }
            isnum = true;
            if (pose+1 != tot)
            {
                if (pose+1 == tot-1)
                {
                    if (t[tot] != 2)    isnum = false;
                    if (t[tot-1] != 1)  isnum = false;
                }
                else if (pose+1 == tot-2)
                {
                    if (t[tot] != 2)    isnum = false;
                    if (t[tot-1] != 1)  isnum = false;
                    if (t[tot-2] != 2)    isnum = false;
                }
                else
                    isnum = false;
            }
            else
            {
                if (t[tot] != 2)    isnum = false;
            }
            if (isnum == false)
                printf("No\n");
            else
                printf("Yes\n");
            continue;
        }
    }
}
