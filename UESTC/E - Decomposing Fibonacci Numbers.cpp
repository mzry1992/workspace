#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

char s1[100],s2[100];
long long f[110];

void outputit(int i)
{
i -= 2;
if (i==1) printf("2\n");
if (i==2) printf("3\n");
if (i==3) printf("5\n");
if (i==4) printf("2 2 2\n");
if (i==5) printf("13\n");
if (i==6) printf("3 7\n");
if (i==7) printf("2 17\n");
if (i==8) printf("5 11\n");
if (i==9) printf("89\n");
if (i==10) printf("2 2 2 2 3 3\n");
if (i==11) printf("233\n");
if (i==12) printf("13 29\n");
if (i==13) printf("2 5 61\n");
if (i==14) printf("3 7 47\n");
if (i==15) printf("1597\n");
if (i==16) printf("2 2 2 17 19\n");
if (i==17) printf("37 113\n");
if (i==18) printf("3 5 11 41\n");
if (i==19) printf("2 13 421\n");
if (i==20) printf("89 199\n");
if (i==21) printf("28657\n");
if (i==22) printf("2 2 2 2 2 3 3 7 23\n");
if (i==23) printf("5 5 3001\n");
if (i==24) printf("233 521\n");
if (i==25) printf("2 17 53 109\n");
if (i==26) printf("3 13 29 281\n");
if (i==27) printf("514229\n");
if (i==28) printf("2 2 2 5 11 31 61\n");
if (i==29) printf("557 2417\n");
if (i==30) printf("3 7 47 2207\n");
if (i==31) printf("2 89 19801\n");
if (i==32) printf("1597 3571\n");
if (i==33) printf("5 13 141961\n");
if (i==34) printf("2 2 2 2 3 3 3 17 19 107\n");
if (i==35) printf("73 149 2221\n");
if (i==36) printf("37 113 9349\n");
if (i==37) printf("2 233 135721\n");
if (i==38) printf("3 5 7 11 41 2161\n");
if (i==39) printf("2789 59369\n");
if (i==40) printf("2 2 2 13 29 211 421\n");
if (i==41) printf("433494437\n");
if (i==42) printf("3 43 89 199 307\n");
if (i==43) printf("2 5 17 61 109441\n");
if (i==44) printf("139 461 28657\n");
if (i==45) printf("2971215073\n");
if (i==46) printf("2 2 2 2 2 2 3 3 7 23 47 1103\n");
if (i==47) printf("13 97 6168709\n");
if (i==48) printf("5 5 11 101 151 3001\n");
if (i==49) printf("2 1597 6376021\n");
if (i==50) printf("3 233 521 90481\n");
if (i==51) printf("953 55945741\n");
if (i==52) printf("2 2 2 17 19 53 109 5779\n");
if (i==53) printf("5 89 661 474541\n");
if (i==54) printf("3 7 7 13 29 281 14503\n");
if (i==55) printf("2 37 113 797 54833\n");
if (i==56) printf("59 19489 514229\n");
if (i==57) printf("353 2710260697\n");
if (i==58) printf("2 2 2 2 3 3 5 11 31 41 61 2521\n");
if (i==59) printf("4513 555003497\n");
if (i==60) printf("557 2417 3010349\n");
if (i==61) printf("2 13 17 421 35239681\n");
if (i==62) printf("3 7 47 1087 2207 4481\n");
if (i==63) printf("5 233 14736206161\n");
if (i==64) printf("2 2 2 89 199 9901 19801\n");
if (i==65) printf("269 116849 1429913\n");
if (i==66) printf("3 67 1597 3571 63443\n");
if (i==67) printf("2 137 829 18077 28657\n");
if (i==68) printf("5 11 13 29 71 911 141961\n");
if (i==69) printf("6673 46165371073\n");
if (i==70) printf("2 2 2 2 2 3 3 3 7 17 19 23 107 103681\n");
if (i==71) printf("9375829 86020717\n");
if (i==72) printf("73 149 2221 54018521\n");
if (i==73) printf("2 5 5 61 3001 230686501\n");
if (i==74) printf("3 37 113 9349 29134601\n");
if (i==75) printf("13 89 988681 4832521\n");
if (i==76) printf("2 2 2 79 233 521 859 135721\n");
if (i==77) printf("157 92180471494753\n");
if (i==78) printf("3 5 7 11 41 47 1601 2161 3041\n");
if (i==79) printf("2 17 53 109 2269 4373 19441\n");
if (i==80) printf("2789 59369 370248451\n");
if (i==81) printf("99194853094755497\n");
if (i==82) printf("2 2 2 2 3 3 13 29 83 211 281 421 1427\n");
if (i==83) printf("5 1597 9521 3415914041\n");
if (i==84) printf("6709 144481 433494437\n");
if (i==85) printf("2 173 514229 3821263937\n");
if (i==86) printf("3 7 43 89 199 263 307 881 967\n");
if (i==87) printf("1069 1665088321800481\n");
if (i==88) printf("2 2 2 5 11 17 19 31 61 181 541 109441\n");
if (i==89) printf("13 13 233 741469 159607993\n");
if (i==90) printf("3 139 461 4969 28657 275449\n");
if (i==91) printf("2 557 2417 4531100550901\n");
if (i==92) printf("2971215073 6643838879\n");
if (i==93) printf("5 37 113 761 29641 67735001\n");
if (i==94) printf("2 2 2 2 2 2 2 3 3 7 23 47 769 1103 2207 3167\n");
if (i==95) printf("193 389 3084989 361040209\n");
if (i==96) printf("13 29 97 6168709 599786069\n");
if (i==97) printf("2 17 89 197 19801 18546805133\n");
if (i==98) printf("3 5 5 11 41 101 151 401 3001 570601\n");
if (i==99) printf("743519377 770857978613\n");
if (i==100) printf("2 2 2 919 1597 3469 3571 6376021\n");
}

int main()
{
    f[0]=0;
    f[1]=1;
    for (int i=2; i<=100; i++)
        f[i]=f[i-1]+f[i-2];
    bool first=true;
    while (scanf("%s",s1)==1)
    {
        scanf("%s",s2);
        long long num1=0,num2=0;
        int len=strlen(s1);
        for (int i=2; i<len; i++)
            if (s1[i]>='a')
                num1=num1*16+s1[i]-'a'+10;
            else
                num1=num1*16+s1[i]-'0';
        len=strlen(s2);
        for (int i=2; i<len; i++)
            if (s2[i]>='a')
                num2=num2*16+s2[i]-'a'+10;
            else
                num2=num2*16+s2[i]-'0';
        if (num1>=num2) break;
        if (!first) printf("\n");
        first=false;
        printf("Range %lld to %lld:\n",num1,num2);
        int total=93;
        int left,right;
        for (left=0; left<total; left++)
        {
            if (f[left]>=num1) break;
        }
        for (right=total-1; right>=0; right--)
            if (f[right]<=num2)  break;
        if (left>right) puts("No Fibonacci numbers in the range");
        else
        {
            for (int i=left; i<=right; i++)
            {
                if (i==0) printf("Fib(0) = 0, lg does not exist\n");
                else printf("Fib(%d) = %I64d, lg is %.6f\n",i,f[i],log((double)(f[i]))/log(2.0));
                if (i==0) printf("No prime factors\n");
                else if (i==1) printf("No prime factors\n");
                else if (i==2) printf("No prime factors\n");
                else
                {
                    printf("Prime factors: ");
                    outputit(i);
                }
            }
        }
    }
    return 0;
}
