var i,j,k,l,s,m,t,x,y,max:longint;
    a:array[1..100] of longint;
    f:array[0..100000] of longint;
begin
readln(l);
readln(s,t,m);
for i:= 1 to m do read(a[i]);
readln;
for i:= 1 to m - 1 do
 for j:= i + 1 to m do
  if a[i] > a[j] then
   begin
   k:=a[i];
   a[i]:=a[j];
   a[j]:=k;
   end;
for i:= 1 to m - 1 do
 begin
 x:=a[i]+1;
 y:=a[i+1]-1;
 k:=y-x;
 if k >= s then
 begin
 max:= 0 ;
 for j:= s  to t do
  if ( k div j ) * j > max then
   max:= ( k div j ) * j ;
 l:=l-max;
 for j:= i+1 to m do
  a[j]:=a[j]-max;
 end;
 end;
for i:= 0 to a[m] + t - 1 do f[i]:=100000;
f[0]:=0;
for i:= s to a[m] + t - 1 do
begin
f[i]:=f[i-s];
 for j:= s to t do
  if f[i] > f[i-j] then f[i]:=f[i-j];
 for j:= 1 to m do
  if a[j] = i then f[i]:=f[i]+1;
end;
max:=f[a[m]+t-1];
for i:= a[m] to a[m] + t - 1 do
 if max > f[i] then max:=f[i];
writeln(max);
end.
