#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

struct columns
{
    char name[100],typ[10];
    int ityp;
}c[10];

const char outcom[2][4] = {"%d","%s"};
char info[10000][10][20],Column_List[200],Condition[200],col[50],val[50],op,outline[50][100];
bool select[10000];
int n,m,Q,len,tmp,tmp2,totout,outw[50];

bool check(int typ,char *val,char op,char *cmp)
{
    if (typ == 1)
    {
        if (strlen(val) != strlen(cmp)-2)   return false;
        for (int i = 1;i < len-1;i++)
            if (val[i-1] != cmp[i]) return false;
        return true;
    }
    else
    {
        sscanf(val,"%d",&tmp);
        sscanf(cmp,"%d",&tmp2);
        if (op == '=')  return tmp == tmp2;
        else if (op == '<') return tmp < tmp2;
        else return tmp > tmp2;
    }
}

void output(char *str,int w)
{
    len = strlen(str);
    tmp = (w-len)/2;
    tmp2 = w-len-tmp;
    for (int i = 0;i < tmp;i++) printf(" ");
    printf("%s",str);
    for (int i = 0;i < tmp2;i++)    printf(" ");
}

int main()
{
    while (scanf("%d%d%d",&m,&n,&Q) != EOF)
    {
        for (int i = 0;i < m;i++)
        {
            scanf("%s%s",c[i].name,c[i].typ);
            if (strcmp(c[i].typ,"INT") == 0)    c[i].ityp = 0;
            else c[i].ityp = 1;
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%s",info[i][j]);
        for (int i = 0;i < Q;i++)
        {
            for (int i = 0;i < n;i++)
                select[i] = false;
            scanf("%*s%s%*s%s",Column_List,Condition);
            len = strlen(Condition);
            for (int j = 0;j < len;j++)
                if (Condition[j] == '=' || Condition[j] == '<' || Condition[j] == '>')
                {
                    op = Condition[j];
                    for (int k = 0;k < j;k++)
                        col[k] = Condition[k];
                    col[j] = 0;
                    for (int k = j+1;k < len;k++)
                        val[k-(j+1)] = Condition[k];
                    val[len-(j+1)] = 0;
                    break;
                }
            for (int j = 0;j < m;j++)
                if (strcmp(col,c[j].name) == 0)
                {
                    len = strlen(val);
                    for (int k = 0;k < n;k++)
                        if (check(c[j].ityp,info[k][j],op,val) == true)
                            select[k] = true;
                    break;
                }
            totout = 0;
            len = strlen(Column_List);
            for (int j = 0;j < len;j++)
                if (j == 0 || Column_List[j-1] == ',')
                {
                    for (int k = j;k < len && Column_List[k] != ',';k++)
                    {
                        outline[totout][k-j] = Column_List[k];
                        outline[totout][k-j+1] = 0;
                    }
                    totout++;
                }
            for (int j = 0;j < totout;j++)
            {
                outw[j] = strlen(outline[j]);
                int colid;
                for (int k = 0;k < m;k++)
                    if (strcmp(outline[j],c[k].name) == 0)
                        colid = k;
                for (int k = 0;k < n;k++)
                    if (select[k] == true)
                        outw[j] = max(outw[j],(int)strlen(info[k][colid]));
            }
            printf("+-");
            for (int j = 0;j < totout;j++)
            {
                if (j != 0) printf("--");
                for (int k = 0;k < outw[j];k++)
                    printf("-");
                printf("-");
            }
            printf("+\n");
            for (int j = 0;j < totout;j++)
            {
                printf("| ");
                output(outline[j],outw[j]);
                printf(" ");
            }
            printf("|\n");
            printf("|-");
            for (int j = 0;j < totout;j++)
            {
                if (j != 0) printf("|-");
                for (int k = 0;k < outw[j];k++)
                    printf("-");
                printf("-");
            }
            printf("|\n");
            for (int j = 0;j < n;j++)
                if (select[j] == true)
                {
                    for (int k = 0;k < totout;k++)
                    {
                        printf("| ");
                        for (int q = 0;q < m;q++)
                            if (strcmp(outline[k],c[q].name) == 0)
                            {
                                output(info[j][q],outw[k]);
                                break;
                            }
                        printf(" ");
                    }
                    printf("|\n");
                }
            printf("+-");
            for (int j = 0;j < totout;j++)
            {
                if (j != 0) printf("--");
                for (int k = 0;k < outw[j];k++)
                    printf("-");
                printf("-");
            }
            printf("+\n\n");
        }
    }
}
