#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//PTS OFF DEF REB AST STL BLK PF FGM-A 3PM-A FTM-A
const int PTS = 0;
const int OFF = 1;
const int DEF = 2;
const int REB = 3;
const int AST = 4;
const int STL = 5;
const int BLK = 6;
const int PF  = 7;
const int FGM = 8;
const int FGMA = 9;
const int PM3 = 10;
const int PM3A = 11;
const int FTM = 12;
const int FTMA = 13;

char Aname[30],Bname[30];
char Alist[12][30],Blist[12][30];
int Apoints,Bpoints;
bool ADNP[12],BDNP[12];
int A[12][14],B[12][14];
char comd[30];
char x1[30],x2[30],x[30];
int m,M,curhold,prehold;

void output(char name[30],char list[12][30],bool DNP[12],int p[12][14])
{
    char tmp[30];
    printf("%s\n",name);
    //header
    printf("              PLAYER PTS OFF DEF REB AST STL BLK PF FGM-A 3PM-A FTM-A\n");
    for (int i = 0; i < 12; i++)
    {
        printf("%20s",list[i]);
        if (DNP[i] == true)
            printf("          DNP - Coach's Decision");
        else
        {
            for (int j = PTS; j < PF; j++)
                printf("%4d",p[i][j]);
            printf("%3d",p[i][PF]);
            for (int j = FGM; j <= FTM; j += 2)
            {
                sprintf(tmp,"%d-%d",p[i][j],p[i][j+1]);
                printf("%6s",tmp);
            }
        }
        printf("\n");
    }
}

int GetId(char name[30])
{
    for (int i = 0; i < 12; i++)
        if (strcmp(Alist[i],name) == 0) return i;
    for (int i = 0; i < 12; i++)
        if (strcmp(Blist[i],name) == 0) return 12+i;
}

void Hold()
{
    //hold毛时要用啊？
    //after jump ball or
    //after a shot was made (including the last free throw) or
    //after a shot was blocked or
    //after timeout.
    scanf("%s%*s%*s",x);
    prehold = curhold;
    curhold = GetId(x); //0-11 A 12-23 B
}

void Jump()
{
    //Jump Ball x1 vs x2
    //你们抢个毛的球
    scanf("%*s%s%*s%s",x1,x2);
    Hold();
}

//These messages will only be given when someone is currently holding the ball.
//These messages may be followed by "Made"/"Missed"/"Blocked by x"/"x Foul".

void Shot(int val)
{
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%s%*s%s",Aname,Bname);
        for (int i = 0; i < 12; i++)
            scanf("%s",Alist[i]);
        for (int i = 0; i < 12; i++)
            scanf("%s",Blist[i]);
        //init
        Apoints = Bpoints = 0;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for (int i = 0; i < 12; i++)
            ADNP[i] = BDNP[i] = true;
        for (int i = 0; i < 5; i++)
            ADNP[i] = BDNP[i] = false;
        curhold = -1;
        //Gao!
        scanf("%*d");
        while (true)
        {
            scanf("%s",comd);
            if (strcmp(comd,"Begin") == 0)
            {
                //开始了就开始了，你读这个有个毛用
            }
            else if (strcmp(comd,"End") == 0)
            {
                //结束
                break;
            }
            else if (strcmp(comd,"Jump") == 0)
            {
                Jump();
            }
                //Layup/ Slam Dunk / Hook Shot / Jump Shot /3pt Shot
                //the first four messages stand for an attempt for 2-point shot
                //while the last message stand for an attempt for 3-point shot.
            else if (strcmp(comd,"Layup") == 0 ||
                     strcmp(comd,"Slam") == 0 ||
                     strcmp(comd,"Hook") == 0 ||
                     strcmp(comd,"Jump") == 0)
            {
                if (strcmp(comd,"Layup") != 0)  scanf("%*s");
                Shot2();
            }
            else if (strcmp(comd,"3pt") == 0)
            {
                scanf("%*s");
                Shot3()
            }
            else
            {

                //x Hold Ball - OK
                //x1 Pass to x2 - 随时可能出现


                //Made Missed
                //Blocked by x
                //x Rebound
                //x Foul
                //Free Throw m of M
                //x Steal
                //x1 Substitution replaced by x2
                //Timeout
                //
            }
        }
        //output
        printf("%s %d-%d %s\n",Aname,Apoints,Bpoints,Bname);
        output(Aname,Alist,ADNP,A);
        output(Bname,Blist,BDNP,B);
        printf("\n");
    }
}
