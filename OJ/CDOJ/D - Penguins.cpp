#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a,b,c;
char aa[100],bb[100];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        a = b = c = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s%s",aa,bb);
            if (strcmp(aa,"Emperor") == 0)
                a++;
            else if (strcmp(aa,"Macaroni") == 0)
                b++;
            else
                c++;
        }
        if (a > b && a > c) printf("Emperor Penguin\n");
        if (b > a && b > c) printf("Macaroni Penguin\n");
        if (c > a && c > b) printf("Little Penguin\n");
    }
}
