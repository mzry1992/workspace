#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

char line[1500],temp[1500];

int main()
{
    int i,j,k,l;
    bool flag;
    gets(line);
    l = strlen(line);
    k = 0;
    for (i = 0;i < l;i++)
    {
        if ((line[i] >= 'A') && (line[i] <= 'Z')) flag = true;
        if ((line[i] == '.') || (line[i] == '?'))
        {
                     flag = false;
                     if ((temp[0] == 'W') && (temp[1] == 'h') && (temp[2] == 'a') && (temp[3] == 't') && (temp[4] == ' '))
                     if ((temp[5] == 'i') && (temp[6] == 's') && (line[i] == '?'))
                     {
				        printf("Forty-two ");
                        for (j = 5;j <= k-1;j++) printf("%c",temp[j]);
                        printf(".\n");
                     }
                     k = 0;
        }
        if (flag == true)  
        {
            temp[k] = line[i];
            k++;
        }
    }
    system("pause");
    return 0;
}
