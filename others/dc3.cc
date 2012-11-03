# define F(x) ( (x)/3 + ((x)%3==1? 0:tb) )
# define G(x) ( (x)<tb? (x)*3+1 : ((x)-tb)*3+2 )
int s3[3*N],sa[3*N];
int c0(int *r,int a,int b)
{   return r[a]==r[b] && r[a+1]==r[b+1] && r[a+2]==r[b+2] ;   }

int c12(int k,int *r,int a,int b)
{   if(k==2) return r[a]<r[b] || r[a]==r[b] && c12(1, r, a+1, b+1);
    else     return r[a]<r[b] || r[a]==r[b] && wv[a+1]<wv[b+1] ;}

void sort(int *r,int *a,int *b,int n,int m)
{   int i;
    For(i, n) wv[i] = r[ a[i] ];
    For(i, m) rk[i] = 0;
    For(i, n) rk[ wv[i] ]++;
    For(i, m) rk[i] += rk[i-1];
    for(i=n-1; i>=0; i--) b[ --rk[ wv[i]]] = a[i];  }

void dc3(int *r,int *sa,int n,int m)
{   /// *r 必须为 int
    int i, j, p, ta=0, tb=(n+1)/3, tbc=0;
    int *rn = r+n, *san = sa+n;
    r[n] = r[n+1] = 0;
    For(i, n) if(i%3!=0) wa[tbc++]=i;
    sort(r+2, wa, wb, tbc, m);
    sort(r+1, wb, wa, tbc, m);
    sort(r  , wa, wb, tbc, m);
    for(rn[ F(wb[0]) ]=0,i=p=1; i<tbc; i++)
        rn[ F(wb[i]) ] = c0(r,wb[i-1],wb[i])? p-1:p++;
    if(p<tbc) dc3(rn, san, tbc, p);
    else       For(i, tbc) san[ rn[i]] = i;
    For(i, tbc) if(san[i]<tb) wb[ta++] = san[i]*3;
    if(n%3==1)    wb[ta++] = n-1;
    sort(r, wb, wa, ta, m);
    For(i, tbc) wv[ wb[i]= G(san[i]) ] = i;
    for(i=j=p=0; i<ta && j<tbc; p++)
        sa[p] = c12(wb[j]%3, r, wa[i], wb[j])?  wa[i++]:wb[j++];
    for(; i<ta; p++)  sa[p] = wa[i++];
    for(; j<tbc; p++) sa[p] = wb[j++];
}

