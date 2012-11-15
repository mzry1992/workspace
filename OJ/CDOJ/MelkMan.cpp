#include <iostream>
#include <vector>
using namespace std;

int n;
struct point
{
    double x,y;
}p[1000];
vector<int> d;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= 3;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        d.clear();

    }
}
