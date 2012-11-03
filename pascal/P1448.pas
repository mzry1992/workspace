var lc,rc,lt,rt,va,vb:array[1..100004] of longint;
    n,m,i,c,l,r,top,ana,anb,temp:longint;
    use:array[1..500000] of boolean;

procedure maketree(l,r:longint);
var now,m:longint;
begin
 inc(top);
 now:=top;
 lt[now]:=l;
 rt[now]:=r;
 if l < r then
  begin
  m:=(l+r) div 2 ;
  lc[now]:=top+1;
  maketree(l,m);
  rc[now]:=top+1;
  maketree(m+1,r);
  end;
end;

procedure add(now,l,r,a,b:longint);
var m:longint;
begin
if ( r < lt[now] ) or ( l > rt[now]) then exit;
if ( l = lt[now] ) and ( r = rt[now] ) then
 begin
 inc(va[now],a);
 inc(vb[now],b);
 exit;
 end;
add(lc[now],l,r,a,b);
add(rc[now],l,r,a,b);
if lc[now] <> 0 then
 begin
 va[now]:=va[lc[now]]+va[rc[now]];
 vb[now]:=vb[lc[now]]+vb[rc[now]];
 end;
end;

procedure tot(now,l,r:longint);
var m:longint;
begin
if ( l <= lt[now] ) and ( r >= rt[now] ) then
begin
 inc(ana,va[now]);
 inc(anb,vb[now]);
 exit;
end;
m:=(lt[now]+rt[now]) div 2 ;
if ( l <= m ) and ( lc[now] <> 0 ) then
 tot(lc[now],l,r);
if ( r >= m ) and ( rc[now] <> 0 ) then
 tot(rc[now],l,r);
end;

begin
fillchar(lc,sizeof(lc),0);
fillchar(rc,sizeof(rc),0);
readln(n,m);
top:=0;
maketree(1,n);
for i:= 1 to m do
 begin
 readln(c,l,r);
 if c = 1 then
  begin
  add(1,r,r,0,1);
  add(1,l,l,1,0);
  end;
 if c = 2 then
  begin
  ana:=0;
  anb:=0;
  tot(1,1,l-1);
  temp:=anb;
  ana:=0;
  anb:=0;
  tot(1,1,r);
  writeln(ana-temp);
  end;
 end;
end.
