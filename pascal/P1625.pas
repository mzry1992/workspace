var v,n,c,i,j,tv,tm:longint;
    f:array[0..10000] of longint;
begin
readln(v,n,c);
for i:= 1 to n  do
 begin
 readln(tv,tm);
 for j:= c downto tm do
  if f[j] < f[j-tm] + tv then
   f[j]:=f[j-tm]+tv;
 end;
for i:= 0 to c do
 if f[i] >= v then
  begin
  writeln(c-i);
  halt;
  end;
writeln('Impossible');
end.