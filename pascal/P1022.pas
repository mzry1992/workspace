var f:array[1..200] of longint;
    n,x,y,z,i,fx,fy:longint;
    s:set of 1..200;
function ff(i:longint):longint;
var j:longint;
begin
if f[i] = i then exit(i);
f[i]:=ff(f[i]);
exit(f[i]);
end;

begin
readln(n);
for x:= 1 to n do f[x]:=x;
for x:= 1 to n do
 begin
 read(y);
 while y <> 0 do
  begin
  fx:=ff(x);
  fy:=ff(y);
  f[fy]:=fx;
  read(y);
  end;
 readln;
 end;
s:=[];
for i:= 1 to n do
 s:=s+[f[i]];
x:=0;
for i:= 1 to n do
 if i in s then inc(x);
writeln(x);
end.
