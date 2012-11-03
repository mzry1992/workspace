var n,k,i,j:longint;
    g:array[1..1000,1..1000] of longint;
    v:array[1..1000,1..1000] of boolean;

procedure output(l,r:longint);
var i:longint;
begin
if v[l,r] then begin write(l,' '); exit; end;
for i:= 1 to n do
if g[l,i] > 0 then
if g[i,r] > 0 then
 if g[l,i] + g[i,r] = g[l,r] then
  begin
  output(l,i);
  output(i,r);
  exit;
  end;
end;

procedure input;
begin
fillchar(v,sizeof(v),false);
readln(n);
for i:= 1 to n do
begin
for j:= 1 to n do
begin
read(g[i,j]);
if g[i,j] > 0 then
v[i,j]:=true;
end;
readln;
end;
end;

begin
input;
for k:= 1 to n do
 for i:= 1 to n do
  for j:= 1 to n do
   if g[i,k] > 0 then
    if g[k,j] > 0 then
     if (g[i,j] = 0 ) or (g[i,k] + g[k,j] < g[i,j]) then
      g[i,j]:=g[i,k]+g[k,j];
for i:= 1 to n do
begin
for j:= 1 to n do write(g[i,j],' ');
writeln;
end;
output(1,n);
writeln(n);
writeln(g[1,n]);
end.
