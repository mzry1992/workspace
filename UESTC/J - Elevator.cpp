#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int UP = 0;
const int DOWN = 1;
const int STOP = 2;

struct Elevator
{
    int cur,sta;
}ele;

const int WAIT = 0;
const int IN = 1;
const int OUT = 2;

struct People
{
    int cur,sta,go,tim,dir;
}peo[101];
int totQ,Left;

void outputtim(int now)
{
    printf("%02d:%02d",now/60,now%60);
}

int main()
{
    //freopen("ele.in","r",stdin);
    //freopen("ele.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&ele.cur,&totQ);
        ele.sta = STOP;
        for (int i = 1;i <= totQ;i++)
        {
            scanf("%d%d%d",&peo[i].tim,&peo[i].cur,&peo[i].go);
            peo[i].sta = WAIT;
            peo[i].dir = (peo[i].go > peo[i].cur)?UP:DOWN;
        }
        Left = totQ;
        printf("Case %d:\n",ft);
        int now = 0;
        while (true)
        {
            //cout << Left << ' ' << now << ' ' << ele.cur << endl;
            //getchar();
            for (int i = 1;i <= totQ;i++)
                if (peo[i].sta != OUT)
                    cout << i << ' ' << peo[i].sta << ' ' << peo[i].tim << ' ' << peo[i].cur << ' ' << peo[i].go << endl;
            if (Left == 0)  break;
            if (ele.sta == STOP)
            {
                bool flag = false;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].tim <= now && peo[i].sta == WAIT && peo[i].cur == ele.cur)
                    {
                        int mintim = peo[i].tim;
                        for (int j = 1;j <= totQ;j++)
                            if (peo[j].tim < mintim && peo[j].sta == WAIT && peo[j].cur == ele.cur)
                                mintim = peo[j].tim;
                        int maxgo = 0;
                        for (int j = 1;j <= totQ;j++)
                            if (peo[j].tim == mintim && peo[j].sta == WAIT && peo[j].cur == ele.cur)
                                if (peo[j].go > maxgo)
                                    maxgo = peo[j].go;
                        int godir = (maxgo > ele.cur)?UP:DOWN;
                        while (true)
                        {
                            bool haspeople0 = false;
                            for (int j = 1;j <= totQ;j++)
                                if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                    haspeople0 = true;
                            if (haspeople0 == false)    break;
                            outputtim(now);
                            printf(" The elevator door is opening.\n");
                            now++;
                            while (true)
                            {
                                int totpeople = 0;
                                for (int j = 1;j <= totQ;j++)
                                    if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                    {
                                        peo[j].sta = IN;
                                        totpeople++;
                                    }
                                if (totpeople == 0) break;
                                outputtim(now);
                                printf(" %d people enter the elevator.\n",totpeople);
                                now++;
                            }
                            outputtim(now);
                            printf(" The elevator door is closing.\n");
                            now++;
                        }
                        outputtim(now);
                        if (godir == DOWN)
                            printf(" The elevator starts to move down from floor %d.\n",ele.cur);
                        else
                            printf(" The elevator starts to move up from floor %d.\n",ele.cur);
                        ele.sta = godir;
                        flag = true;
                        break;
                    }
                if (flag == true)
                    continue;
                bool haspeople = false;
                int mintim;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].tim <= now && peo[i].sta == WAIT)
                    {
                        haspeople = true;
                        mintim = peo[i].tim;
                    }
                if (haspeople == false)
                {
                    now++;
                    continue;
                }
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].tim < mintim && peo[i].sta == WAIT)
                        mintim = peo[i].tim;
                int maxgo = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].tim == mintim && peo[i].sta == WAIT && peo[i].cur > maxgo)
                        maxgo = peo[i].cur;
                int godir = (maxgo > ele.cur)?UP:DOWN;
                outputtim(now);
                if (godir == DOWN)
                    printf(" The elevator starts to move down from floor %d.\n",ele.cur);
                else
                    printf(" The elevator starts to move up from floor %d.\n",ele.cur);
                ele.sta = godir;
            }
            else if (ele.sta == UP)
            {
                ele.cur++;
                now++;
                int totpeople = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == IN)
                        totpeople++;
                int peoplein = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur == ele.cur && peo[i].dir == UP)
                        peoplein++;
                int peopleout = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == IN && peo[i].go == ele.cur)
                    {
                        peopleout++;
                        peo[i].sta = OUT;
                        Left--;
                    }
                if (totpeople == 0 && peoplein == 0)
                {
                    peoplein = 0;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur > ele.cur)
                            peoplein++;
                    if (peoplein != 0)  continue;
                    outputtim(now);
                    printf(" The elevator stops at floor %d.\n",ele.cur);
                    ele.sta = STOP;
                }
                else
                {
                    if (peoplein == 0 && peopleout == 0)  continue;
                    outputtim(now);
                    printf(" The elevator stops at floor %d.\n",ele.cur);
                    outputtim(now);
                    printf(" The elevator door is opening.\n");
                    now++;
                    if (peopleout != 0)
                    {
                        outputtim(now);
                        printf(" %d people leave the elevator.\n",peopleout);
                        now++;
                    }
                    bool doorsta = true;
                    int godir = UP;
                    bool haspeople = false;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == IN)
                            haspeople = true;
                    if (haspeople == false)
                    {
                        bool haspeoplein = false;
                        int mintim = 0;
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur == ele.cur)
                            {
                                haspeoplein = true;
                                mintim = peo[i].tim;
                            }
                        if (haspeoplein == false)
                        {
                            outputtim(now);
                            printf(" The elevator door is closing.\n");
                            now++;
                            ele.sta = STOP;
                            continue;
                        }
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].tim < mintim && peo[i].sta == WAIT && peo[i].cur == ele.cur)
                                mintim = peo[i].tim;
                        int maxgo = 0;
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].tim == mintim && peo[i].sta == WAIT && peo[i].cur == ele.cur && peo[i].go > maxgo)
                                maxgo = peo[i].go;
                        godir = (maxgo > ele.cur)?UP:DOWN;
                    }
                    while (true)
                    {
                        bool haspeople0 = false;
                        for (int j = 1;j <= totQ;j++)
                            if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                haspeople0 = true;
                        if (haspeople0 == false && doorsta == false)    break;
                        if (doorsta == false)
                        {
                            outputtim(now);
                            printf(" The elevator door is opening.\n");
                            now++;
                            doorsta = true;
                        }
                        while (true)
                        {
                            int totpeople = 0;
                            for (int j = 1;j <= totQ;j++)
                                if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                {
                                    peo[j].sta = IN;
                                    totpeople++;
                                }
                            if (totpeople == 0) break;
                            outputtim(now);
                            printf(" %d people enter the elevator.\n",totpeople);
                            now++;
                        }
                        outputtim(now);
                        printf(" The elevator door is closing.\n");
                        now++;
                        doorsta = false;
                    }
                    haspeople = false;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == IN)
                            haspeople = true;
                    if (haspeople == false)
                    {
                        ele.sta = STOP;
                        continue;
                    }
                    bool haspeopleUP = (godir == UP)?true:false;
                    outputtim(now);
                    if (haspeopleUP == true)
                        printf(" The elevator starts to move up from floor %d.\n",ele.cur);
                    else
                    {
                        printf(" The elevator starts to move down from floor %d.\n",ele.cur);
                        ele.sta = DOWN;
                    }
                }
            }
            else if (ele.sta == DOWN)
            {
                ele.cur--;
                now++;
                int totpeople = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == IN)
                        totpeople++;
                int peoplein = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur == ele.cur && peo[i].dir == DOWN)
                        peoplein++;
                int peopleout = 0;
                for (int i = 1;i <= totQ;i++)
                    if (peo[i].sta == IN && peo[i].go == ele.cur)
                    {
                        peopleout++;
                        peo[i].sta = OUT;
                        Left--;
                    }
                if (totpeople == 0 && peoplein == 0)
                {
                    peoplein = 0;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur < ele.cur)
                            peoplein++;
                    if (peoplein != 0)  continue;
                    outputtim(now);
                    printf(" The elevator stops at floor %d.\n",ele.cur);
                    ele.sta = STOP;
                }
                else
                {
                    if (peoplein == 0 && peopleout == 0)  continue;
                    outputtim(now);
                    printf(" The elevator stops at floor %d.\n",ele.cur);
                    outputtim(now);
                    printf(" The elevator door is opening.\n");
                    now++;
                    if (peopleout != 0)
                    {
                        outputtim(now);
                        printf(" %d people leave the elevator.\n",peopleout);
                        now++;
                    }
                    bool doorsta = true;
                    int godir = DOWN;
                    bool haspeople = false;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == IN)
                            haspeople = true;
                    if (haspeople == false)
                    {
                        bool haspeoplein = false;
                        int mintim = 0;
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].sta == WAIT && peo[i].tim <= now && peo[i].cur == ele.cur)
                            {
                                haspeoplein = true;
                                mintim = peo[i].tim;
                            }
                        if (haspeoplein == false)
                        {
                            outputtim(now);
                            printf(" The elevator door is closing.\n");
                            now++;
                            ele.sta = STOP;
                            continue;
                        }
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].tim < mintim && peo[i].sta == WAIT && peo[i].cur == ele.cur)
                                mintim = peo[i].tim;
                        int maxgo = 0;
                        for (int i = 1;i <= totQ;i++)
                            if (peo[i].tim == mintim && peo[i].sta == WAIT && peo[i].cur == ele.cur && peo[i].go > maxgo)
                                maxgo = peo[i].go;
                        godir = (maxgo > ele.cur)?UP:DOWN;
                    }
                    while (true)
                    {
                        bool haspeople0 = false;
                        for (int j = 1;j <= totQ;j++)
                            if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                haspeople0 = true;
                        if (haspeople0 == false && doorsta == false)    break;
                        if (doorsta == false)
                        {
                            outputtim(now);
                            printf(" The elevator door is opening.\n");
                            now++;
                            doorsta = true;
                        }
                        while (true)
                        {
                            int totpeople = 0;
                            for (int j = 1;j <= totQ;j++)
                                if (peo[j].tim <= now && peo[j].sta == WAIT && peo[j].cur == ele.cur && peo[j].dir == godir)
                                {
                                    peo[j].sta = IN;
                                    totpeople++;
                                }
                            if (totpeople == 0) break;
                            outputtim(now);
                            printf(" %d people enter the elevator.\n",totpeople);
                            now++;
                        }
                        outputtim(now);
                        printf(" The elevator door is closing.\n");
                        now++;
                        doorsta = false;
                    }
                    haspeople = false;
                    for (int i = 1;i <= totQ;i++)
                        if (peo[i].sta == IN)
                            haspeople = true;
                    if (haspeople == false)
                    {
                        ele.sta = STOP;
                        continue;
                    }
                    bool haspeopleDOWN = (godir == DOWN)?true:false;
                    outputtim(now);
                    if (haspeopleDOWN == false)
                    {
                        printf(" The elevator starts to move up from floor %d.\n",ele.cur);
                        ele.sta = UP;
                    }
                    else
                        printf(" The elevator starts to move down from floor %d.\n",ele.cur);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
