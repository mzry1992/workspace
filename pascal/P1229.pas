var i,j,k:longint;

function tot(i:longint):longint;
var j,t:longint;
begin
t:=0;
for j:= 1 to i do
 if i mod j = 0 then  inc(i);
exit(t);
end;

begin
readln(k);
for i:= 1 to 20000 do
 begin
 j:=tot(i);
 if j = k then
  begin
  writeln(i);
  halt;
  end;
 end;
writeln('NO SOLUTION');
writeln(tot(16));
end.