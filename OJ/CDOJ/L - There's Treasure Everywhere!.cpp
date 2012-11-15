#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
using namespace std;

double curx,cury;
char s[210];
int len;
string fan;
map<string,pair<double,double> > dir;

int main()
{
    dir["N"] = make_pair(0.0,1.0);
    dir["NE"] = make_pair(sqrt(2.0)/2.0,sqrt(2.0)/2.0);
    dir["E"] = make_pair(1.0,0.0);
    dir["SE"] = make_pair(sqrt(2.0)/2.0,-sqrt(2.0)/2.0);
    dir["S"] = make_pair(0.0,-1.0);
    dir["SW"] = make_pair(-sqrt(2.0)/2.0,-sqrt(2.0)/2.0);
    dir["W"] = make_pair(-1.0,0.0);
    dir["NW"] = make_pair(-sqrt(2.0)/2.0,sqrt(2.0)/2.0);
    int ft = 0;
    while (true)
    {
        gets(s);
        if (strcmp(s,"END") == 0)   break;
        curx = cury = 0.0;
        len = strlen(s);
        for (int i = -1;i < len;i++)
            if (i == -1 || s[i] == ',')
            {
                int dis = 0;
                for (int j = i+1;;j++)
                    if (s[j] >= '0' && s[j] <= '9')
                        dis = dis*10+s[j]-'0';
                    else
                    {
                        fan = "";
                        for (int k = j;k < len && s[k] != ',' && s[k] != '.';k++)
                            fan += s[k];
                        break;
                    }
                //cout << dis << ' ' << fan << endl;
                curx += dis*dir[fan].first;
                cury += dis*dir[fan].second;
            }
        ft++;
        printf("Map #%d\n",ft);
        printf("The treasure is located at (%.3f,%.3f).\n",curx,cury);
        printf("The distance to the treasure is %.3f.\n",sqrt(curx*curx+cury*cury));
        printf("\n");
    }
    return 0;
}
