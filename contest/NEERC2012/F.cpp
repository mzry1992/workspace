#include <cstdio>
struct Links
{
    int val;
    Links *next,*pre;
} link[5000000],*head,*tail;
int N;
Links *newLinks(int v)
{
    link[N].pre=link[N].next=NULL;
    link[N].val=v;
    return &link[N++];
}
int main()
{
    N=0;
    int n;
    while (scanf("%d",&n) != EOF)
    {
        head=tail=NULL;
        int size=0;
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d",&v);
            if (v > 0)
            {
                Links *tmp=newLinks(v);
                if (head==NULL)
                    head=tail=tmp;
                else
                {
                    head->next=tmp;
                    tmp->pre=head;
                    head=tmp;
                }
                size++;
            }
            else if (v == 0)
            {
                Links *now=head;
                int nsize=size;
                for (int i = 0; i < size && nsize<1000000; i++,now=now->pre)
                {
                    Links *tmp=newLinks(now->val);
                    tmp->next=tail;
                    tail->pre=tmp;
                    tail=tmp;
                    nsize++;
                }
                size=nsize;
            }
            else if (v == -1)
            {
                printf("%d\n",head->val);
                head=head->pre;
                size--;
                if (!size)
                    tail=NULL;
				else
					head->next=NULL;
            }
        }
    }
    return 0;
}

