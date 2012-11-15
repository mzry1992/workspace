#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int hS,hI,wS;
char source[100][100],input[100][100];
struct Pointer
{
    int x,y;
    int dx,dy;
}ip;
int stack[10000],top;

int ask()
{
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&hS,&hI);
        gets(source[0]);
        wS = 0;
        for (int i = 0;i < hS;i++)
        {
            gets(source[i]);
            wS = max(wS,(int)strlen(source[i]));
        }
        for (int i = 0;i < hI;i++)
            gets(input[i]);
        ip.x = ip.y = 0;
        ip.dx = 0;
        ip.dy = 1;
        top = 0;
        while (true)
        {
            /*cout << ip.x << ' ' << ip.y << ' ' << ip.dx << ' ' << ip.dy << endl;
            cout << top << endl;*/
            /*for (int i = 0;i < hS;i++)
            {
                for (int j = 0;j < wS;j++)
                    printf("%c",(i == ip.x && j == ip.y)?'X':source[i][j]);
                printf("\n");
            }
            getchar();*/
            if (source[ip.x][ip.y] >= '0' && source[ip.x][ip.y] <= '9')
                stack[top++] = source[ip.x][ip.y]-'0';
            else if (source[ip.x][ip.y] == '+')
            {
                stack[top-2] = stack[top-2]+stack[top-1];
                top--;
            }
            else if (source[ip.x][ip.y] == '-')
            {
                stack[top-2] = stack[top-2]-stack[top-1];
                top--;
            }
            else if (source[ip.x][ip.y] == '*')
            {
                stack[top-2] = stack[top-2]*stack[top-1];
                top--;
            }
            else if (source[ip.x][ip.y] == '/')
            {
                if (stack[top-1] != 0)
                    stack[top-2] = stack[top-2]/stack[top-1];
                else
                    stack[top-2] = ask();
                top--;
            }
            else if (source[ip.x][ip.y] == '%')
            {
                if (stack[top-1] != 0)
                    stack[top-2] = stack[top-2]%stack[top-1];
                else
                    stack[top-2] = ask();
                top--;
            }
            else if (source[ip.x][ip.y] == '!')
                stack[top--] = (stack[top-1] == 0)?1:0;
            else if (source[ip.x][ip.y] == '`')
            {
                if (stack[top-2] > stack[top-1])    stack[top-2] = 1;
                else stack[top-2] = 0;
                top--;
            }
            else if (source[ip.x][ip.y] == '>')
            {
                ip.dx = 0;
                ip.dy = 1;
            }
            else if (source[ip.x][ip.y] == '<')
            {
                ip.dx = 0;
                ip.dy = -1;
            }
            else if (source[ip.x][ip.y] == '^')
            {
                ip.dx = -1;
                ip.dy = 0;
            }
            else if (source[ip.x][ip.y] == 'v')
            {
                ip.dx = 1;
                ip.dy = 0;
            }
            else if (source[ip.x][ip.y] == '_')
            {
                ip.dx = 0;
                if (stack[--top] == 0)  ip.dy = 1;
                else ip.dy = -1;
            }
            else if (source[ip.x][ip.y] == '|')
            {
                ip.dy = 0;
                if (stack[--top] == 0)  ip.dx = 1;
                else ip.dx = -1;
            }
            else if (source[ip.x][ip.y] == '\"')
            {
                while (true)
                {
                    ip.x += ip.dx;
                    ip.y += ip.dy;
                    if (source[ip.x][ip.y] == '\"') break;
                    stack[top++] = source[ip.x][ip.y];
                }
            }
            else if (source[ip.x][ip.y] == ':')
                stack[top++] = stack[top-1];
            else if (source[ip.x][ip.y] == '\\')
                swap(stack[top-2],stack[top-1]);
            else if (source[ip.x][ip.y] == '$')
                top--;
            else if (source[ip.x][ip.y] == '.')
                printf("%d",stack[--top]);
            else if (source[ip.x][ip.y] == ',')
                printf("%c",stack[--top]);
            else if (source[ip.x][ip.y] == '#')
            {
                ip.x += ip.dx;
                ip.y += ip.dy;
            }
            else if (source[ip.x][ip.y] == 'p')
            {
                int y,x,v;
                y = stack[--top];
                x = stack[--top];
                v = stack[--top];
                source[y][x] = v;
            }
            else if (source[ip.x][ip.y] == 'g')
            {
                int y,x,v;
                y = stack[--top];
                x = stack[--top];
                v = source[y][x];
                stack[top++] = v;
            }
            else if (source[ip.x][ip.y] == '&')
                stack[top++] = ask();
            else if (source[ip.x][ip.y] == '~')
                stack[top++] = ask();
            else if (source[ip.x][ip.y] == '@')
                break;
            ip.x += ip.dx;
            ip.y += ip.dy;
            if (ip.x < 0 || ip.x >= hS || ip.y < 0 || ip.y >= wS) break;
        }
    }
    return 0;
}
