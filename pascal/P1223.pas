var n,i:longint;
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
for i:= 1 to n div 20 do
 chen(1048576);
for i:= 1 to n mod 20 do
 chen(2);
writeln(trunc(n*ln(2)/ln(10))+1);
for i:= 1 to 499 do
begin
write(f[501-i]);
if i mod 50 = 0 then writeln;
end;
writeln(f[1]-1);
end.