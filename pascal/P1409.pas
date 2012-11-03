var max,n,i,j,total:longint;
    a:array[1..30000] of longint;
procedure qsort(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l;
j:=r;
m:=a[(l+r) div 2];
repeat
while a[i] < m do inc(i);
while a[j] > m do dec(j);
if i <= j then
begin
temp:=a[i];
a[i]:=a[j];
a[j]:=temp;
inc(i);
dec(j);
end;
until i > j;
if i < r then qsort(i,r);
if l < j then qsort(l,j);
end;

begin
readln(max);
readln(n);
for i:= 1 to n do readln(a[i]);
qsort(1,n);
total:=n;
for j:=  n downto 1 do
begin
if a[j] = 0 then break;
 for i:= 1 to j-1 do
 if ( a[i] <> 0 ) and ( a[j] <> 0 ) then
  if i <> j then
   if a[i] + a[j] <= max then begin a[j]:=a[i]+a[j]; a[i]:=0; dec(total) ;end
   else break;
end;
writeln(total);
end.