var f:array[0..61,0..61,-3000..3000] of boolean;
    a:array[0..61,0..61] of longint;
    n,x,y,z,now,i,j,k:longint;
begin
readln(n);
for x:= 1 to n do
begin
for y:= 1 to x do read(a[x,y]);
readln;
end;
for x:= n+1 to 2*n-1 do
begin
for y:= 1 to 2*n-x do read(a[x,y]);
readln;
end;
fillchar(f,sizeof(f),0);
f[0,1,a[1,1]]:=true;
now:=0;
for i:=2 to n do
begin
now:=1-now;
for j:=1 to i do
for k:=-2700 to 2700 do
f[now,j,k]:=f[1-now,j,k+a[i,j]] or f[1-now,j,k-a[i,j]] or f[1-now,j-1,k+a[i,j]] or f[1-now,j-1,k-a[i,j]];
end;

for i:=n+1 to 2*n-1 do
begin
now:=1-now;
for j:=1 to 2*n-i do
for k:=-2700 to 2700 do
f[now,j,k]:=f[1-now,j,k+a[i,j]] or f[1-now,j,k-a[i,j]] or f[1-now,j+1,k+a[i,j]] or f[1-now,j+1,k-a[i,j]];
end;

for z:= 0 to 3000 do
 if f[now,1,z] or f[now,1,-z] then
  begin
  writeln(z);
  halt;
  end;
end.
