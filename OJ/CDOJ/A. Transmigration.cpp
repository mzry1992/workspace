#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n,m,exp;
double k;
map<string,int> skill;
char nam[30];

int main()
{
    cout << 0.94*8700 << endl;
    while (scanf("%d%d%lf",&n,&m,&k) != EOF)
    {
        skill.clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%s%d",nam,&exp);
            cout << exp << endl;
            cout << (double)exp*k << endl;
            cout << (int)(double)exp*k << endl;
            exp = (int)((double)exp*k);
            cout << exp << endl;
            if (exp >= 100)
                skill[nam] = exp;
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%s",nam);
            if (skill.find(nam) == skill.end())
                skill[nam] = 0;
        }
        printf("%d\n",skill.size());
        for (map<string,int>::iterator it = skill.begin();it != skill.end();it++)
            printf("%s %d\n",it->first.c_str(),it->second);
    }
    return 0;
}
