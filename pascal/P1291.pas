var i,j,n,m,kk,t:longint;
    a,b:array[1..2000] of longint;
procedure qsort(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l;
j:=r;
m:=b[(i+j) div 2];
repeat
while b[i] > m do inc(i);
while b[j] < m do dec(j);
if i <= j then
 begin
 temp:=b[i];
 b[i]:=b[j];
 b[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if i < r then qsort(i,r);
if j > l then qsort(l,j);
end;

begin
readln(n,m);
for i:= 1 to n do readln(a[i]);
for i:= 1 to m do readln(b[i]);
qsort(1,m);
kk:=0;
t:=0;
while b[kk+1] > 0 do inc(kk);
for i:= 1 to n do
for j:= 1 to kk do
if a[i] > b[j] then
begin
inc(t);
b[j]:=maxlongint;
break;
end;
writeln(m-t);
end.