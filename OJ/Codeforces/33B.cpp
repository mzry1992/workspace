#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100100],b[100100],sa[5],sb[5];
int mp[30][30];
int len,n,sw;

int main()
{
    while (scanf("%s%s",a,b) != EOF)
    {
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                mp[i][j] = 19921005;
        for (int i = 0;i < 26;i++)
            mp[i][i] = 0;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s%s%d",sa,sb,&sw);
            mp[sa[0]-'a'][sb[0]-'a'] = min(mp[sa[0]-'a'][sb[0]-'a'],sw);
        }
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (mp[i][j] > mp[i][k]+mp[k][j])
                        mp[i][j] = mp[i][k]+mp[k][j];
        len = strlen(a);
        if (len != strlen(b))
        {
            puts("-1");
            continue;
        }
        int bv,res;
        char best;
        res = 0;
        bool hasres = true;
        for (int i = 0; i < len; i++)
            if (a[i] != b[i])
            {
                bv = 19921005;
                for (int j = 0; j < 26; j++)
                    if (mp[a[i]-'a'][j] < 19921005 && mp[b[i]-'a'][j] < 19921005)
                    {
                        if (bv > mp[a[i]-'a'][j]+mp[b[i]-'a'][j])
                        {
                            bv = mp[a[i]-'a'][j]+mp[b[i]-'a'][j];
                            best = 'a'+j;
                        }
                    }
                if (bv == 19921005)
                {
                    hasres = false;
                    break;
                }
                a[i] = best;
                res += bv;
            }
        if (hasres == false)
            puts("-1");
        else
        {
            printf("%d\n",res);
            puts(a);
        }
    }
    return 0;
}
