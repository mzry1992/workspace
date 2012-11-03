var x,y,f:array[1..100000] of longint;
    a:array[1..100000] of double;
    n,m,i,j,f1,f2:longint;
    s,t:double;

procedure qsort(l,r:longint);
var i,j,t1:longint;
    m,t2:double;
begin
i:=l;   j:=r;   m:=a[(i+j) div 2];
repeat
while a[i] < m do inc(i);
while a[j] > m do dec(j);
if i <= j then
 begin
 t1:=x[i];      x[i]:=x[j];     x[j]:=t1;
 t1:=y[i];      y[i]:=y[j];     y[j]:=t1;
 t2:=a[i];      a[i]:=a[j];     a[j]:=t2;
 inc(i);        dec(j);
 end;
until i > j ;
if i < r then qsort(i,r);
if l < j then qsort(l,j);
end;

function findfather(x:longint):longint;
begin
if f[x] <> x then f[x]:=findfather(f[x]);
exit(f[x]);
end;

begin
readln(s);
readln(n);
readln(m);
for i:= 1 to m do
begin
 readln(x[i],y[i],a[i]);
 f[i]:=i;
end;
if m < n-1 then begin writeln('Impossible'); halt; end;
qsort(1,m);
t:=0;
for i:= 1 to m do
begin
f1:=findfather(x[i]);
f2:=findfather(y[i]);
if f1 <> f2 then
begin
f[f1]:=f2;
t:=t+a[i];
end;
end;
if t <= s then
writeln('Need ',t:0:2,' miles of cable')
else
writeln('Impossible');
end.