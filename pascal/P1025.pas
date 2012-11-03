var m,v:array[1..100] of longint;
    mv,n,i,j,max:longint;
    f:array[0..100] of longint;
begin
readln(n);
readln(mv);
f[0]:=0;
max:=0;
for i:= 1 to n do
begin
readln(m[i],v[i]);
 for j:= mv downto v[i] do
 begin
  if f[j] < f[j-v[i]] + m[i] then
   f[j]:=f[j-v[i]]+m[i];
  if f[j] > max then max:=f[j];
 end;
end;
writeln(max);
end.