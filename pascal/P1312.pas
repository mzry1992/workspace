var n,i,j,k:integer;
    a:array[1..1000] of longint;
    f:array[1..1000,1..1000] of int64;
    max:int64;
begin
readln(n);
for i:= 1 to n do
begin
read(a[i]);
a[i+n]:=a[i];
end;
for i:= 1 to n do
for j:= 1 to 2*n-i do
for k:= j to i+j-1 do
if f[j,i+j] < f[j,k]+f[k+1,i+j]+a[j]*a[k+1]*a[i+j+1] then
 f[j,i+j] := f[j,k]+f[k+1,i+j]+a[j]*a[k+1]*a[i+j+1];
max:=0;
for i:= 1 to n do
if max < f[i,n+i-1] then max:=f[i,n+i-1];
writeln(max);
end.