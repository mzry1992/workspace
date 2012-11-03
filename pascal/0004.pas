var n,i,j,r:longint;f:array[0..11,0..11]of longint;
begin
for n:= 1 to 10 do
begin
for r:= 1 to 10 do
begin
fillchar(f,sizeof(f),0);
for i:=1 to n do f[i,1]:=1;
for i:=2 to n do
for j:=2 to r do
 begin
f[i,j]:=f[i-1,j-1]+f[i-1,j]*j;
 end;
for i:=1 to r do f[n,r]:=f[n,r]*i;
write(f[n,r],'  ');
end;
writeln;
end;
end.
