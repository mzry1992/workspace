#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const char key[32][30]={
"auto", "break", "case", "char", "const", "continue", "default",
"do", "double", "else", "enum", "extern", "float", "for", 
"goto", "if", "int", "long", "register", "return", "short",
"signed", "static", "sizeof", "struct", "switch", "typedef", "union",
"unsigned", "void", "volatile", "while"
};
int ans;
bool zs;
char s[2000];

bool isa(char ch)
{
     if ((ch >= 'a') && (ch <= 'z')) return true;
     if ((ch >= 'A') && (ch <= 'Z')) return true;
     if ((ch >= '0') && (ch <= '9')) return true;
     if (ch == '_')  return true;
     return false;
}

bool ise(char ch)
{
     if (ch == '\t') return true;
     if (ch == ' ')  return true;
     return false;
}

bool iso(char ch)
{
     if (isa(ch) == true)   return false;
     return true;
}

int findword(int x)
{
    while (isa(s[x]) ==  true) x++;
    x--;
    return x;
}

int findnext(int x)
{
    while ((s[x] != '"') && (s[x] != '\0'))
          x++;
    return x;
}

int findzs(int x)
{
    while (!((s[x] == '*') && (s[x+1] == '/')) && (s[x] != '\0'))    x++;
    return x;
}

bool check(int a,int b)
{
     int i,j,l;
     bool flag;    
     for (i = 0;i < 32;i++)
     {
         l = strlen(key[i]);
         if (b-a+1 != l)    continue;
         flag = true;
         for (j = 0;j < l;j++)
         if (key[i][j] != s[a+j])    
            flag = false;
         if (flag) 
         {
            return true;
         }
     }
     return false;
}

void solve()
{
     int i,j,k;
     i = 0;
     if (zs == true)
     {
            j = findzs(0);
            if (s[j] == '*')
            if (s[j+1] == '/')
            {
                       zs = false;
                       j = j+1;
            }
            i = j+1;
           if (s[i] == '\0')
              return;
     }
     else
     {
         while (ise(s[i]) == true) i++;
         if (s[i] == '#')        return;
         if (s[i] == '\0')       return;
     }
     if (zs == false)
     while (true)
     {
           if (isa(s[i]) == true)
           {
              j = findword(i);
              if (check(i,j) == true) ans++;
              i = j+1;
              if (s[i] == '\0')
                 return;
           }
           if (s[i] == '"')
           {
                    j = findnext(i+1);
                    i = j+1;
                    if (s[i] == '\0')
                       return;
           }
           if (s[i] == '\'')
           {
                    if (s[i+1] == '\\')
                       j = i+3;
                    else
                        j = i+2;
                    i = j+1;
                    if (s[i] == '\0')
                       return;
           }
           if (s[i] == '/')
           if (s[i+1] == '/')
              return;
           if (s[i] == '/')
           if (s[i+1] == '*')
           {
                      zs = true;
                      j = findzs(i+2);
                      if (s[j] == '*')
                      if (s[j+1] == '/')
                      {
                                 zs = false;
                                 j = j+1;
                                 i = j+1;
                                 if (s[i] == '\0')
                                    return;
                      }
                      if (s[j+1] == '\0')
                         return;
           }
           if (iso(s[i]) == true)
              j = i;
           i = j+1;
           if (s[i] == '\0')
              return;
     }
}

int main()
{
    ans = 0;
    zs = false;
    while (gets(s))
    {
          if ((s[0] == '#') && (s[1] == '#'))
          {
                    printf("%d\n",ans);
                    ans = 0;
                    zs = false;
          }
          else
          solve();
    }
    printf("%d\n",ans);
	return 0;
}
