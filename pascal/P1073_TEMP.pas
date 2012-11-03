var i,j,n:longint;
    f,a:array[0..100] of longint;

begin
readln(n);
a[0]:=1;
f[0]:=maxlongint;
f[1]:=1;
for i:= 1 to n do
begin
 a[i]:=a[i-1]*2;
 f[i]:=maxlongint;
end;
for i:= 1 to n do
 for j:= 1 to i - 1 do
  if f[i] > f[j]+f[j]+a[i-j]-1 then
   f[i]:=f[j]+f[j]+a[i-j]-1;
writeln(f[n]);
end.