#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char mp[2000][2000];
int n,m;

void addedge(int xa,int ya,int xb,int yb)
{
    xa *= 2;
    ya *= 2;
    xb *= 2;
    yb *= 2;
    if (xa == xb)
        mp[xa][ya+1] = '-';
    else if (ya == yb)
        mp[xa+1][ya] = '|';
    else if (xa < xb)
        mp[xa+1][ya+1] = '\\';
    else
        mp[xa-1][ya+1] = '/';
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        bool sp = false,find = true;
        for (int i = 0;i < 1200;i++)
            for (int j = 0;j < 1200;j++)
                mp[i][j] = ' ';
        for (int i = 0;i < 1200;i += 2)
            for (int j = 0;j < 1200;j += 2)
                mp[i][j] = 'o';

        if (n%2 != 0 && m%2 != 0)
            find = false;
        else if (n == 2 && m == 2)
        {
            addedge(0,0,0,1);
            addedge(0,0,1,0);
            addedge(1,0,1,1);
            addedge(0,1,1,1);
        }
        else if (n%4 == 0 || m%4 == 0)
        {
            if (n == 4 || m%4 != 0)
            {
                swap(n,m);
                sp = !sp;
            }
            for (int i = 0;i < n;i++)
            {
                if (i != 1)
                {
                    addedge(i,0,i,1);
                    addedge(i,m-2,i,m-1);
                }
                if (i%2 == 0)
                {
                    addedge(i,0,i+1,0);
                    addedge(i,m-1,i+1,m-1);
                }
                if (i == 1)
                {
                    addedge(i,0,i+1,1);
                    addedge(n-3,m-2,n-2,m-1);
                }
                if (i > 1 && i%2 == 1)
                {
                    addedge(i,1,i+1,1);
                    addedge(n-1-i,m-2,n-i,m-2);
                }
                if (i == 0)
                    addedge(i,1,i+1,1);
                if (i == 1 || i == n-1)
                    addedge(i,1,i-1,2);

            }

            for (int i = 2;i < m-2;i += 4)
            {
                addedge(0,i,0,i+1);
                addedge(0,i+2,0,i+3);
                addedge(1,i+1,1,i+2);
                addedge(1,i+3,1,i+4);
                for (int j = 0;j < 4;j++)
                    addedge(0,i+j,1,i+j);

                for (int j = 2;j < n-2;j ++)
                {
                    addedge(j,i,j,i+1);
                    addedge(j,i,j+1,i+1);
                }
                addedge(n-2,i,n-1,i);
                addedge(n-1,i,n-1,i+1);
                addedge(n-2,i+1,n-1,i+1);
                addedge(2,i+1,3,i+2);

                addedge(2,i+2,3,i+2);
                addedge(2,i+2,2,i+3);
                addedge(2,i+3,3,i+3);
                for (int j = 4;j < n;j++)
                {
                    addedge(j,i+2,j-1,i+3);
                    addedge(j,i+2,j,i+3);
                }
                addedge(n-1,i+3,n-2,i+4);
            }
        }

        if (find == false)
            puts("No");
        else
        {
            puts("Yes");
            if (sp == false)
            {
                for (int i = 0;i < 2*n-1;i++,puts(""))
                    for (int j = 0;j < 2*m-1;j++)
                        putchar(mp[i][j]);
            }
            else
            {
                for (int i = 0;i < 2*m-1;i++,puts(""))
                    for (int j = 0;j < 2*n-1;j++)
                    {
                        if (mp[j][i] == '-')
                            mp[j][i] = '|';
                        else if (mp[j][i] == '|')
                            mp[j][i] = '-';
                        putchar(mp[j][i]);
                    }
            }
        }
    }
	return 0;
}
