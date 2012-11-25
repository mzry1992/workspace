#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int A[200200];
char a[100100],s[200200],tab[26],b[30];
int la,ls;

void doit()
{
    int j = 0;
    while (s[j] == s[j+1])
        j++;
    A[1] = j;
    int k = 1;
    for (int i = 2;i < ls;i++)
    {
        int Len = k+A[k]-1,L = A[i-k];
        if (L < Len-i+1)
            A[i] = L;
        else
        {
            j = max(0,Len-i+1);
            while (s[i+j] == s[j])
                j++;
            A[i] = j,k = i;
        }
    }
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	//gets(b);
	while (totcas--)
	{
	    scanf("%s%s",b,a);
	    //gets(b);
	    //gets(a);
	    for (int i = 0;i < 26;i++)
            tab[b[i]-'a'] = i+'a';
        la = strlen(a);
        ls = 0;
        for (int i = 0;i < la;i++)
            s[ls++] = tab[a[i]-'a'];
        s[ls++] = '$';
        for (int i = 0;i < la;i++)
            s[ls++] = a[i];
        s[ls] = 0;
        doit();
        int op = la+1+(la+1)/2;
        bool flag = false;
        for (int i = op;i < ls;i++)
            if (A[i] == ls-i)
            {
                ls = 0;
                for (int j = 0;j < (i-la)-1;j++)
                    s[ls++] = a[j];
                for (int j = 0;j < (i-la)-1;j++)
                    s[ls++] = tab[a[j]-'a'];
                s[ls] = 0;
                for (int j = i-la-1;j < la;j++)
                    while (b[a[j]-'a'] != a[j-(i-la-1)])
                        puts("fuck");
                flag = true;
                break;
            }
        if (!flag)
        {
            ls = 0;
            for (int i = 0;i < la;i++)
                s[ls++] = a[i];
            for (int i = 0;i < la;i++)
                s[ls++] = tab[a[i]-'a'];
            s[ls] = 0;
        }
        puts(s);
	}
	return 0;
}
