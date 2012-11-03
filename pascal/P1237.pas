const g = 0.6180339887498949 ;
var a:array[1..30000] of longint;
    n,m,a1,a2,r,l,i,j:longint;
    min:double;

procedure qsort(l,r:longint);
var m,i,j,temp:longint;
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
until i > j ;
if i < r then qsort(i,r);
if j > l then qsort(l,j);
end;

begin
min:=30000;
readln(n);
for i:= 1 to n do read(a[i]);
qsort(1,n);
r:=1;
l:=2;
while a[r] = 0 do inc(r);
while a[l] = 0 do inc(l);
while l <= n do
 begin
 if abs(g-a[r]/a[l]) < min - 1e-10 then
  begin
  a1:=a[r];
  a2:=a[l];
  min:=abs(g-a[r]/a[l]);
  end;
 if a[r]/a[l] < g then inc(r)
 else
 if a[r]/a[l] > g then inc(l);
 end;
writeln(a1);
writeln(a2);
end.
