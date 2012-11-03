var n,m,i,j:longint;
    a,b,c:array[1..100000] of longint;
    d:array[1..100000] of qword;
procedure qsort1(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l; j:=r; m:=a[(i+j) div 2];
repeat
while a[i] < m do inc(i);
while a[j] > m do dec(j);
if i <= j then
 begin
 temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
 inc(i); dec(j);
 end;
until i > j ;
if i < r then qsort1(i,r);
if j > l then qsort1(l,j);
end;
procedure qsort2(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l; j:=r; m:=b[(i+j) div 2];
repeat
while b[i] < m do inc(i);
while b[j] > m do dec(j);
if i <= j then
 begin
 temp:=c[i]; c[i]:=c[j]; c[j]:=temp;
 temp:=b[i]; b[i]:=b[j]; b[j]:=temp;
 inc(i); dec(j);
 end;
until i > j ;
if i < r then qsort2(i,r);
if j > l then qsort2(l,j);
end;
begin
fillchar(a,sizeof(a),0);
readln(n,m);
for i:= 1 to n do read(a[i]);
readln;
for i:= 1 to m do
begin
read(b[i]); c[i]:=i;
end;
readln;
qsort1(1,n); qsort2(1,m);
fillchar(d,sizeof(d),0);
i:=m;
for j:= n downto 1 do
begin
d[c[i]]:=d[c[i]]+a[j];
dec(i);
if i = 0 then i:=m;
end;
for i:= 1 to m do write(d[i],' ');
writeln;
end.