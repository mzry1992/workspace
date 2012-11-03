var n,k,i,j:longint;
    f:array[1..200,0..200] of longint;
begin
while not eof do
begin
readln(n,k);
for i:= 1 to n do
begin
f[i,0]:=1; f[i,i-1]:=1;
end;
for i:= 2 to n do
 for j:= 1 to i-2 do
  f[i,j]:=((i-j)*f[i-1,j-1]+(j+1)*f[i-1,j]) mod 2009;
writeln(f[n,k]);
end;
end.
