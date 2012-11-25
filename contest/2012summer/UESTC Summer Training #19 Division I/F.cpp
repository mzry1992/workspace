#include<cstdio>
#include<cstring>
int main()
{
    gets(s);
    int l=strlen(s);
    node *head=newnode('#'),*p=head;
    for (int i=0;i<L;i++)
    {
        if (s[i]!='L' && s[i]!='R')
            insert(p,s[i]);
        else if (s[i]=='L')
            p=moveleft(p);
        else
            p=moveright(p);
    }
    for (node *i=head;i!=NULL;i=
    return 0;
}
