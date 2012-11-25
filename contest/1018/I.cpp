#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int d[10] = {6,2,5,5,4,5,6,3,7,6};
const int c[10][10] = {{6,2,4,4,3,4,5,3,6,5},
    {2,2,1,2,2,1,1,2,2,2},
    {4,1,5,4,2,3,4,2,5,4},
    {4,2,4,5,3,4,4,3,5,5},
    {3,2,2,3,4,3,3,2,4,4},
    {4,1,3,4,3,5,5,2,5,5},
    {5,1,4,4,3,5,6,2,6,5},
    {3,2,2,3,2,2,2,3,3,3},
    {6,2,5,5,4,5,6,3,7,6},
    {5,2,4,5,4,5,5,3,6,6}
};
int n,n2,tmp;
char s[300000];

bool Gao()
{
    tmp = 0;
    for (int i = n2-1; i >= n; i--)
    {
        for (int j = s[i]-'0'+1; j < 10; j++)
            if (c[j][s[i-n]-'0']+tmp > c[s[i]-'0'][s[i-n]-'0'])
            {
                tmp -= c[s[i]-'0'][s[i-n]-'0']-c[j][s[i-n]-'0'];
                s[i] = '0'+j;
                for (int k = i+1; k < n2; k++)
                    for (int q = 0; q < 10; q++)
                        if (c[s[k-n]-'0'][q]+tmp > c[s[k]-'0'][s[k-n]-'0'])
                        {
                            tmp -= c[s[k]-'0'][s[k-n]-'0']-c[s[k-n]-'0'][q];
                            s[k] = '0'+q;
                            break;
                        }
                return true;
            }
        tmp += c[8][s[i-n]-'0']-c[s[i]-'0'][s[i-n]-'0'];
        s[i] = '8';
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = s[i]-'0'+1; j < 10; j++)
            if (c[j][s[i+n]-'0']+tmp > c[s[i]-'0'][s[i+n]-'0'])
            {
                tmp -= c[s[i]-'0'][s[i+n]-'0']-c[j][s[i+n]-'0'];
                s[i] = '0'+j;
                //cout << tmp << endl;
                //cout << tmp << endl;
                for (int k = i+1;k < n;k++)
                    for (int q = 0; q < 10; q++)
                        if (c[s[k+n]-'0'][q]+tmp > c[s[k]-'0'][s[k+n]-'0'])
                        {
                            tmp -= c[s[k]-'0'][s[k+n]-'0']-c[s[k+n]-'0'][q];
                            s[k] = '0'+q;
                            break;
                        }
                for (int k = n; k < n2; k++)
                    for (int q = 0; q < 10; q++)
                        if (c[s[k-n]-'0'][q]+tmp > c[s[k]-'0'][s[k-n]-'0'])
                        {
                            tmp -= c[s[k]-'0'][s[k-n]-'0']-c[s[k-n]-'0'][q];
                            s[k] = '0'+q;
                            break;
                        }
                return true;
            }
        tmp += c[8][s[i+n]-'0']-c[s[i]-'0'][s[i+n]-'0'];
        s[i] = '8';
    }
    return false;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (scanf("%s",s) != EOF)
    {
        n2 = strlen(s);
        n = n2/2;
        if (Gao() == false)
            puts("-1");
        else
            puts(s);
    }
    return 0;
}

