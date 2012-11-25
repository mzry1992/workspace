#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool visited[3][3][3][3][16][16][16][16];
double exp[3][3][3][3][16][16][16][16];
int c,d,h,s;
bool check(int fc,int fd,int fh,int fs)
{
    return fc>=c&&fd>=d&&fh>=h&&fs>=s;
}
double calc(int jc,int jd,int jh,int js,int fc,int fd,int fh,int fs)
{
    //printf("%d %d %d %d %d %d %d %d\n",jc,jd,jh,js,fc,fd,fh,fs);
    if (visited[jc][jd][jh][js][fc][fd][fh][fs])
        return exp[jc][jd][jh][js][fc][fd][fh][fs];
    visited[jc][jd][jh][js][fc][fd][fh][fs]=1;
    double &ret=exp[jc][jd][jh][js][fc][fd][fh][fs]=1;
    if (check(fc,fd,fh,fs))
        return ret=0;
    int tot=fc+fd+fh+fs,jok=jc+jd+jh+js;
    if (jok<2)
        ret+=min(min(calc(jc+1,jd,jh,js,fc+1,fd,fh,fs),calc(jc,jd+1,jh,js,fc,fd+1,fh,fs)),min(calc(jc,jd,jh+1,js,fc,fd,fh+1,fs),calc(jc,jd,jh,js+1,fc,fd,fh,fs+1)))*(2-jok)/(54-tot);
    if (fc-jc<13)
        ret+=calc(jc,jd,jh,js,fc+1,fd,fh,fs)*(13-fc+jc)/(54-tot);
    if (fd-jd<13)
        ret+=calc(jc,jd,jh,js,fc,fd+1,fh,fs)*(13-fd+jd)/(54-tot);
    if (fh-jh<13)
        ret+=calc(jc,jd,jh,js,fc,fd,fh+1,fs)*(13-fh+jh)/(54-tot);
    if (fs-js<13)
        ret+=calc(jc,jd,jh,js,fc,fd,fh,fs+1)*(13-fs+js)/(54-tot);
    return ret;
}
bool isimp()
{
    return max(c-13,0)+max(d-13,0)+max(s-13,0)+max(h-13,0)>2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d%d",&c,&d,&h,&s);
        if (isimp())
        {
            printf("Case %d: -1.000\n",cas);
            continue;
        }
        memset(visited,0,sizeof(visited));
        double ret=calc(0,0,0,0,0,0,0,0);
        printf("Case %d: %.3f\n",cas,ret);
    }
    return 0;
}
