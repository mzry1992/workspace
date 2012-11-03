var n,k,i,j:longint;
    w:array[0..100000,1..2] of longint;
    e:array[1..10] of longint;
procedure qsort(l,r:longint);
var i,j,m,wwt,temp:longint;
begin
i:=l;
j:=r;
m:=w[(i+j) div 2,1];
wwt:=w[(i+j) div 2,2];
repeat
while (w[i,1] > m) or ((w[i,1]=m) and (w[i,2] < wwt)) do inc(i);
while (w[j,1] < m) or ((w[i,1]=m) and (w[i,2] > wwt)) do dec(j);
if i <= j then
 begin
 temp:=w[i,1];
 w[i,1]:=w[j,1];
 w[j,1]:=temp;
 temp:=w[i,2];
 w[i,2]:=w[j,2];
 w[j,2]:=temp;
 inc(i);
 dec(j);
 end;
until i > j;
if i < r then qsort(i,r);
if l < j then qsort(l,j);
end;
begin
readln(n,k);
if k=0 then
begin
writeln(' ');
exit;
end;
for i:= 1 to 10 do read(e[i]);
for i:= 1 to n do
 begin
 read(w[i,1]);
 w[i,2]:=i;
 end;
qsort(1,n);
for i:= 1 to n do
 w[i,1]:=w[i,1]+e[(i-1) mod 10 + 1 ];
qsort(1,n);
for i:= 1 to k-1 do write(w[i,2],' ');
writeln(w[k,2]);
end.
