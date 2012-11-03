var i,j,n,ta,tb,ta2,tb2,min:longint;
    a,b:array[1..1000000] of longint;

procedure qsort(l,r:longint);
var i,j,k,temp:longint;
begin
i:=l;
j:=r;
k:=a[(i+j) div 2];
repeat
while a[i] < k do inc(i);
while a[j] > k do dec(j);
if i <= j then
 begin
 temp:=a[i];
 a[i]:=a[j];
 a[j]:=temp;
 temp:=b[i];
 b[i]:=b[j];
 b[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if l < j then qsort(l,j);
if i < r then qsort(i,r);
end;

begin
readln(n);
for i:= 1 to n do
 readln(a[i],b[i]);
qsort(1,n);
ta:=a[1];
tb:=b[1];
for i:= 1 to n do
begin
ta2:=a[i];
tb2:=b[i];
if ( ta2 >= ta ) and ( ta2 <= tb ) then
 if tb2 > tb then tb:=tb2;
if ta2 > tb then
 begin
 writeln(ta,' ',tb);
 ta:=ta2;
 tb:=tb2;
 end;
end;
writeln(ta,' ',tb);
end.