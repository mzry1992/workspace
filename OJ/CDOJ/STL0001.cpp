#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;

vector<int> a;
int i,tot;

int main()
{
    tot = 0;
    while (true)
    {
          cin >> i;
          if (i == 0) break;
          tot++;
          a.push_back(i);
    }
    for (i = 0;i < tot;i++)
        cout << a[i] << endl;
    system("pause");
    return 0;
}
