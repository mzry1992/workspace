var n,i,j,max:longint;
    a:array[1..10000] of longint;
    f:array[0..10000,1..2] of longint;
begin
readln(n);
for i:= 1 to n do read(a[i]);
readln;
f[0,1]:=0;
max:=0;
for i:= 1 to n do
 for j:= 0 to i - 1 do
 begin
  if a[j] < a[i] then
   if f[i,1] < f[j,2] + 1 then
    f[i,1]:=f[j,2]+1;
  if a[j] > a[i] then
   if f[i,2] < f[j,1] + 1 then
    f[i,2]:=f[j,1]+1;
  if f[i,1] > max then max:=f[i,1];
  if f[i,2] > max then max:=f[i,2];
 end;
writeln(max);
end.

