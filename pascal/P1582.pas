var tn,n,m,i,j,run:integer;
    list:array[1..50] of string;
begin
readln(tn);
readln(n,m);
for i:= 1 to tn do readln(list[i]);
if n*m mod 8 <> 0 then
begin
writeln('Nobody can win!');
halt;
end;
run:=(n*m div 4 - 1 ) mod tn + 1 ;
writeln(list[run],' can win!');
end.
