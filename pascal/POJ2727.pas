var mt,k,i,j,max:longint;
    t,w:array[1..100] of longint;
    f:array[1..1000] of longint;
begin
readln(mt,k);
for i:= 1 to k do
 readln(t[i],w[i]);
f[0]:=0;
max:=0;
for i:= 1 to k do
 for j:= mt downto t[i] do
  if f[j] < f[j-t[i]] + w[i] then
  begin
   f[j]:=f[j-t[i]]+w[i];
   if f[j] > max then max:=f[j];
  end;
writeln(max);
end.
