var n,i,j:longint;
    f:array[1..500] of longint;
procedure chen(k:longint);
var i,qian:longint;
begin
qian:=0;
for i:= 1 to 500 do
begin
f[i]:=f[i]*k+qian;
qian:=f[i] div 10;
f[i]:=f[i] mod 10;
end;
end;
begin
fillchar(f,sizeof(f),0);
f[1]:=1;
readln(n);
n:=n+1;
for i:= 1 to n div 20 do
 chen(1048576);
for i:= 1 to n mod 20 do
 chen(2);
j:=500;
while f[j] = 0 do dec(j);
for i:= j downto 2 do write(f[i]);
writeln(f[1]-2);
end.