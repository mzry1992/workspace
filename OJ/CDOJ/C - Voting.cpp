#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100];
int Y,N,A,P;

int main()
{
    while (true)
    {
        scanf("%s",s);
        if (strcmp(s,"#") == 0) break;
        Y = N = A = P = 0;
        int l = strlen(s);
        for (int i = 0;i < l;i++)
        if (s[i] == 'Y')    Y++;
        else if (s[i] == 'N') N++;
        else if (s[i] == 'P') P++;
        else if (s[i] == 'A') A++;
        if (A*2 >= l)   printf("need quorum\n");
        else
        {
            if (Y > N)  printf("yes\n");
            else if (Y < N) printf("no\n");
            else printf("tie\n");
        }
    }
}
