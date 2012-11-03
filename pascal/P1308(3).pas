var a,b,n,i,m2,m1:longint;
    f,ou:array[1..1000] of longint;

procedure dfs(ta,tb,tr:longint);
var aa,bb,ii,jj:longint;
begin
if tr > m2 then exit;
if n = m1 then exit;
aa:=ta;
bb:=tb;
if bb mod aa = 0 then
 begin
 bb:=bb div aa;
 if bb < tr then exit;
 if bb > m2 then exit;
 inc(n);
 f[n]:=bb;
 ou:=f;
 m2:=bb;
 f[n]:=0;
 dec(n);
 exit;
 end;
if n = m1 -1 then exit;
while (ta*tr - tb <= 0 ) and ( tr < m2 ) do inc(tr);
while tr < m2 do
begin
ii:=ta*tr-tb;
jj:=tb*tr;
inc(n);
f[n]:=tr;
dfs(ii,jj,tr+1);
f[n]:=0;
dec(n);
inc(tr);
end;
end;

procedure print;
begin
for i:= 1 to m1 do write(f[i],' ');
writeln;
end;


begin
readln(a,b);
i:=2;
n:=0;
m2:=maxlongint;
fillchar(f,sizeof(f),0);
while a*i < b do inc(i);
for  m1:= 1 to 10000 do
 begin
 dfs(a,b,i);
 if m2 < maxlongint then print;
 end;
end.