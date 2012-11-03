var n,m,i,j,k,qian:longint;
    f:array[0..100,0..100,0..200] of integer ;
begin
n:=100; m:=100;
fillchar(f,sizeof(f),0);
for i:= 0 to n do
begin
f[i,i,0]:=1;
f[i,i,1]:=1;
if i >= 1 then
begin
f[i,0,1]:=0;
f[i,0,0]:=0;
end;
end;
for i:= 1 to n do
 for j:= 1 to m do
 begin
 qian:=0;
 for k:= 1 to 200 do
 begin
  f[i,j,k]:=f[i-1,j-1,k]+j*f[i-1,j,k] + qian;
  qian:=f[i,j,k] div 10;
  f[i,j,k]:=f[i,j,k] mod 10;
 end;
 end;
while not eof do
begin
readln(n,m);
k:= 200;
while f[n,m,k] = 0 do dec(k);
if k > 0 then
for i:= k downto 1 do write(f[n,m,i])
else write('0');
writeln;
end;
end.
