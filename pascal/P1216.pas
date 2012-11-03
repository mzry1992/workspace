var i,a,b,total,t,tt:longint;

function tot(i:longint):longint;
var j,t:longint;
begin
t:=0;
for j:= 1 to trunc(sqrt(i)) do
begin
 if i mod j = 0 then t:=t+j+i div j;
 if j = 1 then t:=t-i;
end;
exit(t);
end;

begin
readln(a,b);
total:=0;
for i:= a to b do
 begin
 t:=tot(i);
 if t > i then
  begin
  tt:=tot(t);
  if tt = i then
  inc(total);
  end;
 end;
writeln(total);
end.