#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const string yy = "aiueo";

bool check(string a)
{
    int tot1;
    tot1 = 0;
    bool flag[10000];
    memset(flag,false,sizeof(flag));
    for (int i = 0;i < a.size();i++)
        for (int j = 0;j < yy.size();j++)
            if (a[i] == yy[j])
            {
                tot1++;
                flag[i] = true;
            }
    if (tot1 == 0)
        return false;
    if (a.size() >= 3)
    for (int i = 0;i < a.size()-2;i++)
        if ((flag[i] == flag[i+1]) && (flag[i+1] == flag[i+2]))
            return false;
    if (a.size() >= 2)
    for (int i = 0;i < a.size()-1;i++)
        if (a[i] != 'e')
            if (a[i] != 'o')
                if (a[i] == a[i+1])
                    return false;
    return true;
}

int main()
{
    string a;
    while (true)
    {
        cin >> a;
        if (a == "end") break;
        if (check(a))
            cout << '<' << a << "> is acceptable." << endl;
        else
            cout << '<' << a << "> is not acceptable." << endl;
    }
}
