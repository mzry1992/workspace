var i,n,v,k:longint;
    a:array[1..1501] of longint;

procedure qsort(l,r:longint);
var i,j,k,t:longint;
begin
i:=l; j:=r; k:=a[(l+r) div 2];
repeat
while a[i] < k do inc(i);
while a[j] > k do dec(j);
if i <= j then
 begin
 t:=a[i]; a[i]:=a[j]; a[j]:=t;
 inc(i); dec(j);
 end;
until i > j;
if i < r then qsort(i,r);
if l < j then qsort(l,j);
end;

begin
readln(n,v,k);
for i:= 1 to n - 1 do read(a[i]);
a[n]:=v;
qsort(1,n);
for i:= 1 to n do
 if (( a[i] - a[1] ) <= k ) and (( a[n] -a[i] ) <= k ) then
  begin
  writeln('Yes'); halt;
  end;
writeln('No');
end.
