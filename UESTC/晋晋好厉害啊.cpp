#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

FILE *f;
void noblank(char &ch)
{
     while (ch==' '||ch=='\n')
         ch=fgetc(f);
}
//====================================================================
void identifier(char name[],char &ch)
{
     int i;
     for (i=0;i<10;i++)
         name[i]='\0';
     i=0;
     name[i]=ch;i++;
     ch=fgetc(f);
     while (('0'<=ch&&ch<='9')||('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z'))
     {
         name[i]=ch;
         i++;
         ch=fgetc(f);
     }
}
//====================================================================
int intconst(char &ch)
{
     int num=0;
     while ('0'<=ch&&ch<='9')
     {
         num=num*10+(ch-'0');
         ch=fgetc(f);
     }
     return num;
}
//====================================================================
int main()
{
     char ch,name[20];
     char st1[10]={"#include"};
     char st2[10]={"main()"};
     char st3[10]={"{"};
     char st4[10]={"int"};
     char st5[10]={"}"};
     char st6[20]={"cout<<"};
     int num;
     f=fopen("·ÖÎö.cpp","r");
     if (f==NULL)
         cout<<"no such file."<<endl;
     while (!feof(f))
     {
         ch=fgetc(f);
         noblank(ch);
         if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
         {
             identifier(name,ch);
             if (!strcmp(name,st1))        printf("${\n");
             else if (!strcmp(name,st2))   printf("$}\n");
             else if (!strcmp(name,st3))   printf("$int\n");
             else if (!strcmp(name,st4))   printf("$cout<<\n");
             else if (!strcmp(name,st5))   printf("$#include\n");
             else printf("$id,%s\n",name);
         }
         else if (ch>='0'&&ch<='9')
         {
             num=intconst(ch);
             printf("$intc,%d\n",num);
         }
         else switch(ch)
         {
             case'(':cout<<"lparen"<<endl;
                 break;
             case')':cout<<"rparen"<<endl;
                 break;
             case'+':cout<<"plus"<<endl;
                 break;
             case'*':cout<<"mult"<<endl;
                 break;
             case';':cout<<"semi"<<endl;
                 break;
             case'=':cout<<"give value"<<endl;
                 break;
             case'.':cout<<"point"<<endl;
                 break;
             default:break;
         }
     }fclose(f);
}
