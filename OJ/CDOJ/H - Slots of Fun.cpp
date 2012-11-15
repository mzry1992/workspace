#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y;
    char id;
    Point(){}
    Point(int _x,int _y,char _id)
        {
            x = _x;
            y = _y;
            id = _id;
        }
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
    int len()
        {
            return x*x+3*y*y;
        }
};

int n,cur;
char s[15*15];
bool res[26],flag;
Point mp[15*15];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%s",s);
        cur = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j <= i;j++)
            {
                mp[cur] = Point(n-1-i+2*j,(n-1-i),s[cur]);
                cur++;
            }
        n = n*(n+1)/2;
        memset(res,false,sizeof(res));
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                for (int k = j+1;k < n;k++)
                    if (mp[i].id == mp[j].id && mp[j].id == mp[k].id)
                        if (Point(mp[i],mp[j]).len() == Point(mp[i],mp[k]).len())
                            if (Point(mp[i],mp[k]).len() == Point(mp[k],mp[j]).len())
                                res[mp[i].id-'a'] = true;
        flag = false;
        for (int i = 0;i < 26;i++)
            if (res[i] == true)
            {
                flag = true;
                printf("%c",'a'+i);
            }
        if (flag == false)  printf("LOOOOOOOOSER!");
        printf("\n");
    }
    return 0;
}
