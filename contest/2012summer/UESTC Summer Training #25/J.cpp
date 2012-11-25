#include<cstdio>
#include<algorithm>
using namespace std;
struct Rec
{
    int w,h;
    Rec(){}
    Rec(int _w,int _h)
    {
        w=_w;
        h=_h;
    }
    bool operator<(const Rec a)const
    {
        if (w!=a.w)
            return w<a.w;
        else
            return h>a.h;
    }
}rec[1000];
int main()
{
    int n;
    while (scanf("%d",&n),n!=-1)
    {
        for (int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (x>y)
                swap(x,y);
            rec[i]=Rec(x,y);
        }
        sort(rec,rec+n);
        int pre=0,ans=0;
        for (int i=0;i<n;i++)
        {
            ans+=(rec[i].h+rec[i+1].h-pre-rec[i].w)*(rec[i].w-pre);
            pre=rec[i].w;
            while (i+1<n && rec[i].w==rec[i+1].w)
                i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
