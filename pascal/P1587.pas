var n,m,k,o,i,year,mont,day:longint;
    mon:array[1..5000] of longint;
    xq:array[0..5000] of qword;
begin
readln(n,m,k);
readln(o);
fillchar(xq,sizeof(xq),0);
for i:= 1 to m do read(mon[i]);
day:=1;
for year := 1 to n do
 for mont := 1 to m do
 begin
 if mon[mont] >= o then inc(xq[(day+o-1) mod k]);
 day:=(day+mon[mont] mod k) mod k;
 end;
for i:= 1 to k-1 do write(xq[i],' ');
writeln(xq[0]);
end.

