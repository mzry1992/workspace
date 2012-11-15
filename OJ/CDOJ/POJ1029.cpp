#include <iostream>
#define LESS 0
#define EQUAL 1
#define GREATER 2
using namespace std;

int n,k,fk,i,j,tp[110],pl[110][1010],pr[110][1010],po[110],result,sumresult,result1,result2;
char order;
bool coin[1010],flag;

int main()
{
    cin >> n >> k;
    for (fk = 1;fk <= k;fk++)
    {
        cin >> tp[fk];
        for (i = 1;i <= tp[fk];i++)
            cin >> pl[fk][i];
        for (i = 1;i <= tp[fk];i++)
            cin >> pr[fk][i];
        cin >> order;
        if (order == '<')    po[fk] = LESS;
        if (order == '=')    po[fk] = EQUAL;
        if (order == '>')    po[fk] = GREATER;
    }
    flag = true;
    
    /*假设假硬币重量更小*/ 
    for (i = 1;i <= n;i++)
        coin[i] = false;
    for (fk = 1;fk <= k;fk++)
    {
        if (po[fk] == LESS)
        for (i = 1;i <= tp[fk];i++)
            coin[pr[fk][i]] = true;
        if (po[fk] == EQUAL)
        for (i = 1;i <= tp[fk];i++)
        {
            coin[pr[fk][i]] = true;
            coin[pl[fk][i]] = true;
        }
        if (po[fk] == GREATER)
        for (i = 1;i <= tp[fk];i++)
            coin[pl[fk][i]] = true;
    }
    sumresult = 0;
    for (i = 1;i <= n;i++)
    if (coin[i] == false)
    {
                result = i;
                sumresult++;
    }
    if (sumresult == 1)
                  result1 = result;
    else
                  result1 = 0;
                  
    /*假设假硬币重量更大*/ 
    for (i = 1;i <= n;i++)
        coin[i] = false;
    for (fk = 1;fk <= k;fk++)
    {
        if (po[fk] == GREATER)
        for (i = 1;i <= tp[fk];i++)
            coin[pr[fk][i]] = true;
        if (po[fk] == EQUAL)
        for (i = 1;i <= tp[fk];i++)
        {
            coin[pr[fk][i]] = true;
            coin[pl[fk][i]] = true;
        }
        if (po[fk] == LESS)
        for (i = 1;i <= tp[fk];i++)
            coin[pl[fk][i]] = true;
    }
    sumresult = 0;
    for (i = 1;i <= n;i++)
    if (coin[i] == false)
    {
                result = i;
                sumresult++;
    }
    if (sumresult == 1)
        result2 = result;
    else
        result2 = 0;
        
    if ((result1 == 0) && (result2 == 0))     cout << 0 << endl;
    if ((result1 != 0) && (result2 != 0))     cout << 0 << endl;
    if ((result1 != 0) && (result2 == 0))     cout << result1 << endl;
    if ((result1 == 0) && (result2 != 0))     cout << result2 << endl;
    system("pause");
    return 0;
}
