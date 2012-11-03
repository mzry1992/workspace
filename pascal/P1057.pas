var n,m,x,y,max,k:longint;
    a,f:array[0..1000,0..1000] of longint;

function min(a,b:longint):longint;
begin
if a < b then exit(a);
exit(b);
end;

begin
readln(n,m);
fillchar(f,sizeof(f),0);
for x:= 1 to n do
begin
 for y:= 1 to m do
 read(a[x,y]);
readln;
end;
max:=0;
for x:= 1 to n do
for y:= 1 to m do
if a[x,y] = 1 then
begin
 f[x,y]:= min( min(f[x-1,y],f[x,y-1]) ,f[x-1,y-1] ) + 1 ;
 if f[x,y] > max then max:=f[x,y];
end;
writeln(max);
end.