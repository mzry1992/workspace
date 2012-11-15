#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const char g[100][5] =
{"H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu",
"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr",
"Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
"Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
"W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb",
"Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
"U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm" };

int main()
{
    cout << 17 << ' ' << 17 << endl;
    int a[20];
    for (int i = 1;i <= 17;i++)
    {
        a[i] = rand()%50+1;
        cout << g[a[i]-1] << ' ';
    }
    cout << endl;
    int cur = 1;
    while (true)
    {
        int tot = rand()%7+4;
        if (cur+tot > 17)   tot = 17-cur+1;
        int sum = 0;
        for (int i = cur;i <= cur+tot-1;i++)
            sum += a[i];
        //cout << cur << ' ' << tot << ' ' << cur+tot-1 << endl;
        if (cur > 17)   break;
        if (sum > 100)  continue;
        cout << g[sum-1] << ' ';
        cur = cur+tot;
    }
    cout << endl;
}
