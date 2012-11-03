#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

char com[10];
int now,head,tail;
deque<pair<int,int> > Q;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        head = tail = 0;
        Q.clear();
        while (true)
        {
            scanf("%s",com);
            if (strcmp(com,"END") == 0) break;
            else if (strcmp(com,"C") == 0)
            {
                scanf("%*s%d",&now);
                while (true)
                {
                    if (Q.empty())  break;
                    if (Q.front().first <= now) Q.pop_front();
                    else    break;
                }
                Q.push_front(make_pair(now,tail++));
            }
            else if (strcmp(com,"G") == 0)
            {
                head++;
                while (true)
                {
                    if (Q.empty())  break;
                    if (Q.back().second < head)    Q.pop_back();
                    else    break;
                }
            }
            else if (strcmp(com,"Q") == 0)
            {
                if (Q.empty())  puts("-1");
                else    printf("%d\n",Q.back().first);
            }
            /*printf("Q : [");
            for (int i = 0;i < Q.size();i++)
                printf("(%d,%d) ",Q[i].first,Q[i].second);
            printf("]\n");*/
        }
    }
    return 0;
}
