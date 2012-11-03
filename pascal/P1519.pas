var f:array[0..301,0..301,0..2] of qword;
    a:array[1..300,1..300] of longint;
    max:qword;
    i,k,x,y:longint;
begin
readln(k);
for x:= 1 to k do
begin
for y:= 1 to x do read(a[x,y]);
readln;
end;
fillchar(f,sizeof(f),0);
max:=0;
for x:= 1 to k do
 for y:= 1 to x do
  begin
  if f[x,y,0] < f[x-1,y,0] + a[x,y] then
   f[x,y,0]:=f[x-1,y,0] + a[x,y];
  if f[x,y,0] < f[x-1,y-1,0] + a[x,y] then
   f[x,y,0]:=f[x-1,y-1,0] + a[x,y];
  if f[x,y,1] < f[x-1,y-1,1] + a[x,y] then
   f[x,y,1]:=f[x-1,y-1,1] + a[x,y];
  if f[x,y,1] < f[x-1,y,1] + a[x,y] then
   f[x,y,1]:=f[x-1,y,1] + a[x,y];
  if f[x,y,1] < f[x-1,y-1,2] + a[x,y] then
   f[x,y,1]:=f[x-1,y-1,2] + a[x,y];
  if f[x,y,1] < f[x-1,y,2] + a[x,y] then
   f[x,y,1]:=f[x-1,y,2] + a[x,y];
  for i:= 1 to x-1 do
   if f[x,y,2] < f[x-1,i,0] + a[x,y] then
    f[x,y,2]:=f[x-1,i,0] + a[x,y];
  if f[x,y,0] > max then max:=f[x,y,0];
  if f[x,y,1] > max then max:=f[x,y,1];
  if f[x,y,2] > max then max:=f[x,y,2];
  end;
writeln(max);
end.
