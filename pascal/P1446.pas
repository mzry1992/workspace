var d:array[1..100,1..100] of longint;
    n,m,x,y,i,j,k,p,ans:longint;
begin
readln(n,m);
for x:= 1 to n do
 for y:= 1 to n do
  d[x,y]:=100000;
for i:= 1 to m do
 begin
 readln(x,y);
 d[x,y]:=1;
 d[y,x]:=1;
 end;
for k:= 1 to n do
for i:= 1 to n do
 for j:= 1 to n do
  if d[i,j] > d[i,k]+d[k,j] then
   d[i,j]:=d[i,k]+d[k,j];
readln(p);
for i:= 1 to p do
 begin
 readln(x,y);
 ans:=2;
 for j:= 1 to n do
    if d[x,y]=d[x,j]+d[j,y] then
     inc(ans);
 writeln(ans);
 end;
end.

